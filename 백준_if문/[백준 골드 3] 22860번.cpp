#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int N, M, Q, isFolder;
string Parent, Child, Target;
map<string, vector<string>> FileList;
map<string, set<string>> Directory;
map<string, int> Result;

void find(string target);
void dfs(string cur);

int main() {
	cin >> N >> M;

	Directory["main"] = set<string>();

	for (int i = 0; i < N + M; ++i) {
		cin >> Parent >> Child >> isFolder;
		if (isFolder) {
			Directory[Parent].insert(Child);
		}
		else {
			FileList[Parent].push_back(Child);
		}
	}

	cin >> Q;

	for (int i = 0; i < Q; ++i) {
		cin >> Target;
		stringstream ss(Target);
		string buffer;
		vector<string> arr;

		while (getline(ss, buffer, '/')) {
			arr.push_back(buffer);
		}

		find(arr.back());
	}

	return 0;
}

void find(string target) {
	Result.clear();

	dfs(target);

	int sum = 0;

	for (pair<string, int> x : Result) {
		sum += x.second;
	}

	cout << Result.size() << ' ' << sum << '\n';
}

void dfs(string cur) {
	if (Directory.find(cur) != Directory.end()) {
		for (string next : Directory[cur]) dfs(next);
	}
	if (FileList.find(cur) != FileList.end()) {
		for (string next : FileList[cur]) ++Result[next];
	}
}