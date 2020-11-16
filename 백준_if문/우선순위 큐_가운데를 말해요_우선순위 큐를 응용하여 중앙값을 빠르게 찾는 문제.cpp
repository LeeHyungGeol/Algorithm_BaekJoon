//�켱���� ť�� �����Ͽ� �߾Ӱ��� ������ ã�� ����
//https://hsho.tistory.com/121
#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> heapAscending;//�߰� �� ���� ū ����//��������
	priority_queue<int, vector<int>, less<int>> heapDescending;//�߰� �� ���� ���� ����//��������
	int N, x;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		if (heapDescending.size() == heapAscending.size())
			heapDescending.push(x);
		else
			heapAscending.push(x);
		if (!heapDescending.empty() && !heapAscending.empty() && heapDescending.top() > heapAscending.top()) {
			int d = heapDescending.top();
			int a = heapAscending.top();
			heapDescending.pop();
			heapAscending.pop();
			heapDescending.push(a);
			heapAscending.push(d);
		}
		
		cout << heapDescending.top() << '\n';
	}

	return 0;
}