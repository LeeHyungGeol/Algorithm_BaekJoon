//https://blog.naver.com/PostView.nhn?blogId=adamdoha&logNo=222136922767&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
//https://jh280722.tistory.com/6
//���� Ǯ�� : ���� �ּҸ� ���Ͽ���.������ Ʋ�ȴ�..
//�������� Ǯ�� : kth ���׸�Ʈ Ʈ���� Ǯ�� O(NlogX)�̴�.
//
//Query 1. ������ ���� 200�������� Segment Tree �����
//����1�� ������ �Է� ������ ���׸�Ʈ Ʈ���� ����,

//Query 2. num ��° ���� ã��
//K��° ��尡 �� K�� ��Ÿ���� ������ ��Ÿ�� �� �ִ�.
//�� ����� ���� �� ���� ������ �Է��ϰ� ���׸�Ʈ Ʈ���� �������� ���� ����
//K ��° ���� �ᱹ ���ʿ� K���� ������ �� ��尡 K��° ���̹Ƿ� ��ġ�� ���� ���� �� �ִ�.
//K�� ���� ����� ������ Ŭ ���, K - ���� ����� ������ �ٽ� K�� �Ͽ� ������ ��忡�� ã�´�.
//
//���� ����
//Query 1������ �ش� ���ڿ� ���� + 1�� �������� �����ϴ� ������ �ݴ�� �ϸ� �˴ϴ�.
//num��° ���ڿ� �ش��ϴ� ���� �����ϴ� ������ - 1�� ���׸�Ʈ Ʈ�� ������Ʈ�� ���ָ� �˴ϴ�.
#include <iostream>
#include <vector>
using namespace std;
#define MAX 2000001
int N;
vector<int> rangeSum;

int update(int index, int newValue, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return rangeSum[node];
	if (nodeL == nodeR) return rangeSum[node] += newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeSum[node] = update(index, newValue, node * 2, nodeL, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeR);
}
int query(int index, int node, int nodeL, int nodeR) {
	if (nodeL == nodeR) return nodeL;
	int mid = (nodeL + nodeR) / 2;
	if (index <= rangeSum[node * 2]) return query(index, node * 2, nodeL, mid);
	else return query(index - rangeSum[node * 2], node * 2 + 1, mid + 1, nodeR);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	rangeSum.resize(4 * MAX);

	int T, X;
	for (int i = 0; i < N; ++i) {
		cin >> T >> X;
		if (T == 1) {
			update(X, 1, 1, 1, MAX);
		}
		else {
			int pos = query(X, 1, 1, MAX);
			update(pos, -1, 1, 1, MAX);
			cout << pos << '\n';
		}
	}
}