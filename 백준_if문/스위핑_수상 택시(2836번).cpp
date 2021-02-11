//스위핑 응용 문제: 이전의 선 긋기 문제(2170번)과 달리
//오른쪽 좌표보다 왼쪽 좌표가 작은 경우, 왼쪽 좌표와 오른쪽 좌표를 위치를 바꿔서 오름차순으로 정렬 후, 오른쪽에서 왼쪽으로 이동한 값을 2배하여, 전체의 길이에서 더해줘야 한다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
vector<pll> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	arr.resize(N);

	ll L, R;
	for (int i = 0; i < N; ++i) {
		cin >> L >> R;
		//오른쪽 보다 왼쪽이 더 큰 경우만 오른쪽과 왼쪽의 위치를 바꿔서 push_back
		if (L > R) arr[i] = { R,L };
	}

	//오름차순 정렬
	sort(arr.begin(), arr.end());

	ll result = 0;
	L = -1, R = -1;
	for (int i = 0; i < arr.size(); ++i) {	
		//새로운 구간에 대한 처리
		if (R < arr[i].first) {
			//오른쪽에서 왼쪽으로 back하는 경우, back한 만큼 다시 앞으로 가야하기 때문에 2배를 해준다.
			result +=2* (R - L);
			L = arr[i].first;
			R = arr[i].second;
		}
		//겹치는 구간에 대한 처리
		else R = max(R, arr[i].second);
	}
	//마지막 구간에 대한 처리
	result += 2 * (R - L);
	cout << M+result << '\n';
	return 0;
}