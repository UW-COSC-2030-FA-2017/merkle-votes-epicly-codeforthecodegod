#ifndef BTREE_H_
#define BTREE_H_

#include <string>
#include "time.h"
#include <iostream>
#include <list>
#include <vector>
#include "hashFuncs.h"
using namespace std;

class bTREE
{
    public:
    class treeNode{
    public:
        string data_;
        int time_;
        treeNode * left_;
        treeNode * right_;
        bool isLeaf;

    public:
        treeNode( string data = "empty", 
            int time = 0, bool leaf = false,
            treeNode * left = NULL,
            treeNode * right = NULL )
            : data_(data), time_(time), isLeaf(leaf),
            left_(left),
            right_(right){
                //cout << "Node created!" << endl;
                //cout << this << endl;
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
    void fromArray(vector<string> list);
    void hashRents(int selHash);
    bool hashRents(treeNode *& subtree, int selHash);
    void childInsert(string data, int time);
    bool childInsert(treeNode *& subtree, string data, int time);
    void spinsterPrune();
    bool spinsterPrune(treeNode *& subtree);
    void copyConstructor(int);
    void copyConstructor(treeNode * & subtree, int height, int count);
    int numberOfNodes();
    void empty();
    void childrenAdd(int);
    bool childAdd(int num);
    bool childAdd(treeNode *& subtree, int num);
    void copyBuilder(int);
    //int insert(string, int, bool);
    
    int find(string key);
    string locate(string key);
    void display(std::ostream& outfile);
    list<string> toList();
    list<string> toList(treeNode *& subtree);
    

private:
    string dataInserted(const treeNode * subtree);
    int numberOfNodes( const treeNode * subtree);
    //int insert(treeNode *& subtree, string data, int time, bool leaf);
    void destroy(treeNode * & subtree);
    int find(treeNode * subtree, string key);
    string locate(treeNode * subtree, string key);
    static void displayLeft(std::ostream & outfile, treeNode * subtree, string prefix);
    static void displayRight(std::ostream & outfile, treeNode * subtree, string prefix);
    //int find(const treeNode * subtree, string key);
    //string locate(const treeNode * subtree, string);

    
};

#endif