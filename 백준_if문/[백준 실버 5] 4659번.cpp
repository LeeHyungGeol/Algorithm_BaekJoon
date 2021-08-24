// 문자열

// 조건에 따른 합불여부
// 항상 조건을 한번에 처리하지 않아도 된다!

#include <iostream>
#include <string>

using namespace std;

string Str;
bool conditionOne(string str);
bool conditionTwo(string str);
bool conditionThree(string str);
bool isVowel(char c);

int main() {
	while (cin >> Str) {
		if (Str == "end") {
			break;
		}

		if (!conditionOne(Str)) {
			cout << "<" << Str << "> is not acceptable." << '\n';
			continue;
		}
		if (!conditionTwo(Str)) {
			cout << "<" << Str << "> is not acceptable." << '\n';
			continue;
		}
		if (!conditionThree(Str)) {
			cout << "<" << Str << "> is not acceptable." << '\n';
			continue;
		}
		cout << "<" << Str << "> is acceptable." << '\n';
	}

	return 0;
}

bool conditionOne(string str) {
	int countVowel = 0;
	
	for (auto c : Str) {
		if (isVowel(c)) {
			++countVowel;
		}
	}

	if (countVowel > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool conditionTwo(string str) {
	int countConsonant = 0, countVowel = 0;

	for (auto c : Str) {
		if (isVowel(c)) {
			++countVowel;
			countConsonant = 0;
		}
		else {
			++countConsonant;
			countVowel = 0;
		}
		if (countConsonant == 3 || countVowel == 3) {
			return false;
		}
 	}

	return true;
}

bool conditionThree(string str) {
	bool flag = true;
	int countConsonant = 0, countVowel = 0;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == str[i + 1]) {
			if (str[i] == 'e' || str[i] == 'o') {
				continue;
			}
			else {
				flag = false;
				break;
			}
		}
	}

	return flag;
}

bool isVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

