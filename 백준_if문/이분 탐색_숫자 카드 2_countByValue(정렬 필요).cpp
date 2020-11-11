#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countByValue(vector<int>& v, int target);
int first(vector<int>& v, int target, int start, int end);
int last(vector<int>& v, int target, int start, int end);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	cin >> M;

	sort(v.begin(), v.end());
	for (int i = 0; i < M; ++i) {
		cin >> x;
		cout << countByValue(v, x) << ' ';
	}
	cout << '\n';
	return 0;
}
int countByValue(vector<int>& v, int target) {
	int n = v.size();
	//target�� ó�� ������ �ε��� �� ����
	int firstIndex = first(v, target, 0, n - 1);
	if (firstIndex == -1) //�迭�� ���Ұ� �������� �ʴ� ��� 0�� ����
		return 0;
	//target�� ���������� ������ �ε��� �� ����
	int lastIndex = last(v, target, 0, n - 1);

	return lastIndex - firstIndex + 1;
}
int first(vector<int>& v, int target, int start, int end) {
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if ((mid == 0 || target > v[mid - 1]) && v[mid] == target)//target���� ������ ���� �߿��� ���� ���ʿ� �ִ� ��쿡�� �ε��� ���� ����
		return mid;
	else if (v[mid] >= target) // >= // �߰� ���� ������ target���� �۰ų� ���� ��쿡 ������ Ȯ�� 
		return first(v, target, start, mid - 1);
	else
		return first(v, target, mid + 1, end); //�߰� ���� ������ target���� ū ��쿡 �������� Ȯ�� 
}
int last(vector<int>& v, int target, int start, int end) {
	if (start > end)
		return -1;
	int n = v.size();
	int mid = (start + end) / 2;
	if ((mid == n - 1 || target < v[mid + 1]) && v[mid] == target) //target���� ������ ���� �߿��� ���� ���� �ʿ� �ִ� ��쿡�� �ε��� ���� ����
		return mid;
	else if (v[mid] > target) // �߰� ���� ������ target���� �۰ų� ���� ��쿡 ������ Ȯ��
		return last(v, target, start, mid - 1); 
	else
		return last(v, target, mid + 1, end); //�߰� ���� ������ target���� ū ��쿡 �������� Ȯ��
}