#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

//typedef pair<int, int> pii;
//#define number first
//#define cnt second
//vector<pii> cntInfo;
bool compare(const pair<int, int>& a, const pair<int, int>& b);
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> cntV;
	vector<int> numV, tmpV(8001);
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
			tmpV[4000 + abs(input)]++;
		}
		else
			tmpV[input]++;
	}

	for (int i = 0; i < tmpV.size(); ++i) {
		if (i > 4000 && tmpV[i] != 0) {
			cntV.push_back(make_pair(-(i-4000), tmpV[i]));
		}
		else if (tmpV[i] != 0) {
			cntV.push_back(make_pair(i, tmpV[i]));
		}
	}

	sort(cntV.begin(), cntV.end(), compare);
	sort(numV.begin(), numV.end());

	if (round((double)sum / (double)N) == -0) 
		cout << "0" << '\n';
	else 
		cout << round((double)sum / (double)N) << '\n'; //산술평균 출력//N개의 수들의 합을 N으로 나눈 값

	cout << numV[N / 2] << '\n';//중앙값 출력// N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	
	if (cntV.size() > 1) {
		if (cntV[cntV.size() - 1].second == cntV[cntV.size() - 2].second)
			cout << cntV[cntV.size() - 2].first << '\n';//최빈값 중 두 번째로 작은 값을 출력한다.
		else
			cout << cntV[cntV.size() - 1].first << '\n';//최빈값 : N개의 수들 중 가장 많이 나타나는 값
	}
	else
		cout << cntV[cntV.size() - 1].first << '\n';//최빈값 출력//최빈값 : N개의 수들 중 가장 많이 나타나는 값
	
	cout << max - min << '\n';//범위 출력//범위 : N개의 수들 중 최댓값과 최솟값의 차이

	return 0;
}
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) //숫자의 갯수가 같다면 
		return a.first > b.first; //숫자의 크기를 기준으로 오름차순 정렬
	return a.second < b.second; //숫자의 갯수를 기준으로 내림차순 정렬
}