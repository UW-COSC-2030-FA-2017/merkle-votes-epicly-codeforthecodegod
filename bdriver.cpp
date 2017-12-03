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
	test.insert("peepeepoopoo", 3);
	test.insert("crabs", 4);
	//test.print();
	cout << "Size now: " << test.numberOfNodes() << endl;
	cout << "finding penis: " <<test.find("penis") << endl;
	cout << "finding benis: " << test.find("benis") << endl;
	cout << "locating penis: " << test.locate("penis") << endl;
	cout << "locating crabs: " << test.locate("crabs") << endl;
	cout << "locating benisa: " << test.locate("benisa") << endl;
	cout << "tree" << endl;
	test.display(cout);
	//test.print();
	//delete test;
}