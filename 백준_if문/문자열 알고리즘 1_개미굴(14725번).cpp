//https://imnotabear.tistory.com/312 //map과 포인터로 TRIE 구현
//https://justicehui.github.io/ps/2019/08/27/BOJ14725/ //각 노드에는 단어를 저장하고 child배열에는 다음에 나올 단어를 저장
//https://yabmoons.tistory.com/379 //TRIE 구현 및 작동원리 //TRIE 구조체 alphabet 기준으로 구현 
//https://twpower.github.io/187-trie-concept-and-basic-problem //TRIE 구현 및 작동원리 //Trie* find(const char * key): key에 해당하는 문자열을 접두어로 가지고 있는지 확인하고 가지고 있다면 해당 접두어가 끝나는 부분의 위치를 반환합니다.
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
struct TRIE {
	map<string, TRIE*> child; 
	map<string, TRIE*>::iterator iter;
	void insert(const vector<string>& str, int level) {
		if (level == str.size())
			return;
		string s = str[level];
		iter = child.find(s);
		if (iter != child.end()) {//이미 있는 경우
			iter->second->insert(str, level + 1);
		}
		else {//없는 경우
			TRIE* trie = new TRIE();//TRIE 구조체 하나를 가리키는 TRIE 포인터를 생성
			child.insert({ s, trie });//map에 insert
			trie->insert(str, level + 1);
		}
	}
	void print(int level) {
		if (child.empty())
			return;
		for (auto iter = child.begin(); iter != child.end(); ++iter) {
			for (int i = 0; i < level; ++i)
				cout << "--";
			cout << iter->first << '\n';
			iter->second->print(level + 1);
		}
	}
};

int main() {
	TRIE* root = new TRIE();
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int K;
		cin >> K;
		vector<string> s(K);
		for (int j = 0; j < K; ++j)
			cin >> s[j];
		root->insert(s, 0);
	}
	root->print(0);
	return 0;
}