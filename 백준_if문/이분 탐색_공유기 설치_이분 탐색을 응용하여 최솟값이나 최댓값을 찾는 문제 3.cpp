//이분 탐색을 응용하여 최솟값이나 최댓값을 찾는 문제 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int C, N, x;
	cin >> N >> C;

	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int start = 1; //v[1] - v[0];
	int end = v.back();
	//int end = v[N - 1] - v[0]; //구하고자 하는 값은 최대"간격" -> "두 점 사이의 거리"이므로 '좌표 값 - 좌표 값'
	int result = 0;
	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;
		int value = v[0]; //첫번째 집에는 무조건 공유기 1대를 설치했다고 가정
		for (int i = 1; i < N; ++i) {
			if (v[i] >= mid + value) {
				value = v[i];
				cnt++;
			}
		}
		if (cnt < C - 1)//첫번째 집에 1대를 설치했다고 가정했기 때문에 전체 공유기 갯수에서 1을 빼준다.
			end = mid - 1;
		else { 
			start = mid + 1;
			result = mid; 
		}
	}
	cout << result << '\n';

	return 0;
}