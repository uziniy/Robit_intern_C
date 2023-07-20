//
//  main.c
//  로빛_3_4
//
//  Created by 최우진 on 2023/07/20.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int N,tmp,sum=0;
    float avg;
    printf("몇 개의 원소를 할당하겠습니까? : ");
    scanf("%d",&N);
    
    //동적할당 이용해서 배열에 포인터 넣기
    int *Arr = (int*)malloc(sizeof(int)*N);
    for (int i=0; i<N; i++) {
        printf("정수형 데이터 입력:");
        scanf("%d",&Arr[i]);
        sum+=Arr[i];
    }
    
    //정렬
    for (int i=0; i<N-1; i++) {
        for (int j=1; j<N; j++) {
            if(Arr[i]>Arr[j]){
                tmp=Arr[i];
                Arr[i]=Arr[j];
                Arr[j]=tmp;
            }
        }
    }
    //평균
    avg=sum/N;
    
    //출력
    printf("최대값: %d\n",Arr[N-1]);
    printf("최소값: %d\n",Arr[0]);
    printf("전체합: %d\n",sum);
    printf("평균: %f\n",avg);
        
    return 0;
}

