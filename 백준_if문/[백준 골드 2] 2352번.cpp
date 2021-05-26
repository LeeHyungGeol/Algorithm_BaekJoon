// �̺� Ž���� �̿��� `���� �� �����ϴ� �κ� ����(LIS)` ����
// C++�� STL���̺귯���� <algorithm>�� ���Ե� �Լ��� lower_bound()�� �����ϰų� ���̺귯���� ����Ͽ� �ذ��Ѵ�. 

// [���� ��� 2] 12015�� : ���� �� �����ϴ� �κ� ����2 �� ������ �Ȱ���.
// ��, ���� �� �����ϴ� �κ� ������ ũ�⸸ ������ ��, �� ���� ��ҵ��� ���� �� �����ϴ� �κ� ������ ������ �ʴٴ� ��ǿ� ��������!!
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt = 0;
vector<int> port;

int first(vector<int>& arr, int target, int start, int end);

int main() {
	cin >> N;

	// ���ʷ� 1�� ��Ʈ�� ����Ǿ�� �ϴ� ��Ʈ ��ȣ, 
	// 2�� ��Ʈ�� ����Ǿ�� �ϴ� ��Ʈ ��ȣ, ��, 
	// n�� ��Ʈ�� ����Ǿ�� �ϴ� ��Ʈ ��ȣ�� �־�����.
	// �� ������ 1 �̻� n �����̸� ���� ���� ���� ���ٰ� ��������.

	// ������ 1 �̻� n ���϶�� �Ͽ����Ƿ�, ��������� ���� ���� ���� -1 �� �Է��صд�.
	port.push_back(-1);

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;

		if (port.back() < temp) {
			port.push_back(temp);
			++cnt;
		}
		else {
			int index = first(port, temp, 0, port.size() - 1);
			//int index = lower_bound(port.begin(), port.end(), temp) - port.begin();
			port[index] = temp;
		}
	}

	cout << cnt << '\n';

	return 0;
}

int first(vector<int>& arr, int target, int start, int end) {
	if (start > end) {
		return start;
	}

	int mid = (start + end) / 2;

	// ���� �κ� Ž��
	if (arr[mid] >= target) {
		return first(arr, target, start, mid - 1);
	}
	// ������ �κ� Ž��
	else {
		return first(arr, target, mid + 1, end);
	}
}