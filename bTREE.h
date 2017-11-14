#pragma once
#include <string>
#include "time.h"
using namespace std;

class bTREE
{

    struct treeNode{
        string data;
        int time;
        treeNode * left_;
        treeNode * right_;
        bool isLeaf();
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    treeNode * tree_
    
public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes();
    
    bool insert(string, int);
    
    bool find(string);
    
    string locate(string);

    int size( const treeNode * subtree);
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

