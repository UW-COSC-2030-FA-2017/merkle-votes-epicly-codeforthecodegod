#include "pMT.h"
#include <string>
#include <sstream>
pMT::pMT(int selhash)
/**
 * @brief 
 * @param selectedHash a number corresponding to the hashfunction to use for this pMT
 * @return 
 */
{
	selectedHash = selhash;
}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
}

string pMT::getRoot(){
	return myMerkle.getRoot();
}

void pMT::fromArray(vector<string> childList){
	int size = childList.size();
	myMerkle.copyBuilder(size);
	for(int i = 0; i < size; i++){
		string unscanned = childList[i];
		istringstream is( unscanned );
		string data;
		int time;
		is >> data >> time;
		//cout << data;
		insert(data, time);
	}
	myMerkle.hashRents(selectedHash);
	cout << "--------------------------" << endl;
	cout << "Array: " << endl;
	cout << "--------------------------" << endl;
	for (auto v : childList)
        std::cout << v << "\n";
   cout << "--------------------------" << endl;
	myMerkle.display(cout);
	cout << "--------------------------" << endl <<endl;;
}


int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a stringd
 * @param time - an int representing the time 
 * @return the number of operations needed to do the insert, -1 if out of memory
 */
{
	//time = time(0);
	// if(selectedHash == 1)
	// {
	// 	myMerkle.childInsert(hash_1(vote),time);
	// }
	// else if (selectedHash == 2)
	// {
	// 	myMerkle.childInsert(hash_2(vote),time);
	// }
	// else if(selectedHash == 3)
	// {
	// 	myMerkle.childInsert(hash_3(vote),time);
	// }
	myMerkle.childInsert(vote,time);
	return 1;
}

int pMT::find(string vote, int time, int selectedHash)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param selectedHash, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{
	int found;
	int operations = 0;
	if(selectedHash == 1)
	{
		found = myMerkle.find(hash_1(vote));
	}
	else if (selectedHash == 2)
	{
		found = myMerkle.find(hash_2(vote));
	}
	else{
		found = myMerkle.find(hash_3(vote));
	}
	operations++;
	if(found == 0){
		return found;
	} else {
		return operations;
	}
}

list<string> pMT::toList(){
	return myMerkle.toList();
}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
	int found;
	int operations = 0;
	if(selectedHash == 1)
	{
		found = myMerkle.find(mhash);
	}
	else if (selectedHash == 2)
	{
		found = myMerkle.find(mhash);
	}
	else{
		found = myMerkle.find(mhash);
	}
	operations++;
	if(found == 0){
		return found;
	} else {
		return operations;
	}

}


string pMT::locateData(string vote)
// *
//  * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
//  * @param vote, the data to search for 
//  * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
{
	int timestamp = myMerkle.find(vote);
	if(selectedHash == 1)
	{
		return locateHash(hash_1(vote));
	}
	else if (selectedHash == 2)
	{
		return locateHash(hash_2(vote));
	}
	else{
		return locateHash(hash_3(vote));
	}
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param mhash, the hash to search for 
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
	return myMerkle.locate(mhash);
}



string pMT::hash_1(string key) //RSHash lab 9
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

   for(std::size_t i = 0; i < key.length(); i++)
   {
      hash = hash * a + key[i];
      a    = a * b;
   }

   return to_string(hash);
}

string pMT::hash_2(string key)//JSHash lab9
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
   unsigned int hash = 1315423911;

   for(std::size_t i = 0; i < key.length(); i++)
   {
      hash ^= ((hash << 5) + key[i] + (hash >> 2));
   }

   return to_string(hash);
}

string pMT::hash_3(string key)//PJWHash lab9
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
	unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash              = 0;
   unsigned int test              = 0;

   for(std::size_t i = 0; i < key.length(); i++)
   {
      hash = (hash << OneEighth) + key[i];

      if((test = hash & HighBits)  != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }
   return to_string(hash);
};



bool operator ==(pMT& lhs, pMT& rhs)
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if equal, false otherwise
*/
{
	list<string> left;
	list<string> right;
	left.splice(left.end(), lhs.toList());
	right.splice(left.end(), rhs.toList());
	return (left == right);
}

 bool operator !=(pMT& lhs, pMT& rhs)
 /**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
 {
 	list<string> left;
	list<string> right;
	left.splice(left.end(), lhs.myMerkle.toList());
	right.splice(left.end(), rhs.myMerkle.toList());
	return (left != right);
}
pMT operator ^=(pMT& lhs, pMT& rhs)

/*
 * @brief XOR between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
 	list<string> left;
 	list<string> right;
 	list<string> xr;
 	list<string> xr2;
 	left.splice(left.end(), lhs.toList());
 	right.splice(right.end(), rhs.toList());
	std::set_difference(left.begin(), left.end(), right.begin(), right.end(), std::inserter(xr, xr.begin()));
	std::set_difference(right.begin(), right.end(), left.begin(), left.end(), std::inserter(xr2, xr2.begin()));
	
	
	pMT temp(1);
	xr.splice(xr.end(),xr2);
	cout << "Unique HASHES: " << endl;
	for (auto v : xr)
     std::cout << v << "\n";
   std::vector<string> tempVect{ std::begin(xr), std::end(xr) };
   temp.fromArray(tempVect);
	return temp;
}



pMT operator ^( pMT& lhs, pMT& rhs)

/* @brief Where do two trees differ
 * @param lhs
 * @param rhs
 * @return a tree comprised of the right hand side tree nodes that are different from the left
 */
{
 	list<string> left;
 	list<string> right;
 	list<string> xr;
 	list<string> xr2;
 	left.splice(left.end(), lhs.toList());
 	right.splice(right.end(), rhs.toList());
	std::set_difference(left.begin(), left.end(), right.begin(), right.end(), std::inserter(xr, xr.begin()));
	std::set_difference(right.begin(), right.end(), left.begin(), left.end(), std::inserter(xr2, xr2.begin()));
	
	
	pMT temp(1);
	xr.splice(xr.end(),xr2);
	cout << "Unique HASHES: " << endl;
	for (auto v : xr)
     std::cout << v << "\n";
   std::vector<string> tempVect{ std::begin(xr), std::end(xr) };
   temp.fromArray(tempVect);
	return temp;
}

std::ostream& pMT::display(std::ostream& out){
	myMerkle.display(out);
	return out;
}


std::ostream& operator<<(std::ostream& out, pMT& p){
 	return p.display(out);
}

