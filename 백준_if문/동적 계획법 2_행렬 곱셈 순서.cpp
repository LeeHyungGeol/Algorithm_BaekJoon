//���̳��� ���α׷���(Dynamic Programming): ���� ��ȹ�� - "�ߺ��Ǵ� ������ ������"
// 1. ū ������ ���� ������ ���� �� �ִ�.
// 2. ���� �������� ���� ������ �װ��� �����ϴ� ū ���������� �����ϴ�.

//��� ����� ���ϴµ� �ʿ��� ���� ���� Ƚ���� �ּڰ��� ���ϴ� ���α׷�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<pair<int, int>> arr; //����� ũ�� r�� c (1 �� r, c �� 500)
	int N, r, c;//����� ���� N(1 �� N �� 500)
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> r >> c;
		arr.push_back(make_pair(r, c));
	}
	
	return 0;
}