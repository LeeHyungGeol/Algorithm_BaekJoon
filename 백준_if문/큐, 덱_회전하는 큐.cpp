//덱을 활용하여 큐를 회전시키는 문제
#include <iostream>
#include <deque>
using namespace std;

int main() {

	int N, M, x, cnt1 = 0, cnt2 = 0, answer = 0;
	cin >> N >> M;
	deque<pair<int, int>> dq;
	//int arr[51] = { 0 };
	
	for (int i = 1; i <= N; ++i) {
		dq.push_back(make_pair(i, i)); // i: index, x: num
	}
	for (int i = 1; i <= M; ++i) {
		cin >> x;
		while (true) {
			cnt1 = 0;
			cnt2 = 0;
			for (int i = 0; i < dq.size(); ++i) { //left
				if (dq[i].first == x) {
					//cnt1++;
					break;
				}
				else
					cnt1++;
			}
			for (int i = dq.size() - 1; i >= 0; --i) {//right
				if (dq[i].first == x) {
					cnt2++;
					break;
				}
				else
					cnt2++;
			}
			if (cnt1 < cnt2) {
				while (true) {
					if (cnt1 == 0)
						break;
					dq.push_back(dq.front()); //answer++;
					dq.pop_front();
					cnt1--;
					answer++;
				}
				if (dq.front().first == x) {
					dq.pop_front();
					break;
				}
			}
			else {
				while (true) {
					if (cnt2 == 0)
						break;
					dq.push_front(dq.back()); //answer++;
					dq.pop_back();
					cnt2--;
					answer++;
				}
				if (dq.front().first == x) {
					dq.pop_front();
					break;
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}