#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	fstream file;
	int wordlength;
	int words = 0;
	int NumLetters[30] = {};
	string word, filename;

	cout << "Enter the name of the file to report all the words and the amount of letters each have: " << endl;
	cin >> filename;

	file.open(filename.c_str());

	while(file >> word){
		words++;	
		for ( int i = 0; i < word.length(); i++ ){
			if (ispunct(word[i])){
				word.erase(i--, 1);
			}
		}
		wordlength = word.length();
		NumLetters[wordlength - 1]++;;
	}	
	
	cout << "The number of words in the file is: " << words << endl;
	
	for(int i = 0; i < 30; i++){;
		if ( NumLetters[i] != 0 ){
			cout << "The number of words that have " << i+1 << " letters is " << NumLetters[i] << endl;
		}
	} 
}
