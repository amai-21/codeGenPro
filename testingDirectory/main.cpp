//main.cpp
#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char* argv[]){

	string myText;
	if (argc > 1) {
		ifstream MyReadFile(argv[1]);
		cout << argv[1];
		while (getline (MyReadFile, myText)) {
			cout << myText;
		}
		MyReadFile.close();
	}
	//cout << argv[0];
	
	
	return 0;
}
