#include <iostream>
using namespace std;

int N, M; //(1 ≤ M ≤ N ≤ 8)
int answer[8 + 1]; //인덱스가 0부터 시작하므로 1을 하나 더한다
bool isUsed[8 + 1];
void backTracking(int x);

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	backTracking(1); //숫자 1부터 백트랙킹 시작

	return 0;
}
void backTracking(int x) { //숫자 x에 대해  백트랙킹 시작
	if (x == M + 1) {//answer배열 index를 0부터 사용하지 않고 1부터 사용했기 때문에 +1을 해준다.
		for (int i = 1; i <= M; ++i) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) { //1부터 N까지 사용했는지 안했는지 재귀로 체크하면서 answer배열에 사용한 숫자를 삽입
		if (!isUsed[i]) {//숫자가 사용되지 않았을 때 if문 통과 //숫자가 사용되었다면 다른 숫자를 사용해야 하기 때문에
			answer[x] = i;
			isUsed[i] = true; //숫자 i가 사용되었다.
			backTracking(x + 1);
			isUsed[i] = false; //base case에서 출력하고 재귀를 빠져나왔기 때문에 사용한 숫자 i를 반납한다.
		}
	}
}