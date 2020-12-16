//https://imnotabear.tistory.com/224 //������ Ǯ��
//https://kyunstudio.tistory.com/172 //�迭 Ǯ��
//https://penglog.tistory.com/96 //�迭 Ǯ��
#include <iostream>
using namespace std;
typedef struct TreeNode {
	int data;
	//TreeNode* parent;
	TreeNode* left;
	TreeNode* right; 
}TreeNode;

TreeNode* insertNode(TreeNode* node, int data);
void postOrder(TreeNode* node);

int main() {
	int num;
	TreeNode* node = nullptr;
	//TreeNode* node = NULL;

	while (cin >> num) {    //EOF�� ���������� ���� �Է� //EOF : End Of File	
		/*if (num == EOF)
			break;*/
		node = insertNode(node, num);
	}
	postOrder(node);

	return 0;
}
TreeNode* insertNode(TreeNode* node, int data) {
	if (node == NULL) {
		node = new TreeNode();
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else if (data <= node->data) {
		node->left = insertNode(node->left, data);
	}
	else
		node->right = insertNode(node->right, data);
	return node;
}
void postOrder(TreeNode* node) {
	if (node->left != NULL)
		postOrder(node->left);
	if (node->right != NULL)
		postOrder(node->right);
	cout << node->data << '\n';
}