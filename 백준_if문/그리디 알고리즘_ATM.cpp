//��ٸ��� �ð��� ���� �ּ�ȭ�ϴ� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<int> v;
	int N, x, sum = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			sum += v[j];
			//sum += v[i]*(N-i); //�̷��� ���ָ� 1���� �迭 ��� ����
		}
	}
	cout << sum << '\n';
	return 0;
}