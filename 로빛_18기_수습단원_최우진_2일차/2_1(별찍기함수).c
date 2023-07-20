//
//  main.c
//  1qjssjs
//
//  Created by 최우진 on 2023/07/19.
//

#include <stdio.h>

void type1(int size){
    for(int i = 0; i < size/2; i++){
        for(int j = 0; j < i+1; j++){
            printf("*");
        }
        printf("\n");
    }
    if(size%2 == 1){
        for(int i = 0; i < size/2+1; i++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = size/2; i > 0; i--){
        for(int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
}

void type2(int size) {
    if(size%2 == 1){
        int cnt = 1;
        for(int j = 0; j < size/2; j++){
            for(int k = 0; k < size/2+1-cnt; k++){
                printf(" ");
            }
            for(int k = 0; k<cnt; k++){
                printf("*");
            }
            cnt++;
            printf("\n");
        }

        for (int i = 0; i < size / 2 + 1; i++) {
            printf("*");
        }
        printf("\n");

        int cnt2 = size/2;
        for(int j = 0; j<size/2; j++){
            for(int k = 0; k < size/2+1-cnt2; k++){
                printf(" ");
            }
            for(int k = 0; k<cnt2; k++){
                printf("*");
            }
            cnt2--;
            printf("\n");
        }
    }
    else{
        int cnt = 1;
        for(int j = 0; j < size/2; j++){
            for(int k = 0; k < size/2-cnt; k++){
                printf(" ");
            }
            for(int k = 0; k<cnt; k++){
                printf("*");
            }
            cnt++;
            printf("\n");
        }

        int cnt2 = size/2;
        for(int j = 0; j<size/2; j++){
            for(int k = 0; k < size/2-cnt2; k++){
                printf(" ");
            }
            for(int k = 0; k<cnt2; k++){
                printf("*");
            }
            cnt2--;
            printf("\n");
        }
    }
}


void type3(int size){
    int halfSize = (size + 1) / 2;
    
    // 위쪽
    for (int i = 1; i <= halfSize; i++) {
        for (int j = 1; j <= size; j++) {
            if (j >= i && j <= size - i + 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // 아래쪽
    for (int i = halfSize - 1; i >= 1; i--) {
        for (int j = 1; j <= size; j++) {
            if (j >= i && j <= size - i + 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void type4(int size){
    if(size%2 == 1){
        int cnt = size/2+1;
        for(int j = 0; j < size/2; j++){
            for(int k = 0; k<size/2+1-cnt; k++){
                printf(" ");
            }
            for(int k = 0; k < cnt; k++){
                printf("*");
            }
            cnt--;
            printf("\n");
        }
        
        for(int j = 0; j<size/2; j++){
            printf(" ");
        }
        printf("*\n");
        
        int cnt2 = 2;
        for(int j = 0; j < size/2; j++){
            for(int k = 0; k<size/2; k++){
                printf(" ");
            }
            for(int k = 0; k < cnt2; k++){
                printf("*");
            }
            cnt2++;
            printf("\n");
        }
    }
    else{
        int cnt = size/2+1;
        for(int j = 0; j < size/2; j++){
            for(int k = 0; k<size/2+1-cnt; k++){
                printf(" ");
            }
            for(int k = 0; k < cnt; k++){
                printf("*");
            }
            cnt--;
            printf("\n");
        }
        
        int cnt2 = 2;
        for(int j = 0; j < size/2; j++){
            for(int k = 0; k<size/2; k++){
                printf(" ");
            }
            for(int k = 0; k < cnt2; k++){
                printf("*");
            }
            cnt2++;
            printf("\n");
        }
    }
}

int main(int argc, const char * argv[]) {
    int size = 0, type = 0;
    printf("사이즈와 종류를 입력하시오.");
    scanf("%d %d", &size, &type);
    if(type == 1)
    {
        type1(size);
    }
    else if(type == 2)
    {
        type2(size);
    }
    else if(type == 3)
    {
        type3(size);
    }
    else if(type == 4){
        type4(size);
    }
    else{
        printf("1~4까지의 숫자만 입력하세요.");
        return 0;
    }
    return 0;
}
