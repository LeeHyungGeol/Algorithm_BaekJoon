// �׸���(Ž���), ���ڿ� ����

// �ݷʸ� �׻� �������!!
// Case1 : ....X
// Case2 : .

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Str, Answer;

int main() {
	cin >> Str;

	bool flag = false;
	string fourA = "AAAA", twoB = "BB";
	int cntX = 0, cntDot = 0;

	for (int i = 0; i < Str.length(); ++i) {
		if (Str[i] == 'X') {
			++cntX;
			if (cntX == 2) {
				if (Str[i + 1] == 'X') {
					continue;
				}
				else {
					Answer += twoB;
					cntX = 0;
				}
			}
			if (cntX == 4) {
				Answer += fourA;
				cntX = 0;
			}
		}
		else {
			if (cntX != 0) {
				flag = true;
				break;
			}
			Answer += '.';
		}
	}

	if (flag || cntX != 0) {
		cout << "-1" << '\n';
	}
	else {
		cout << Answer << '\n';
	}

	return 0;
}