// dp����
// (���� �ǹ� 1) ���� �ﰢ��(1932��) �� �ſ� ������ ����
// (���� ��� 5) ���� ū ���簢��(1915��) �� �Ȱ��� ���� 

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, answer;
vector<vector<int>> arr;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		vector<int> tmpArr;
		
		for (int j = 0; j < m; ++j) {
			int temp;
			scanf("%1d", &temp);
			tmpArr.push_back(temp);
		}

		arr.push_back(tmpArr);
	}

	answer = arr[0][0];

	for (int i = 1; i < arr.size(); ++i) {
		for (int j = 1; j < arr[0].size(); ++j) {
			if (arr[i][j]) {
				arr[i][j] = min(arr[i - 1][j - 1], min(arr[i][j - 1], arr[i - 1][j])) + 1;
				answer = max(answer, arr[i][j]);
			}
		}
	}

	cout << answer * answer << '\n';

	return 0;
}