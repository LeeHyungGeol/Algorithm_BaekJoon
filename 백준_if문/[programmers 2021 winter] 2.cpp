#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(int time, int gold, vector<vector<int>> upgrade) {
    int answer = -1;

    for (int i = 0; i < upgrade.size(); ++i) {
        int Case = 1;
        while (Case <= upgrade.size()) {
            int money = 0;
            bool flag = false;

            for (int j = 0; j < Case; ++j) {
                int upgradeCost = upgrade[j][0];
                int timePerRock = upgrade[j][1];
                int count = 0;
                if (time <= 0) {
                    flag = true;
                    break;
                }

                if (j == Case - 1) {
                    count = time / timePerRock;
                    money += gold * count;
                }
                else {
                    count = (time % timePerRock == 0) ? time / timePerRock : (time / timePerRock) + 1;
                    time -= count * timePerRock;
                    money += gold * count;
                    money -= upgradeCost;
                }
            }
            if (flag) break;
            answer = max(answer, money);
            ++Case;
        }
    }

    return answer;
}