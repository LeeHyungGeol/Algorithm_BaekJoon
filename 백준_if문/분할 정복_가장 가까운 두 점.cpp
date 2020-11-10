//https://casterian.net/archives/92
//http://chanhaeng.blogspot.com/2018/07/divide-and-conquer-closest-pair-of.html
//https://letsgoturing.tistory.com/69
//---���� ����� ������ �� ã�� (Divide and Conquer, Closest Pair of Points)---
//�켱 x�� ���� ������������ ������ �մϴ�.
//�� ���� ��� ���� �������� �����ʰ� ������ �����ϰ�,
//�����ʰ� ���ʿ� ���ؼ� ���� ����� �� �� ���� �Ÿ��� ã���ϴ�.
//�׸��� ��� �߽����� �������� �����ʰ� ���ʿ� ���ؼ� ���� ã�� ���� ����� �� �� ���� �Ÿ� �� ���� �Ϳ� ���� 
//�� �Ÿ� ��ŭ x, y��ȿ� �����ϴ� ���鿡 ���� �̺��� �� ����� ������ �����ϴ��� �˻��մϴ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define X first
#define Y second
vector<pii> varr;
int n;
int divideAndConquer(int first, int last);
int dist(const pii& a, const pii& b);
bool compare(const pii& a, const pii& b);

int main() {

	int x, y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		varr.push_back(make_pair(x, y));
	}
	sort(varr.begin(), varr.end()); //x��ǥ�� �������� �������� ����
	int answer = divideAndConquer(0, n - 1);
	cout << answer << '\n';

	return 0;
}
int divideAndConquer(int first, int last) {
	if ((last - first) == 1)//���� 2���� ��
		return dist(varr[first], varr[last]);
	if ((last - first) == 2)//���� 3���� ��
		return min(
				dist(varr[first], varr[first + 1]),

			min(dist(varr[first + 1], varr[first + 2]), 

				dist(varr[first], varr[first + 2])));

	int mid = (int)(last + first) / 2; //�߰� ��(���ؼ�) ���
	int dl = divideAndConquer(first, mid); //�߰� �� ���� ������ �ּҰŸ�
	int dr = divideAndConquer(mid + 1, last); //�߰� �� ���� �������� �ּҰŸ�
	int distanceMin = min(dl, dr);  //���� ���� ������ �� �� �� ���� ��

	//�߰� ��(���ؼ�) �������� ��, �쿡 �ϳ��� ���� �ִ� ��� ó��
	vector<pii> tmp;
	int d = 0;
	for (int i = first; i < mid; ++i) { // ���ؼ��� �߽����� �¿� �Ÿ� distanceMin �̳��� ������ �������� ���ϱ� ���� 
		d = varr[i].X - varr[mid].X; //x��ǥ�� �������� distanceMin ���� �ִ��� Ȯ��
		if (d * d < distanceMin)
			tmp.push_back(varr[i]);
		
	}
	for (int i = mid + 1; i <= last; ++i) { // ���ؼ��� �߽����� �¿� �Ÿ� distanceMin �̳��� ������ �������� ���ϱ� ���� 
		d = varr[i].X - varr[mid].X; //x��ǥ�� �������� distanceMin ���� �ִ��� Ȯ��
		if (d * d < distanceMin)
			tmp.push_back(varr[i]);

	}

	int length = tmp.size();
	sort(tmp.begin(), tmp.end(), compare); //y��ǥ�� �������� �������� ����
	//for (int i = 0; i < length - 1; ++i) {
	//	for (int j = i + 1; j < length; ++j) {
	//		d = tmp[j].Y - tmp[i].Y;
	//	
	//		/*cout << "(" << tmp[i].X << " ," << tmp[i].Y << ") vs"
	//			<< "(" << tmp[j].X << " ," << tmp[j].Y << ")" << endl;
	//		
	//		cout << d << " Vs " << distanceMin << endl;*/
	//		
	//		if (d * d < distanceMin)
	//			distanceMin = min(distanceMin, dist(tmp[i], tmp[j]));
	//		else
	//			break;
	//	}
	//}
	for (int i = 0; i < length - 1; ++i) {
		for (int j = i + 1; j < length && (tmp[j].Y - tmp[i].Y) * (tmp[j].Y - tmp[i].Y) < distanceMin; ++j) {
				distanceMin = min(distanceMin, dist(tmp[i], tmp[j]));
		}
	}
	return distanceMin;
}
int dist(const pii& a, const pii& b) { // �� �� ������ �Ÿ� ���ϴ� �Լ�
	int x = a.X - b.X;
	int y = a.Y - b.Y;
	return x * x + y * y;
}
bool compare(const pii& a, const pii& b) { //y��ǥ�� �������� �������� ����
	if (a.second == b.second) 
		return a.first < b.first;
	return a.second < b.second;
}