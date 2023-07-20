//
//  main.c
//  로빛_3_1
//
//  Created by 최우진 on 2023/07/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int ss[5][5]={0};
    int n=1;
    //위쪽
    for (int i=0; i<2; i++) {
        for (int j=0+i; j<5-i; j++) {
            ss[i][j]+=n;
            n++;
        }
    }
    //중간
    for (int i=2; i<3; i++) {
        for (int j=2; j<3; j++) {
            ss[i][j]+=n;
            n++;
        }
    }
    //아래쪽
    for (int i=3; i<5; i++) {
        for (int j=1-(i-3); j<4+(i-3); j++) {
            ss[i][j]+=n;
            n++;
        }
    }
    //출력
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            printf("%3d",ss[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
