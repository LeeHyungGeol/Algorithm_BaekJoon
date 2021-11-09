#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;

int main() {
	getline(cin, S);

	bool flag = false;
	string str = "";

	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == '<') {
			if (!str.empty()) {
				reverse(str.begin(), str.end());
				cout << str;
				str.clear();
			}
			cout << S[i];
			flag = true;
			continue;
		}
		else if (S[i] == '>') {
			if (!str.empty()) {
				reverse(str.begin(), str.end());
				cout << str;
				str.clear();
			}
			cout << S[i];
			flag = false;
			continue;
		}
		if (flag) {
			cout << S[i];
			continue;
		}
		if (S[i] == ' ' && !str.empty()) {
			reverse(str.begin(), str.end());
			cout << str << ' ';
			str.clear();
			continue;
		}
		str.push_back(S[i]);
	}

	if (!str.empty()) {
		reverse(str.begin(), str.end());
		cout << str;
		str.clear();
	}

	return 0;
}