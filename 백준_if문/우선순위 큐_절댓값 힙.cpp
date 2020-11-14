//새로운 기준으로 뽑는 우선순위 큐를 만드는 문제
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<pair<int, char>> heap;
	int N, x;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		if (x == 0) {
			if (heap.empty())
				cout << "0" << '\n';
			else {
				if (heap.top().second == '+') {
					cout << -heap.top().first << '\n';
					heap.pop();
				}
				else {
					cout << heap.top().first << '\n';
					heap.pop();
				}
			}
		}
		else {
			if (x > 0)
				heap.push(make_pair(-x, '+'));
			else
				heap.push(make_pair(x, '-'));
		}
	}
	return 0;
}