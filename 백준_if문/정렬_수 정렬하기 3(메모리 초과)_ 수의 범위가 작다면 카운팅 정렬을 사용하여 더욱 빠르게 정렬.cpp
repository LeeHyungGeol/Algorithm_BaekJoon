#include <iostream>
using namespace std;
/*
ī��������(Counting Sort) - ���� ���ؼ� �����ϴ� ����̶�� ���ٴ� ���� ������ ���� �� ������ ���� ��ġ�� �������ִ� ���
��, �����͵鰣�� ũ�⸦ ���ϰų� �׷� ���� ����� �ƴϴ�.
https://bowbowbow.tistory.com/8
*/
int main() {

	int N, countNum[10001] = { 0 }, countSum[10001];
	cin >> N;
	int* arr = new int[N];
	int* sortedArray = new int[N];

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		countNum[arr[i]]++;
	}

	//������ ����
	countSum[0] = countNum[0];
	for (int i = 1; i <= N; ++i) {
		countSum[i] = countSum[i - 1] + countNum[i];
	}

	for (int i = N; i >= 1; --i) {
		sortedArray[countSum[arr[i]]] = arr[i];
		countSum[arr[i]]--;
	}

	for (int i = 1; i <= N; ++i) {
		cout << sortedArray[i] << '\n';
	}

	delete[] arr;
	delete[] sortedArray;

	return 0;
}