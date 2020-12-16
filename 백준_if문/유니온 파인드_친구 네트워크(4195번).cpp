//유니온 파인드에 집합의 크기를 구하는 기능을 넣는 문제
#include <iostream>
#include <string>
#include <map>
using namespace std;
int T;
int F;// 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다.
map<string, int> parent[100001];

int main() {

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> F;
		for (int j = 1; j <= F; ++j) {
			parent->insert({ "", i });
		}
		string str1, str2;
		for (int j = 1; j <= F; ++j) {
			cin >> str1 >> str2;

		}
	
	}
	return 0;
}