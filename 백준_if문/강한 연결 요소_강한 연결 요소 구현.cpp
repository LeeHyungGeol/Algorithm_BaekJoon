//���� ���� ���(Strongly Connected Componensts): ���ϰ� ����� ���� ����
//���� SCC�� ���ϴ� �� ������ ���� ������ �����ϴ�.
//����Ŭ�� �߻��ϴ� ��� ������ SCC�� �ش��Ѵ�.
//���� �׷����� ���� �ǹ̰� �ִ�. ���� �׷������ �� �׷��� ��ü�� ������ SCC�̴�.
//�ڻ���� �˰���(Kosaraju's Algorithm), Ÿ�� �˰���(Tarjan's Algorithm)

//Ÿ�� �˰���(Tarjan's Algorithm): ��� ������ ���� DFS�� �����Ͽ� SCC�� ã�� �˰���
//1. DFS�� �����ϸ鼭 �θ� ���� Ȯ���Ѵ�. 
//2. Stack���� �ش� �θ� ���� ���� �� ���� ���Ҹ� �̾Ƴ���. 

//Ÿ�� �˰����� ���� �� �ϳ��� SCC�� ���� ������ �������� �����Ѵٴ� ��
//���� ���� ���(SCC)�� �� ��ü�δ� ū �ǹ̰� ������, ���� ����(Topological Sort)�� �Բ� ���� �� �ǹ̰� �� Ŀ����.
//""�� SCC ������ ����""���� �ϴ� ""��������""�� ���� �����ϴ�.
//���� ���� ��� �˰����� �ð� ���⵵�� O(V+E)�̴� : ��� ������ ���ؼ� DFS�� ����, ��� ������ ���ؼ� �ϳ��� Ȯ���Ѵ�.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define MAX 100000//������ �� ����� ����

int id, pa[MAX];//�� ��帶�� ������ ��ȣ�� �Ҵ�
bool finished[MAX];//���� Ư���� ��忡 ���� DFS�� �������� Ȯ���� �� �ֵ��� �Ѵ�.
vector<int> adj[MAX];//���������� ������ ��带 ��� �迭
vector<vector<int>> SCC;//SCC�� �� �׷��� ������ ���� ���� ���� �� �ֱ� ������ 2���� ���ͷ� ����
stack<int> s;

//DFS�� �� ������ ������ŭ �����Ѵ�.
int dfs(int x) {
	//��帶�� ������ ��ȣ�� �Ҵ�
	pa[x] = ++id;//�� ó���� �θ�� ������ ��
	s.push(x); //stack�� �ڱ� �ڽ��� ����

	//parent���� ���� �ڽ��� �θ� �������� Ȯ��
	int parent = pa[x];//�� ó�� ���� ���� �ڱ� �ڽ��� �θ� �ȴ�.
	
	//������ ��带 �ϳ��� Ȯ���Ѵ�.
	for (int i = 0; i < adj[x].size(); ++i) { 
		int next = adj[x][i];
		
		//�湮���� ���� �̿�
		//�ش� ��带 �湮�� ���� ���ٸ� DFS�� ����
		if (pa[next] == 0)
			parent = min(parent, dfs(next));

		//ó�� ���� �̿�
		//�湮�� �Ͽ�����, DFS�� �������� ���: ���� stack�� �̿� ��尡 �� �ִ� ���� 
		//��,DFS�� ������ ���� ���¿��� �̿� ���� �� �� �ִٴ� ���� �̿� ��尡 �ڽ��� �θ��� ������ �� �� �ִ�.
		else if (!finished[next])//ó������ �̿��� �ڽ��� �θ��� �ش� ������ SCC�� �����ϱ� ���� ���� �θ� ���� ������ �Ѵ�.
			parent = min(parent, pa[next]);

	}

	//�θ��尡 �ڱ� �ڽ��� ���
	if (parent == pa[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;//�ϳ��� ��带 �����鼭 ó���� �Ϸ�Ǿ��ٰ� ǥ��
			//�ڱ� �ڽ��� ��, ��, �θ� ���� ���� ��� �ݺ����� ����������. 
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	//�ڽ��� �θ� ���� ��ȯ�Ѵ�.
	return parent;
}
int main() {
	int v = 11;
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(1);
	adj[4].push_back(2);
	adj[4].push_back(5);
	adj[5].push_back(7);
	adj[6].push_back(5); 
	adj[7].push_back(6);
	adj[8].push_back(5);
	adj[8].push_back(9);
	adj[9].push_back(10);
	adj[10].push_back(11);
	adj[11].push_back(3);
	adj[11].push_back(8);

	for (int i = 1; i <= v; ++i) {
		//�ѹ��� �湮���� ���� ��忡 ���Ͽ� dfs�� ����
		//DFS�� �� ������ ������ŭ �����Ѵ�.
		if (pa[i] == 0) dfs(i);
	}

	cout << "SCC�� ���� : " << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); ++i) {
		cout << i + 1 << "��° SCC :";
		for (int j = 0; j < SCC[i].size(); ++j) {
			cout << SCC[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}