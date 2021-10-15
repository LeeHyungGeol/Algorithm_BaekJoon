#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// bool operator < 의 우선순위는 bool compare의 반대이다.
typedef struct Info {
	int x, y, blanks, friends;

	bool operator < (const Info& other) const {
		if (friends == other.friends) {
			if (blanks == other.blanks) {
				if (x == other.x) {
					return y > other.y;
				}
				else {
					return x > other.x;
				}
			}
			else {
				return blanks < other.blanks;
			}
		}
		else {
			return friends < other.friends;
		}
	}
}Info;

typedef struct Student {
	int id, x,y,likes[4];
}Student;

int N, Answer = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int Score[] = { 0,1,10,100,1000 };
vector<vector<int>> Arr;
vector<Student> Students;

int main() {
	cin >> N;

	Arr.resize(N, vector<int>(N, 0));
	Students.resize(N * N);

	for (int i = 0; i < N*N; ++i) {
		cin >> Students[i].id;
		for (int j = 0; j < 4; ++j) {
			cin >> Students[i].likes[j];
		}
	}

	for (int n = 0; n < N * N; ++n) {
		priority_queue<Info> pq;

		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < N; ++y) {
				if (Arr[x][y] == 0) {
					int blankCnt = 0, friendCnt = 0;

					for (int i = 0; i < 4; ++i) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (0 <= nx && nx < N && 0 <= ny && ny < N) {
							if (Arr[nx][ny] == 0) {
								++blankCnt;
							}
							else {
								for (int k = 0; k < 4; ++k) {
									if(Arr[nx][ny] == Students[n].likes[k]) {
										++friendCnt;
										// break;
									}
								}
							}
						}
					}

					pq.push({ x,y,blankCnt, friendCnt });
				}
			}
		}

		if (!pq.empty()) {
			int x = pq.top().x;
			int y = pq.top().y;

			Arr[x][y] = Students[n].id;
			Students[n].x = x;
			Students[n].y = y;
		}
	}

	for (int n = 0; n < N * N; ++n) {
		int x = Students[n].x;
		int y = Students[n].y;

		int cnt = 0;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				for (int j = 0; j < 4; ++j) {
					if (Arr[nx][ny] == Students[n].likes[j]) {
						++cnt;
					}
				}
			}
		}
		Answer += Score[cnt];
	}

	cout << Answer << '\n';

	return 0;
}