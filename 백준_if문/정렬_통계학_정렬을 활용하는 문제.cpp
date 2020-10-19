#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//typedef pair<int, int> pii;
//#define number first
//#define cnt second
//vector<pii> info(8001);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> numV, cntV, tmpV(8001);
	int N, input, sum = 0, max = -4000, min = 4000;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		if (input > max)
			max = input;
		if (input < min)
			min = input;
		sum += input;
		numV.push_back(input);
		if (input < 0) {
			tmpV[4000 + abs(input)] = input;
			cntV[4000 + abs(input)]++;
		}
		else {
			tmpV[input] = input;
			cntV[input]++;
		}
	}
	sort(cntV.begin(), cntV.end());
	int n = cntV.size();
	cout << cntV[n] << '\n';
	for (int i = 0; i < N; ++i) {
		
	}
	sort(numV.begin(), numV.end());
	cout << round((double)sum / N) << '\n';
	cout << numV[N / 2] << '\n';


	cout << max - min << '\n';

	return 0;
}