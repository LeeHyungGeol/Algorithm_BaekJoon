#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define mod 1000000007
int N, M, K;
vector<ll> rangeMUL;
vector<ll> arr;

//node��尡 arr[left..right] �迭�� ǥ���� ��
//node�� ��Ʈ�� �ϴ� ����Ʈ���� �ʱ�ȭ �ϰ�, �� ������ ���� ��ȯ�ϴ�.
//��Ʈ ���� �迭�� 1�� ����
//��� i�� ���� �ڽ��� 2*i, ��� i�� ������ �ڽ��� 2*i+1
// node: ���׸�Ʈ Ʈ�� ��� ��ȣ
ll init(int node, int left, int right) {
	if (left == right) return rangeMUL[node] = arr[left]%mod;
	int mid = (left + right) / 2;
	return rangeMUL[node] = (init(node * 2, left, mid) * init(node * 2+1, mid + 1, right))%mod;
}
// node: ���׸�Ʈ Ʈ�� ��� ��ȣ
//node�� ���� ���� �ִ� ����� ��ȣ(�ε���)
//nodeL�� nodeR�� �� ��尡 �����ϴ� ����
//L�� R�� ���� �츮�� ���ϰ��� �ϴ� ����
//���� [L, R]�� query�� ���ϰ� ���� ���� �� ó���� query(L, R, 1, 0, N-1)�� ȣ��
ll query(int L, int R, int node, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 1;
	if (L <= nodeL && nodeR <= R) return rangeMUL[node];
	int mid = (nodeL + nodeR) / 2;
	return (query(L, R, node * 2, nodeL, mid) * query(L, R, node * 2 + 1, mid + 1, nodeR))%mod;
} 
// node: ���׸�Ʈ Ʈ�� ��� ��ȣ
//arr[index]=newValue�� �ٲ���� ��, 
//node�� ��Ʈ�� �ϴ� ���� Ʈ���� �����Ѵ�.
//���⼭�� ��尡 ǥ���ϴ� ������ ���� ��ȯ�Ѵ�.
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