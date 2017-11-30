#pragma once
#include <string>
#include "time.h"
#include <iostream>
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
    treeNode * tree_;
    
public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    
    int numberOfNodes(const treeNode * subtree);
    
    int insert(treeNode * subtree, string data, int time);
    
    int find(const treeNode * subtree, string key);
    
    string locate(const treeNode * subtree, string);

    void destroy(treeNode * & subtree);
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

