#include <iostream>
#include <list>
#include <math.h>
using namespace std;

int timesCalc(int times){
		if(times > 1){
			int it = (times - 9)/2 - 1;
			return it - timesCalc(it);
		} else {
			return times;
		}
	}

int parentNumCalc(int childNum){
    int pNum;
    if(childNum > 1){
        pNum = childNum / 2 + childNum % 2;
        return pNum + parentNumCalc(pNum);
    }
    return 0;
}

int treeSizeCalc(int childNum){
    return childNum + parentNumCalc(childNum);
}

int treeHeight(int nodeNum){
    return log2(nodeNum);
}