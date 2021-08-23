// 문자열(문자열 뒤집기 : reverse(), 문자열 한 문장 입력받기 : getline(cin, str))

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

int main() {
	while (getline(cin, str)) {
		if (str == "END") {
			break;
		}
		
		reverse(str.begin(), str.end());

		cout << str << '\n';
	}

	return 0;
}
