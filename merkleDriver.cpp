#include "pMT.cpp"
#include "bTREE.cpp"
int main(){
	pMT test(1);
	pMT test2(1);
	vector<string> vec{"a\t1","b\t2","c\t1","d\t1","e\t1"};
	test.fromArray(vec);
	vector<string> ree{"b\t2","c\t2","d\t1","e\t3","f\t4", "g\t5"};
	test2.fromArray(ree);
	test ^= test2;
	cout << (test == test2) << endl;
	
}