//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
#include <algorithm>

using namespace std;

typedef long long ll;

class Solution {
public:
    ll solution(int X, int Y, int walkTime, int sneakTime) {
        ll x = X;
        ll y = Y;
        ll w = walkTime;
        ll s = sneakTime;
        ll case1, case2, case3;

        case1 = (x + y) * w;

        if ((x + y) % 2 == 0) case2 = max(x, y) * s;
        else case2 = ((max(x, y) - 1) * s) + w;

        case3 = (min(x, y) * s) + (abs(x - y) * w);

        return (ll)min(case1, min(case2, case3));
    }
};