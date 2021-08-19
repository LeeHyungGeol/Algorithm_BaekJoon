#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate90degree(vector<vector<int>> arr);

int main() {
	
	return 0;
}

vector<vector<int>> rotate90degree(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> result(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[j][n - i - 1] = arr[i][j];
        }
    }

    return result;
}