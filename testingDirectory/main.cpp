//main.cpp
#include <iostream>
#include <fstream>


using namespace std;

int getASCII(char);

int main(int argc, char* argv[]){
	char ch = 'A';

	cout << (getASCII(ch));
	


	
	return 0;
}

int getASCII(char ch) {
	if (ch == 65) {
		return 65;
	} else {
		return 0;
	}
	
}
