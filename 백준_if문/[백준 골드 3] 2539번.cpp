// 이분 탐색, 파아메트릭 서치
// 파라메트릭 서치(parametric search) : 최적화 기법을 결정 문제로 바꾸어 해결하는 기법이다.
// -> 이분 탐색으로 결정 문제를 해결하면서 범위를 좁혀나갈 수 있다.

// 문제에서 주어진 조건으로 
// 1. 색종이들은 크기가 모두 같은 '정사각형' 이라는 조건과
// 2. 모든 색종이들은 도화지의 '밑변'에 맞추어 붙인다.
// 위의 2개의 조건을 활용하면 문제를 쉽게 풀 수 있다.

// 처음에는 x좌표와 y좌표를 따로 처리해서 구해줘야 하나 하고, 생각이 깊어졌는데
// 도화지의 밑변에 맞추어야 한다는 조건으로 그럴 필요가 없어졌다.

// 잘못 칠해진 색종이들의 좌표를 받을 때, 그때의 x좌표의 최대값을 구해주면, 
// 그것이 색종이의 최소 크기가 되고, x좌표에 대한 처리가 끝나게 된다.

// 그러면 이제 y좌표가 남는데, y좌표에 대해 파라메트릭 서치를 진행하면 된다.
// 맨 첫번째 좌표는 무조건 포함해야 하므로, 초기값을 맨 처음 y좌표를 설정해주고
// 두 번째 좌표부터 '현재 좌표 부터 한변의 길이를 더했을 때 다음 좌표가 더 크거나 같다면' 
// 새로운 색종이가 필요한 것이므로 색종이 수를 1개 늘리고, 좌표도 바꿔준다.

// 결정 문제 부분 : 
// 구한 색종이수가 필요한 색종이 수 보다 작다면, 한변의 길이를 너무 크게 잡은 것이므로, 길이를 작게 해준다(mid - 1)
// 반대로 색종이 수보다 크거나 같다면 알맞게 했거나 더 작게 잡은 것이므로, 답을 저장하고, 한변의 길이를 더 크게 해준다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M, usePaper, wrongPaintedNumber;
vector<int> arr;

int main() {
	cin >> N >> M >> usePaper >> wrongPaintedNumber;

	int maxX = 0;

	for (int i = 0; i < wrongPaintedNumber; ++i) {
		int x, y;
		cin >> x >> y;
		arr.push_back(y);
		// 잘못 칠해진 색종이들의 좌표를 받을 때, 그때의 x좌표의 최대값을 구해주면, 
		// 그것이 색종이의 최소 크기가 되고, x좌표에 대한 처리가 끝나게 된다.
		maxX = max(maxX, x);
	}

	sort(arr.begin(), arr.end());

	// 최소는 x좌표의 최대값이고, 최대는 열의 최대 크기이다.
	int start = maxX, end = 100000, result = 0;

	while (start < end) {
		int cnt = 1;

		int value = arr[0];

		int mid = (start + end) / 2;

		for (int i = 1; i < wrongPaintedNumber; ++i) {
			if (value + mid <= arr[i]) {
				value = arr[i];
				++cnt;
			}
		}
	
		if (cnt <= usePaper) {
			result = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}