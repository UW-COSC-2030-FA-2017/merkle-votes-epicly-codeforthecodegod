#include <iostream>
#include <list>
#include <math.h>
using namespace std;

inline int timesCalc(int times){
		if(times > 1){
			int it = (times - 9)/2 - 1;
			return it - timesCalc(it);
		} else {
			return times;
		}
	}

inline int parentNumCalc(int childNum){
    int pNum;
    if(childNum > 1){
        pNum = childNum / 2 + childNum % 2;
        return pNum + parentNumCalc(pNum);
    }
    return 0;
}

inline int treeSizeCalc(int childNum){
    return childNum + parentNumCalc(childNum);
}

inline int treeHeight(int nodeNum){
    return log2(nodeNum);
}