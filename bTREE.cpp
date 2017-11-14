#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
	: tree_( NULL )
{

}

bTREE::~bTREE() 
{
	destroy( tree_ );
}

int bTREE::dataInserted()
{

}

int bTREE::numberOfNodes()
{
	return tree_.size();
}

// int bTREE::size( const treeNode * subtree){
// 	if(subtree == NULL){
// 		return 0;
// 	}

// 	return 1 + size(subtree->left_) + size(subtree->right_);
// }

int bTREE::insert(string data, int time)
{
    /* If the tree is empty, return a new node */
    if (tree_ == NULL) 
    	{
    		tree_.time = time;
    		tree_.data = data;
    		
    	}
    /* Otherwise, recur down the tree */
    if (data < tree_->data)
       { tree_->left_  = insert(tree_->left_, data);}
    else if (tree_ > tree_->data)
       { tree_->right_ = insert(tree_->right_, data);}   

 	return tree_->time;
}

int bTREE::find(string key)
{
	if (tree_ == NULL || tree_->data == key){
		return tree_->time;
	}

	if (tree_->data < key){
		return find(tree_->right_, key);
	}

	return find(tree_->left_, key);
}

string bTREE::locate(string key)
{
	if (tree_ == NULL || tree_->data == key){
		return tree_->data;
	}

	if (tree_->data < key){
		return find(tree_->right_, key);
	}

	return find(tree_->left_, key);
}

friend bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs->data == rhs->data && lhs->time == rhs->time){
		return 1;
	}
	return 0;
}

friend bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs->data == rhs->data || lhs->time == rhs->time){
		return 1;
	}
	return 0;
}

friend std::ostream& bTREE::operator <<(std::ostream& out, const bTREE& p)
{
	std::cout << "Timestamp: " << p->time << " Data: " << p->data;
}
