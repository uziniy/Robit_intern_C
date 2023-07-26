//
//  main.c
//  로빛_4_3
//
//  Created by 최우진 on 2023/07/21.
//

#include <stdio.h>
struct string_input{
    char str[100];
};
int stringCompare(const char* str1, const char* str2) {
    //아스키코드가 소문자가 더 크니깐 대문자 소문자 크기 바꿔줌
    while (*str1&&*str2) {
        char cc1 = ((*str1>='A') && (*str1<='Z')) ? (*str1) : (*str1);
        char cc2 = ((*str2>='A') && (*str2<='Z')) ? (*str2) : (*str2);

        if(cc1<cc2){
            return 1;
        }
        else if (cc1>cc2){
            return -1;
        }
        
        str1++;
        str2++;
    }
    return 0;
    }
int main(int argc, const char * argv[]) {
    struct string_input str1;
    struct string_input str2;
    int f;
    
    printf("Str1 = ");
    scanf("%s",str1.str);
    printf("Str2 = ");
    scanf("%s",str2.str);
    
    f=stringCompare(str1.str, str2.str);
    
    if (f==1) {
        printf("Str1가 더 빠릅니다.\n");
    }
    else if (f==-1) {
        printf("Str2가 더 빠릅니다.\n");
    }
    else{
        printf("Str1==Str2.\n");
    }
    
    return 0;
}
