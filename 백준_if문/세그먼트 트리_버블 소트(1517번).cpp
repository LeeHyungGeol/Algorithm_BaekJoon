//https://jason9319.tistory.com/153
//https://stonejjun.tistory.com/83 - Segment Tree 응용 (2) - Inversion counting , LIS, 3-elements.
//https://stackoverflow.com/questions/18758532/how-to-count-number-of-inversions-in-an-array-using-segment-trees

//수열을 pair<값,위치>로 입력받아서 오름차순 정렬하고, 앞에서부터 읽는다.
//이것은 원래의 수열에서 값이 작으면서 앞에 있는 숫자부터 보는 것이 된다.
//세그먼트 트리를 Root에서부터 Leaf까지 읽으면서 자신보다 큰 값을 카운팅해준다.
//그리고 자신의 위치가 포함되는 세그먼트 노드의 값을 업데이트해준다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int N;
vector<pll> arr;
vector<ll> inversionCount;

ll query(int L, int R, int node, int nodeL, int nodeR) {
	if (nodeR < L || R < nodeL) return 0;
	if (L <= nodeL && nodeR <= R) return inversionCount[node];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}
ll update(int index, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return inversionCount[node];
	if (nodeL == nodeR)  return ++inversionCount[node];
	int mid = (nodeL + nodeR) / 2;
	return inversionCount[node] = update(index, node * 2, nodeL, mid) + update(index, node * 2 + 1, mid + 1, nodeR);
}

int main() {
	ios_base::sync_with_stdio(false);//536ms->320ms
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr.resize(N);
	inversionCount.resize(4 * N, 0);

	ll tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		arr[i] = { tmp, i };
	}

	//sort(arr.begin(), arr.end(), greater<pll>());
	sort(arr.begin(), arr.end());

	ll answer=0;
	for (int i = 0; i < N; ++i) {
		int index = arr[i].second;
		//answer += query(0, index, 1, 0, N - 1);
		answer += query(index + 1, N - 1, 1, 0, N - 1);
		update(index, 1, 0, N - 1);
	}

	//cout << answer << '\n';
	return 0;
}
