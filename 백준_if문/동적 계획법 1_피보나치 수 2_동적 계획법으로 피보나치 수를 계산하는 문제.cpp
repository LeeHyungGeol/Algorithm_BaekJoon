#include <iostream>
using namespace std;
//��κ��� ���� �Ϲ� �������� 32bit�̱� ������ 2�� ������ ǥ������ ���Ѵ�. 64bit �������� ����� �ǵ�
//���� ũ�Ⱑ int������ �ѱ� ������ long long���� �ٲ�� �Ѵ�. 
//Dynamic Programming(���� ��ȹ��) �ذῡ �޸������̼ǰ� �ݺ����� ����ϴ� ��� ���� �� �˾Ƶ���.
int main() {

	int N;
	cin >> N;
	long long int arr[91];
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= N; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[N] << '\n';
	return 0;
}
