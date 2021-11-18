#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W, Left, Right, Answer;
vector<int> Arr;

int getLeftMax(int index);
int getRightMax(int index);

int main() {
	cin >> H >> W;

	for (int i = 0, height; i < W; ++i) {
		cin >> height;
		Arr.push_back(height);
	}

	for (int i = 0; i < W; ++i) {
		if (i == 0 || i == W - 1) continue;
		int height = min(getLeftMax(i), getRightMax(i));
		if(height > Arr[i]) Answer += height - Arr[i];
	}

	cout << Answer << '\n';

	return 0;
}

int getLeftMax(int index) {
	int h = 0;
	for (int i = 0; i < index; ++i) h = max(h, Arr[i]);
	return h;
}

int getRightMax(int index) {
	int h = 0;
	for (int i = index+1; i < Arr.size(); ++i) h = max(h, Arr[i]);
	return h;
}