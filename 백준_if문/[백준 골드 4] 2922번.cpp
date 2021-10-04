#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

string Str;

ll dfs(int countVowel, int countConsonant, int countL, int index);
bool isVowel(char c);

int main() {
	cin >> Str;

	ll result = dfs(0, 0, 0, 0);
	
	cout << result << '\n';

	return 0;
}

ll dfs(int countVowel, int countConsonant, int countL, int index) {
	if (countVowel >= 3) {
		return 0;
	}
	if (countConsonant >= 3) {
		return 0;
	}

	if (index == Str.length()) {
		if (countL == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}


	if (Str[index] == '_') {
		return 5 * dfs(countVowel + 1, 0, countL, index + 1) + 20 * dfs(0, countConsonant + 1, countL, index + 1) + dfs(0, countConsonant+1, countL+1, index + 1);
	}
	else {
		if (isVowel(Str[index])) {
			return dfs(countVowel + 1, 0, countL, index + 1);
		}
		else {
			if (Str[index] == 'L') {
				return dfs(0, countConsonant+1, countL + 1, index + 1);
			}
			else {
				return dfs(0, countConsonant + 1, countL, index + 1);
			}
		}
	}
}

bool isVowel(char c) {
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}