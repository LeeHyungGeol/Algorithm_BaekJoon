#include <iostream>
using namespace std;
/*
ī��������(Counting Sort) - ���� ���ؼ� �����ϴ� ����̶�� ���ٴ� ���� ������ ���� �� ������ ���� ��ġ�� �������ִ� ���
��, �����͵鰣�� ũ�⸦ ���ϰų� �׷� ���� ����� �ƴϴ�.
https://hongku.tistory.com/155
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, n, count[10001] = { 0 };
	cin >> N;
	
	for (int i = 1; i <= N; ++i) {
		cin >> n;
		count[n]++;
	}

	for (int i = 1; i <= 10000; ++i) {//�Է� ���� ��(���⼭�� n)�� �ִ���ڷ� ����.
		if (count[i] != 0) {
			for (int j = 1; j <= count[i]; ++j) {
				cout << i;
				cout << '\n';
			}
		}
	}

	return 0;
}