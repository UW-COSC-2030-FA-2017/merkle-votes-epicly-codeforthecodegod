

#include "bTREE.h"
#include <string>
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
    void fromArray(vector<string> childList);
    int insert(string, int);
    int find(string vote, int time, int selectedHash);
    int findHash(string);
    string locateData(string vote);
    string locateHash(string mhash);
    
    // friend bool operator==(const pMT& lhs, const pMT& rhs); // = comparison 
    
    // friend bool operator!=(const pMT& lhs, const pMT& rhs);// not = comparison

    // friend pMT operator^=(const pMT& lhs, const pMT& rhs); //
    
    // friend pMT operator^(const pMT& lhs, const pMT& rhs);

    // friend std::ostream& operator<<(std::ostream& out, const pMT& p); //display function

};

