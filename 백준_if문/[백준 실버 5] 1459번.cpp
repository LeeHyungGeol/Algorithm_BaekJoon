// [참고] https://kingsubin.tistory.com/95

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll X, Y, W, S, Case1, Case2, Case3, Answer;

int main() {
    cin >> X >> Y >> W >> S;

    // 1. 수평으로만 이동하는 경우
    Case1 = (X + Y) * W;

    // 2. 대각선으로만 이동하는 경우
    // 2-1. 짝수일 경우 대각선으로만 이동 가능
    // 2-2. 홀수일 경우 대각선 이동 후 수평이동 1칸
    if ((X + Y) % 2 == 0) Case2 = max(X, Y) * S;
    else Case2 = ((max(X, Y) - 1) * S) + W;

    // 3. 대각선 + 수평 : 대각선으로 최대한 이동 후 수평 이동
    Case3 = (min(X, Y) * S) + (abs(X - Y) * W);

    Answer = min(Case1, min(Case2, Case3));

    cout << Answer << '\n';

    return 0;

}