#include <iostream>
using namespace std;

//void swap(int *n);
//int main() {
//
//	int a, b;
//	cin >> a >> b;
//	swap(&a);
//	swap(&b);
//	if (a > b)
//		cout << a << "\n";
//	else
//		cout << b << '\n';
//	return 0;
//}
//void swap(int *n) {
//	
//	int a = 0, b = 0, c = 0, num = *n;
//	c = *n % 10; //1�� �ڸ�
//	b = (*n / 10) % 10; //10�� �ڸ�
//	a = *n / 100; //100�� �ڸ�
//	*n = (c * 100) + (b * 10) + (a);
//}
int main() {

	string str1, str2, bigger;
	cin >> str1 >> str2;

	for (int i = 2; i >= 0; i--) {
		if (str1[i] > str2[i]) {
			bigger = str1;
			break;
		}
		else if (str2[i] > str1[i]) {
			bigger = str2;
			break;
		}
	}
	cout << bigger[2] << bigger[1] << bigger[0] << '\n';

	return 0;
}