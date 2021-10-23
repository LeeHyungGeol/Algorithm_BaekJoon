#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int solution(int size);

int main() {
    cin >> N;

    cout << solution(N) << '\n';

    return 0;
}

int solution(int N) {
    int answer = 0;

    for (int a = 1; a < N; ++a) {
        for (int b = a; b < N; ++b) {
            int c = N - (a + b);
            if (c < b) break;
            if (b + a > c) ++answer;
        }
    }

    return answer;
}