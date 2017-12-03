#include "bTREE.cpp"
#include <iostream>
using namespace std;
int main(){
	bTREE test;
	cout << "Size: " << test.numberOfNodes() << endl;
	//cout << test.dataInserted();
	cout << "Adding one... " << endl;
	
	test.insert("penis", 1);
	//test.print();
	cout << "Size now: " << test.numberOfNodes() << endl;
	test.insert("bagina", 2);
	//test.print();
	cout << "Size now: " << test.numberOfNodes() << endl;
	//test.print();
	//delete test;
}