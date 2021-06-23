// 기본 구현 문제
// 문자열을 입력 받아서, 정렬한 후 숫자만을 따로 처리하는 문제
// 숫자와 문자가 같이 있을 때 정렬하면, 숫자가 앞쪽에 위치하게 된다.

// isalnum(문자): 영문자 또는 숫자인 경우만 참을 리턴 
// isalpha(문자) : 문자가 영문자인 경우만 참을 리턴
// isdigit(문자) : 문자가 숫자인 경우만 참을 리턴
// islower(문자) : 문자가 영어 소문자인 경우만 참을 리턴
// isupper(문자) : 문자가 영어 대문자인 경우만 참을 리턴

// 각각의 함수에 들어가는 매개변수의 타입은 'char (문자)' 이다.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int number;

int main() {
	cin >> str;

	sort(str.begin(), str.end());

	auto it = str.begin();

	while (isdigit(*it)) {
		number += *it - '0';
		str.erase(it);
	}

	str += to_string(number);

	cout << str << '\n';

	return 0;
}