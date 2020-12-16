//https://tttuer.tistory.com/174
//https://suhwanc.tistory.com/26
//중위 순회와 후위 순회가 주어졌을 때 전위 순회를 구하는 문제
//전위 순회나 후위 순회가 주어지면 한번에 루트가 무엇인지 알 수 있다.
//중위 순회는 전위 순회 혹은 후위 순회에서 루트값을 뽑아낼 때, 어디부터 어디까지인지 왼쪽 서브트리와 오른쪽 서브트리를 구분하고 
//전위순회의 루트 값을 출력하기 위해 주어진다.
#include <iostream>
using namespace std;
int N;
int inOrder[100001] = {0};
int postOrder[100001] = {0};
int position[100001] = {0};
void preOrder(int in_start, int in_end, int post_start, int post_end);
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> inOrder[i];
		position[inOrder[i]] = i;//중위순회에서 노드의 값들의 위치를 index로 갖는 배열
	}
	for (int i = 0; i < N; ++i) {
		cin >> postOrder[i];
	}
	preOrder(0, N - 1, 0, N - 1);
	cout << '\n';
	return 0;
}
void preOrder(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end)
		return;
	int root = postOrder[post_end];//후위순회에서 root값을 알아내기
	cout << root << ' ';
	int in_root = position[root];//중위순회에서 root의 위치(index)
	int leftSize = in_root - in_start;//중위순회에서 왼쪽 서브 트리의 사이즈 
	preOrder(in_start, in_root - 1, post_start, post_start + leftSize - 1);//left
	preOrder(in_root + 1, in_end, post_start + leftSize, post_end - 1);//right;
}
