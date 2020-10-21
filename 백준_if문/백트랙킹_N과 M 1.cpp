#include <iostream>
using namespace std;

int N, M; //(1 �� M �� N �� 8)
int answer[8 + 1]; //�ε����� 0���� �����ϹǷ� 1�� �ϳ� ���Ѵ�
bool isUsed[8 + 1];
void backTracking(int x);

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	backTracking(1); //���� 1���� ��Ʈ��ŷ ����

	return 0;
}
void backTracking(int x) { //���� x�� ����  ��Ʈ��ŷ ����
	if (x == M + 1) {//answer�迭 index�� 0���� ������� �ʰ� 1���� ����߱� ������ +1�� ���ش�.
		for (int i = 1; i <= M; ++i) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) { //1���� N���� ����ߴ��� ���ߴ��� ��ͷ� üũ�ϸ鼭 answer�迭�� ����� ���ڸ� ����
		if (!isUsed[i]) {//���ڰ� ������ �ʾ��� �� if�� ��� //���ڰ� ���Ǿ��ٸ� �ٸ� ���ڸ� ����ؾ� �ϱ� ������
			answer[x] = i;
			isUsed[i] = true; //���� i�� ���Ǿ���.
			backTracking(x + 1);
			isUsed[i] = false; //base case���� ����ϰ� ��͸� �������Ա� ������ ����� ���� i�� �ݳ��Ѵ�.
		}
	}
}