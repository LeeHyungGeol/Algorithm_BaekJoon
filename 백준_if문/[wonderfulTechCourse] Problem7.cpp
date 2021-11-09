#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int X, Y;

int main() {
	vector<string> grid = { "1","234", "56789","ABCDEFG" };
	bool clockWiese = true;

	vector<string> answer = solution(grid, clockWiese);

	for (string s : answer) {
		cout << s << '\n';
	}

	return 0;
}

vector<string> solution(vector<string> grid, bool clockWise) {
	vector<string> result;

	if (clockWise) {
		int sx = grid.size() - 1, sy = 0;

		
	}
	else {
		int sx = grid.size() - 1, sy = grid[grid.size() - 1][grid.back().length() - 1];

		
	}
}