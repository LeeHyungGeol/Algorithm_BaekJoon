// 이분 탐색(파라메트릭 서치) 문제

// 0분에는 M만큼의 사람이 탄다.
// A 놀이기구가 mid 분까지 몇 명을 태우는가? : mid / (A의 운행시간)
// K분에 몇 개의 놀이기구가 운행 가능한가? : K % Times[i](각각의 놀이기구의 운행시간) == 0 일 때마다 카운트

// https://suhwanc.tistory.com/45
// http://melonicedlatte.com/algorithm/2018/08/09/115053.html

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll N, M, Answer, TotalTime;
vector<ll> Times;

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int time;
		cin >> time;
		Times.push_back(time);
	}

	if (N <= M) {
		cout << N << '\n';
		return 0;
	}

	ll start = 0, end = 60000000000;

	while (start <= end) {
		ll mid = (start + end) / 2;
		ll totalChildren = M;

		for (int i = 0; i < Times.size(); ++i) {
			totalChildren += mid / Times[i];
		}

		if (totalChildren < N) {
			start = mid + 1;
		}
		else {
			TotalTime = mid;
			end = mid - 1;
		}
	}

	ll children = M;

	for (int i = 0; i < Times.size(); ++i) {
		children += (TotalTime - 1) / Times[i];
	}

	for (int i = 0; i < Times.size(); ++i) {
		if (TotalTime % Times[i] == 0) {
			++children;
		}
		if (children == N) {
			cout << i + 1 << '\n';
			break;
		}
	}

	return 0;
}
