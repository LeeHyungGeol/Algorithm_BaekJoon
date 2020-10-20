#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(const pair<int, pair<int, string>>& a, const pair<int, pair<int, string>>& b);
int main() {
	string name;
	int N, age;
	cin >> N;
	vector<pair<int, pair<int, string>>> v;

	for (int i = 0; i < N; ++i) {
		cin >> age >> name;
		v.push_back(make_pair(i, make_pair(age, name)));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].second.first << " " << v[i].second.second << '\n';
	}
	return 0;
}
bool compare(const pair<int, pair<int, string>> & a, const pair<int, pair<int, string>>& b) {
	if (a.second.first == b.second.first)
		return a.first < b.first;
	return a.second.first < b.second.first;
}