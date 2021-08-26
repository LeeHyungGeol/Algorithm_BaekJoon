// 문자열, 투 포인터, 회문(Palindrome) 

#include <iostream>
#include <string>

using namespace std;

int T;
string Str;

bool isPalindrome(string str);
bool isPseudoPalindrome(string str);

int main() {
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> Str;

		if (isPalindrome(Str)) {
			cout << "0" << '\n';
		}
		else {
			if (isPseudoPalindrome(Str)) {
				cout << "1" << '\n';
			}
			else {
				cout << "2" << '\n';
			}
		}
	}

	return 0;
}

bool isPalindrome(string str) {
	int start = 0;
	int end = str.length() - 1;

	while (start < end) {
		if (str[start] != str[end]) {
			return false;
		}
		++start;
		--end;
	}
	return true;
}

bool isPseudoPalindrome(string str) {
	int start = 0;
	int end = str.length() - 1;

	while (start < end) {
		if (str[start] != str[end]) {
			string temp = str;
			string first = temp.erase(start, 1);
			string second = str.erase(end, 1);

			if (isPalindrome(first)) {
				return true;
			}
			else if (isPalindrome(second)) {
				return true;
			}
			else {
				return false;
			}
		}

		++start;
		--end;
	}
}