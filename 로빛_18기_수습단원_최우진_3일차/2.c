//
//  main.c
//  로빛_3_2
//
//  Created by 최우진 on 2023/07/20.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int n1,n2,size=0;
    printf("N1 : ");
    scanf("%d",&n1);
    printf("N2 : ");
    scanf("%d",&n2);
    
    //이중포인터로 배열안에 입력 받은 값 넣기
    int **Arr = (int **)malloc (sizeof(int*)*n1);
    for (int i=0;i<n1;i++){
        Arr[i] = (int *)malloc (sizeof(int)*n2);
    }
    //입력
    int num=1;
    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            Arr[i][j]=num++;
        }
    }
    //출력
    for (int i=0; i<n2; i++) {
        for (int j=0; j<n1; j++) {
            printf("%d ",Arr[j][i]);
        }
        printf("\n");
    }
    
    
    return 0;
}

