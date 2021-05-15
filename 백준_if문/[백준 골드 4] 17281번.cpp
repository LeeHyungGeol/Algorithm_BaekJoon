#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const static int PLAYER_NUM = 10;

int N, result;
int innings[51][PLAYER_NUM] = { 0, };
// 4�� Ÿ�ڴ� ���õǾ���.
int order[PLAYER_NUM] = { 0, };
// 4�� Ÿ�ڴ� 1�� �����̴�.
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

	// 4�� ������ ���õǾ���.
	Select[4] = true;
	// 4�� Ÿ�ڴ� 1�� �����̴�.
	order[4] = 1;
	// 2�� ���� ���� ������ �����ش�.
	dfs(2);

	cout << result << '\n';

	return 0;
}

void dfs(int cnt) {
	// cnt �� ���� 10�̾�� 1�� ���� 9�� �������� ������ ��� ���� ��
	if (cnt == PLAYER_NUM) {
		//������ ������ ���� ������ �����Ѵ�.
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
	//Ȩ, 1��, 2��, 3��
	int base[4] = { 0, };
	// ù��° ����
	int startPlayer = 1;
	// �� ��
	int score = 0;

	// N��(�̴��� ��)��ŭ ������ ����
	for (int i = 1; i <= N; ++i) {
		int outCnt = 0;
		bool next = false;
		memset(base, 0, sizeof(base));

		while (true) {
			//1�� Ÿ�� ���� 9�� Ÿ�ڱ���
			for (int j = startPlayer; j <= 9; ++j) {
				int nowPlayer = innings[i][order[j]];

				if (nowPlayer == 0) {
					++outCnt;
				}
				//��Ÿ�϶�
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
				// 2��Ÿ�� ��
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
				// 3��Ÿ�� ��
				else if (nowPlayer == 3) {
					for (int player = 3; player >= 1; --player) {
						if (base[player]) {
							base[player] = 0;
							++score;
						}
					}

					base[3] = 1;
				}
				//Ȩ���� ���
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
					//startPlayer�� 10���̾�߸� 9��Ÿ�ڱ��� ��� ���� ģ ���̴�. 
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