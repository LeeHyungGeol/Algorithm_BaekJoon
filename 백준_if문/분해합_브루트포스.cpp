#include <iostream>
#include <vector>
using namespace std;

int decomposition(int n);//������ ���ϴ� �Լ�
int main() {

	int N, result = 0;
	cin >> N;
	for (int M = 1; M <= N; ++M) {
		result = decomposition(M);
		if (result == N) {
			cout << M << '\n';//���� N�� �����ڰ� M�̴�.
			return 0;
		}
	}
	cout << "0" << '\n';
	return 0;
}
int decomposition(int n) {
	int tmp = n, sum = 0;
	vector<int> v; //�ڸ������� �����ϱ� ���� ����

	while (true) {
		if (tmp == 0)
			break;
		v.push_back(tmp % 10);
		tmp = tmp / 10;
	}
	for (int i = 0; i < v.size(); ++i) {
		sum += v[i];
	}
	return n + sum;
}