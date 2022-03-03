#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;
struct player{
    string name;
    int score;
};
const string WORD_LIST[] = {
 "angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
 "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
 }; 
const string FIGURE[] = {
 " ------------- \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |            | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |            | \n"
 " |            O \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
" ------------- \n"
 " |            | \n"
 " |            O \n"
 " |            | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |            | \n"
 " |            O \n"
 " |           /| \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |            | \n"
 " |            O \n"
 " |           /|\\ \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |            | \n"
 " |            O \n"
 " |           /|\\ \n"
 " |           / \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |            | \n"
 " |            O \n"
 " |           /|\\ \n"
 " |           / \\ \n"
 " | \n"
 " ----- \n"
 };
const int MAX_BAD_GUESSES=7;
const int WORD_COUNT=sizeof(WORD_LIST)/sizeof(string);
string chooseWord();
void renderGame (const string &guessedWord,const int &badGuessCount,const player &pl);
void update(string &guessedWord, const string &secretWord, char guess);
bool contains (const string &word,const char &ch);
void gameMain(player &pl);
void createPlayer(vector <player> &LIST_PLAYERS);
void printChart(const vector <player> &LIST_PLAYERS);
void preProcess(vector <player> &LIST_PLAYERS);
int main(){
    vector <player> LIST_PLAYERS;
    int choose;
    do {
        cout<<string(40,'-')<<endl;
        cout<<"1. PLAY NOW"<<endl
            <<"2. Print chart"<<endl
            <<"3. Create new player"<<endl
            <<"0. exit"<<endl;
        cin>>choose;
        switch (choose){
            case 1:
                cout<<"HANGMAN CUSTOM VERSION 2.1 "<<endl;
                preProcess(LIST_PLAYERS);
                break;
            case 2:
                system("cls");
                cout<<"Print chart"<<endl;
                printChart(LIST_PLAYERS);
                break;
            case 3:
                system("cls");
                cout<<"Create new player: "<<endl;
                createPlayer(LIST_PLAYERS);
                break;
            case 0:
                cout<<"exit"<<endl;
                break;
        }
    } while (choose!=0);
    
    return 0;
}
string chooseWord (){
    int randomIndex= rand()%WORD_COUNT;
    return WORD_LIST[randomIndex];
}
void renderGame (const string &guessedWord, const int &badGuessCount, const player &pl){
    cout<<FIGURE[badGuessCount]<<endl;
    cout<<"Live score : "<<pl.score<<endl;
    cout<<guessedWord<<endl;
    cout<<"Number of wrong guesses:"<<badGuessCount<<endl;
}
void update(string &guessedWord,const string &secretWord, char guess){
    for (int i=0; i<secretWord.size(); i++){
        if (guess==secretWord[i]) guessedWord[i]=guess;
    }
}
bool contains (const string &word, const char &ch){
    for (int i=0; i<word.size(); i++){
        if (word[i]==ch) return true;
    }
    return false;
}
void gameMain(player &pl){
    srand(time(0));
    string secretWord=chooseWord();
    char guess;
    guess=tolower(guess);
    int badGuessCount=0;
    string guessedWord=string(secretWord.size(),'-');
    do {
        system("cls");
        renderGame(guessedWord,badGuessCount,pl);
        cin>>guess;
        if (contains(secretWord,guess)==true){
            update(guessedWord,secretWord,guess);
            pl.score++;
        } else {
            badGuessCount++;
        }

    }  while (badGuessCount<MAX_BAD_GUESSES&&secretWord!=guessedWord);
    system("cls");
    renderGame(guessedWord,badGuessCount,pl);
    if (badGuessCount<MAX_BAD_GUESSES) cout<<"Congratulations! You win!"; 
        else cout<<"You lost. The secret word is "<<secretWord<<endl;
}
void createPlayer(vector <player> &LIST_PLAYERS){
    player pl;
    string temp_name;
    bool is_true;
    do {
        cin.ignore();
        is_true=1;
        cout<<"Enter your username: "; getline(cin,temp_name); cout<<endl;
        for (int i=0; i<LIST_PLAYERS.size(); i++){
            if (temp_name==LIST_PLAYERS[i].name) is_true=0;
        }
        if (is_true==0) cout<<"This username already exists! Please try a diffrent name!"<<endl;
    } while(is_true==0);
    pl.name=temp_name;
    pl.score=0;
    LIST_PLAYERS.push_back(pl);
}
void printChart(const vector <player> &LIST_PLAYERS){
    cout<<string(40,'-')<<endl;
    for (int i=1; i<=LIST_PLAYERS.size(); i++){
        cout<<"|"<<left<<setw(2)<<i<<". "<<left<<setw(20)<<LIST_PLAYERS[i-1].name<<"| "<<"score: "<<LIST_PLAYERS[i-1].score<<right<<setw(5)<<" |"<<endl;
    }
}
void preProcess(vector <player> &LIST_PLAYERS){
    int index;
    if (LIST_PLAYERS.size()==0){
        cout<<"Player list is empty! Please create a username:"<<endl;
        createPlayer(LIST_PLAYERS);
        gameMain(LIST_PLAYERS[0]);
    } else {
    cout<<"Please enter your username:"<<endl;
    cin.ignore();
    do {
        string temp_name; getline(cin,temp_name);
        index=-1;
        for (int i=0; i<LIST_PLAYERS.size(); i++){
            if (temp_name==LIST_PLAYERS[i].name){
                index=i;
                break;
            }
        }
        if (index==-1) cout<<"No exist. Check it again!"<<endl; 
    } while (index==-1);
        gameMain(LIST_PLAYERS[index]);
    }
}