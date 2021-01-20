//강한 연결 요소(Strongly Connected Componensts): 강하게 연결된 정점 집합
//같은 SCC에 속하는 두 정점은 서로 도달이 가능하다.
//사이클이 발생하는 경우 무조건 SCC에 해당한다.
//방향 그래프일 때만 의미가 있다. 무향 그래프라면 그 그래프 전체는 무조건 SCC이다.
//코사라주 알고리즘(Kosaraju's Algorithm), 타잔 알고리즘(Tarjan's Algorithm)

//타잔 알고리즘(Tarjan's Algorithm): 모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘
//1. DFS를 수행하면서 부모 값을 확인한다. 
//2. Stack에서 해당 부모 값이 나올 때 까지 원소를 뽑아낸다. 

//""각 SCC 집합을 정점""으로 하는 ""위상정렬""을 수행 가능하다.
//강한 연결 요소 알고리즘의 시간 복잡도는 O(V+E)이다 : 모든 정점에 대해서 DFS를 수행, 모든 간선에 대해서 하나씩 확인한다.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;



int main() {


}