#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
int N, M, cnt = 0;
struct TRIE {
	bool terminal;
	TRIE* child[26];
	TRIE() {
		terminal = false;
		memset(child, NULL, sizeof(child));
	}
	void insert(const char* key) {
		if (*key == NULL) {
			terminal = true;
			return;
		}
		else {
			int cur = *key - 'a';
			//해당 노드가 없으면 생성해준다.
			if (child[cur] == NULL)
				child[cur] = new TRIE();
			child[cur]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if(*key==NULL && )
	}
};
int main() {
	TRIE* trie = new TRIE();//생성한 TRIE 구조체를 가리키는 포인터 생성
	cin >> N >> M;
	vector<string> str1(N);
	for (int i = 0; i < N; ++i) {
		cin >> str1[i];
	}
	vector<string> str2(M);
	for (int i = 0; i < M; ++i) {
		cin >> str2[i];
	}
	cout << cnt << '\n';
	return 0;
}