//
//  main.c
//  로빛_4_1
//
//  Created by 최우진 on 2023/07/21.
//

#include <stdio.h>
struct string_input{
    char str[100];
};
int string_len(char str1[],char str2[]){
    int n1,n2;
    for (int i=0; i<100; i++) {
            if(str1[i]=='\0'){
                n1 = i;
                break;
            }
        }
    for (int i=0; i<100; i++) {
            if(str2[i]=='\0'){
                n2 = i;
                break;
            }
        }
    if(n1>n2){
        return -1;
    }
    else if(n1<n2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    struct string_input str1;
    struct string_input str2;
    int f;
    
    printf("문자열 str1을 입력하시오. ");
    scanf("%s",str1.str);
    printf("문자열 str2을 입력하시오. ");
    scanf("%s",str2.str);
    
    f=string_len(str1.str, str2.str);
    if(f==-1){
        printf("str1가 더 깁니다.");
    }
    else if(f==1){
        printf("str2가 더 깁니다.");

    }
    else{
        printf("문자열의 길이가 같습니다.");
    }
    
    
    return 0;
}
