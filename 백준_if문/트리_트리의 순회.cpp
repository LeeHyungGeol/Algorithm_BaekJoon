//https://tttuer.tistory.com/174
//https://suhwanc.tistory.com/26
//���� ��ȸ�� ���� ��ȸ�� �־����� �� ���� ��ȸ�� ���ϴ� ����
//���� ��ȸ�� ���� ��ȸ�� �־����� �ѹ��� ��Ʈ�� �������� �� �� �ִ�.
//���� ��ȸ�� ���� ��ȸ Ȥ�� ���� ��ȸ���� ��Ʈ���� �̾Ƴ� ��, ������ ���������� ���� ����Ʈ���� ������ ����Ʈ���� �����ϰ� 
//������ȸ�� ��Ʈ ���� ����ϱ� ���� �־�����.
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
		position[inOrder[i]] = i;//������ȸ���� ����� ������ ��ġ�� index�� ���� �迭
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
	int root = postOrder[post_end];//������ȸ���� root���� �˾Ƴ���
	cout << root << ' ';
	int in_root = position[root];//������ȸ���� root�� ��ġ(index)
	int leftSize = in_root - in_start;//������ȸ���� ���� ���� Ʈ���� ������ 
	preOrder(in_start, in_root - 1, post_start, post_start + leftSize - 1);//left
	preOrder(in_root + 1, in_end, post_start + leftSize, post_end - 1);//right;
}
