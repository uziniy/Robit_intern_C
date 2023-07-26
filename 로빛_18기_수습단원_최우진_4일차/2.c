//
//  main.c
//  로빛_4_2
//
//  Created by 최우진 on 2023/07/21.
//

#include <stdio.h>
struct string_input{
    char str[100];
};
char* string_cat(char s1[], char s2[]) {
    int n1,n2;
    char out[100];
    for (int i=0; i<100; i++) {
            if(s1[i]=='\0'){
                n1 = i;
                break;
            }
        }
    for (int i=0; i<100; i++) {
            if(s2[i]=='\0'){
                n2 = i;
                break;
            }
        }

    if(n1<n2){
        int i = 0;
        int j = 0;
        while (s2[j] != '\0') {
            out[i]=s2[j];
            i++;
            j++;
        }
        s1[i] = "\0";
        printf("복사되었습니다.\n");
        printf("%s\n",s1);
    }
    else{
        printf("복사할 수 없습니다.\n");
    }
        
        return 0;
}
                
            
int main(int argc, const char * argv[]) {
    struct string_input str1;
    struct string_input str2;
    printf("문자열을 입력하시오(str1). ");
    scanf("%s",str1.str);
    printf("문자열을 입력하시오(str2). ");
    scanf("%s",str2.str);
    string_cat(str1.str, str2.str);
    return 0;
}
