#include <iostream>
#include <vector>
using namespace std;

vector<int> height, weight;
int ranking(int index, int n);
int main() {

	int N, h, w;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> h >> w;
		height.push_back(h);
		weight.push_back(w);
	}

	for (int i = 0; i < N; ++i) {
		cout << ranking(i, N) << ' ';//������ ����� ���
	}
	cout << '\n';
	return 0;
}
int ranking(int index, int n) {//index�� �׶��� ���� ���
	int cnt = 1;//1����� �����ϱ� ������
	for (int i = 0; i < n; ++i) {
		if (index == i)
			continue;
		if (height[index] < height[i] && weight[index] < weight[i])//Ű�� �����԰� �� �� ū����� ����� �ű��
			cnt++;
	}
	return cnt;
}