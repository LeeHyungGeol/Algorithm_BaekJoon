// 이분탐색(파라메트릭 서치) 문제

// 문제의 조건을 잘 파악하는 것이 역시 중요하다.
// 입력의 범위가 상당히 크기 때문에 long long 타입으로 선언하고 시작하는 것이 좋다.
// start = 1 로 초기화 해야 하는 것도 잊지 말자!!

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll S, C, Sum;
vector<ll> Arr;

int main() {
	cin >> S >> C;

	for (int i = 0; i < S; ++i) {
		ll x;
		cin >> x;
		Arr.push_back(x);
		Sum += x;
	}

	ll start = 1, end = 1000000000, result = 0;

	while (start <= end) {
		ll mid = (start + end) / 2;

		ll total = 0;

		for (int i = 0; i < Arr.size(); ++i) {
			total += (Arr[i] / mid);
		}

		if (total < C) {
			end = mid - 1;
		}
		else {
			result = mid;			
			start = mid + 1;
		}
	}

	cout << Sum - (result * C) << '\n';

	return 0;
}