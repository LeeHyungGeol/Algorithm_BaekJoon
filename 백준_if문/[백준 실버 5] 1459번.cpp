// [����] https://kingsubin.tistory.com/95

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll X, Y, W, S, Case1, Case2, Case3, Answer;

int main() {
    cin >> X >> Y >> W >> S;

    // 1. �������θ� �̵��ϴ� ���
    Case1 = (X + Y) * W;

    // 2. �밢�����θ� �̵��ϴ� ���
    // 2-1. ¦���� ��� �밢�����θ� �̵� ����
    // 2-2. Ȧ���� ��� �밢�� �̵� �� �����̵� 1ĭ
    if ((X + Y) % 2 == 0) Case2 = max(X, Y) * S;
    else Case2 = ((max(X, Y) - 1) * S) + W;

    // 3. �밢�� + ���� : �밢������ �ִ��� �̵� �� ���� �̵�
    Case3 = (min(X, Y) * S) + (abs(X - Y) * W);

    Answer = min(Case1, min(Case2, Case3));

    cout << Answer << '\n';

    return 0;

}