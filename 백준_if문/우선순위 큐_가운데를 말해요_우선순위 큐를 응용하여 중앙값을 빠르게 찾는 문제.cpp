//우선순위 큐를 응용하여 중앙값을 빠르게 찾는 문제
#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>()> heapAscending;//중간 값 보다 큰 값들//오름차순
	priority_queue<int, vector<int>, less<int>()> heapDescending;//중간 값 보다 작은 값들//내림차순
	int N, x, mid = -10001;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		if (mid == -10001) {
			mid = x;
			cout << mid << '\n';
			continue;
		}
		if()
		else if (mid < x)
			heapAscending.push(x);
		else if (x < mid)
			heapDescending.push(x);


		cout << mid << '\n';
	}

	return 0;
}