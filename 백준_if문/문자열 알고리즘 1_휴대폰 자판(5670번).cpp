#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
char inputList[100005][81];
struct TRIE {
	bool terminal;
	int childCount = 0;
	TRIE* child[26];
	TRIE() {
		terminal = false;
		childCount = 0;
		for (int i = 0; i < 26; ++i)
			child[i] = NULL;
	}
	~TRIE() {
		for (int i = 0; i < 26; ++i)
			if (child[i])
				delete child[i];
	}
	void insert(const char* key) {
		if (*key == NULL) {
			this->terminal = true;
			return;
		}
		else {
			int next = *key - 'a'; //ABC
			if (child[next] == NULL) {
				this->child[next] = new TRIE();
				//child[cur]->childCount += 1;
				this->childCount++;
				//child[cur]->childCount++;
			}
			child[next]->insert(key + 1);
		}
	}
	double count(const char* key, double count) {
		if (*(key + 1) == NULL)
			return count;
		//if (this->terminal) count++;
		
		int cur = *key - 'a';
		if (child[cur]->terminal) count++;//h, hi, he
		//if (*key !=NULL && child[cur]->terminal) count++;
		else if (child[cur]->childCount > 1) count++;
		//if (childCount > 1) count++;
		return child[cur]->count(key + 1, count);
	}
	double count2(TRIE* trie, const char* key) {
		double cnt = 1;
		TRIE* t = trie->child[*key - 'a'];
		while (*(key + 1) != NULL && t != NULL) {
			if (t->childCount > 1 || t->terminal)
				cnt++;
			key++;
			t = t->child[*key - 'a'];
		}
		return cnt;
	}
};
int main() {
	int T;
	while (cin >> T) {
		//getchar();
		TRIE* root = new TRIE();
		for (int i = 0; i < T; ++i) {
			cin >> inputList[i];
			root->insert(inputList[i]);
		}
		double total = 0;
		double cur;
		for (int i = 0; i < T; ++i) {
			cur = root->count(inputList[i], 1);
			//cur = root->count2(root, inputList[i]);
			total += cur;
			//cout << cur << '\n';
		}
		//cout << total << '\n';
		cout << fixed;   //소수점 자릿수 고정
		cout.precision(2);
		cout << total / T << '\n';
		delete root;
	}
	return 0;
}