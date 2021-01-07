//트라이(trie)를 연습하기 위해 풀었지만, 자료구조<set>을 이용하면 더 쉽게 풀 구 있는 문제다.
//map으로 푼 문제의 시간복잡도는 o(문자열의 갯수(10000)*map의 탐색 시간(log10000)) 이고
//trie를 이용한 문제의 시간복잡도는 o(문자열의 갯수(10000)* trie의 탐색 시간 즉, 문자열의 길이(500)) 이므로
//trie를 이용한것이 map을 이용한것보다 시간이 올래 걸리는것을 알 수 있다.
//trie를 이용한 공간 복잡도(메모리): 메모리 1091016KB는 노드 크기(26*8)(노드 하나 당)*문자열 길이(500)*문자열 개수(10000)
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
int N, M, cnt = 0;//(1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10,000)
struct TRIE {
	bool terminal;
	TRIE* child[26];
	TRIE() {
		terminal = false;
		memset(child, NULL, sizeof(child));
	}
	~TRIE() {
		for (int i = 0; i < 26; ++i) {
			if (child[i])
				delete child[i];
		}
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
		if (*key == NULL && terminal)
			return true;
		int cur = *key - 'a';
		if (child[cur] == NULL)
			return false;
		return child[cur]->find(key + 1);
	}
};
int main() {
	TRIE* root = new TRIE();//생성한 TRIE 구조체를 가리키는 포인터 생성
	cin >> N >> M;
	char str[501];
	for (int i = 0; i < N; ++i) {
		cin >> str;
		root->insert(str);
	}
	for (int i = 0; i < M; ++i) {
		cin >> str;
		if (root->find(str)) ++cnt;
	}
	//delete root;
	cout << cnt << '\n';
	return 0;
}