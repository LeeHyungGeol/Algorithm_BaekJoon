#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef struct Fireball {
	int x, y, m, s, d;
}Fireball;

int N, M, K, Answer;
const int Dx[] = { -1,-1,0,1,1,1,0,-1 };
const int Dy[] = { 0,1,1,1,0,-1,-1,-1 };
deque<Fireball> Arr[51][51];
deque<Fireball> Fireballs;

void moveFireball();
void splitFireball();

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; ++i) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		Fireballs.push_back({ r,c,m,s,d });
	}
	
	while (K--) {
		moveFireball();
		splitFireball();
	}

	for (int i = 0; i < Fireballs.size(); ++i) {
		Answer += Fireballs[i].m;
	}

	cout << Answer << '\n';

	return 0;
}

void moveFireball() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			Arr[i][j].clear();
		}
	}

	for (int i = 0; i < Fireballs.size(); ++i) {
		Fireball cur = Fireballs[i];
		int nx = cur.x + (Dx[cur.d] * cur.s);
		int ny = cur.y + (Dy[cur.d] * cur.s);

		while (nx < 1) nx += N; 
		while (ny < 1) ny += N;
		while (nx > N) nx -= N;
		while (ny > N) ny -= N;

		Arr[nx][ny].push_back({ nx,ny,cur.m, cur.s, cur.d });
	}

	return;
}

void splitFireball() {
	deque<Fireball> temp;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int size = Arr[i][j].size();

			if (size == 0) continue;
			else if (size == 1) {
				temp.push_back(Arr[i][j][0]);
			}
			else {
				int mSum = 0, sSum = 0;
				bool odd = true, even = true;

				for (int k = 0; k < size; ++k) {
					mSum += Arr[i][j][k].m;
					sSum += Arr[i][j][k].s;

					if (Arr[i][j][k].d % 2) {
						even = false;
					}
					else {
						odd = false;
					}
				}

				mSum /= 5;
				sSum /= size;

				if (mSum == 0) continue;
				if (odd || even) {
					temp.push_back({ i,j,mSum, sSum, 0 });
					temp.push_back({ i,j,mSum, sSum, 2 });
					temp.push_back({ i,j,mSum, sSum, 4 });
					temp.push_back({ i,j,mSum, sSum, 6 });
				}
				else {
					temp.push_back({ i,j,mSum, sSum, 1 });
					temp.push_back({ i,j,mSum, sSum, 3 });
					temp.push_back({ i,j,mSum, sSum, 5 });
					temp.push_back({ i,j,mSum, sSum, 7 });
				}
			}
		}
	}

	Fireballs = temp;

	return;
}