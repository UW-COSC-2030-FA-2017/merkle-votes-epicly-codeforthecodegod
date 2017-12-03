#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE() : tree_(NULL)
{
	cout << tree_;
}

bTREE::~bTREE() 
{
	destroy( tree_ );
}

string bTREE::dataInserted()
{
	return dataInserted(tree_);
}

string bTREE::dataInserted(const treeNode * subtree){
	return subtree->data_;
}

int bTREE::numberOfNodes(){
	if(tree_ == NULL){
		return 0;
	}
	return 1 + numberOfNodes(tree_->left_) + numberOfNodes(tree_->right_);
}

int bTREE::numberOfNodes(const treeNode * subtree){
	if(subtree == NULL){
		return 0;
	}
	return 1 + numberOfNodes(subtree->left_) + numberOfNodes(subtree->right_);
}


int bTREE::insert(string data, int time){
	cout << "here";
	return insert(tree_, data, time);
}

int bTREE::insert(treeNode * &subtree, string data, int time){
	cout << "here2";
	if(subtree == NULL){
		
		cout << "here4";
		subtree = new treeNode(data, time);
		cout << "tree:" << tree_;
		cout << (subtree == NULL);
		cout << "subtree: " << subtree->data_ << endl;
	} else {
		//delete subtree;
		cout << "here3";
		if(subtree->data_ > data){
			return insert(subtree->left_, data, time);
		}
		if(subtree->data_ < data){
			return insert(subtree->right_, data, time);
		}
	}
	return 1;
}

void bTREE::destroy(treeNode * & subtree){
	if(subtree != NULL){
		destroy( subtree->left_);
		destroy( subtree->right_);
		delete subtree;
		subtree = NULL;
		cout << "Tree Destroyed!!" << endl;
	}

}
