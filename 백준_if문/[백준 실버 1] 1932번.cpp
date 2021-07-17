// dp����
// �� ���� ��� ĭ���� �ִ��� �����ϸ鼭 ���� ��ȹ������ Ǫ�� ����

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer;
vector<vector<int>> arr;

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		vector<int> tmpArr;
		
		for (int j = 0; j <= i; ++j) {
			int temp;
			cin >> temp;
			tmpArr.push_back(temp);
		}

		arr.push_back(tmpArr);
	}

	answer = arr[0][0];

	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			int left;
			int right;

			if (j - 1 < 0) {
				left = 0;
			}
			else {
				left = arr[i - 1][j - 1];
			}
			if (j > i-1) {
				right = 0;
			}
			else {
				right = arr[i - 1][j];
			}

			arr[i][j] = arr[i][j] + max(left, right);
		}
	}

	for (int i = 0; i < n; ++i) {
		answer = max(answer, arr[n - 1][i]);
	}
	
	cout << answer << '\n';

	return 0;
}