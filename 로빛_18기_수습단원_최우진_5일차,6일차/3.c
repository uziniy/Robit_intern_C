//
//  main.c
//  로빛_5_3
//
//  Created by 최우진 on 2023/07/24.
//

#include <stdio.h>
#include<stdlib.h>

void print(int *row,int *col,int **pArr);
void arr_ij(int *n1, int *n2, int **tmp);

int main(int argc, const char * argv[]) {
    int n1, n2;
    int *p1,*p2;
    
    printf("열의 수를 입력하세요:");
    scanf("%d",&n1);
    printf("행의 수를 입력하세요:");
    scanf("%d",&n2);
    
    p1 = &n1;
    p2 = &n2;
    //동적할당으로 배열 만들기
    int **arr = (int **)malloc (sizeof(int*)*n1);
    for (int i=0;i<n1;i++){
        arr[i] = (int *)malloc (sizeof(int)*n2);
    }
    //밑에서 조건 걸기 위해 모두 0으로 초기화
    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            arr[i][j]=0;
        }
    }
    arr_ij(p1, p2, arr);
    print(p1, p2, arr);
    return 0;
}

//달팽이 만드는 함수
//void arr_ij(int *n1, int *n2, int **tmp){
//    int x = -1, y = 0, k = 0;
//    while (k != ((*n1)*(*n2))) {//두개 곱한게 k라면 다 채운거 니깐 탈출하게 조건 검
//        //오른쪽
//        while (((x+1)<*n2) && (tmp[y][x + 1] == 0)) {
//            tmp[y][++x] = ++k;
//        }
//        //아래
//        while (y + 1 < (*n1) && tmp[y + 1][x] == 0) {
//            tmp[++y][x] = ++k;
//        }
//        //왼쪽
//        while (x - 1 >= 0 && tmp[y][x - 1] == 0) {
//            tmp[y][--x] = ++k;
//        }
//
//        //위
//        while (y - 1 >= 0 && tmp[y - 1][x] == 0) {
//            tmp[--y][x] = ++k;
//        }
//
//    }
//}
void arr_ij(int *n1, int *n2, int **tmp){
    int x = 0, y = 0, k = 1;
    while (k <= ((*n1)*(*n2))) {
        // 오른쪽
        while (((x < *n2) && (tmp[y][x] == 0))) {
            tmp[y][x] = k++;
            x++;
        }
        x--;
        y++;
        // 아래
        while (((y < *n1) && (tmp[y][x] == 0))) {
            tmp[y][x] = k++;
            y++;
        }
        y--;
        x--;
        // 왼쪽
        while (((x >= 0) && (tmp[y][x] == 0))) {
            tmp[y][x] = k++;
            x--;
        }
        x++;
        y--;
        // 위
        while (((y >= 0) && (tmp[y][x] == 0))) {
            tmp[y][x] = k++;
            y--;
        }
        y++;
        x++;
    }
}

//출력하는 함수
void print(int *row,int *col,int **pArr){
    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            printf(" %3d", pArr[i][j]);
        }
        printf("\n");
    }
}
