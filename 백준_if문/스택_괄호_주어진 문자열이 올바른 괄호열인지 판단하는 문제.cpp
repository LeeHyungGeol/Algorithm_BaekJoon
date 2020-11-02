//주어진 문자열이 올바른 괄호열인지 판단하는 문제
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	string str;
	int T, cnt = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> str;
		stack<char> stack;
		cnt = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				stack.push(str[j]);
				cnt++;
			}
			else {
				if (stack.empty()) {
					cout << "NO" << '\n';
					cnt = -100;//하나의 괄호 문자열의 길이는 2 이상 50 이하이므로 
					break;
				}
				stack.pop();
				cnt--;
			}
		}
		if (cnt == -100) { //위의 조건문에서 break로 for문을 빠져나올 경우, 
			continue;      //NO 혹은 YES가 출력 될 것을 방지하기 위해 -100(cnt가 절대로 될 수 없는 값)으로 설정  
		}
		else if (cnt != 0)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}

	return 0;
}