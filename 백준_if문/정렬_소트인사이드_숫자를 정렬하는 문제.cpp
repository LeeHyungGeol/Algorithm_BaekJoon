#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int N;
	cin >> N;
	while (true) {
		if (N <= 0)
			break;
		v.push_back(N % 10);
		N = N / 10;
	}										  //greater<int>(): ù��° ���ڰ� �ι�° ���ں��� ũ�� true ��ȯ (bool)
	sort(v.begin(), v.end(), greater<int>()); //����_�������� ���� 
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
	}
	return 0;
}