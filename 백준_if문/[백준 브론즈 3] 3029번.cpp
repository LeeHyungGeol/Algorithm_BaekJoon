// 문자열(시간 (24:24:24) 빼기 계산)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

using namespace std;

int Now[3], Throw[3], Answer[3];

int main() {
    scanf("%d:%d:%d", &Now[0], &Now[1], &Now[2]);
    scanf("%d:%d:%d", &Throw[0], &Throw[1], &Throw[2]);

    // 초
    if (Throw[2] >= Now[2]) {
        Answer[2] = Throw[2] - Now[2];
    }
    else { 
        Answer[2] = Throw[2] - Now[2] + 60; 
        --Throw[1]; 
    }

    // 분
    if (Throw[1] >= Now[1]) {
        Answer[1] = Throw[1] - Now[1];
    }
    else { 
        Answer[1] = Throw[1] - Now[1] + 60; 
        --Throw[0]; 
    }

    // 시
    if (Throw[0] >= Now[0]) {
        Answer[0] = Throw[0] - Now[0];
    }
    else { 
        Answer[0] = Throw[0] - Now[0] + 24; 
    }

    if (Answer[0] == 0 && Answer[1] == 0 && Answer[2] == 0) {
        Answer[0] = 24;
    }

    printf("%02d:%02d:%02d\n", Answer[0], Answer[1], Answer[2]);

	return 0;
}