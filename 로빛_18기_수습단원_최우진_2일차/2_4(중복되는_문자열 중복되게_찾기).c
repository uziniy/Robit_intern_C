//
//  main.c
//  로빛_2_4
//
//  Created by 최우진 on 2023/07/19.
//

#include <stdio.h>

//strlen함숫
int len(char str[]){
    for (int i=0; i<100; i++) {
        if(str[i]=='\0'){
            return i;
        }
    }
    return 0;
}

//같은 문자열 찾는 함수
int compare(char inputStr[], char subStr[], int index){
    for(int i = index; i < len(inputStr)-len(subStr)+1;i++){
        for(int j = 0; j<len(subStr); j++){
            if(subStr[j] == inputStr[i+j] && j == len(subStr)-1){
                return i+1;
            }
            else if(subStr[j] != inputStr[i+j]){
                break;
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    //변수 선언
    char inputStr[100],subStr[100];
    int index = 0;
    
    //입력 받기
    printf("최대 99개 문자 입력 <inputStr> : ");
    scanf("%s",inputStr);
    printf("찾는 문자열 <subStr> : ");
    scanf("%s",subStr);
    
    while(1){
        int temp = compare(inputStr,subStr,index);
        if(temp == 0){
            break;
        }
        printf("%s의 위치 : %d\n", subStr, temp);
        index = temp+len(subStr);
    }
    
    return 0;
}
