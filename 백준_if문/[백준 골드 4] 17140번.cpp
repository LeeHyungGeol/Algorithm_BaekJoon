#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int r, c, k, Answer, Row = 3, Col = 3;
int Arr[101][101];
int Counter[101];

void operateR();
void operateC();
bool compare(const pii& a, const pii& b);
void rotate();

int main() {
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cin >> Arr[i][j];
		}
	}

	bool flag = false;

	for (int i = 0; i < 101; ++i) {
		if (Arr[r][c] == k) {
			flag = true;
			break;
		}
		if (Row >= Col) {
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
	vector<int> longest;

	for (int i = 1; i <= Row; ++i) {
		vector<pii> temp;
		memset(Counter, 0, sizeof(Counter));

		for (int j = 1; j <= Col; ++j) ++Counter[Arr[i][j]];

		for (int j = 1; j < 101; ++j) {
			if (Counter[j] == 0) continue;
			temp.push_back({ j, Counter[j] });
		}

		sort(temp.begin(), temp.end(), compare);

		for (int j = 1; j <= Col; ++j) Arr[i][j] = 0;

		int k = 1;
		for (int j = 0; j < temp.size(); ++j) {
			Arr[i][k] = temp[j].first;
			Arr[i][k + 1] = temp[j].second;
			k += 2;
		}
		--k;
		longest.push_back(k);
	}

	sort(longest.begin(), longest.end());
	Col = longest.back();
}

void operateC() {
	vector<int> longest;

	for (int i = 1; i <= Col; ++i) {
		vector<pii> temp;
		memset(Counter, 0, sizeof(Counter));

		for (int j = 1; j <= Row; ++j) ++Counter[Arr[j][i]];

		for (int j = 1; j < 101; ++j) {
			if (Counter[j] == 0) continue;
			temp.push_back({ j, Counter[j] });
		}

		sort(temp.begin(), temp.end(), compare);

		for (int j = 1; j <= Row; ++j) Arr[j][i] = 0;

		int k = 1;
		for (int j = 0; j < temp.size(); ++j) {
			Arr[k][i] = temp[j].first;
			Arr[k+1][i] = temp[j].second;
			k += 2;
		}
		--k;
		longest.push_back(k);
	}

	sort(longest.begin(), longest.end());
	Row = longest.back();
}

// y=x ´ëÄªÀÌµ¿
//void rotate() {
//	vector<vector<int>> temp(Arr[0].size(), vector<int>(Arr.size(), 0));
//
//	for (int i = 0; i < Arr.size(); ++i) {
//		for (int j = 0; j < Arr[i].size(); ++j) {
//			temp[j][i] = Arr[i][j];
//		}
//	}
//
//	Arr = temp;
//}

bool compare(const pii& a, const pii& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
