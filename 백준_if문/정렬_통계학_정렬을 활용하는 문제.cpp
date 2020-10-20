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
		cout << round((double)sum / (double)N) << '\n'; //������ ���//N���� ������ ���� N���� ���� ��

	cout << numV[N / 2] << '\n';//�߾Ӱ� ���// N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
	
	if (cntV.size() > 1) {
		if (cntV[cntV.size() - 1].second == cntV[cntV.size() - 2].second)
			cout << cntV[cntV.size() - 2].first << '\n';//�ֺ� �� �� ��°�� ���� ���� ����Ѵ�.
		else
			cout << cntV[cntV.size() - 1].first << '\n';//�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
	}
	else
		cout << cntV[cntV.size() - 1].first << '\n';//�ֺ� ���//�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
	
	cout << max - min << '\n';//���� ���//���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����

	return 0;
}
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) //������ ������ ���ٸ� 
		return a.first > b.first; //������ ũ�⸦ �������� �������� ����
	return a.second < b.second; //������ ������ �������� �������� ����
}