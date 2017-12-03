#include "pMT.cpp"
int main(){
	pMT test(1);
	test.insert("penis", 1);
	test.insert("bagina", 2);
	test.insert("crusty", 3);
	test.insert("dank", 4);
	cout << "finding penis by timestamp and data: " 
	<< test.find("penis",1,1) << endl;
	cout << "finding penis by hash ('Wrong): " << test.findHash("33211002410") << endl;
	cout << test;
	cout << "locate by hash ('2481728102'): " << test.locateHash("2481728102") << endl; 
	cout << "locate 'crusty': " << test.locateData("crusty") << endl; 
}