//식의 값을 가능한 한 작게 만드는 문제
#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0, sum = 0;
	string str, tmp = "";
	cin >> str;

	for (int i = 0; i <= str.size(); ++i) { 
		if (str[i] == '-' || str[i] == '+' || str[i] == NULL) {
			//문자열에서 널문자의 역할은 주로 문자열의 끝을 나타내는 것이다.
			//문장마다 길이가 다르듯이 문자열을 표현할 때는 메모리 할당량도 일정하지 않고,
			//메모리에 저장될 때 해당 문자열의 끝이 어디인지 모르기 때문에 널문자가 필요한 것
			if (cnt == 1) //'-'
				sum -= stoi(tmp);
			else
				sum += stoi(tmp);
			if (str[i] == '-')
				cnt = 1;
			tmp = "";
			continue;
		}
		else 
			tmp += str[i];
	}
	cout << sum << '\n';

	return 0;
}
