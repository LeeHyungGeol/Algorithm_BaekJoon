//스위핑 알고리즘(Sweeping Algorithm): 수평선의 왼쪽 끝에서부터 훑다가 마주치는 선분이 있으면 뭔가 처리를 해주는 방식

//-> 선분을 왼쪽 끝 좌표 순으로 정렬하여 순회하면 된다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000001
typedef long long ll;
typedef pair<ll, ll> pll;

int N; //선을 그은 횟수 N(1 ≤ N ≤ 1,000,000)
vector<pll> arr;

int main() {
	ios_base::sync_with_stdio(false);//시간 초과->387ms
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr.resize(N);

	//선을 그을 때 선택한 두 점의 위치 x, y(-1,000,000,000 ≤ x < y ≤ 1,000,000,000)
	ll L, R, result = 0;
	for (int i = 0; i < N; ++i) {
		cin >> L >> R;
		arr[i] = { L,R };
	}

	//선분들을 왼쪽 끝 좌표 순으로 정렬
	sort(arr.begin(), arr.end());

	//왼쪽 점과 오른쪽 점에 대한 초기값을 최소값인 -1e9보다 하나 더 작은 값으로 초기화
	L = -MAX, R = -MAX;
	for (int i = 0; i < N; ++i) {
		//새로운 구간에 대한 처리
		if (R < arr[i].first) {
			//현재 구간에 대한 값을 결과값에 더해준다.
			result += R - L;
			//새로운 구간으로 설정
			L = arr[i].first;
			R = arr[i].second;
		}
		//겹치는 구간에 대한 처리
		else R = max(R, arr[i].second);
	}
	//마지막 구간에 대한 값도 결과값에 더해준다.
	result += R - L;
	cout << result << '\n';

	return 0;
}