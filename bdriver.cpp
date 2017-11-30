#include "bTREE.cpp"
#include <iostream>
using namespace std;
int main(){
	bTREE test;
	cout << "Size: " << test.numberOfNodes() << endl;
	cout << "Adding one... " << endl;
	test.insert("penis", 1);
	test.insert("bagina", 2);
	cout << "Size now: " << test.numberOfNodes() << endl;

}