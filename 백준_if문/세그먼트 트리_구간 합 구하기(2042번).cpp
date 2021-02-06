//세그먼트 트리(구간 트리): 구간에 대한 질문 대답하기 
//구간 합 문제: 연속적으로 나열된 N개의 수가 있을 때, ""특정 구간의 모든 수를 합한 값을 계산""하는 문제
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MAX 1000001
int N, M, K;//N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 
vector<ll> rangeSum;
vector<ll> arr;

//node노드가 arr[left..right] 배열을 표현할 때
//node를 루트로 하는 서브트리를 초기화 하고, 이 구간의 합을 반환하다.
//루트 노드는 배열의 1번 원소
//노드 i의 왼쪽 자식은 2*i, 노드 i의 오른쪽 자식은 2*i+1
// node: 세그먼트 트리 노드 번호
ll init(int node, int left, int right) {
	if (left == right) return rangeSum[node] = arr[left];
	int mid = (left + right) / 2;
	return rangeSum[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}
//node은 현재 보고 있는 노드의 번호(인덱스)
//nodeL과 nodeR은 그 노드가 포함하는 구간
//L과 R이 본래 우리가 구하고자 하는 구간
//구간 [L, R]의 query을 구하고 싶을 때는 맨 처음에 query(L, R, 1, 0, N-1)을 호출
ll query(int L, int R, int node, int nodeL, int nodeR) {
	// [nodeL, nodeR]과 [L, R]이 전혀 안 겹치는 경우. 바로 0을 리턴, 0은 구간의 합에 무관하기 때문에
	if (nodeR < L || R < nodeL) return 0;
	//[nodeL, nodeR]이 [L, R]에 완전히 포함되는 경우. 바로 자신의 값을 리턴
	if (L <= nodeL && nodeR <= R) return rangeSum[node];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}
//index번째 수를 val로 변경한다면, 그 수가 얼마만큼 변했는지를 알아야 한다. 이 수를 diff라고 하면, diff = val - a[index]로 쉽게 구할 수 있습니다.
//1. [start,end]에 index가 포함되는 경우
//2. [start, end]에 index가 포함되지 않는 경우
/*
void update(int index, ll diff, int node, int nodeL, int nodeR) {
	if (nodeR < index || index < nodeL) return;
	
	//node의 구간에 포함되는 경우에는 diff만큼 증가시켜 합을 변경해 줄 수 있다.
	rangeSum[node] += diff;

	//리프 노드가 아닌 경우에는 자식도 변경해줘야 하기 때문에, 
	//start != end로 리프 노드인지 검사를 해야 합니다.
	if (nodeL != nodeR) {
		int mid = (nodeL + nodeR) / 2;
		update(index, diff, node * 2, nodeL, mid);
		update(index, diff, node * 2 + 1, mid + 1, nodeR);
	}
}
*/

// node: 세그먼트 트리 노드 번호

//arr[index]=newValue로 바뀌었을 때, 
//node를 루트로 하는 구간 트리를 갱신한다.
//여기서는 노드가 표현하는 구간의 곱을 반환한다.
ll update(int index, ll newValue, int node, int nodeL, int nodeR) {
	//index가 노드가 표현하는 구간과 상관없는 경우에는 무시한다.
	if (nodeL > index || index > nodeR) return rangeSum[node];
	//트리의 리프 노드까지 내려온 경우
	if (nodeL == nodeR) return rangeSum[node] = newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeSum[node] = update(index, newValue, node * 2, nodeL, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeR);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	arr.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	//배열의 크기를 안전하게 구하려면,
	//가장 가까운 2의 거듭제곱으로 n을 올림한 뒤, 2를 곱해야한다.
	
	// 2^k >= N인 최소의 k를 찾아야 함.
	// 양변에 log을 취하면,
	// k >= logN / log2
	// (logN / log2)의 값을 올림한 후 1을 더하면 k가 됨.
	// 위에서 구한 k를 제곱하면 세그먼트 트리의 size를 구할 수 있음.

//	int k = (int) Math.ceil(Math.log(N) / Math.log(2)) + 1;
//	int size = (int) Math.pow(2, k);
//		
//	tree = new long[size];


	//-> 4*n은 모든 경우에 필요로 하는 배열의 크기보다 크다.
	rangeSum.resize(4 * N);

	//루트 노드는 배열의 1번 원소
	init(1, 0, N - 1);

	ll a, b, c;
	for (int i = 0; i < M + K; ++i) {
		cin >> a >> b >> c;
		if (a == 1) {
			//b--; // 인덱스로 맞춤
			//ll diff = (ll)(c - arr[b]);// 차이값 저장
			//arr[b] = c; // arr[b] 값 변경
			//update(b, diff, 1, 0, N - 1);
			update(b-1, c, 1, 0, N - 1);
		}
		else if (a == 2) {
			cout << query(b - 1, c - 1, 1, 0, N - 1) << '\n';
		}
	}
	return 0;
}