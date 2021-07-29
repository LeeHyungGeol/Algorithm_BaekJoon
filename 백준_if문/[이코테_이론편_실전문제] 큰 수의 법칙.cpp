#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, cnt, answer;
vector<int> nums;
void solution1(int first, int second);
void solution2(int first, int second);

int main() {
    cin >> N >> M >> K;

    nums.resize(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums.rbegin(), nums.rend());

    int first = nums[0], second = nums[1];

    // solution1(first, second);
    solution2(first, second);

    cout << answer << '\n';

    return 0;
}

void solution1(int first, int second) {
    while (true) {
        for (int i = 0; i < K; ++i) {
            if (M == 0) {
                break;
            }
            answer += first;
            --M;
        }

        if (M == 0) {
            break;
        }

        answer += second;
        --M;
    }

    return;
}

void solution2(int first, int second) {
    cnt = (M / (K + 1)) * K;
    cnt += (M % (K + 1));

    answer += cnt * first;
    answer += (M - cnt) * second;

    return;
}