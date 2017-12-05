#include "bTREE.h"
#include "merkFuncs.cpp"
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE() : tree_(NULL)
{

}

bTREE::~bTREE() 
{

	destroy( tree_ );

}

// Returns the root value of the tree
string bTREE::getRoot(){

	return tree_->data_;

}

// Returns data inserted from the tree
string bTREE::dataInserted()
{

	return dataInserted(tree_);

}

// returns the data inserted for a specific node
string bTREE::dataInserted(const treeNode * subtree){

	if(subtree != NULL){
		return subtree->data_ + dataInserted(subtree->left_) + dataInserted(subtree->right_);
	} else {
		return "";
	}

}

// Fetchs the number of nodes in the tree
int bTREE::numberOfNodes(){

	if(tree_ == NULL){
		return 0;
	}
	return 1 + numberOfNodes(tree_->left_) + numberOfNodes(tree_->right_);

}

// Fetches the number of nodes of a specific subtree
int bTREE::numberOfNodes(const treeNode * subtree){

	if(subtree == NULL){
		return 0;
	}
	return 1 + numberOfNodes(subtree->left_) + numberOfNodes(subtree->right_);

}

// A bit of a misnomer. Constructes a balanced binary tree from a vector containing the child nodes.
void bTREE::fromList(vector<string> list){

	int size = list.size();
	copyBuilder(size);
	for(int i = 0; i < size; i++){
		childInsert(list[i], time(NULL));
	}
	hashRents(1);

}


// Inserts a child into the tree. Ensures that children are inserted at the lowest point of the tree.
void bTREE::childInsert(string data, int time = 1){
	
	childInsert(tree_, data, time);

}

// Inserts a child node into a subtree
bool bTREE::childInsert(treeNode * & subtree, string data, int time = 1){
	//cout << "hey!" << endl;
	if(subtree == NULL){
	//	cout << "end of tree!" << endl;
		return false;
		
	} else if(!subtree->isLeaf){
		//cout << "subtree: " << subtree->data_ << endl;
		if(!childInsert(subtree->left_, data, time)){
			return childInsert(subtree->right_, data, time);
		} else {
			return true;
		}
	} else if(subtree->data_.at(0) == '#'){ 
	//if(subtree->data_.at(0) == '#'){
		//cout << "child found!" << endl;
		subtree->time_ = time;
		subtree->data_ = data;
		//subtree->isLeaf = true;
		return true;
	}
}


// Recursively hashes the parents ('rents) of the tree, hashing their children and continuing up
void bTREE::hashRents(int selHash = 0){
	
	hashRents(tree_, selHash);

}

// Recursively hashes the parent nodes of a subtree
bool bTREE::hashRents(treeNode *& subtree, int selHash = 0){
	if(subtree == NULL){
		
		return true;

	}else if (subtree->isLeaf){
	
		return true;

	} else if(hashRents(subtree->left_, selHash) && hashRents(subtree->right_, selHash)) {
	//	
		subtree->time_ = time(NULL);
		
		if(subtree->left_ != NULL && subtree->right_ != NULL){
			subtree->data_ = hasher(subtree->left_->data_ + subtree->right_->data_, selHash);
		} else if(subtree->right_ != NULL){
			subtree->data_ = hasher(subtree->right_->data_, selHash);
		} else	{
			subtree->data_ = hasher(subtree->left_->data_, selHash);
		}
		return true;
	}
}


// Prunes the childless (i.e. spinster) nodes from the tree
void bTREE::spinsterPrune(){
	spinsterPrune(tree_);
}

// Prunes the spinsters of a subtree
bool bTREE::spinsterPrune(treeNode *& subtree){

	if(subtree->left_ != NULL){
		if(!spinsterPrune(subtree->left_) && !spinsterPrune(subtree->right_)){
			destroy(subtree->left_);
			destroy(subtree->right_);
			destroy(subtree);
			
		} else {
			return true;
		}
	}
	else if(subtree->right_ != NULL){
	
		if(!spinsterPrune(subtree->left_) && !spinsterPrune(subtree->right_)){
		
			destroy(subtree->left_);
			destroy(subtree->right_);
			destroy(subtree);

		} else {

			return true;

		}
	}
	else {
		if(subtree->isLeaf){

			return true;

		} else {

			destroy(subtree);

		}
	}
}


// Build a balance binary tree based on the number of child nodes we want the tree to have
// 'copy' because it essentially copies the fundamental tree structure all the way down
void bTREE::copyBuilder(int childNum){
	if(tree_ != NULL){
		destroy(tree_);
	}
	
	if(childNum > 2){
		// 1. Build the childless skeleton of the tree
		// 2. Add children
		// 3. Remove the nodes who are unfortunately childless

		copyConstructor(parentNumCalc(childNum));
		childrenAdd(childNum);
		spinsterPrune();

	} else {

		childNum++;
		copyConstructor(childNum);

	}
}

// Creates an unpruned and overall childless skeleton on which to attach children
// 'copy' because it essentially copies the fundamental tree structure all the way down
void bTREE::copyConstructor(int parentNum){

	parentNum = parentNumCalc(parentNum);
	int h = treeHeight(parentNum) + 1;
	int count = 0;
	copyConstructor(tree_, h, count);

}

// Creates childless skeleton of a subnode
void bTREE::copyConstructor(treeNode * & subtree, int height, int count){

	count ++;
	if(height > 0){
		height --;
		string node = string("(") + to_string(height) + ", " + to_string(count) + ") ";
		subtree = new treeNode(node);
		copyConstructor(subtree->left_, height, count - 1);
		copyConstructor(subtree->right_, height, count);
	}

}


// Empties the tree
void bTREE::empty(){

	destroy(tree_);

}


// Allows adding multiple children placeholders to the tree
void bTREE::childrenAdd(int numChildren){
	
	while(numChildren > 0){
		
		childAdd(numChildren);
		numChildren--;

	}

}

// Adds one child placeholder to the tree
bool bTREE::childAdd(int num){
	
	return childAdd(tree_, num);
}

// Adds once child placeholder to a subtree
bool bTREE::childAdd(treeNode * &subtree, int num){

	if(!subtree->isLeaf){

		if(subtree->left_ == NULL && subtree->right_==NULL){
		
			subtree->left_ = new treeNode("#child " + to_string(num), 1, true);
			return true;
			

		} else if(subtree->right_ == NULL && subtree->left_->isLeaf){
			
			subtree->right_ = new treeNode("#child " + to_string(num), 1, true);
			return true;

		} else {
	
			if(!childAdd(subtree->right_, num)){
		
				return childAdd(subtree->left_, num);
			
			} else {
				
				return true;
				
			}

		}

	} else {
		
		return false;
	
	}

}

// Destroys nodes recursively down a subtree
void bTREE::destroy(treeNode * & subtree){
	
	if(subtree != NULL){
		
		destroy( subtree->left_);
		destroy( subtree->right_);
		delete subtree;
		subtree = NULL;
		
	}

}


// Finds a node by its hash
int bTREE::find(string key){

	return find(tree_, key);

}

// Finds a node by its hash in a subtree
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

// Finds the order required to reach a node
string bTREE::locate(string key){

	return locate(tree_, key);

}

// Finds the order required to reach a node in a subtree
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


// Provides a visual representation of the tree
void bTREE::display(std::ostream& outfile){

	string prefix;

	if( tree_ == NULL){

		outfile << "-" << endl;

	} else {

		displayLeft(outfile, tree_->left_, "    ");
		outfile << "---" << tree_->data_ << " " << tree_->time_ << endl;
		displayRight(outfile, tree_->right_, "    ");

	}
	
}

// Provides a visual represtation of the left subtree
void bTREE::displayLeft( std::ostream & outfile, 
   treeNode * subtree, std::string prefix )
{
   
   if( subtree == NULL ) {
   
      outfile << prefix + "/" << std::endl;
   
   } else {
   
      displayLeft( outfile, subtree->left_, prefix + "     " );
      outfile << prefix + "/---" << subtree->data_ << " " << subtree->time_ 
      << std::endl;
      displayRight( outfile, subtree->right_, prefix + "|    " );
   
   }

}

// Provides a visual represtation of the left subtree
void bTREE::displayRight( std::ostream & outfile, 
   treeNode * subtree, std::string prefix )
{
   
   if( subtree == NULL ) {
   
      outfile << prefix + "\\" << std::endl;
   
   } else {
   
      displayLeft( outfile, subtree->left_, prefix + "|    " );
      outfile << prefix + "\\---" << subtree->data_ << " " << subtree->time_ 
      << std::endl;
      displayRight( outfile, subtree->right_, prefix + "     " );
   
   }

}

// Returns a list of the nodes in the tree
list<string> bTREE::toList(){

	return toList(tree_);

}

// Returns a list of the nodes in a subtree
list<string> bTREE::toList(treeNode *& subtree){
	
	list<string> temp;
	list<string> tempL;
	list<string> tempR;
	
	temp.push_back(subtree->data_ + "\t" +to_string(subtree->time_));
	
	if(subtree->left_ != NULL){
	
		if(subtree->right_ != NULL){
	
			tempL = toList(subtree->left_);
			tempR = toList(subtree->right_);
			tempL.splice(tempL.end(), tempR);
			temp.splice(temp.end(), tempL);
	
			return temp;
	
		} else{ 
	
			tempL = toList(subtree->left_);
			temp.splice(temp.end(), tempL);
	
			return temp;
	
		}
	
	} else if(subtree->right_ != NULL){
	
		tempR = toList(subtree->right_);
		temp.splice(temp.end(), tempR);
	
		return temp;
	
	} else {
	
		return temp;
	
	}
	
}
