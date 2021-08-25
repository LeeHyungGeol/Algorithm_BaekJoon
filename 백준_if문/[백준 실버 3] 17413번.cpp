// 문자열, Stack, 구현
// 다음에는 Stack으로 구현해보자.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S, Answer;

int main() {
	getline(cin, S);

	bool isInTag = false;
	string tag = "", notTag = "";

	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == '<') {
			if (!notTag.empty()) {
				reverse(notTag.begin(), notTag.end());
				cout << notTag;
				notTag.clear();
			}

			isInTag = true;
			cout << '<';
			continue;
		}
		if (S[i] == '>') {
			isInTag = false;
			cout << tag << '>';
			tag.clear();
			continue;
		}
		if (isInTag) {
			tag += S[i];
		}
		if (!isInTag) {
			if (isalpha(S[i]) || isdigit(S[i])) {
				notTag += S[i];
			}
			else {
				reverse(notTag.begin(), notTag.end());
				cout << notTag << ' ';
				notTag.clear();
			}
		}
	}

	if (!notTag.empty()) {
		reverse(notTag.begin(), notTag.end());
		cout << notTag << ' ';
		notTag.clear();
	}

	return 0;
}