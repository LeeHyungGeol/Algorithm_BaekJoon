// 8진수 45를 2진수로 변환할려면 8진수 한자리는 2진수 3자리에 해당되므로
// EX) 4 5 = 100  101  가 됩니다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Str, Answer = "";
vector<string> Oct = { "000","001","010","011","100","101","110","111" };

int main() {
	cin >> Str;

	if (Str == "0") {
		cout << "0" << '\n';
		return 0;
	}

	for (int i = 0; i < Str.length(); ++i) {
		Answer += Oct[Str[i] - '0'];
	}

	int index = 0;
	for (int i = 0; i < Answer.length(); ++i) {
		if (Answer[i] == '1') {
			index = i;
			break;
		}
	}

	for (int i = index; i < Answer.length(); ++i) {
		cout << Answer[i];
	}
	cout << '\n';

	return 0;
}