//큐의 개념이 응용된 문제
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M, x, cnt = 0, wantedPriority = 0, answer = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M;
		cnt = 0;
		answer = 0;
		wantedPriority = 0;
		queue<pair<int, int>> que;
		vector<int> v;
		int arr[101] = { 0 };
		for (int j = 0; j < N; ++j) {
			cin >> x;
			que.push(make_pair(j, x));// first: index, second: priority
			arr[j] = x;
			if (j == M) {
				wantedPriority = x; //wantedIndex == M
			}
		}
		for (int j = 0; j < N; ++j) {
			if (arr[j] > wantedPriority)
				v.push_back(arr[j]);
		}
		sort(v.begin(), v.end(), greater<int>());
		int j = 0;
		while (true) {
			if (j != v.size() && que.front().second == v[j]) { //우선 순위가 가장 큰 놈부터 pop() //j != v.size() - 이 조건은 무조건 맨 앞에 있어야 런타임 에러가 안난다.
				j++;
				answer++;
				que.pop();
			}
			else if (j != v.size() && que.front().second != v[j] && que.front().second > wantedPriority) {//우선 순위가 wantedPriority보다 크지만, 뒤에 더 큰 우선순위가 있는 경우, 맨 뒤로 보낸다.
				que.push(que.front());
				que.pop();
			}
			else if (que.front().second == wantedPriority) {
				if (j == v.size() && que.front().first == M) {//index가 같은지 확인
					answer++;
					cout << answer << '\n';
					break;
				}
				else if (j != v.size()) { //wantedPriority와 크기는 같지만 뒤에 더 큰 우선순위가 있는 경우, 맨 뒤로 보낸다.
					que.push(que.front());
					que.pop();
				}
				else {//wantedPriority와 크기가 같고, 뒤에 더 큰 우선순위를 가진 숫자도 없는 경우, 출력한다.
					answer++;
					que.pop();
				}
			}
			else if (que.front().second < wantedPriority) { //wantedPriority보다 크기가 작은 경우, 맨 뒤로 보낸다.
				que.push(que.front());
				que.pop();
			}
		}
	}

	return 0;
}
//38 29
//7 1 8 4 7 1 3 4 6 5 7 8 3 2 8 5 9 4 6 8 2 1 8 7 4 8 5 3 7 6 3 4 6 1 5 2 8 5