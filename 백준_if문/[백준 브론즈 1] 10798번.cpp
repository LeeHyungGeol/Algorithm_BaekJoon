// ¹®ÀÚ¿­

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Str, Answer;
vector<vector<char>> Sentences;

int main() {
	Sentences.resize(5, vector<char>(15, ' '));

	for (int i = 0; i < 5; ++i) {
		cin >> Str;
		for (int j = 0; j < Str.length(); ++j) {
			Sentences[i][j] = Str[j];
		}
	}

	for (int j = 0; j < 15; ++j) {
		for (int i = 0; i < 5; ++i) {
			if (Sentences[i][j] != ' ') {
				Answer += Sentences[i][j];
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}