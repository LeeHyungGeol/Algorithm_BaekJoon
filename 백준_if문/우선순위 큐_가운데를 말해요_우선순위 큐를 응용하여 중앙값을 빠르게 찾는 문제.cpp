//우선순위 큐를 응용하여 중앙값을 빠르게 찾는 문제
//https://hsho.tistory.com/121
#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> heapAscending;//중간 값 보다 큰 값들//오름차순
	priority_queue<int, vector<int>, less<int>> heapDescending;//중간 값 보다 작은 값들//내림차순
	int N, x;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		if (heapDescending.size() == heapAscending.size())
			heapDescending.push(x);
		else
			heapAscending.push(x);
		if (!heapDescending.empty() && !heapAscending.empty() && heapDescending.top() > heapAscending.top()) {
			int d = heapDescending.top();
			int a = heapAscending.top();
			heapDescending.pop();
			heapAscending.pop();
			heapDescending.push(a);
			heapAscending.push(d);
		}
		
		cout << heapDescending.top() << '\n';
	}

	return 0;
}