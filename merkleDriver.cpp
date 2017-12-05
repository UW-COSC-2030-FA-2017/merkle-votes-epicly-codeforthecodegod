#include "pMT.cpp"
int main(){
	pMT test(1);
	vector<string> vec{"a\t1","b\t2","c\t1","d\t1"};
	test.fromArray(vec);
}