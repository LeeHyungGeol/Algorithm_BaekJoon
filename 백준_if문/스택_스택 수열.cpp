// 스택을 활용하는 문제 1
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int arr[100001] = { 0 };
int main() {

	queue<char> queue;
	stack<int> stack;
	int N, i = 1, j = 1;
	cin >> N;
	for (int i = 1; i <= N; ++i) { //4 3 6 8 7 5 2 1
		cin >> arr[i];
	}
	while (true) {
		if (j > N)
			break;
		int num = arr[j];
		while (i <= num) {
			stack.push(i);
			queue.push('+');
			i++;
		}
		if (stack.top() == arr[j]) {
			stack.pop();
			queue.push('-');
			j++;
		}
		else {
			cout << "NO" << '\n';
			return 0;
		}
	}
	while (!queue.empty()) {
		cout << queue.front() << '\n';
		queue.pop();
	}

	return 0;
}