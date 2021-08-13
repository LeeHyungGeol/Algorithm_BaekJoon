// 최단경로(플로이드 워셜) 문제

// [백준 골드 4] 키 순서(2458번) 문제와 비슷하다.
// 모든 지점에서 다른 모든 지점까지의 `관계` 를 구하는 문제
// a is b : a -> b : Graph[a][b] = 1 : a와 b가 `관계` 가 있다는 의미
// Graph[a][b] == INF : a와 b사이에 `관계`가 없다는 의미

// 추가로 C++ 에서,
// `공백을 포함한 문자열`을 받을 때, getline(cin, string); 을 하면 된다.
// string을 입력 받기에 앞서 숫자를 입력 받았다면, cin.ignore()를 추가한다.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M;
vector<vector<int>> Graph;

void init();
void floyd_warshall();

int main() {
	cin >> N;
	//추가 안할 경우 getline에서 subscript range 에러 발생
	cin.ignore();

	init();

	string str;

	for (int i = 0; i < N; ++i) {
		string str;
		getline(cin, str);
		Graph[str[0] - 'a'][str[5] - 'a'] = 1;
	}

	floyd_warshall();

	cin >> M;
	cin.ignore();

	for (int i = 0; i < M; ++i) {
		string str;
		getline(cin, str);
		if (Graph[str[0] - 'a'][str[5] - 'a'] != INF) {
			cout << 'T' << '\n';
		}
		else {
			cout << 'F' << '\n';
		}
	}

	return 0;
}

void init() {
	Graph.resize(26, vector<int>(26, INF));

	for (int i = 0; i <= 25; ++i) {
		for (int j = 0; j <= 25; ++j) {
			if (i == j) {
				Graph[i][j] = 0;
			}
		}
	}
}

void floyd_warshall() {
	for (int k = 0; k <= 25; ++k) {
		for (int i = 0; i <= 25; ++i) {
			for (int j = 0; j <= 25; ++j) {
				Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
			}
		}
	}
	return;
}