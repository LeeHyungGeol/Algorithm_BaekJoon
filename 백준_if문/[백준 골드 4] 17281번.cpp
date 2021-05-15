#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const static int PLAYER_NUM = 10;

int N, result;
int innings[51][PLAYER_NUM] = { 0, };
// 4번 타자는 선택되었다.
int order[PLAYER_NUM] = { 0, };
// 4번 타자는 1번 선수이다.
bool Select[PLAYER_NUM];

void dfs(int cnt);
void play();

int main() {
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cin >> innings[i][j];
		}
	}

	// 4번 선수는 선택되었다.
	Select[4] = true;
	// 4번 타자는 1번 선수이다.
	order[4] = 1;
	// 2번 선수 부터 순서를 정해준다.
	dfs(2);

	cout << result << '\n';

	return 0;
}

void dfs(int cnt) {
	// cnt 의 수가 10이어야 1번 부터 9번 선수까지 순서를 모두 정한 것
	if (cnt == PLAYER_NUM) {
		//정해진 순서에 따라 게임을 진행한다.
		play();
		return;
	}

	for (int i = 1; i < PLAYER_NUM; ++i) {
		if (Select[i] == true) {
			continue;
		}
		Select[i] = true;
		order[i] = cnt;
		dfs(cnt + 1);
		Select[i] = false;
	}
}

void play() {
	//홈, 1루, 2루, 3루
	int base[4] = { 0, };
	// 첫번째 선수
	int startPlayer = 1;
	// 총 점
	int score = 0;

	// N번(이닝의 수)만큼 게임을 진행
	for (int i = 1; i <= N; ++i) {
		int outCnt = 0;
		bool next = false;
		memset(base, 0, sizeof(base));

		while (true) {
			//1번 타자 부터 9번 타자까지
			for (int j = startPlayer; j <= 9; ++j) {
				int nowPlayer = innings[i][order[j]];

				if (nowPlayer == 0) {
					++outCnt;
				}
				//안타일때
				else if (nowPlayer == 1) {
					for (int player = 3; player >= 1; --player) {
						if (base[player]) {
							if (player == 3) {
								base[player] = 0;
								++score;
							}
							else {
								base[player + 1] = 1;
								base[player] = 0;
							}
						}
					}

					base[1] = 1;
				}
				// 2루타일 때
				else if (nowPlayer == 2) {
					for (int player = 3; player >= 1; --player) {
						if (base[player]) {
							if (player == 3 || player == 2) {
								base[player] = 0;
								++score;
							}
							else {
								base[player + 2] = 1;
								base[player] = 0;
							}
						}
					}

					base[2] = 1;
				}
				// 3루타일 때
				else if (nowPlayer == 3) {
					for (int player = 3; player >= 1; --player) {
						if (base[player]) {
							base[player] = 0;
							++score;
						}
					}

					base[3] = 1;
				}
				//홈런일 경우
				else if (nowPlayer == 4) {
					for (int player = 3; player >= 1; --player) {
						if (base[player]) {
							base[player] = 0;
							++score;
						}
					}

					++score;
				}
				if (outCnt == 3) {
					next = true;
					startPlayer = j + 1;
					//startPlayer가 10번이어야만 9번타자까지 모두 공을 친 것이다. 
					if (startPlayer == PLAYER_NUM) {
						startPlayer = 1;
					}
					break;
				}
			}

			if (next) {
				break;
			}

			startPlayer = 1;
		}
	}

	result = max(result, score);
}