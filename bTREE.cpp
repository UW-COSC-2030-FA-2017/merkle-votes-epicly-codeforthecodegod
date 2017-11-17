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
	return 1;
}

int bTREE::numberOfNodes(const treeNode * subtree)
{
	if(subtree == NULL){
		return 0;
	} else {
		return 1 + numberOfNodes(subtree->left_) + numberOfNodes(subtree->right_);
	}
}

// int bTREE::size( const treeNode * subtree){
// 	if(subtree == NULL){
// 		return 0;
// 	}

// 	return 1 + size(subtree->left_) + size(subtree->right_);
// }

int bTREE::insert(treeNode * subtree, string data, int time)
{
    /* If the tree is empty, return a new node */
    if (subtree == NULL) 
    	{
    		subtree->time = time;
    		subtree->data = data;
    		
    	}
    /* Otherwise, recur down the tree */
    if (data < subtree->data){
       return insert(subtree->left_, data, time);
    }
    else if (data > subtree->data){ 
    	return insert(subtree->right_, data, time);
    }   

 	return subtree->time;
}

int bTREE::find(const treeNode * subtree, string key)
{
	if (subtree == NULL || subtree->data == key){
		return subtree->time;
	}

	if (subtree->data < key){
		return find(subtree->right_, key);
	}

	return find(subtree->left_, key);
}

string bTREE::locate(const treeNode * subtree, string key)
{
	if (subtree== NULL || subtree->data == key){
		return subtree->data;
	}

	if (subtree->data < key){
		return locate(subtree->right_, key);
	}

	return locate(subtree->left_, key);
}

void 
   bTREE:: destroy( treeNode * & subtree )
{
   if( subtree != NULL )
   {
      destroy( subtree->left_ );
      destroy( subtree->right_ );
      delete subtree;
      subtree = NULL;
   }
}

bool operator==(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs.tree_->data == rhs.tree_->data && lhs.tree_->time == rhs.tree_->time){
		return 1;
	}
	return 0;
}

bool operator !=(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs.tree_->data == rhs.tree_->data || lhs.tree_->time == rhs.tree_->time){
		return 1;
	}
	return 0;
}

std::ostream& operator <<(std::ostream& out, const bTREE& p)
{
	return std::cout << "Timestamp: " << p.tree_->time << " Data: " << p.tree_->data;
}
