#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> Arr;
vector<int> Temp;

int main() {
	cin >> N;

	Arr.assign(N + 1, vector<int>(N + 1, 0));
	Temp.assign(N + 1, 0);

	rotateLeftDiagnol();
	rotateCenterRow();
	rotateRightDiagnol();
	rotateCenterColumn();

	return 0;
}