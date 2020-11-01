//가능한 한 많은 구간을 선택하는 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;
	int N, start, end, cnt = 1, max = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), compare);
	/*for (int i = 0; i < N; ++i) {
		cout << v[i].first << " " << v[i].second << '\n';
	}*/
	//for (int i = 0; i < N; ++i) { // O(N^2) 만큼의 시간 복잡도가 생기므로 Online Judge에서 시간 초과가 생긴다.
	//	for (int j = i; j < N; ++j) {
	//		if (j == i && v[i].second == v[i].first)
	//			continue;
	//		if (v[j].first >= end) {
	//			end = v[j].second;
	//			cnt++;
	//		}
	//	}
	//	if (max < cnt) {
	//		max = cnt;
	//		//cout << i << " " << v[i].first << " " << v[i].second <<" "<<max<< '\n';
	//	}
	//	cnt = 1;
	//}
	//cout << max << '\n';
	end = v[0].second;
	for (int i = 1; i < N; ++i) {
		if (v[i].first >= end) {
			cnt++;
			end = v[i].second;
		}
	}
	cout << cnt << '\n';
	return 0;
}
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) 
		return a.first < b.first;
	return a.second < b.second;
}