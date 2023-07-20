//
//  main.c
//  로빛_3_5
//
//  Created by 최우진 on 2023/07/20.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int n,k,num=1;
    printf("N : ");
    scanf("%d", &n);
    
    //동적할당으로 배열에 입력 받은 변수 넣기
    int **arr = (int **)malloc (sizeof(int*)*n);
    for (int i=0;i<n;i++){
        arr[i] = (int *)malloc (sizeof(int)*n);
    }

    //알고리즘 t=i, row=j, col=k
      for(int i=0; i<n*2; i++){
        for(int j=0; j<n; j++){
          k = i-j;
            //할당한거 밖으로 안튀어나가게 하기 위해 설정
          if((0<=k) && (k<n))
              arr[j][k] = num++;
        }
      }

    //출력
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          printf("%2d ", arr[i][j]);
        }
        printf("\n");
      }
      return 0;
}
