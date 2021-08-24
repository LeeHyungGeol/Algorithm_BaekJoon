// 문자열(isalpha(), str.find(K) != string::npos)

// isalpha() :
// 알파벳 대문자 "A-Z"는 1을 반환.
// 알파벳 소문자 'a-z"는 2를 반환.
// 알파벳이 아닌것은 0을 반환합니다.

#include <iostream>
#include <string>

using namespace std;

string S, K;

int main() {
	cin >> S >> K;

	string str = "";

	for (auto c : S) {
		if (isalpha(c)) {
			str += c;
		}
	}

	if (str.find(K) != string::npos) {
		cout << "1" << '\n';
	}
	else {
		cout << "0" << '\n';
	}
 
	return 0;
}