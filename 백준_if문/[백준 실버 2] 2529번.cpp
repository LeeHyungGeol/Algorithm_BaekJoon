// 순열(permutation), 완전탐색

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int K;
vector<int> Nums = { 0,1,2,3,4,5,6,7,8,9 };
vector<int> SelectedNums;
vector<bool> Select;
vector<char> Infos;
vector<string> Answers;

void dfs(int cnt);

int main() {
	cin >> K;

	for (int i = 0; i < K; ++i) {
		char c;
		cin >> c;
		Infos.push_back(c);
	}

	Select.resize(10, false);

	dfs(0);
	
	cout << Answers[(int)Answers.size() - 1] << '\n';
	cout << Answers[0] << '\n';
	
	return 0;
}

void dfs(int cnt) {
	if (cnt == K + 1) {
		string result = to_string(SelectedNums[0]);

		for (int i = 0; i < Infos.size(); ++i) {
			char op = Infos[i];
			if(op == '<') {
				if (SelectedNums[i] < SelectedNums[i + 1]) {
					result += to_string(SelectedNums[i + 1]);
				}
				else {
					break;
				}
			}
			else if (op == '>') {
				if (SelectedNums[i] > SelectedNums[i + 1]) {
					result += to_string(SelectedNums[i + 1]);
				}
				else {
					break;
				}
			}
		}

		if (result.length() == K + 1) {
			Answers.push_back(result);
		}
		return;
	}

	for (int i = 0; i < Nums.size(); ++i) {
		if (Select[i]) {
			continue;
		}
		Select[i] = true;
		SelectedNums.push_back(Nums[i]);
		dfs(cnt + 1);
		SelectedNums.pop_back();
		Select[i] = false;
	}
}