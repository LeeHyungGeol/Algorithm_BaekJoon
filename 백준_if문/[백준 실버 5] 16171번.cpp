// ���ڿ�(isalpha(), str.find(K) != string::npos)

// isalpha() :
// ���ĺ� �빮�� "A-Z"�� 1�� ��ȯ.
// ���ĺ� �ҹ��� 'a-z"�� 2�� ��ȯ.
// ���ĺ��� �ƴѰ��� 0�� ��ȯ�մϴ�.

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