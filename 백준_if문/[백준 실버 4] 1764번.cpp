// ¹®ÀÚ¿­, Set or Map(Map.find() != Map.end())

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string Str;
set<string> Set;
vector<string> Answer;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> Str;
		Set.insert(Str);
	}

	for (int i = 0; i < M; ++i) {
		cin >> Str;
		if (Set.find(Str) != Set.end()) {
			Answer.push_back(Str);
		}
	}

	sort(Answer.begin(), Answer.end());

	cout << Answer.size() << '\n';

	for (string s : Answer) {
		cout << s << '\n';
	}

	return 0;
}