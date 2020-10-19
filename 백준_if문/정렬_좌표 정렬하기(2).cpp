#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second
vector<pii> coordinates;
//vector<pii> coordinates(100000);
bool compare(const pair<int, int>& a, const pair<int, int>& b);
int main() {
	int N, X, Y;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> X >> Y;
		coordinates.push_back(make_pair(X, Y));
	}
	sort(coordinates.begin(), coordinates.end(), compare);
	for (int i = 0; i < N; ++i) {
		cout << coordinates[i].x << " " << coordinates[i].y << '\n';
	}

	return 0;
}
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	//first가 같다면 //second로 오름차순
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first; //first로 오름차순
}