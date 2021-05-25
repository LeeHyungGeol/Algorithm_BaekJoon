// �Ķ��Ʈ�� ��ġ ����
// �Ķ��Ʈ�� ��ġ : ����ȭ ����� ���� ������ �ٲپ� �ذ��ϴ� ���
// ����ȭ ���� : ���� ������ �� ������ ������ '�Ÿ�'�� '�ִ�'�� �ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int N, C;
vector<int> house;

int main() {
	cin >> N >> C;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		house.push_back(temp);
	}

	// ���� ���ʴ�� ���� ���� ���� -> �̺� Ž���� ������ �� �ִ�.
	sort(house.begin(), house.end());

	// �� ������ ������ �ϳ��� ��ġ�� �� �����Ƿ�
	// ���� ������ �� ������ ������ �Ÿ��� �ּڰ��� 1 �̴�.

	/*�Ÿ��� �ִ��� �� ������ ������ �� ó�� ���� �� �Ÿ��̴�.*/
	int start = 1, end = house[N - 1] - house[0], result = 0;

	while (start <= end) {
		/* ó�� ���� ������ �����⸦ ��ġ�ߴٰ� �����Ѵ�. */
		int count = 1;

		int mid = (start + end) / 2;
	
		/* ó�� ���� ��ġ�� ������ ����Ѵ�. */
		int temp = house[0];

		for (int i = 1; i < N; ++i) {
			
			// house[i] - temp : ���� ������ �� ������ ������ �Ÿ�
			if (mid  <= house[i] - temp) {
				++count;
				temp = house[i];
			}
		}

		// ������ C���� ��ġ�ؾ� �Ѵ�. 
		// �׷���, ��ġ ���� �۴ٴ� ���� �Ÿ�(mid)�� �ʹ� ũ�� ������ ���̱� �����̴�.
		// (���� �κ� Ž��)
		if (C > count) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}