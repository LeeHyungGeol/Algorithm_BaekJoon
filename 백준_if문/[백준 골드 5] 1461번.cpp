// 정렬 문제, 그리디 문제
// 각 책들의 위치를 양수, 음수로 나누어 배열에 입력 받은 후, 
// 가장 먼 책들(M개)를 제외하고, 차례로 책을 가져다 놓는다.

// 입력 받은 수가 전부 양수이거나 음수일 수 있다!!

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

int N, M;
deque<ll> dq;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		ll temp;
		cin >> temp;
		dq.push_back(temp);
	}

	sort(dq.begin(), dq.end());

	long long sum = 0;
	ll Max = max(dq.back(), abs(dq.front()));

	// 입력 받은 수가 전부 양수이거나 음수일 수 있다!!

	while (!dq.empty()) {
		if (dq.back() < 0) {
			break;
		}

		bool flag = false;
		sum += dq.back() * 2;
		
		// 조건문을 사용할 때는 항상 우선 조건문을 생각하자!!
		// 조건문은 조건문 비교를 순차적으로 수행한다.
		for (int i = 0; i < M; ++i) {
			if (dq.empty() || dq.back() < 0) {
				flag = true;
				break;
			}
			dq.pop_back();
		}

		if (flag) {
			break;
		}
	}

	while (!dq.empty()) {
		if (dq.front() > 0) {
			break;
		}

		bool flag = false;
		sum += abs(dq.front()) * 2;

		// 조건문을 사용할 때는 항상 우선 조건문을 생각하자!!
		// 조건문은 조건문 비교를 순차적으로 수행한다.
		for (int i = 0; i < M; ++i) {
			if (dq.empty() || dq.front() > 0) {
				flag = true;
				break;
			}
			dq.pop_front();
		}

		if (flag) {
			break;
		}
	}

	cout << sum - Max << '\n';

	return 0;
}