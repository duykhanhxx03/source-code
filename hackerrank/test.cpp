#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void print(const string &chars, string &s, int pos, int charsLeft) {
	for (const char c : chars) {
		s[pos] = c;
		if (charsLeft == 1) {
		    cout << s << endl;
		}
		else print(chars, s, pos+1, charsLeft-1);
	}
}

int main() {
	string chars;
	cin >> chars;
	sort(chars.begin(), chars.end());
	string s(chars.size(),' ');
	for (int i = 1; i <= chars.size(); i++)
	{
	    print(chars, s, 0, i);
	}
	return 0;
}