//
//  main.c
//  로빛_2_5
//
//  Created by 최우진 on 2023/07/19.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    //변수 선언
    int n,b,s,s1,tmp;
    int nn[100]={0,};
    
    //n값과 b값 입력
    printf("N : ");
    scanf("%d",&n);
    printf("B : ");
    scanf("%d",&b);
    printf("\n");
    
    //짝수일때 예외처리
    if(n%2==0){
        printf("짝수입니다. 홀수를 입력해주세요.");
        return 0;
    }
    
    //수열 입력
    for (int i=0; i<n; i++) {
        scanf("%d",&nn[i]);
    }
    
    //정렬
    for (int i=0; i<n-1; i++) {
        for (int j=1; j<n; j++) {
            if(nn[i]>nn[j]){
                tmp=nn[i];
                nn[i]=nn[j];
                nn[j]=tmp;
            }
        }
    }
    
    //중앙값이 몇번째 수열에 있는지 찾기
    for (int i=0; i<n; i++) {
        if(b==nn[i]){
            s1=i;//5
            break;
        }
    }
    
    if(s1>=(n+1)/2){
        s=n-s1;
        printf("중앙값이 %d인 부분수열의 개수 : %d\n",b,s);
    }
    else if(s1<(n+1)/2){
        s=s1;
        printf("중앙값이 %d인 부분수열의 개수 : %d\n",b,s);
    }
    
    
    
    return 0;
}
