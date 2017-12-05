#include "pMT.cpp"
#include<iostream>
#include<fstream>
using namespace std;

//void mainMenu();

vector<string> stripper(string fileName){
	ifstream file;
	
	string str;
	vector<string> vect;
	file.open(fileName);
	string header;
	if(file.is_open()){
		//cout<< "file open!" << endl;
		getline(file, header);
		//cout << header << endl;
		//cout << "past first getline" << endl;
		while(getline(file, str)){
			//cout << str << endl;
			vect.push_back(str);
		}
		//for (auto v : vect) std::cout << v << "\n";
		file.close();
		return vect;
	} else {
		cout << "Problem with opening file!" << endl;
		exit(0);
	}
	
}

void treeExaminer(){
	string spacer = "----------------------------------------------------------";
	cout << spacer << endl << endl;
	cout << "\t" << "Welcome to the Tree Examiner!" << endl;
	cout << "\t" << "Here you can examine a merkle tree from a list" << endl<< endl;
	cout << spacer << endl;
	cout << "\t" << "Enter your filename: ";
	string filename;
	cin >> filename;
	vector<string> fileVect = stripper(filename);
	pMT tree(1);
	tree.fromArray(fileVect);
	cout << "\t" << "The root node of this tree is: " << tree.getRoot() << endl << endl;
	cout << spacer << endl << endl;
	// cout << "\t" << "Return to menu? (y,n): ";
	// string response;
	// cin >> response;
	// if(response == "y"){
	// 	mainMenu();
	// } else {
	// 	treeExaminer();
	// }
}

void treeCompare(){
	
	pMT tree1(1);
	pMT tree2(1);
	string filename1;
	string filename2;
	
	string spacer = "----------------------------------------------------------";
	cout << spacer;
	cout << "\t" <<"Welcome to the Tree Comparison!" << endl;
	cout << "\t" <<"Here you can compare to merkle trees" << endl <<endl;
	
	cout << spacer << endl;
	cout << "\t" << "Enter your filename: ";
	cin >> filename1;
	
	cout << spacer << endl;
	cout << "\t" << "Enter another filename: ";
	cin >> filename2;
	cout << spacer << endl;
	cout <<"\t" << "**Comparisons**" << endl;
	cout << spacer << endl;
	
	vector<string> fileVect1 = stripper(filename1);
	vector<string> fileVect2 = stripper(filename2);
	tree1.fromArray(fileVect1);
	tree2.fromArray(fileVect2);
	
	if(tree1 == tree2)
	{
		cout << "Tree's are equal!";
	}
	else if(tree1 != tree2)
	{
		cout << "Tree's are not equal!";
		cout << spacer << endl;
		cout << "Tree's Differ: \n";
		tree1 ^ tree2;
		cout << "\n";
		cout << "Xor: \n";
		tree1 ^= tree2;
		cout << "\n";
	}
}

void mainMenu(){
	string spacer = "----------------------------------------------------------\n\n";
	cout << spacer;
	cout << "\tWelcome to Kip and Connor's Vote Comparator!\n\n";
	cout << spacer;
	cout << "\tWe work hard to bring you the best in\n\tcryptographic vote analysis\n";
	cout << "\n\tPick from one of the options below!\n\n";
	cout << spacer;
	cout << "\t1. Tree Examiner:\t\tTake a vote file and see its pretty tree!\n";
	cout << "\t2. Tree Comparator:\t\tTake two list of votes and compare them to see if they are valid!\n\n";
	cout << spacer;
	cout << "Your selection? ";
	string input;
	cin >> input;
	if(input == "1"){
		treeExaminer();
	} else if (input == "2"){
		treeCompare();
	} else {
		mainMenu();
	}
}

int main(int argc, char **argv)
{
	mainMenu();
	return 1;
}
