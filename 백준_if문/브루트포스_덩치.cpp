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
		cout << ranking(i, N) << ' ';//각각의 등수를 출력
	}
	cout << '\n';
	return 0;
}
int ranking(int index, int n) {//index는 그때의 기준 사람
	int cnt = 1;//1등부터 시작하기 때문에
	for (int i = 0; i < n; ++i) {
		if (index == i)
			continue;
		if (height[index] < height[i] && weight[index] < weight[i])//키와 몸무게가 둘 다 큰사람만 등수를 매긴다
			cnt++;
	}
	return cnt;
}