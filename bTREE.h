#pragma once
#include <string>
#include "time.h"
#include <iostream>
using namespace std;

class bTREE
{
    
    class treeNode{
    public:
        string data_;
        int time_;
        treeNode * left_;
        treeNode * right_;
        bool isLeaf;

    public:
        treeNode( string data = "empty", 
            int time = 0, bool leaf = 1,
            treeNode * left = NULL,
            treeNode * right = NULL )
            : data_(data), time_(time), isLeaf(leaf),
            left_(left),
            right_(right){
                cout << "Node created!" << endl;
                cout << this << endl;
            }
        ~treeNode(){
            }
    private:
        treeNode( const treeNode & );
        const treeNode & operator =( const treeNode & );
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    treeNode * tree_;
    
public:
    bTREE();
    ~bTREE();
    
    string dataInserted();
    
    int numberOfNodes();
    
    int insert(string, int);
    // returns timestamp if found
    int find(string key);
    // returns the sequence to get to the data
    string locate(string key);
    void display(std::ostream& outfile);

    // void print();

    // void printList(treeNode * node);
    
    
    // friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    // friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    // friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

private:
    string dataInserted(const treeNode * subtree);
    int numberOfNodes( const treeNode * subtree);
    int insert(treeNode *& subtree, string data, int time);
    void destroy(treeNode * & subtree);
    int find(treeNode * subtree, string key);
    string locate(treeNode * subtree, string key);
    static void displayLeft(std::ostream & outfile, treeNode * subtree, string prefix);
    static void displayRight(std::ostream & outfile, treeNode * subtree, string prefix);
    //int find(const treeNode * subtree, string key);
    //string locate(const treeNode * subtree, string);

    
};

