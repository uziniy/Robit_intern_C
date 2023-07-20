//
//  main.c
//  3__3
//
//  Created by 최우진 on 2023/07/20.
//

#include <stdio.h>
#include<stdlib.h>

int main(int argc, const char * argv[]) {
    int n1, n2;
    int x = -1, y = 0, k = 0;
    printf("n1 n2 : ");
    scanf("%d %d", &n1, &n2);
    //동적할당으로 배열 만들기
    int **tmp = (int **)malloc (sizeof(int*)*n1);
    for (int i=0;i<n1;i++){
        tmp[i] = (int *)malloc (sizeof(int)*n2);
    }
    //밑에서 조건 걸기 위해 모두 0으로 초기화
    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            tmp[i][j]=0;
        }
    }

    while (k != (n1*n2)) {//두개 곱한게 k라면 다 채운거 니깐 탈출하게 조건 검
        //오른쪽
        while (((x+1)<n2) && (tmp[y][x + 1] == 0)) {
            tmp[y][++x] = ++k;
        }
        //아래
        while (y + 1 < n1 && tmp[y + 1][x] == 0) {
            tmp[++y][x] = ++k;
        }
        //왼쪽
        while (x - 1 >= 0 && tmp[y][x - 1] == 0) {
            tmp[y][--x] = ++k;
        }
 
        //위
        while (y - 1 >= 0 && tmp[y - 1][x] == 0) {
            tmp[--y][x] = ++k;
        }

    }
    //출력
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            printf(" %2d", tmp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
