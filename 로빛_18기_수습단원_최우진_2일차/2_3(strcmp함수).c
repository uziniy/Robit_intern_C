//
//  main.c
//  asdf
//
//  Created by 최우진 on 2023/07/19.
//

#include <stdio.h>

int pp(char ss[10],char as[10],char ds[10]);
//strcmp함수
int compare(const char str1[], const char str2[]) {
    int i = 0;

    while (str1[i] && str1[i] == str2[i]) {
        i++;
    }

    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

int main(int argc, const char * argv[]) {
    char ss[10];
    char as[10]="cdefgabC";
    char ds[10]="Cbagfedc";
    
    printf("음 입력\n");
    scanf("%s",ss);
    printf("\n");
    
    printf("결과 : ");
    int sw=pp(ss,as,ds);
    
    switch (sw) {
        case 1:
            printf("ascending");
            break;
        case 2:
            printf("descending");
            break;
        case 3:
            printf("mixed");
            break;
            
        default:
            break;
    }
    printf("\n");
    
    return 0;
}

int pp(char ss[10],char as[10],char ds[10]){
    if(compare(ss,as)==0){
        return 1;
    }
    else if (compare(ss,ds)==0){
        return 2;
    }
    else{
        return 3;
    }
    return 0;
}
