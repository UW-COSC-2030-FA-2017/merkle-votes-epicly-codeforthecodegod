#pragma once
#include <string>
using namespace std;

class bTREE
{

    struct treeNode{
        string data;
        int time;
        treeNode * left_;
        treeNode * right_;
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    
public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes();
    
    bool insert(string, int);
    
    bool find(string);
    
    string locate(string);

    bool isLeaf(treeNode bruh);
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

