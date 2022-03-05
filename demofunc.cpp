	#include <iostream>
	using namespace std;
	string generateWord(){
		return "book";
	}
	char getWord(){
		char word;
		cin>>word;
		return word;
	}


	string update(char word, string secretWord, string updatedWord){
		for(int i=0;i<secretWord.length();i++){
			if(word==secretWord[i]){
				updatedWord[i]=word;
			}
		}
		return updatedWord;
	}
	void renderGame(string updateWord, int badGuessCount){
		cout<<updateWord<<endl;
		cout<<"Number of wrong guesses:"<<badGuessCount<<endl;
	}
	bool contains(string secretWord, char ch){
		for (int i=0; i<secretWord.size(); i++){
			if (ch==secretWord[i]) return true;
		}
		return false;
	}
	int main(){
		string secretWord=generateWord();
		string updatedWord=string(secretWord.size(), '-');
		int badGuessCount=0;
		do{
			system("cls");
			renderGame(updatedWord,badGuessCount);
			cout<<"Enter your guess:";
			char word=getWord();
			if (contains(secretWord,word)) updatedWord= update(word, secretWord, updatedWord);
				else badGuessCount++;
			
		}while(badGuessCount<7&&updatedWord!=secretWord);
		system("cls");
		renderGame(updatedWord,badGuessCount);
		if (badGuessCount<7) cout<<"win!"; else cout<<"lose!";
		
	}