#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // ���� ���� N(2 �� N �� 11)
vector<int> number;// (1 �� Ai �� 100)
int operation[4] = { 0 }; //���� N-1�� 4���� ����, ���ʴ�� ����(+)�� ����, ����(-)�� ����, ����(��)�� ����, ������(��)�� ����
int Min = 100000000, Max = -1000000000;
void backtracking(int i, int result);
int operate(int op, int x, int cur);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, result = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		number.push_back(input);
	}
	cin >> operation[0] >> operation[1] >> operation[2] >> operation[3];

	backtracking(0, number[0]);
	
	cout << Max << '\n' << Min << '\n';
	
	return 0;
}
void backtracking(int x, int result) {
	if (x == number.size()-1) {
		if (result > Max)
			Max = result;
		if (result < Min)
			Min = result;
		return;
	}
	
	for (int i = 0; i < 4; ++i) {
		if (operation[i] != 0) {
			operation[i]--;  
			backtracking(x + 1, operate(i, x + 1, result));
			operation[i]++;
		}
	}
}
int operate(int op, int x, int cur) {
	int ret = 0;
	if (op == 0)
		ret = cur + number[x];
	else if (op == 1)
		ret = cur - number[x];
	else if (op == 2)
		ret = cur * number[x];
	else if (op == 3)
		ret = cur / number[x];
	return ret;
}
