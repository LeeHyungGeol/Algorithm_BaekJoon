//���׸�Ʈ Ʈ��(���� Ʈ��): ������ ���� ���� ����ϱ� 
//���� �� ����: ���������� ������ N���� ���� ���� ��, ""Ư�� ������ ��� ���� ���� ���� ���""�ϴ� ����
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MAX 1000001
int N, M, K;//N(1 �� N �� 1,000,000)�� M(1 �� M �� 10,000), K(1 �� K �� 10,000) 
vector<ll> rangeSum;
vector<ll> arr;

//node��尡 arr[left..right] �迭�� ǥ���� ��
//node�� ��Ʈ�� �ϴ� ����Ʈ���� �ʱ�ȭ �ϰ�, �� ������ ���� ��ȯ�ϴ�.
//��Ʈ ���� �迭�� 1�� ����
//��� i�� ���� �ڽ��� 2*i, ��� i�� ������ �ڽ��� 2*i+1
// node: ���׸�Ʈ Ʈ�� ��� ��ȣ
ll init(int node, int left, int right) {
	if (left == right) return rangeSum[node] = arr[left];
	int mid = (left + right) / 2;
	return rangeSum[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}
//node�� ���� ���� �ִ� ����� ��ȣ(�ε���)
//nodeL�� nodeR�� �� ��尡 �����ϴ� ����
//L�� R�� ���� �츮�� ���ϰ��� �ϴ� ����
//���� [L, R]�� query�� ���ϰ� ���� ���� �� ó���� query(L, R, 1, 0, N-1)�� ȣ��
ll query(int L, int R, int node, int nodeL, int nodeR) {
	// [nodeL, nodeR]�� [L, R]�� ���� �� ��ġ�� ���. �ٷ� 0�� ����, 0�� ������ �տ� �����ϱ� ������
	if (nodeR < L || R < nodeL) return 0;
	//[nodeL, nodeR]�� [L, R]�� ������ ���ԵǴ� ���. �ٷ� �ڽ��� ���� ����
	if (L <= nodeL && nodeR <= R) return rangeSum[node];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}
//index��° ���� val�� �����Ѵٸ�, �� ���� �󸶸�ŭ ���ߴ����� �˾ƾ� �Ѵ�. �� ���� diff��� �ϸ�, diff = val - a[index]�� ���� ���� �� �ֽ��ϴ�.
//1. [start,end]�� index�� ���ԵǴ� ���
//2. [start, end]�� index�� ���Ե��� �ʴ� ���
/*
void update(int index, ll diff, int node, int nodeL, int nodeR) {
	if (nodeR < index || index < nodeL) return;
	
	//node�� ������ ���ԵǴ� ��쿡�� diff��ŭ �������� ���� ������ �� �� �ִ�.
	rangeSum[node] += diff;

	//���� ��尡 �ƴ� ��쿡�� �ڽĵ� ��������� �ϱ� ������, 
	//start != end�� ���� ������� �˻縦 �ؾ� �մϴ�.
	if (nodeL != nodeR) {
		int mid = (nodeL + nodeR) / 2;
		update(index, diff, node * 2, nodeL, mid);
		update(index, diff, node * 2 + 1, mid + 1, nodeR);
	}
}
*/

// node: ���׸�Ʈ Ʈ�� ��� ��ȣ

//arr[index]=newValue�� �ٲ���� ��, 
//node�� ��Ʈ�� �ϴ� ���� Ʈ���� �����Ѵ�.
//���⼭�� ��尡 ǥ���ϴ� ������ ���� ��ȯ�Ѵ�.
ll update(int index, ll newValue, int node, int nodeL, int nodeR) {
	//index�� ��尡 ǥ���ϴ� ������ ������� ��쿡�� �����Ѵ�.
	if (nodeL > index || index > nodeR) return rangeSum[node];
	//Ʈ���� ���� ������ ������ ���
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

	//�迭�� ũ�⸦ �����ϰ� ���Ϸ���,
	//���� ����� 2�� �ŵ��������� n�� �ø��� ��, 2�� ���ؾ��Ѵ�.
	
	// 2^k >= N�� �ּ��� k�� ã�ƾ� ��.
	// �纯�� log�� ���ϸ�,
	// k >= logN / log2
	// (logN / log2)�� ���� �ø��� �� 1�� ���ϸ� k�� ��.
	// ������ ���� k�� �����ϸ� ���׸�Ʈ Ʈ���� size�� ���� �� ����.

//	int k = (int) Math.ceil(Math.log(N) / Math.log(2)) + 1;
//	int size = (int) Math.pow(2, k);
//		
//	tree = new long[size];


	//-> 4*n�� ��� ��쿡 �ʿ�� �ϴ� �迭�� ũ�⺸�� ũ��.
	rangeSum.resize(4 * N);

	//��Ʈ ���� �迭�� 1�� ����
	init(1, 0, N - 1);

	ll a, b, c;
	for (int i = 0; i < M + K; ++i) {
		cin >> a >> b >> c;
		if (a == 1) {
			//b--; // �ε����� ����
			//ll diff = (ll)(c - arr[b]);// ���̰� ����
			//arr[b] = c; // arr[b] �� ����
			//update(b, diff, 1, 0, N - 1);
			update(b-1, c, 1, 0, N - 1);
		}
		else if (a == 2) {
			cout << query(b - 1, c - 1, 1, 0, N - 1) << '\n';
		}
	}
	return 0;
}