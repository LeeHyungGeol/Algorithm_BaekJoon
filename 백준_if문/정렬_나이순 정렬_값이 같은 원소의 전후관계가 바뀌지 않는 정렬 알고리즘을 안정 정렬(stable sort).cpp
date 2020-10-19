#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(const pair<int, pair<int, string>>& a, const pair<int, pair<int, string>>& b);
int main() {
	string s;
	int N, n;
	cin >> N;
	vector<pair<int, pair<int, string>>> v;

	for (int i = 0; i < N; ++i) {
		cin >> n >> s;
		v.push_back(make_pair(i, make_pair(n, s)));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].second.first << v[i].second.second << '\n';
	}
	return 0;
}
bool compare(const pair<int, pair<int, string>> & a, const pair<int, pair<int, string>>& b) {
	
}