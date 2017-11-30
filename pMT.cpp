#include "pMT.h"
pMT::pMT(int selectedHash)
/**
 * @brief 
 * @param selectedHash a number corresponding to the hashfunction to use for this pMT
 * @return 
 */
{
	//int time = time(0);
}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
}

int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time 
 * @return the number of operations needed to do the insert, -1 if out of memory
 */
{
	//time = time(0);
	int operations = 0;
	if(selectedHash == 1)
	{
		insert(hash_1(vote),time);
	}
	else if (selectedHash == 2)
	{
		insert(hash_2(vote),time);
	}
	else if(selectedHash == 3)
	{
		insert(hash_3(vote),time);
	}
	return operations;
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
	int operations = 0;
	if(find(vote, time, selectedHash) == 1)
	{
		operations = 1;
		return operations;
	}
	else 
	{
		return operations;
	}
    
}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
	int operations = 0;
	if(myMerkle.numberOfNodes(myMerkle) != 0)
	{
		myMerkle.locate(mhash);
		operations = 1;
		return operations;
	}
	else
	{
		return operations;
	}

}


string pMT::locateData(string vote)
/**
 * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param vote, the data to search for 
 * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
 */
{
	int operations = 0;
	if(myMerkle != null)
	{
		myMerkle.Tree_->left_.locate(vote);
		myMerkle.Tree_->right_.locate(vote);
		operations = 2;
		return operations;
	}
	else
	{
		return operations;
	}
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param mhash, the hash to search for 
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
		int operations = 0;
	if(myMerkle != null)
	{
		myMerkle.Tree_->left_.locate(mhash);
		myMerkle.Tree_->right_.locate(mhash);
		operations = 2;
		return operations;
	}
	else
	{
		return operations;
	}
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
}

friend bool pMT::operator ==(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if equal, false otherwise
 */
{
	if(lhs.tree_->data == rhs.tree_->data && lhs.tree_->time == rhs.tree_->time){
		return true;
	}
	return false;
}

friend bool pMT::operator !=(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
  if(lhs.tree_->data != rhs.tree_->data && lhs.tree_->time != rhs.tree_->time){
		return true;
	}
	return false;  
}

friend pMT pMT::operator ^=(const pMT& lhs, const pMT& rhs)
/**
 * @brief XOR between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
    if(lhs.tree_->data ^= rhs.tree_->data && lhs.tree_->time ^= rhs.tree_->time){
		return true;
	}
	return false;
}


friend std::ostream& pMT::operator <<(std::ostream& out, const pMT& p)
/**
 * @brief Print out a tree
 * @param out
 * @param p
 * @return a tree to the screen
 */
{

std::string prefix;
   if( tree_ == NULL )
   {
      out << "-" << std::endl;
   }
   else
   {
      displayLeft( out, tree_->left_, "    " );
      outfile << "---" << tree_->entry_ << std::endl;
      displayRight( out, tree_->right_, "    " );
   }
}


friend pMT pMT::operator ^(const pMT& lhs, const pMT& rhs)
/**
 * @brief Where do two trees differ
 * @param lhs
 * @param rhs
 * @return a tree comprised of the right hand side tree nodes that are different from the left
 */
{
 	bTREE diftree = new bTREE;
 	for(int i = 0; i < lhs.length; i++)
 	{
 		for(int j = 0; j < rhs.length;j++)
 		{
	 		if (lhs.i != rhs.j)
	 		{
	 			diftree.insert(rhs.j);
	 		}
	 	}
 	}
}


void 
   pMT:: displayLeft( std::ostream & outfile, 
   BinaryNode * subtree, std::string prefix )
{
   if( subtree == NULL )
   {
      outfile << prefix + "/" << std::endl;
   }
   else
   {
      displayLeft( outfile, subtree->left_, prefix + "     " );
      outfile << prefix + "/---" << subtree->entry_ << std::endl;
      displayRight( outfile, subtree->right_, prefix + "|    " );
   }
}

void 
   pMT:: displayRight( std::ostream & outfile, 
   BinaryNode * subtree, std::string prefix )
{
   if( subtree == NULL )
   {
      outfile << prefix + "\\" << std::endl;
   }
   else
   {
      displayLeft( outfile, subtree->left_, prefix + "|    " );
      outfile << prefix + "\\---" << subtree->entry_ << std::endl;
      displayRight( outfile, subtree->right_, prefix + "     " );
   }
}