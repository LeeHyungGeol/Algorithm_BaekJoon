#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const string& a, const string& b);
int main() {
	vector<string> v;
	int N;
	string s;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(),v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end()); //벡터_중복 제거
	//unique 함수는 앞과 뒤의 원소들을 비교하기 때문에 반드시 정렬을 한 뒤 실행해야 합니다.
	//[정렬하지 않았을 때] 1 2 1 은 1 사이에 2가 있어서 지워지지 않았지만 
	//5 5는 중간에 어떠한 수도 없이 연속적으로 나타나서 중복된 원소로 판단되었다는 것을 확인할 수 있습니다.

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << '\n';
	}
	return 0;
}
bool compare(const string& a, const string& b) {
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

