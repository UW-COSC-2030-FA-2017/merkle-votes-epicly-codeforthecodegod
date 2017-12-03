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
		subtree->isLeaf = 0;
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

int bTREE::find(string key){
	return find(tree_, key);
}

int bTREE::find(treeNode * subtree, string key){
	if(subtree == NULL){
		return 0;
	} else {
		if( subtree->data_ == key ){
			return subtree->time_;
		} else {
			return find(subtree->left_, key) + find(subtree->right_,key);
		}
	}
}


string bTREE::locate(string key){
	return locate(tree_, key);
}

string bTREE::locate(treeNode * subtree, string key){
	if(subtree == NULL){
		return ".";
	} else {
		if( subtree->data_ == key ){
			return "<" + key + ">";
		} else {
			string left = locate(subtree->left_, key);
			string right = locate(subtree->right_, key);
			if(left != "."){
				return "l" + left;
			} else if(right != "."){
				return "r" + right;
			} else {
				return ".";
			}
		}
	}
}

void bTREE::display(std::ostream& outfile) const {
	string prefix;
	if( tree_ == NULL){
		outfile << "-" << endl;
	} else {
		displayLeft(outfile, tree_->left_, "    ");
		outfile << "---" << tree_->data_ << endl;
		displayRight(outfile, tree_->right_, "    ");
	}
}

void bTREE::displayLeft( std::ostream & outfile, 
   treeNode * subtree, std::string prefix )
{
   if( subtree == NULL )
   {
      outfile << prefix + "/" << std::endl;
   }
   else
   {
      displayLeft( outfile, subtree->left_, prefix + "     " );
      outfile << prefix + "/---" << subtree->data_ << " " << subtree->isLeaf 
      << std::endl;
      displayRight( outfile, subtree->right_, prefix + "|    " );
   }
}

void bTREE::displayRight( std::ostream & outfile, 
   treeNode * subtree, std::string prefix )
{
   if( subtree == NULL )
   {
      outfile << prefix + "\\" << std::endl;
   }
   else
   {
      displayLeft( outfile, subtree->left_, prefix + "|    " );
      outfile << prefix + "\\---" << subtree->data_ << " " << subtree->isLeaf 
      << std::endl;
      displayRight( outfile, subtree->right_, prefix + "     " );
   }
}