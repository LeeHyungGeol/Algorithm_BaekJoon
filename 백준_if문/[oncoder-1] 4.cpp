#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> Arr;

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution {
public:
    bool compare(const pii& a, const pii& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }

    int solution(vector<int> price, vector<int> cost) {

        for (int i = 0; i < price.size(); ++i) {
            Arr.push_back({ price[i], cost[i] });
        }

        sort(Arr.begin(), Arr.end());

        int maxPrice = 0, maxTotalPeice = 0;

        for (int i = 0; i < Arr.size(); ++i) {
            int sum = 0;
            for (int j = i; j < Arr.size(); ++j) {
                int benefit = Arr[i].first - Arr[j].second;
                sum += (benefit > 0) ? benefit : 0;
            }
            if (maxTotalPeice < sum) {
                maxTotalPeice = sum;
                maxPrice = Arr[i].first;
            }
        }

        return maxPrice;
    }
};