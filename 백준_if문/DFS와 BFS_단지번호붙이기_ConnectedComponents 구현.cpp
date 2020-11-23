#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int cnt = 0;
vector<int> vectorcnt;
int graph[26][26] = { 0 };
bool visited[26][26];
int vecX[5] = { 0,-1,1,0,0 };
int vecY[5] = { 0,0,0,1,-1 };

bool dfs(int v, int w);
void dfs2(int x, int y);

int main() {

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%1d", &graph[i][j]);
        }
    }
    /*for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cnt = 0;
            if (dfs(i, j)) {
                vectorcnt.push_back(cnt);
            }
        }
    }*/
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (visited[i][j] == false && graph[i][j] == 1) {
                cnt = 0;
                dfs2(i, j);
                vectorcnt.push_back(cnt);
            }
        }
    }
    cout << vectorcnt.size() << '\n';
    sort(vectorcnt.begin(), vectorcnt.end());
    for (int i = 0; i < vectorcnt.size(); ++i) {
        cout << vectorcnt[i] << '\n';
    }
    return 0;
}
bool dfs(int v, int w) {
    if (v < 1 || v > N || w < 1 || w > N)
        return false;
    if (graph[v][w] == 1 && visited[v][w] == false) {
        visited[v][w] = true;
        cnt++;
        dfs(v - 1, w);
        dfs(v + 1, w);
        dfs(v, w - 1);
        dfs(v, w + 1);
        return true;
    }
    return false;
}
void dfs2(int x, int y) {
    visited[x][y] = true;
    cnt++;
    for (int i = 1; i <= 4; ++i) {
        int newX = x + vecX[i];
        int newY = y + vecY[i];
        if (newX >= 1 && newX <= N && newY >= 1 && newY <= N && visited[newX][newY] == false && graph[newX][newY] == 1) {
            dfs2(newX, newY);
        }
    }
}
