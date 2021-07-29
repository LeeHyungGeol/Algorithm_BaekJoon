// 그리디(탐욕법)
// 현재 보고 있는 숫자와 바로 한칸 뒤에 나오는 숫자가 다를 때,
// 현재 보고 있는 숫자가 0인지 1인지를 구분하여 0의 연속인지 1의 연속인지 각각을 count하고
// 둘 중 작은 숫자를 정답으로 출력한다.

// 헷갈렸던 부분 : 맨마지막 문자의 경우 C++은 문자열 마지막에 'NULL문자'를 넣으므로, 
// 마지막 문자열의 연속(00.. 혹은 11..) 을 구분하여 count할 수 있다.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

int main() {
	cin >> str;

	int cnt0  = 0, cnt1 = 0;

	for (int i = 0; i < str.length(); ++i) {
		int after = str[i+1] - '0';
		int now = str[i] - '0';

		if (after != now) {
			if (now == 0) {
				++cnt0;
			}
			else {
				++cnt1;
			}
		}
	}

	cout << min(cnt0, cnt1) << '\n';

	return 0;
}