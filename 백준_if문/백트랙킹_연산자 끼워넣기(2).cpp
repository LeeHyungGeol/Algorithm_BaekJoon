#include <iostream>
using namespace std;

int N, Max = -1000000000, Min = 1000000000;
int num[11] = { 0 };//2 ¡Â N ¡Â 11
int operation[4] = { 0 };
void backtracking(int cnt, int result);

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	cin >> operation[0] >> operation[1] >> operation[2] >> operation[3];

	int result = num[0];
	backtracking(1, result);

	cout << Max << '\n' << Min << '\n';
	return 0;
}
void backtracking(int cnt, int result) {
	if (cnt == N) {
		if (result > Max)
			Max = result;
		if (result < Min)
			Min = result;
		return;
	}

	if (operation[0] != 0) {
		result += num[cnt];
		operation[0]--;
		backtracking(cnt + 1, result);
		operation[0]++;
		result -= num[cnt];
	}

	if (operation[1] != 0) {
		result -= num[cnt];
		operation[1]--;
		backtracking(cnt + 1, result);
		operation[1]++;
		result += num[cnt];
	}

	if (operation[2] != 0) {
		result *= num[cnt];
		operation[2]--;
		backtracking(cnt + 1, result);
		operation[2]++;
		result /= num[cnt];
	}

	if (operation[3] != 0) {
		result /= num[cnt];
		operation[3]--;
		backtracking(cnt + 1, result);
		operation[3]++;
		result *= num[cnt];
	}
	
}