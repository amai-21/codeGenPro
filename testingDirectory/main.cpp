//main.cpp
#include <iostream>
#include <fstream>


using namespace std;

//int getASCII(char);

int main(int argc, char* argv[]){
	//char ch = 'A';

//	cout << (getASCII(ch));
	
	string str("some string");
	//char charArray[];
	int arraySize = 0;
	for (auto c: str) {
		arraySize++;
	}

	char charArray[arraySize];

	for (auto c : str) {
		charArray[];
	}


	
	return 0;
}

/*
int getASCII(char ch) {
	if (ch == 65) {
		return 65;
	} else {
		return 0;
	}
	
}
*/
