#include <iostream>
using namespace std;

int main() {

	int n, y = 0, tmp = 0, result = 0;
	cin >> n;
	y = n / 5;
	while (y >= 0) {
		tmp = 0;
		tmp = n - (5 * y);
		if (tmp % 3 == 0) {
			cout << y + (tmp / 3) << '\n';
			return 0;
		}
		y--;
	}
	cout << "-1" << '\n';
	return 0;
}

//
//int solution(int& N) {
//
//	int y = N / 5; //5�� ���������� ��
//
//	while (y >= 0) {   //5�� ������������ ���� �ϳ��� �����ϸ鼭 ���
//		int tmp = N - (5 * y);   //tmp�� ��ü ���� 5*���� �� ��
//		if (tmp % 3 == 0) {    //tmp�� 3���� ���� �������� 0�� ���(0�� ���Ե�)
//			return y + (tmp / 3);   //5�� ���� + 3�� ����
//		}
//		y--;
//	}
//	return -1;
//}
//
//int main(void) {
//	int N;
//	int result;
//	cin >> N;
//
//	result = solution(N);
//
//	cout << result << '\n';
//	return 0;
//}
