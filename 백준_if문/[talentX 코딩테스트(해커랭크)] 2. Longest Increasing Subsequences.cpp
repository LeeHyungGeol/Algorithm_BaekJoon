#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Complete the function below.
 */
int findLIS(vector < int > s) {
    vector<int> answer;
    answer.push_back(-1);

    for (int i = 0; i < s.size(); ++i) {
        if (answer.back() < s[i]) {
            answer.push_back(s[i]);
        }
        else {
            int index = lower_bound(answer.begin(), answer.end(), s[i]) - answer.begin();
            answer[index] = s[i];
        }
    }

    return answer.size() - 1;
}
