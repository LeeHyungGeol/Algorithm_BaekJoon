//�켱���� ť�� �����Ͽ� �߾Ӱ��� ������ ã�� ����
#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>()> heapAscending;//�߰� �� ���� ū ����//��������
	priority_queue<int, vector<int>, less<int>()> heapDescending;//�߰� �� ���� ���� ����//��������
	int N, x, mid = -10001;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		if (mid == -10001) {
			mid = x;
			cout << mid << '\n';
			continue;
		}
		if()
		else if (mid < x)
			heapAscending.push(x);
		else if (x < mid)
			heapDescending.push(x);


		cout << mid << '\n';
	}

	return 0;
}