#include <iostream>
using namespace std;

int N; //(1 ¡Â N < 15)
int arr[15 + 1];
int cnt = 0;
void dfs(int x);

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dfs(1);

	cout << cnt << '\n';
	return 0;
}
void dfs(int x) {
	if (x == N) {
		cnt++;
		return;
	}

	for (int i = 1; i <= N; ++i) {
		
	}

}