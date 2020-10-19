#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int N;
	cin >> N;
	while (true) {
		if (N <= 0)
			break;
		v.push_back(N % 10);
		N = N / 10;
	}										  //greater<int>(): 첫번째 인자가 두번째 인자보다 크면 true 반환 (bool)
	sort(v.begin(), v.end(), greater<int>()); //벡터_내림차순 정렬 
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
	}
	return 0;
}