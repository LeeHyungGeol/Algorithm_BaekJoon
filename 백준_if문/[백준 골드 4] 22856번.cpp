#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
	int num;
	Node* Parent;
	Node* Left;
	Node* Right;
}Node;

int N, End, Answer;
bool Flag;
vector<Node> Nodes;
vector<int> inOrders;
vector<bool> Visited;
Node* Root;

void addNodes(Node* parent, Node* left, Node* right);
void inOrder(Node* cur);
void pseudoInOrder(Node* cur);

int main() {
	cin >> N;

	Nodes.resize(N + 1);
	Visited.assign(N + 1, false);

	for (int i = 1; i <= N; ++i) Nodes[i].num = i;

	Root = &Nodes[1];
	Root->Parent = NULL;
	Node* left = NULL; 
	Node* right = NULL;

	for (int i = 0, a, b, c; i < N; ++i) {
		cin >> a >> b >> c;
		left = (b == -1) ? NULL : &Nodes[b];
		right = (c == -1) ? NULL : &Nodes[c];
		addNodes(&Nodes[a], left, right);
	}

	inOrder(Root);
	
	End = inOrders.back();

	pseudoInOrder(Root);

	cout << Answer << '\n';

	return 0;
}

void addNodes(Node* parent, Node* left, Node* right) {
	parent->Left = left;
	parent->Right = right;
	if (left != NULL) left->Parent = parent;
	if (right != NULL) right->Parent = parent;
}

void inOrder(Node* cur) {
	if (cur == NULL) return;
	inOrder(cur->Left);
	inOrders.push_back(cur->num);
	inOrder(cur->Right);
}

void pseudoInOrder(Node* cur) {
	if (!Flag && cur->Left != NULL && !Visited[cur->Left->num]) {
		++Answer;
		Visited[cur->Left->num] = true;
		pseudoInOrder(cur->Left);
	}
	if (!Flag && cur->Right != NULL && !Visited[cur->Right->num]) {
		++Answer;
		Visited[cur->Right->num] = true;
		pseudoInOrder(cur->Right);
	}
	if (cur->num == End) {
		Flag = true;
		return;
	}
	if (!Flag && cur->Parent != NULL) {
		++Answer;
		pseudoInOrder(cur->Parent);
	}
}