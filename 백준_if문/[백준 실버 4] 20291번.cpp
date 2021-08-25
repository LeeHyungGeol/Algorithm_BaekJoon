// ¹®ÀÚ¿­, Map

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<string, int> psi;

int N;
string Str;
map<string, int> Map;
vector<psi> Extensions;

string getExtension(const string& str);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> Str;
		string extenstion = getExtension(Str);
		++Map[extenstion];
	}
	
	for (auto m : Map) {
		Extensions.push_back({ m.first, m.second });
	}

	sort(Extensions.begin(), Extensions.end());

	for (auto ext : Extensions) {
		cout << ext.first << ' ' << ext.second << '\n';
	}

	return 0;
}

string getExtension(const string& str) {
	return str.substr((int)str.find('.') + 1);
}