#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'closestSquaredDistance' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER_ARRAY y
 */

typedef pair<int, int> pii;

vector<pii> coordinates;

bool compare(const pii& a, const pii& b) {
    return a.first < b.first;
}

long getDistance(pii& a, pii& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

long closestSquaredDistance(vector<int> x, vector<int> y) {
    for (int i = 0; i < x.size(); ++i) {
        coordinates.push_back({ x[i], y[i] });
    }

    sort(coordinates.begin(), coordinates.end(), compare);

    vector<pii> temp = { coordinates[0], coordinates[1] };

    long answer = getDistance(coordinates[0], coordinates[1]);

    for (int i = 2; i < x.size(); ++i) {
        pii cur = coordinates[i];

        for (auto it = temp.begin(); it != temp.end();) {
            auto p = *it;
            int x = cur.first - p.first;

            if (x * x > answer) {
                it = temp.erase(it);
            }
            else {
                long dist = getDistance(cur, p);
                if (answer > dist) {
                    answer = dist;
                }
                ++it;
            }
        }
        temp.push_back(cur);
    }

    return answer;
}

