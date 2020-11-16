//�̺� Ž���� �����Ͽ� �ּڰ��̳� �ִ��� ã�� ���� 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int C, N, x;
	cin >> N >> C;

	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int start = 1; //v[1] - v[0];
	int end = v.back();
	//int end = v[N - 1] - v[0]; //���ϰ��� �ϴ� ���� �ִ�"����" -> "�� �� ������ �Ÿ�"�̹Ƿ� '��ǥ �� - ��ǥ ��'
	int result = 0;
	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;
		int value = v[0]; //ù��° ������ ������ ������ 1�븦 ��ġ�ߴٰ� ����
		for (int i = 1; i < N; ++i) {
			if (v[i] >= mid + value) {
				value = v[i];
				cnt++;
			}
		}
		if (cnt < C - 1)//ù��° ���� 1�븦 ��ġ�ߴٰ� �����߱� ������ ��ü ������ �������� 1�� ���ش�.
			end = mid - 1;
		else { 
			start = mid + 1;
			result = mid; 
		}
	}
	cout << result << '\n';

	return 0;
}