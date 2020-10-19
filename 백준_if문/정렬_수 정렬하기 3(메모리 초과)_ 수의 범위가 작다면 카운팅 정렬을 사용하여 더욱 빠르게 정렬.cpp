#include <iostream>
using namespace std;
/*
카운팅정렬(Counting Sort) - 값을 비교해서 정렬하는 방식이라기 보다는 값의 갯수를 세고 그 갯수에 따라서 위치를 설정해주는 방식
즉, 데이터들간의 크기를 비교하거나 그런 정렬 방식이 아니다.
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

	//누적합 구성
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