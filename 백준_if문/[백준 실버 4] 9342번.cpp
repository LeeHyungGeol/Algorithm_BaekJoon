// 문자열(str.find(), str.rfind()), 단조증가(index의 위치로 판별하자)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
string Str;

bool isABCDEF(char c);

int main() {
	cin >> T;

	for (int i = 0; i < T; ++i) {	
		cin >> Str;

		if (!isABCDEF(Str[0]) || !isABCDEF(Str[(int)Str.length() - 1])) {
			cout << "Good" << '\n';
			continue;
		}

		bool flag = false;
		int firstA = Str.find('A');
		int firstF = Str.find('F');
		int firstC = Str.find('C');
		int lastA = Str.rfind('A');
		int lastF = Str.rfind('F');

		if (firstA < firstF && firstF < firstC && firstA < firstC) {
			if (lastA == firstF - 1 && lastF == firstC - 1) {
				flag = true;
			}
		}
		
		if (flag) {
			cout << "Infected!" << '\n';
		}
		else {
			cout << "Good" << '\n';
		}
	}

	return 0;
}

bool isABCDEF(char c) {
	return (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F');
}