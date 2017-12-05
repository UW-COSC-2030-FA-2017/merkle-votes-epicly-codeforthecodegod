#ifndef PMT_H_
#define PMT_H_

#include "bTREE.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
    
public:
    pMT(int);
    ~pMT();
    std::ostream& display(std::ostream& out);
    void hashRents();
    void hashRents(bTREE::treeNode *& subtree);
    void fromArray(vector<string> childList);
    int insert(string, int);
    int find(string vote, int time, int selectedHash);
    int findHash(string);
    string locateData(string vote);
    string locateHash(string mhash);
    list<string> toList();
    
    friend bool operator==(pMT& lhs, pMT& rhs); // = comparison 
    
    friend bool operator!=( pMT& lhs, pMT& rhs);// not = comparison

    friend pMT operator^=( pMT& lhs, pMT& rhs); //
    
    // friend pMT operator^(const pMT& lhs, const pMT& rhs);

    friend std::ostream& operator<<(std::ostream& out, const pMT& p); //display function
    
    

};

#endif