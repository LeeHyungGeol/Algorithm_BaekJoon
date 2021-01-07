//Ʈ����(trie)�� �����ϱ� ���� Ǯ������, �ڷᱸ��<set>�� �̿��ϸ� �� ���� Ǯ �� �ִ� ������.
//map���� Ǭ ������ �ð����⵵�� o(���ڿ��� ����(10000)*map�� Ž�� �ð�(log10000)) �̰�
//trie�� �̿��� ������ �ð����⵵�� o(���ڿ��� ����(10000)* trie�� Ž�� �ð� ��, ���ڿ��� ����(500)) �̹Ƿ�
//trie�� �̿��Ѱ��� map�� �̿��Ѱͺ��� �ð��� �÷� �ɸ��°��� �� �� �ִ�.
//trie�� �̿��� ���� ���⵵(�޸�): �޸� 1091016KB�� ��� ũ��(26*8)(��� �ϳ� ��)*���ڿ� ����(500)*���ڿ� ����(10000)
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
int N, M, cnt = 0;//(1 �� N �� 10,000, 1 �� M �� 10,000)
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
			//�ش� ��尡 ������ �������ش�.
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
	TRIE* root = new TRIE();//������ TRIE ����ü�� ����Ű�� ������ ����
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