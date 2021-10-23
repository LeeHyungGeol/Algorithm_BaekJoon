#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef struct fireball {
	int x, y, m, s, d;
}fireball;

int n, m, k, answer;
const int dx[] = { -1,-1,0,1,1,1,0,-1 };
const int dy[] = { 0,1,1,1,0,-1,-1,-1 };
deque<fireball> arr[51][51];
deque<fireball> fireballs;

void movefireball();
void splitfireball();

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireballs.push_back({ r,c,m,s,d });
	}
	
	while (k--) {
		movefireball();
		splitfireball();
	}

	for (int i = 0; i < fireballs.size(); ++i) {
		answer += fireballs[i].m;
	}

	cout << answer << '\n';

	return 0;
}

void movefireball() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			arr[i][j].clear();
		}
	}

	for (int i = 0; i < fireballs.size(); ++i) {
		fireball cur = fireballs[i];
		int move = cur.s % n;
		int nx = cur.x + (dx[cur.d] * move);
		int ny = cur.y + (dy[cur.d] * move);

		if (nx < 1) nx += n;
		if (ny < 1) ny += n;
		if (nx > n) nx -= n;
		if (ny > n) ny -= n;

		arr[nx][ny].push_back({ nx,ny,cur.m, cur.s, cur.d });
	}

	return;
}

void splitfireball() {
	deque<fireball> temp;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int size = arr[i][j].size();

			if (size == 0) continue;
			else if (size == 1) {
				temp.push_back(arr[i][j][0]);
			}
			else {
				int msum = 0, ssum = 0;
				bool odd = true, even = true;

				for (int k = 0; k < size; ++k) {
					msum += arr[i][j][k].m;
					ssum += arr[i][j][k].s;

					if (arr[i][j][k].d % 2) {
						even = false;
					}
					else {
						odd = false;
					}
				}

				msum /= 5;
				ssum /= size;

				if (msum == 0) continue;
				if (odd || even) {
					temp.push_back({ i,j,msum, ssum, 0 });
					temp.push_back({ i,j,msum, ssum, 2 });
					temp.push_back({ i,j,msum, ssum, 4 });
					temp.push_back({ i,j,msum, ssum, 6 });
				}
				else {
					temp.push_back({ i,j,msum, ssum, 1 });
					temp.push_back({ i,j,msum, ssum, 3 });
					temp.push_back({ i,j,msum, ssum, 5 });
					temp.push_back({ i,j,msum, ssum, 7 });
				}
			}
		}
	}

	fireballs = temp;

	return;
}

//----------------2번째 풀이-------------------//

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
int makeRange(int n);

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
		int nx = cur.x;
		int ny = cur.y;

		for (int j = 0; j < cur.s; ++j) {
			nx += Dx[cur.d];
			ny += Dy[cur.d];
			nx = makeRange(nx);
			ny = makeRange(ny);
		}

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

int makeRange(int n) {
	if (n < 1) return N;
	if (n > N) return 1;
	return n;
}