// map 문제, 해쉬를 사용한 집합과 맵

#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, int> Map1;
map<int, string> Map2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		string str;
		cin >> str;
		Map1[str] = i;
		Map2[i] = str;
	}

	for (int i = 0; i < M; ++i) {
		string str;
		cin >> str;
		if (isdigit(str[0])) {
			cout << Map2[stoi(str)] << '\n';
		}
		else {
			cout << Map1[str] << '\n';
		}
	}

	return 0;
}