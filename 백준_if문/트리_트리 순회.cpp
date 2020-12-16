//https://sw-ko.tistory.com/167
//https://sihyungyou.github.io/baekjoon-1991/
#include <iostream>
using namespace std;
typedef struct TreeNode {
	char left;
	char right;
}TreeNode;
TreeNode node[26];
char Node[26][2];
int N;
void preOrder(char root);
void inOrder(char root);
void postOrder(char root);
int main() {
	cin >> N;
	char root, left, right;
	for (int i = 0; i < N; ++i) {
		cin >> root >> left >> right;
		node[root-'A'].left = left;
		node[root-'A'].right = right;
		//Node[root - 'A'][0] = left;
		//Node[root - 'A'][1] = right;
	}
	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');
	cout << '\n';
	return 0;
}
void preOrder(char root) {
	if (root == '.')
		return;
	cout << root;
	preOrder(node[root-'A'].left);
	preOrder(node[root-'A'].right);
}
void inOrder(char root) {
	if (root == '.')
		return;
	inOrder(node[root-'A'].left);
	cout << root;
	inOrder(node[root-'A'].right);
}
void postOrder(char root) {
	if (root == '.')
		return;
	postOrder(node[root-'A'].left);
	postOrder(node[root-'A'].right);
	cout << root;
}
