//���׸�Ʈ Ʈ��(���� Ʈ��): ������ ���� ���� ����ϱ� 
//���� �� ����: ���������� ������ N���� ���� ���� ��, ""Ư�� ������ ��� ���� ���� ���� ���""�ϴ� ����

//N���� ������ ������ ������ �ִ�.
//M���� ����(Query) ������ �־�����.
//	-�� ������ Left�� Right���� �����ȴ�.
//	-�� ������ ���Ͽ� [Left, Right]������ ���Ե� �����͵��� ���� ����ؾ� �Ѵ�.
//���� �ð� ������ O(N + M)�̴�.

//���λ� ��(Prefix Sum): �迭�� �� �պ��� Ư�� ��ġ������ ���� �̸� ���� ���� ��

//���λ� ��(Prefix Sum)�� Ȱ���� �˰���
//	- N���� �� ��ġ ������ ���Ͽ� ���λ� ���� ����Ͽ� P(�迭)�� �����Ѵ�.
//	- �� M���� ���� ������ Ȯ���� �� ���� ���� P[Rigjt] - P[Left - 1]�̴�.

#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
int N, M;
int PrefixSum[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int tmp,sum=0;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		sum += tmp;
		PrefixSum[i + 1] = sum;
	}

	int right, left;
	for (int i = 0; i < M; ++i) {
		cin >> left >> right;
		cout << PrefixSum[right] - PrefixSum[left - 1] << '\n';
	}
	return 0;
}