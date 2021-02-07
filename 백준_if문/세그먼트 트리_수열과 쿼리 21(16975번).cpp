//https://kangwlgns.tistory.com/8
//https://kyu9341.github.io/algorithm/2020/04/06/algorithm16975/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int N, M;
vector<ll> arr;
vector<ll> rangeSum;

void init(int node, int left, int right) {
	// 세그먼트 트리 생성 리프 노드를 제외한 나머지 노드는 0으로 초기화
	if (left == right) { rangeSum[node] = arr[left]; return; }
	rangeSum[node] = 0;
	int mid = (left + right) / 2;
	init(node * 2, left, mid);
	init(node * 2 + 1, mid + 1, right);
}
//ll query(int index, int node, int nodeL, int nodeR, ll answer) {
//	// index에 맞는 리프 노드까지 이동하며 거치는 노드의 값을 모두 누적한다.
//	if (index < nodeL || nodeR < index) return 0;
//	answer += rangeSum[node];
//	// 리프 노드에 도달하면 누적된 값 리턴
//	if (nodeL==nodeR) return answer;
//	int mid = (nodeL + nodeR) / 2;
//	return query(index, node * 2, nodeL, mid,answer) + query(index, node * 2 + 1, mid + 1, nodeR,answer);
//}
ll query(int index, int node, int nodeL, int nodeR, ll answer) {
	// index에 맞는 리프 노드까지 이동하며 거치는 노드의 값을 모두 누적한다.
	if (index < nodeL || nodeR < index) return 0;
	// 리프 노드에 도달하면 누적된 값 리턴
	if (nodeL == nodeR) return rangeSum[node];
	int mid = (nodeL + nodeR) / 2;
	return rangeSum[node] + query(index, node * 2, nodeL, mid, answer) + query(index, node * 2 + 1, mid + 1, nodeR, answer);
}
void update(int L, int R, ll newValue, int node, int nodeL, int nodeR) {
	// 각 노드에 더해질 newValue값들을 모두 누적하여 쿼리 수행 시 거쳐가는 모든 노드의 값을 더할 수 있도록 구성.
	// 범위를 벗어난 경우 리턴
	if (R < nodeL || nodeR < L) return;
	// 완전히 범위 내에 들어온 경우 현재 노드에 newValue를 누적
	if (L <= nodeL && nodeR <= R) { rangeSum[node] += newValue; return; }
	int mid = (nodeL + nodeR) / 2;
	update(L, R, newValue, node * 2, nodeL, mid);
	update(L, R, newValue, node * 2 + 1, mid + 1, nodeR);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr.resize(N);
	rangeSum.resize(4 * N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	cin >> M;

	init(1, 0, N - 1);
	
	ll Q, a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> Q;
		if (Q==1) {
			cin >> a >> b >> c;
			update(a - 1, b - 1, c, 1, 0, N - 1);
		}
		else {
			cin >> a;
			cout << query(a-1,1,0,N-1,0) << '\n';
		}
	}

	return 0;
}