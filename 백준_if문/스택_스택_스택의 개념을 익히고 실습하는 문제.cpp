//스택의 개념을 익히고 실습하는 문제

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> stack;
	string str;
	int x, i = 0, N;
	cin >> N;
	while (i < N) {
		cin >> str;
		if (str == "push") {
			cin >> x;
			stack.push(x);
		}
		else if (str == "pop") {
			if (stack.empty()) {
				cout << "-1" << '\n';
				i++;
				continue;
			}
			cout << stack.top() << '\n';
			stack.pop();

		}
		else if (str == "size") {
			cout << stack.size() << '\n';
		}
		else if (str == "empty") {
			if (stack.empty())
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (str == "top") {
			if (stack.empty())
				cout << "-1" << '\n';
			else
				cout << stack.top() << '\n';
		}
		i++;
	}
	return 0;
}