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
	
	//Testing creating files and writing input text into a file:
	if (argc == 1){
		ofstream MyFile("creatingTestFile.txt");
		cout << "Enter some text and we will write the text into 'creatingTestFile.txt'";
		//cin >> myText;
		
		int counter = 1;
		while (argv[counter] != '\0') {
			counter++;
			getline(cin, argv[counter]);

		}

		//test cases:
		int counter2 = 1;
		while ()

		//MyFile << myText;

		//cout << myText;
	}



	
	return 0;
}
