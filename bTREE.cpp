#include "bTREE.h"
#include "merkFuncs.cpp"
#include <string>

using namespace std;

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

void bTREE::childInsert(string data, int time){
	childInsert(tree_, data, time);
}

void bTREE::hashRents(){
	hashRents(tree_);
}

bool bTREE::hashRents(treeNode *& subtree){
	if(subtree == NULL){
		return true;
	} else if (subtree->isLeaf){
		return true;
	} else if(hashRents(subtree->left_) && hashRents(subtree->right_)) {
		cout << "hashing" << endl;
		if(subtree->left_ != NULL && subtree->right_ != NULL){
			subtree->data_ = subtree->left_->data_.substr(0, 2) + subtree->right_->data_.substr(0,2);
		} else if(subtree->left_ != NULL){
			subtree->data_ = subtree->left_->data_.substr(0,2);
		} else {
			subtree->data_ = subtree->right_->data_.substr(0,2);
		}
		return true;
	}
}

bool bTREE::childInsert(treeNode * & subtree, string data, int time){
	//cout << "hey!" << endl;
	if(subtree == NULL){
		cout << "end of tree!" << endl;
		return false;
		
	} else if(!subtree->isLeaf){
		cout << "subtree: " << subtree->data_ << endl;
		if(!childInsert(subtree->left_, data, time)){
			return childInsert(subtree->right_, data, time);
		} else {
			return true;
		}
	} else {
		cout << "child found!" << endl;
		subtree->data_ = data;
		subtree->time_ = time;
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
	cout << "Pruning the tree!" << endl;
	if(subtree->left_ != NULL){
		if(!spinsterPrune(subtree->left_) && !spinsterPrune(subtree->right_)){
			cout << "subtree " << subtree->data_ << " pruned!" << endl;
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
			cout << "subtree " << subtree->data_ << " pruned!" << endl;
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
	
	display(cout);
}


void bTREE::baseCopy(){
	createBST(2);
}

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

int bTREE::createBST(int childNum){
	
	int times = timesCalc(childNum);
	cout << "times " << times << endl;
	
	// while(times > 0){
	// 		childNum = childNum + parentNumCalc(childNum);
	// 		cout << "child num" << childNum << endl;
	// 		times--;
	// 	}
	// if(childNum % 2 < 1 ){
	// 	childNum = childNum - 1;
	// }
	
	if(childNum % 8 == 0){
		childNum = childNum - 1;
	}
	
	if(childNum % 3 < 2){
		childNum = childNum - 1;
	}
	
	cout << "child num" << childNum << endl;
	createBST(tree_, 0, parentNumCalc(childNum));
}

int bTREE::createBST(treeNode * &subtree, int start, int end){
	cout << "start: " << start << " end: " << end << endl;
	if(start > end && start != end){
		cout << "nil reached!" << endl;
		return 1;
	}
	int mid;
	int r;
	if(end - start > 7 && (start -  end + 1) % 3 > 1 && start != end){
		mid = 7;
		r = end - start - mid - 2;
	} else {
		mid = (start + end) / 2;
		r = mid + 1;
	}
	std::string node;
	node = string("(") + to_string(start) + ", " + to_string(end) + ", " + to_string(mid) + ") ";
	subtree = new treeNode(node);
	cout << "node: " << node << "created!" << endl;
	createBST(subtree->left_, start, mid - 1);
	createBST(subtree->right_, r, end);
	return 1;
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

void bTREE::BSTconstruct(int childNum){
	if(tree_ != NULL){
		destroy(tree_);
	}
	// if(childNum > 8){
	// 	createBST(8);
	// 	childrenAdd((8 * (childNum/8)));
	// } else {
		createBST(childNum);
	// }
	//childrenAdd(childNum);
	display(cout);
}

bool bTREE::childAdd(int num){
	return childAdd(tree_, num);
}

bool bTREE::childAdd(treeNode * &subtree, int num){
	if(!subtree->isLeaf){
		if(subtree->left_ == NULL && subtree->right_==NULL){
			cout << subtree->data_ << " Adding to the left: ";
			subtree->left_ = new treeNode("child " + to_string(num), 1, true);
			cout << "Success!" << endl;
			return true;
			

		} else if(subtree->right_ == NULL && subtree->left_->isLeaf){
			cout << subtree->data_ << " Adding to the right: ";
			subtree->right_ = new treeNode("child " + to_string(num), 1, true);
			cout << "Success!" << endl;
			return true;
		}
		else {
			cout << subtree-> data_ << " has non-child nodes, searching left: " << endl;
			if(!childAdd(subtree->right_, num)){
				cout << "failure, searching right..." << endl;
				return childAdd(subtree->left_, num);
			} else {
				return true;
				
			}
		}
	} else {
		return false;
	}
}

int bTREE::insert(string data, int time, bool leaf){
	
	return insert(tree_, data, time, leaf);
}

int bTREE::insert(treeNode * &subtree, string data, int time, bool leaf){
	// cout << "here3";
	// if(subtree != NULL){
	// 	if(subtree->left_->isLeaf != 0){
	// 		if(numberOfNodes(subtree->left_) <= numberOfNodes(subtree->right_)){
	// 			insert(subtree->left_, data, time);
	// 		} else {
	// 			insert(subtree->right_, data, time);
	// 		}
	// 	} else {
	// 		insert(subtree->right_, data, time);
	// 	}
	// } else {
	// 	subtree->isLeaf = 0;
	// 	subtree = new treeNode(data,time);
	// }
	
	// if(subtree == NULL){
	// 	//cout << "here4";
	// 	subtree = new treeNode(data, time, leaf);
	// } else {
		
	// 		if(subtree->left_ == NULL){
	// 			if(numberOfNodes(subtree->left_) <= numberOfNodes(subtree->right_)){
	// 				if(insert(subtree->left_, data, time, leaf) == 0){
	// 					insert(subtree->right_, data, time, leaf);
	// 				}
	// 			} else {
	// 				if(insert(subtree->right_, data, time, leaf) == 0){
	// 					insert(subtree->left_, data, time, leaf);
	// 				}
	// 			}
	// 		}else if(subtree->right_ == NULL){
	// 			if(insert(subtree->right_, data, time, leaf) == 0){
	// 				insert(subtree->left_, data, time, leaf);
	// 			}
	// 		} else {
	// 			if(!subtree->left_->isLeaf){
	// 				if(insert(subtree->right_, data, time, leaf) == 0){
	// 					insert(subtree->left_, data, time, leaf);
	// 				}
	// 			} else {
	// 				return 0;
	// 			}
	// 		}
	// }
	// return 1;
	
	// if(subtree == NULL){
	// 	//cout << "here4";
	// 	subtree = new treeNode(data, time);
	// } else {
	// 	subtree->isLeaf = 0;
	// 	if(subtree->left_ == NULL){
	// 		if(numberOfNodes(subtree->left_) <= numberOfNodes(subtree->right_)){
	// 			return insert(subtree->left_, data, time);
	// 		} else {
	// 			return insert(subtree->right_, data, time);
	// 		}
			
	// 	}else if(subtree->right_ == NULL){
	// 		return insert(subtree->right_, data, time);
	// 	} else {
	// 		return insert(subtree->left_, data, time);
	// 	}
	// }
	// return 1;
}

void bTREE::pseudoBuild(int childNum){
	int nodeNum = treeSizeCalc(childNum);
	cout << nodeNum << endl;
	// for(int i = 0; i < nodeNum; i++){
	// 	if(i <= (nodeNum - childNum - 1)){
	// 		pseudoInsert("parent", i, false, );
	// 	} else {
	// 		pseudoInsert("child", i, true);
	// 	}
	// }
	pseudoInsert("node", 0, nodeNum);
	
	
}

void bTREE::pseudoInsert(string data, int time, int size){
	pseudoInsert(tree_, data, time, size, 0);
}

void bTREE::pseudoInsert(treeNode * &subtree, string data, int time, int size, bool swch){
	if(size == 0 )
   {
      subtree = NULL;
   }
   else if (size > 8){
   	subtree = new treeNode(data, time);
   	int leftSize = (((size - 1) / 7)/2)*7;
   	int rightSize = size - 1 - leftSize;
   	pseudoInsert(subtree->left_, data, size, leftSize, 0);
      pseudoInsert(subtree->right_, data, size, rightSize, 0);
   }
   else if(swch){
   	cout << "switch" << endl;
   	cout << size << endl;
   	subtree = new treeNode(data, time);
   	size = size - 1;
   	pseudoInsert(subtree->left_, data, time, size, 1);
   }
   else if(size == 1){
   	
   	cout << size << endl;
   	size = 0;
   	subtree = new treeNode(data, time);
   	pseudoInsert(subtree->left_, data, time, size, 0);
 
   } else if(size == 3){
   	cout << size << endl;
   	size = 1;
   	subtree = new treeNode(data, time);
   	pseudoInsert(subtree->left_, data, time, size, 0);
		pseudoInsert(subtree->right_, data, time, size, 0);
   } else if(size < 6 && size %2 == 0){
   	int leftSize = size - 1;
   	subtree = new treeNode(data, time);
   	pseudoInsert(subtree->left_, data, time, leftSize, 0);
   	cout << "size: " << size << endl;
      cout << "left size: " << leftSize << endl;
      //cout << "right size: " << rightSize << endl; 
   }
   else
   {
      subtree = new treeNode(data, time);
      int leftSize = size/3 + (size % 2);
      cout <<leftSize << endl;
      if(size % 7 != 0){
      	leftSize = leftSize - size %2;
      } else {
      	if(size % 2 == 0){
      		leftSize += 2;
      	}
      }
      int rightSize = size - leftSize - 1;
      if(leftSize == 3){
      	if(rightSize <= 3){
      		pseudoInsert(subtree->left_, data, leftSize, leftSize, 0);
      		pseudoInsert(subtree->right_, data, rightSize, rightSize, 0);
      	} else {
      		pseudoInsert(subtree->left_, data, leftSize, leftSize, 1);
      		pseudoInsert(subtree->right_, data, rightSize, rightSize, 0);
      	}
      } else {
      	pseudoInsert(subtree->left_, data, time, leftSize, 0);
      	pseudoInsert(subtree->right_, data, time, rightSize, 0);
      }
      cout << "size: " << size << endl;
      cout << "left size: " << leftSize << endl;
      cout << "right size: " << rightSize << endl; 
     // if(size % 3 == 0){
	    //  int leftSize = size - 3;
	    //  pseudoInsert(subtree->left_, data, time, leftSize);
	    //  int rightSize = size - 1 - leftSize;
	    //  pseudoInsert(subtree->right_, data, time, rightSize );
	    //}else{
	    //	int leftSize = size - 1;
	    //  pseudoInsert(subtree->left_, data, time, leftSize);
	    //  int rightSize = size - 1 - leftSize;
	    //  pseudoInsert(subtree->right_, data, time, rightSize );
	    //}
   } 
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

void bTREE::display(std::ostream& outfile){
	string prefix;
	if( tree_ == NULL){
		outfile << "-" << endl;
	} else {
		displayLeft(outfile, tree_->left_, "    ");
		outfile << "---" << tree_->data_ << " " << tree_->time_ << endl;
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
      outfile << prefix + "/---" << subtree->data_ << " " << subtree->time_ 
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
      outfile << prefix + "\\---" << subtree->data_ << " " << subtree->time_ 
      << std::endl;
      displayRight( outfile, subtree->right_, prefix + "     " );
   }
}