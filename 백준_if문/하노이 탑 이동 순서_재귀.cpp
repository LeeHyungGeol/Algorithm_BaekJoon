#include <iostream>
#include <cmath>
using namespace std;

void rHanoi(int n, int first, int second, int third);
int main() {

	int N;
	cin >> N;
	cout << (int)pow(2, N) - 1 << '\n'; //(1 << n), pow()�� �Ǽ������� ���
	rHanoi(N, 1, 2, 3);

	return 0;
}
void rHanoi(int n, int first, int second, int third) {
	
	if (n == 1)
		cout << first << " " << third << '\n';
	else {
		rHanoi(n - 1, first, third, second);
		cout << first << " " << third << '\n';
		rHanoi(n - 1, second, first, third);
	}
}
//1. 1������� n - 1���� 2��������� �̵�. 1����տ� ���� ū ���� �ϳ��� ����.
//2. 1������� ���� ū ������ 3��������� �̵�.
//3. 2������� n - 1���� ������ ��� 3��������� �̵�.