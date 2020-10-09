#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> movieName;
	int N;
	cin >> N;
	if (N == 1) {
		for (int i = 0; i < 3; ++i)
			movieName.push_back(6);
		for (int i = 0; i < movieName.size(); ++i)
			cout << movieName[i];
		return 0;
	}
	else {
		movieName.push_back(N - 1);
		for (int i = 0; i < 3; ++i)
			movieName.push_back(6);
		for (int i = 0; i < movieName.size(); ++i)
			cout << movieName[i];
	}
	return 0;
}