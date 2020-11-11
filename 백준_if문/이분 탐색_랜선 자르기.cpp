//���� parametric search��� �θ���, �̺� Ž���� �����Ͽ� �ּڰ��̳� �ִ��� ã�� ��ũ���� ���� ����
//�Ķ��Ʈ�� ��ġ(parametric search) : ����ȭ ������ ���� ������ �ٲپ� �ذ��ϴ� ���
//���� ����: '��' Ȥ�� '�ƴϿ�'�� ���ϴ� ����
//'���ϴ� ������ �����ϴ� ���� �˸��� ���� ã�� ����'�� �Ķ��Ʈ�� ��ġ(parametric search)�� ����Ѵ�.
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int K, N, x;
	cin >> K >> N;
	vector<int> v;
	for (int i = 0; i < K; ++i) {
		cin >> x;
		v.push_back(x);
	}
	long long int start = 0, end = 2147483647;//2^31-1
	long long int mid = 0, cnt = 0, result = 0;

	while (start <= end) {
		cnt = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < K; ++i) {
			cnt += (v[i] / mid);
		}
		if (cnt < N)
			end = mid - 1;
		else {
			result = mid;
			start = mid + 1;
		}
	}
	cout << result << '\n';
	return 0;
}