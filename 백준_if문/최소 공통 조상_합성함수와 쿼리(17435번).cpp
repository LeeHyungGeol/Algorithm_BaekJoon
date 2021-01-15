//https://blog.naver.com/kks227/220793361738
//각각의 값 x를 정점으로 생각하고, 나가는 간선이 정확히 한 개이면서, 그 도착지가 f(x)임을 알 수 있습니다.
//f_n(x)는 x에서 n번 이동 후 어디냐를 말하는 것

//예를 들어 k = 13이라면 이진수로 나타내었을 때 "1101(2)"이므로, 
//켜져 있는 비트에 해당하는 1칸, 4칸, 8칸 이렇게 총 3번 뛰면 됩니다. 
//뛰는 순서에는 상관이 없다는 점에 주목

//시간 복잡도: O(logN)
#include <iostream>
using namespace std;
#define LOG 19//2^19 > 500,000
int m, Q;// (1 ≤ m ≤ 200,000),쿼리의 개수 Q (1 ≤ Q ≤ 200,000)
int n, x;//(1 ≤ n ≤ 500,000; 1 ≤ x ≤ m)
int parent[200001][LOG];// 2^k >= MAX인 최소의 k, 2^19 > 500,000
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;

	// parent[i][j] = 정점 i에서 2^j번 이동한 후의 정점
	for (int i = 1; i <= m; ++i)
		cin >> parent[i][0];

	// 작은 j부터 배열을 채워가면서 전체 배열을 채울 수 있다.
	// i에서 2^(j+1)번 이동한 후의 정점은 i에서 2^j번*2번 이동하는 것
	// parent[i][j+1] = parent[ parent[i][j] ][j]
	for (int j = 1; j < LOG; ++j)
		for (int i = 1; i <= m; ++i)
			parent[i][j] = parent[ parent[i][j - 1] ][j - 1];
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		//각각의 값 x를 정점으로 생각하고, 나가는 간선이 정확히 한 개이면서, 그 도착지가 f(x)임을 알 수 있습니다.
		//f_n(x)는 x에서 n번 이동 후 어디냐를 말하는 것
		cin >> n >> x;
		for (int j = LOG - 1; j >= 0; --j) {
			if (n >= 1 << j) {//if ((n & (1 << j)) > 0) {
				n -= 1 << j;
				x = parent[x][j];
			}
		}
		cout << x << '\n';
	}
	return 0;
}