//������ ������ Ư���ؼ� ���� ���α׷��ֺ��� ������ ���� ã�� �� �ִ� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<int> v;
	int x, N, K, result = 0;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<int>());//�������� ����
	for (int i = 0; i < N; ++i) {
		if (K / v[i] > 0) {
			result += K / v[i];
			K %= v[i];
		}
	}
	cout << result << '\n';
	return 0;
}