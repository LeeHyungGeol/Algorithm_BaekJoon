#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define mod 1000000007
int N, M, K;
vector<ll> rangeMUL;
vector<ll> arr;

//node노드가 arr[left..right] 배열을 표현할 때
//node를 루트로 하는 서브트리를 초기화 하고, 이 구간의 곱을 반환하다.
//루트 노드는 배열의 1번 원소
//노드 i의 왼쪽 자식은 2*i, 노드 i의 오른쪽 자식은 2*i+1
// node: 세그먼트 트리 노드 번호
ll init(int node, int left, int right) {
	if (left == right) return rangeMUL[node] = arr[left]%mod;
	int mid = (left + right) / 2;
	return rangeMUL[node] = (init(node * 2, left, mid) * init(node * 2+1, mid + 1, right))%mod;
}
// node: 세그먼트 트리 노드 번호
//node는 현재 보고 있는 노드의 번호(인덱스)
//nodeL과 nodeR은 그 노드가 포함하는 구간
//L과 R이 본래 우리가 구하고자 하는 구간
//구간 [L, R]의 query을 구하고 싶을 때는 맨 처음에 query(L, R, 1, 0, N-1)을 호출
ll query(int L, int R, int node, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 1;
	if (L <= nodeL && nodeR <= R) return rangeMUL[node];
	int mid = (nodeL + nodeR) / 2;
	return (query(L, R, node * 2, nodeL, mid) * query(L, R, node * 2 + 1, mid + 1, nodeR))%mod;
} 
// node: 세그먼트 트리 노드 번호
//arr[index]=newValue로 바뀌었을 때, 
//node를 루트로 하는 구간 트리를 갱신한다.
//여기서는 노드가 표현하는 구간의 곱을 반환한다.
ll update(int index, ll newValue, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return rangeMUL[node];
	if (nodeL == nodeR) return rangeMUL[node] = newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeMUL[node] = (update(index, newValue, node * 2, nodeL, mid) * update(index, newValue, node * 2 + 1, mid + 1, nodeR))%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	arr.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	rangeMUL.resize(4 * N);

	init(1, 0, N - 1);

	ll a, b, c;
	for (int i = 0; i < M + K; ++i) {
		cin >> a >> b >> c;
		if (a == 1) 
			update(b-1,c,1,0,N-1);
		
		else if (a == 2)
			cout << query(b-1,c-1,1,0,N-1) << '\n';
	}

	return 0;
}