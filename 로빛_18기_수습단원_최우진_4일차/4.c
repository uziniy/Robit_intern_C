//
//  main.c
//  로빛_4_4
//
//  Created by 최우진 on 2023/07/21.
//

#include <stdio.h>
struct point{
    int x;
    int y;
};

int main(int argc, const char * argv[]) {
    int x1,x2,x3,x4,y1,y2,y3,y4,n1,n2,n3,n4,num1=0,num2=0,   size_sum;
    struct point p1;
    struct point p2;
    struct point p3;
    struct point p4;\
    
    
    int arr1[100][100];
    int arr2[100][100];
    
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            arr1[i][j]=1;
        }
    }
    
    printf("1번 좌표 : ");
    scanf("%d %d",&p1.x,&p1.y);
    printf("2번 좌표 : ");
    scanf("%d %d",&p2.x,&p2.y);
    printf("3번 좌표 : ");
    scanf("%d %d",&p3.x,&p3.y);
    printf("4번 좌표 : ");
    scanf("%d %d",&p4.x,&p4.y);
    
    
    //예외처리 사각형 아닐때
    if((p1.x==p2.x) && (p1.y==p2.y)){
        printf("사각형이 만들어 지지 않습니다.");
        return 0;
    }
    if((p3.x==p4.x) && (p3.y==p4.y)){
        printf("사각형이 만들어 지지 않습니다.");
        return 0;
    }
    //좌표끼리 뺸 값이 양수이게 조건걸어서 선언
    n1=((p1.x-p2.x)>0 ? (p1.x-p2.x):-(p1.x-p2.x));
    n2=((p1.y-p2.y)>0 ? (p1.y-p2.y):-(p1.y-p2.y));
    n3=((p3.x-p4.x)>0 ? (p3.x-p4.x):-(p3.x-p4.x));
    n4=((p3.y-p4.y)>0 ? (p3.y-p4.y):-(p3.y-p4.y));
    
    //p1,p2
    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            num1++;
        }
    }
    //p3,p4
    for (int i=0; i<n3; i++) {
        for (int j=0; j<n4; j++) {
            num2++;
        }
    }
    
    //합집합 면적
    size_sum=num1+num2;
    printf("교집합 빼기 전: %d\n",size_sum);
    
    //>가 0개 4C0=1 1개 경우
    if((p1.x<p2.x)&&(p1.y<p2.y)&&(p3.x<p4.x)&&(p3.y<p4.y)){
        for (int i=p1.x; i<p2.x; i++) {
            for (int j=p1.y; j<p2.y; j++) {
                for (int k=p3.x; k<p4.x; k++) {
                    for (int l=p3.y; l<p4.y; l++) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    
    //>가 1개 4C1=4 4개 경우
    if((p1.x>p2.x)&&(p1.y<p2.y)&&(p3.x<p4.x)&&(p3.y<p4.y)){
        for (int i=p1.x; i>p2.x; i--) {
            for (int j=p1.y; j<p2.y; j++) {
                for (int k=p3.x; k<p4.x; k++) {
                    for (int l=p3.y; l<p4.y; l++) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x<p2.x)&&(p1.y>p2.y)&&(p3.x<p4.x)&&(p3.y<p4.y)){
        for (int i=p1.x; i<p2.x; i++) {
            for (int j=p1.y; j>p2.y; j--) {
                for (int k=p3.x; k<p4.x; k++) {
                    for (int l=p3.y; l<p4.y; l++) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x<p2.x)&&(p1.y<p2.y)&&(p3.x>p4.x)&&(p3.y<p4.y)){
        for (int i=p1.x; i<p2.x; i++) {
            for (int j=p1.y; j<p2.y; j++) {
                for (int k=p3.x; k>p4.x; k--) {
                    for (int l=p3.y; l<p4.y; l++) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x<p2.x)&&(p1.y<p2.y)&&(p3.x<p4.x)&&(p3.y>p4.y)){
        for (int i=p1.x; i<p2.x; i++) {
            for (int j=p1.y; j<p2.y; j++) {
                for (int k=p3.x; k<p4.x; k++) {
                    for (int l=p3.y; l>p4.y; l--) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    
    //>가 1개 4C2=6 6개 경우
    if((p1.x>p2.x)&&(p1.y>p2.y)&&(p3.x<p4.x)&&(p3.y<p4.y)){
        for (int i=p1.x; i>p2.x; i--) {
            for (int j=p1.y; j>p2.y; j--) {
                for (int k=p3.x; k<p4.x; k++) {
                    for (int l=p3.y; l<p4.y; l++) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x>p2.x)&&(p1.y<p2.y)&&(p3.x>p4.x)&&(p3.y<p4.y)){
        for (int i=p1.x; i>p2.x; i--) {
            for (int j=p1.y; j<p2.y; j++) {
                for (int k=p3.x; k>p4.x; k--) {
                    for (int l=p3.y; l<p4.y; l++) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x>p2.x)&&(p1.y<p2.y)&&(p3.x<p4.x)&&(p3.y>p4.y)){
        for (int i=p1.x; i>p2.x; i--) {
            for (int j=p1.y; j<p2.y; j++) {
                for (int k=p3.x; k<p4.x; k++) {
                    for (int l=p3.y; l>p4.y; l--) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x<p2.x)&&(p1.y>p2.y)&&(p3.x>p4.x)&&(p3.y<p4.y)){
        for (int i=p1.x; i<p2.x; i++) {
            for (int j=p1.y; j>p2.y; j--) {
                for (int k=p3.x; k>p4.x; k--) {
                    for (int l=p3.y; l<p4.y; l++) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x<p2.x)&&(p1.y>p2.y)&&(p3.x<p4.x)&&(p3.y>p4.y)){
        for (int i=p1.x; i<p2.x; i++) {
            for (int j=p1.y; j>p2.y; j--) {
                for (int k=p3.x; k<p4.x; k++) {
                    for (int l=p3.y; l>p4.y; l--) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x<p2.x)&&(p1.y<p2.y)&&(p3.x>p4.x)&&(p3.y>p4.y)){
        for (int i=p1.x; i<p2.x; i++) {
            for (int j=p1.y; j<p2.y; j++) {
                for (int k=p3.x; k>p4.x; k--) {
                    for (int l=p3.y; l>p4.y; l--) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    
    //>가 3개일때 4C3=4 4개의 경우
    if((p1.x>p2.x)&&(p1.y>p2.y)&&(p3.x>p4.x)&&(p3.y<p4.y)){
        for (int i=p1.x; i>p2.x; i--) {
            for (int j=p1.y; j>p2.y; j--) {
                for (int k=p3.x; k>p4.x; k--) {
                    for (int l=p3.y; l<p4.y; l++) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x<p2.x)&&(p1.y>p2.y)&&(p3.x>p4.x)&&(p3.y>p4.y)){
        for (int i=p1.x; i<p2.x; i++) {
            for (int j=p1.y; j>p2.y; j--) {
                for (int k=p3.x; k>p4.x; k--) {
                    for (int l=p3.y; l>p4.y; l--) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x>p2.x)&&(p1.y<p2.y)&&(p3.x>p4.x)&&(p3.y>p4.y)){
        for (int i=p1.x; i>p2.x; i--) {
            for (int j=p1.y; j<p2.y; j++) {
                for (int k=p3.x; k>p4.x; k--) {
                    for (int l=p3.y; l>p4.y; l--) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    if((p1.x>p2.x)&&(p1.y>p2.y)&&(p3.x<p4.x)&&(p3.y>p4.y)){
        for (int i=p1.x; i>p2.x; i--) {
            for (int j=p1.y; j>p2.y; j--) {
                for (int k=p3.x; k<p4.x; k++) {
                    for (int l=p3.y; l>p4.y; l--) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    //>가 4개 4C4=1 1개 경우
    if((p1.x>p2.x)&&(p1.y>p2.y)&&(p3.x>p4.x)&&(p3.y>p4.y)){
        for (int i=p1.x; i>p2.x; i--) {
            for (int j=p1.y; j>p2.y; j--) {
                for (int k=p3.x; k>p4.x; k--) {
                    for (int l=p3.y; l>p4.y; l--) {
                        if((i==k)&&(j==l)){
                            size_sum-=1;
                        }
                    }
                }
            }
        }
    }
    
    printf("합집합 뺸 후 : %d\n",size_sum);
    return 0;
}
