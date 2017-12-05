#include "merkFuncs.cpp"

int main(){
    int childNum;
    cout << "Enter in number of child nodes: ";
    cin >> childNum;
    cout << "Total nodes: " << treeSizeCalc(childNum) << endl;
}