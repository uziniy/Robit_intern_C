//
//  main.c
//  로빛_5_2
//
//  Created by 최우진 on 2023/07/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int i, char **str2) {
    for (int j=0; j<i; j++) {
        if(strcmp(str2[i], str2[j])==0){
            i--;
        }
    }
    printf("{");
    for (int j=0; j<i+1; j++) {
        printf(" %s,",str2[j]);
    }
    printf("}");
    printf("\n");
    return i;
}

void f_remove(int i, char **str2) {
    for (int j=0; j<i+1; j++) {
        if(strcmp(str2[i], str2[j])==0){
            for (int k=j; k<i; k++) {
                strcpy(str2[k], str2[k+1]);
            }
        }
    }
    printf("{");
    for (int j=0; j<i-1; j++) {
        printf(" %s,",str2[j]);
    }
    printf("}");
    printf("\n");
}

int check(int i, char **str2) {
    int n1=0;
    for (int j=0; j<i; j++) {
        if(strcmp(str2[i], str2[j])==0){
            n1 = 1;
        }
    }
    switch (n1) {
        case 1:
            for (int j=0; j<i+1; j++) {
                if(strcmp(str2[i], str2[j])==0){
                    printf("1\n");
                    break;
                }
            }
            break;
        default:
            printf("0\n");
            break;
    }
    return 0;
}

int toggle(int i, char **str2) {
    int n1=0;
    for (int j=0; j<i; j++) {
        if(strcmp(str2[i], str2[j])==0){
            for (int k=j; k<i; k++) {
                strcpy(str2[k], str2[k+1]);
            }
            n1=1;
        }
    }
    switch (n1) {
        case 1:
            i-=2;
            printf("{");
            for (int j=0; j<i+1; j++) {
                printf(" %s,",str2[j]);
            }
            printf("}");
            printf("\n");
            break;
        default:
            printf("{");
            for (int j=0; j<i+1; j++) {
                printf(" %s,",str2[j]);
            }
            printf("}");
            printf("\n");
            break;
    }
    return i;
}
void all(int i, char **str2) {
    for (int i=0; i<9; i++) {
        sprintf(str2[i], "%x", i+1);
    }
    for (int i=15; i<20; i++) {
        sprintf(str2[i-6], "%x", i+1);
    }
    for (int i=20; i<25; i++) {
        sprintf(str2[i-6], "%x", i+1);
    }
    str2[19]="20";
    
    printf("{");
    for (int j=0; j<20; j++) {
        if(str2[j]==0){
            continue;
        }
        printf(" %s,",str2[j]);
    }
    printf("}");
    printf("\n");
}
void empty(int i, char **str2) {
    free(str2);
    i=0;
    printf("{");
    printf(" }");
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int i=0;
    char str1[100];
    char **str2 = (char **)malloc (sizeof(char*)*20);
    for (int i=0;i<20;i++){
        str2[i] = (char *)malloc (sizeof(char)*20);
    }
    char **out = (char **)malloc (sizeof(char*)*20);
    for (int i=0;i<20;i++){
        out[i] = (char *)malloc (sizeof(char)*20);
    }
    i=0;
    
    while(1)  {
        printf("연산을 선택하세요.\tadd : ~\tremove : ~\ttoggle : ~\tall : ~\tempty : ~\n\n");
        scanf("%s",str1);
        if(strcmp(str1, "quit")==0){
            free(str2);
            break;
        }
        //empty
//        if(strcmp(str1, "empty")==0){
//            empty(i, str2);
//            free(str2);
//            char **str2 = (char **)malloc (sizeof(char*)*20);
//            for (int j=0;j<20;j++){
//                str2[j] = (char *)malloc (sizeof(char)*20);
//            }
//            scanf("%s",str1);
//        }
        if(strcmp(str1, "empty")==0){
            empty(i, str2);
            i = 0;
            scanf("%s", str1);
        }
        //all
        if(strcmp(str1, "all")==0){
            all(i, str2);
            i=0;
            scanf("%s",str1);
        }
        scanf(" %s",str2[i]);
        
        //add
        if(strcmp(str1, "add")==0){
            i=add(i,str2);
            i++;
        }
        //remove
        if(strcmp(str1, "remove")==0){
            f_remove(i, str2);
            i--;
        }
        //check
        if(strcmp(str1, "check")==0){
            check(i, str2);
        }
        //toggle
        if(strcmp(str1, "toggle")==0){
            i=toggle(i, str2);
            i++;
        }
    }
    return 0;
}

