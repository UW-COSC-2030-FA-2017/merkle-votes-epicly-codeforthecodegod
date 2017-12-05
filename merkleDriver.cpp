#include "pMT.cpp"
int main(){
	pMT test(1);
	test.insert("stuff", 1);
	test.insert("things", 2);
	test.insert("garbage", 3);
	test.insert("dank", 4);
	cout << "finding stuff by timestamp and data: " 
	<< test.find("stuff",1,1) << endl;
	cout << "finding stuff by hash ('Wrong): " << test.findHash("33211002410") << endl;
	cout << test;
	cout << "locate by hash ('2481728102'): " << test.locateHash("2481728102") << endl; 
	cout << "locate 'garbage': " << test.locateData("garbage") << endl; 
}