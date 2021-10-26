#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int r, c, k, Answer;
vector<vector<int>> Arr;
vector<vector<pii>> TempArr;
map<int, int> Counter;

void operateR();
void operateC();
void rotate();
bool compare(const pii& a, const pii& b);

int main() {
	cin >> r >> c >> k;

	Arr.assign(3, vector<int>(3, 0));

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> Arr[i][j];
		}
	}

	bool flag = false;

	for (int i = 0; i < 100; ++i) {
		if (Arr[r - 1][c - 1] == k) {
			flag = true;
			break;
		}
		if (Arr.size() >= Arr[0].size()) {
			operateR();
		}
		else {
			operateC();
		}
		++Answer;
	}

	if (flag) {
		cout << Answer << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}

void operateR() {
	int longest = 0;
	TempArr.clear();

	for (int i = 0; i < Arr.size(); ++i) {
		Counter.clear();
		vector<pii> temp;

		for (int j = 0; j < Arr[i].size(); ++j) {
			if (Arr[i][j] == 0) continue;
			++Counter[Arr[i][j]];
		}

		temp.assign(Counter.begin(), Counter.end());
		sort(temp.begin(), temp.end(), compare);

		TempArr.push_back(temp);
		if (temp.size() > longest) {
			longest = temp.size();
		}
	}

	Arr.clear();

	if (longest > 50) longest = 50;

	for (int i = 0; i < TempArr.size(); ++i) {
		vector<int> temp(longest * 2, 0);
		int k = 0;

		for (int j = 0; j < TempArr[i].size(); ++j) {
			temp[k] = TempArr[i][j].first;
			temp[k + 1] = TempArr[i][j].second;
			k += 2;
		}

		Arr.push_back(temp);
	}
}

void operateC() {
	rotate();

	operateR();

	rotate();
}

// y=x ´ëÄªÀÌµ¿
void rotate() {
	vector<vector<int>> temp(Arr[0].size(), vector<int>(Arr.size(), 0));

	for (int i = 0; i < Arr.size(); ++i) {
		for (int j = 0; j < Arr[i].size(); ++j) {
			temp[j][i] = Arr[i][j];
		}
	}

	Arr = temp;
}

bool compare(const pii& a, const pii& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
