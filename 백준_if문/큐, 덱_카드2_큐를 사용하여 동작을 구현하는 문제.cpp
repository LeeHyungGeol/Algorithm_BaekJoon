//ť�� ����Ͽ� ������ �����ϴ� ����
#include <iostream>
#include <queue>
using namespace std;

int main() {

	queue<int> queue;
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		queue.push(i);
	}
	while (queue.size() > 1) {
		queue.pop();
		int n = queue.front();
		queue.pop();
		queue.push(n);
	}
	cout << queue.front() << '\n';
	return 0;
}