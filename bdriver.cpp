#include "bTREE.cpp"
#include <iostream>
#include <vector>
using namespace std;
int main(){
	bTREE pseudo;
	//cout << test.dataInserted();
	// cout << "Adding one... " << endl;
	// bTREE pseudo;
	// for(int i = 1; i < 10; i++){
	// 	pseudo.copyBuilder(i);
	// }
	// pseudo.childInsert("works");
	// pseudo.childInsert("bear");
	// pseudo.display(cout);
	// pseudo.hashRents();
	// pseudo.display(cout);
	vector<string> list{"a","b","c","d","e","f"};
	pseudo.fromArray(list);
	pseudo.display(cout);
	
	// test.insert("stuff", 1);
	// //test.print();
	// cout << "Size now: " << test.numberOfNodes() << endl;
	// test.insert("things", 2);
	// test.insert("dank", 3);
	// test.insert("garbage", 4);
	// test.insert("yourMom", 6);
	// //test.print();
	// cout << "Size now: " << test.numberOfNodes() << endl;
	// cout << "finding stuff: " <<test.find("stuff") << endl;
	// cout << "finding benis: " << test.find("benis") << endl;
	// cout << "locating stuff: " << test.locate("stuff") << endl;
	// cout << "locating garbage: " << test.locate("garbage") << endl;
	// cout << "locating benisa: " << test.locate("benisa") << endl;
	// cout << "tree" << endl;
	// test.display(cout)
	// pseudo.display(cout);
	// pseudo.BSTconstruct(8);
	// pseudo.BSTconstruct(7);

	// pseudo.BSTconstruct(10);
	// pseudo.BSTconstruct(11);
	// pseudo.BSTconstruct(20);
	//cout << pseudo;
	//test.myMerkle.display(out);

	//test.print();
	//delete test;
}