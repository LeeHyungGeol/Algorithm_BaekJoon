// 파라메트릭 서치 문제
// 파라메트릭 서치 : 최적화 기법을 결정 문제로 바꾸어 해결하는 기법
// 최적화 문제 : 가장 인접한 두 공유기 사이의 '거리'를 '최대'로 하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int N, C;
vector<int> house;

int main() {
	cin >> N >> C;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		house.push_back(temp);
	}

	// 집을 차례대로 보기 위한 정렬 -> 이분 탐색을 수행할 수 있다.
	sort(house.begin(), house.end());

	// 한 집에는 공유기 하나만 설치할 수 있으므로
	// 가장 인접한 두 공유기 사이의 거리의 최솟값은 1 이다.

	/*거리의 최댓값은 맨 마지막 집에서 맨 처음 집을 뺀 거리이다.*/
	int start = 1, end = house[N - 1] - house[0], result = 0;

	while (start <= end) {
		/* 처음 집은 무조건 공유기를 설치했다고 가정한다. */
		int count = 1;

		int mid = (start + end) / 2;
	
		/* 처음 집의 위치의 집부터 계산한다. */
		int temp = house[0];

		for (int i = 1; i < N; ++i) {
			
			// house[i] - temp : 가장 인접한 두 공유기 사이의 거리
			if (mid  <= house[i] - temp) {
				++count;
				temp = house[i];
			}
		}

		// 공유기 C개를 설치해야 한다. 
		// 그런데, 설치 수가 작다는 것은 거리(mid)를 너무 크게 설정한 것이기 때문이다.
		// (왼쪽 부분 탐색)
		if (C > count) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}