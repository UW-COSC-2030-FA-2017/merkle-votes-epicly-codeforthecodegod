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
	if(tree_ == NULL){
		return 0;
	}
	return 1 + 
}

int bTREE::insert(string data, int time)
{
}

int bTREE::find(string)
{
}

string bTREE::locate()
{
}

friend bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
{
}

friend bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
{
}

friend std::ostream& bTREE::operator <<(std::ostream& out, const bTREE& p)
{
}
