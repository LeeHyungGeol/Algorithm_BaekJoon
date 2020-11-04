//ť�� ������ ����� ����
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
			if (j != v.size() && que.front().second == v[j]) { //�켱 ������ ���� ū ����� pop() //j != v.size() - �� ������ ������ �� �տ� �־�� ��Ÿ�� ������ �ȳ���.
				j++;
				answer++;
				que.pop();
			}
			else if (j != v.size() && que.front().second != v[j] && que.front().second > wantedPriority) {//�켱 ������ wantedPriority���� ũ����, �ڿ� �� ū �켱������ �ִ� ���, �� �ڷ� ������.
				que.push(que.front());
				que.pop();
			}
			else if (que.front().second == wantedPriority) {
				if (j == v.size() && que.front().first == M) {//index�� ������ Ȯ��
					answer++;
					cout << answer << '\n';
					break;
				}
				else if (j != v.size()) { //wantedPriority�� ũ��� ������ �ڿ� �� ū �켱������ �ִ� ���, �� �ڷ� ������.
					que.push(que.front());
					que.pop();
				}
				else {//wantedPriority�� ũ�Ⱑ ����, �ڿ� �� ū �켱������ ���� ���ڵ� ���� ���, ����Ѵ�.
					answer++;
					que.pop();
				}
			}
			else if (que.front().second < wantedPriority) { //wantedPriority���� ũ�Ⱑ ���� ���, �� �ڷ� ������.
				que.push(que.front());
				que.pop();
			}
		}
	}

	return 0;
}
//38 29
//7 1 8 4 7 1 3 4 6 5 7 8 3 2 8 5 9 4 6 8 2 1 8 7 4 8 5 3 7 6 3 4 6 1 5 2 8 5