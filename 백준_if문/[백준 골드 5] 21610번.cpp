#include <iostream>
#include <vector>

using namespace std;

typedef struct Cloud {
	int x, y;
}Cloud;
typedef pair<int, int> pii;

int N, M, Answer;
const int Dx[] = { 0,0,-1,-1,-1,0,1,1,1 };
const int Dy[] = { 0,-1,-1,0,1,1,1,0,-1 };
vector<vector<int>> Arr;
vector<Cloud> Clouds;
vector<pii> WaterAddedSpots;

void wantRain(int d, int s);
void waterCopyBug();
int makeRange(int n);
void print() {
	cout << '\n';
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << Arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	cin >> N >> M;

	Arr.assign(N + 1, vector<int>(N + 1, 0));
	Clouds.push_back({ N,1 });
	Clouds.push_back({ N,2 });
	Clouds.push_back({ N - 1,1 });
	Clouds.push_back({ N - 1,2 });

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> Arr[i][j];
		}
	}

	int d, s;

	while (M--) {
		cin >> d >> s;
		wantRain(d, s);
		waterCopyBug();
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			Answer += Arr[i][j];
		}
	}

	cout << Answer << '\n';

	return 0;
}

void wantRain(int d, int s) {
	WaterAddedSpots.clear();

	for (int i = 0; i < Clouds.size(); ++i) {
		Cloud cloud = Clouds[i];
		int nx = cloud.x;
		int ny = cloud.y;

		for (int j = 0; j < s; ++j) {
			nx += Dx[d];
			ny += Dy[d];
			nx = makeRange(nx);
			ny = makeRange(ny);
		}

		Arr[nx][ny] += 1;
		WaterAddedSpots.push_back({ nx,ny });
		Clouds[i].x = nx;
		Clouds[i].y = ny;
	}
}

void waterCopyBug() {
	int dx[] = { -1,-1,1,1 };
	int dy[] = { -1,1,-1,1 };
	vector<Cloud> temp;

	for (pii cur : WaterAddedSpots) {
		int cnt = 0;
		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (!(1 <= nx && nx <= N && 1 <= ny && ny <= N)) continue;
			if (Arr[nx][ny] != 0) ++cnt;
		}
		Arr[cur.first][cur.second] += cnt;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (Arr[i][j] >= 2) {
				bool isExist = false;
				for (Cloud cur : Clouds) {
					if (i == cur.x && j == cur.y) isExist = true;
				}
				if (!isExist) {
					temp.push_back({ i,j });
					Arr[i][j] -= 2;
				}
			}
		}
	}

	Clouds = temp;
}

int makeRange(int n) {
	if (n < 1) return N;
	if (n > N) return 1;
	return n;
}