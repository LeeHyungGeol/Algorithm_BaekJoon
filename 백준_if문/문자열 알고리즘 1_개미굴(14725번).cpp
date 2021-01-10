//https://imnotabear.tistory.com/312 //map�� �����ͷ� TRIE ����
//https://justicehui.github.io/ps/2019/08/27/BOJ14725/ //�� ��忡�� �ܾ �����ϰ� child�迭���� ������ ���� �ܾ ����
//https://yabmoons.tistory.com/379 //TRIE ���� �� �۵����� //TRIE ����ü alphabet �������� ���� 
//https://twpower.github.io/187-trie-concept-and-basic-problem //TRIE ���� �� �۵����� //Trie* find(const char * key): key�� �ش��ϴ� ���ڿ��� ���ξ�� ������ �ִ��� Ȯ���ϰ� ������ �ִٸ� �ش� ���ξ ������ �κ��� ��ġ�� ��ȯ�մϴ�.
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
		if (iter != child.end()) {//�̹� �ִ� ���
			iter->second->insert(str, level + 1);
		}
		else {//���� ���
			TRIE* trie = new TRIE();//TRIE ����ü �ϳ��� ����Ű�� TRIE �����͸� ����
			child.insert({ s, trie });//map�� insert
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