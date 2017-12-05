#include "bTREE.h"
#include "merkFuncs.cpp"
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE() : tree_(NULL)
{
	//cout << tree_;
}

bTREE::~bTREE() 
{
	destroy( tree_ );
}

string bTREE::getRoot(){
	return tree_->data_;
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

void bTREE::fromArray(vector<string> list){
	int size = list.size();
	//cout << "size: " << size << endl;
	copyBuilder(size);
	for(int i = 0; i < size; i++){
		childInsert(list[i], time(NULL));
	}
	hashRents(1);
}

int bTREE::numberOfNodes(const treeNode * subtree){
	if(subtree == NULL){
		return 0;
	}
	return 1 + numberOfNodes(subtree->left_) + numberOfNodes(subtree->right_);
}

void bTREE::childInsert(string data, int time = 1){
	childInsert(tree_, data, time);
}

void bTREE::hashRents(int selHash = 0){
	hashRents(tree_, selHash);
}

bool bTREE::hashRents(treeNode *& subtree, int selHash = 0){
	if(subtree == NULL){
		return true;
	} else if (subtree->isLeaf){
		//cout << "Leaf hit!" << endl;
		return true;
	} else if(hashRents(subtree->left_, selHash) && hashRents(subtree->right_, selHash)) {
	//	cout << "hashing" << endl;
		//cout << "hashing subtree: " << subtree->data_ << " leaf: " << subtree->isLeaf << endl;
		subtree->time_ = time(NULL);
		
			if(subtree->left_ != NULL && subtree->right_ != NULL){
				subtree->data_ = hasher(subtree->left_->data_ + subtree->right_->data_, selHash);
			} else if(subtree->right_ != NULL){
				subtree->data_ = hasher(subtree->right_->data_, selHash);
			} else	{
				subtree->data_ = hasher(subtree->left_->data_, selHash);
				return true;
			}
		
	}
}

bool bTREE::childInsert(treeNode * & subtree, string data, int time = 1){
	//cout << "hey!" << endl;
	if(subtree == NULL){
	//	cout << "end of tree!" << endl;
		return false;
		
	} else if(!subtree->isLeaf){
	//	cout << "subtree: " << subtree->data_ << endl;
		if(!childInsert(subtree->left_, data, time)){
			return childInsert(subtree->right_, data, time);
		} else {
			return true;
		}
	} else if(subtree->data_.at(0) == '#'){
	//	cout << "child found!" << endl;
		subtree->time_ = time;
		subtree->data_ = data;
		subtree->isLeaf = true;
		return true;
	}
}

// void bTREE::createBST(int childNum){
// 	tree_ = createBST(0, treeSizeCalc(childNum) -1);
// }

// treeNode bTREE::createBST(int start, int end){
// 	if(start > end){
// 		return NULL
// 	}
	
// 	int mid = (start + end)/2;
// 	root = new treeNode("pseudo", start + end);
// 	root->left_ = createBST(start, mid - 1);
// 	root->right_ = createBST(mid + 1, end);
// 	return root;
// }

void bTREE::spinsterPrune(){
	spinsterPrune(tree_);
}

bool bTREE::spinsterPrune(treeNode *& subtree){
//	cout << "Pruning the tree!" << endl;
	if(subtree->left_ != NULL){
		if(!spinsterPrune(subtree->left_) && !spinsterPrune(subtree->right_)){
		//	cout << "subtree " << subtree->data_ << " pruned!" << endl;
			destroy(subtree->left_);
			destroy(subtree->right_);
			destroy(subtree);
			
		} else {
			return true;
		}
	}
	else if(subtree->right_ != NULL){
	// 	if(!spinsterPrune(subtree->right_)){
	// 		cout << "subtree " << subtree->data_ << " pruned!" << endl;
	// 		delete subtree;
	// 	} else {
	// 		return true;
	// 	}
		if(!spinsterPrune(subtree->left_) && !spinsterPrune(subtree->right_)){
		//	cout << "subtree " << subtree->data_ << " pruned!" << endl;
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

void bTREE::copyBuilder(int childNum){
	if(tree_ != NULL){
		destroy(tree_);
	}
	// if(childNum > 8){
	// 	createBST(8);
	// 	childrenAdd((8 * (childNum/8)));
	// } else {
	if(childNum > 2){
		copyConstructor(parentNumCalc(childNum));
	// }
		childrenAdd(childNum);
		spinsterPrune();
	} else {
		childNum++;
		copyConstructor(childNum);
	}
	
	//display(cout);
}


// void bTREE::baseCopy(){
// 	createBST(2);
// }

void bTREE::copyConstructor(int parentNum){
	//baseCopy();
	parentNum = parentNumCalc(parentNum);
	int h = treeHeight(parentNum) + 1;
	int count = 0;
	copyConstructor(tree_, h, count);
}

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


void bTREE::empty(){
	destroy(tree_);
}

void bTREE::childrenAdd(int numChildren){
	while(numChildren > 0){
		childAdd(numChildren);
		numChildren--;
	}
}


bool bTREE::childAdd(int num){
	return childAdd(tree_, num);
}

bool bTREE::childAdd(treeNode * &subtree, int num){
	if(!subtree->isLeaf){
		if(subtree->left_ == NULL && subtree->right_==NULL){
	//		cout << subtree->data_ << " Adding to the left: ";
			subtree->left_ = new treeNode("#child " + to_string(num), 1, true);
		//	cout << "Success!" << endl;
			return true;
			

		} else if(subtree->right_ == NULL && subtree->left_->isLeaf){
	//		cout << subtree->data_ << " Adding to the right: ";
			subtree->right_ = new treeNode("#child " + to_string(num), 1, true);
		//	cout << "Success!" << endl;
			return true;
		}
		else {
	//		cout << subtree-> data_ << " has non-child nodes, searching left: " << endl;
			if(!childAdd(subtree->right_, num)){
		//		cout << "failure, searching right..." << endl;
				return childAdd(subtree->left_, num);
			} else {
				return true;
				
			}
		}
	} else {
		return false;
	}
}


void bTREE::destroy(treeNode * & subtree){
	if(subtree != NULL){
		destroy( subtree->left_);
		destroy( subtree->right_);
		delete subtree;
		subtree = NULL;
		//cout << "Tree Destroyed!!" << endl;
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

void bTREE::display(std::ostream& outfile){
	string prefix;
	if( tree_ == NULL){
		outfile << "-" << endl;
	} else {
		displayLeft(outfile, tree_->left_, "    ");
		outfile << "-------" << tree_->data_ << " " << tree_->time_ << endl;
		displayRight(outfile, tree_->right_, "    ");
	}
	//return outfile;
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
      outfile << prefix + "/------" << subtree->data_ << " " << subtree->time_ 
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
      outfile << prefix + "\\------" << subtree->data_ << " " << subtree->time_ 
      << std::endl;
      displayRight( outfile, subtree->right_, prefix + "     " );
   }
}

list<string> bTREE::toList(){
	return toList(tree_);
}

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
