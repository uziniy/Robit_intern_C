//
//  main.c
//  로빛과제ㅔㅔ
//
//  Created by 최우진 on 2023/07/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f_Substring(const char* str1, const char* str2, char** result) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int** dp_table = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        dp_table[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }

    *result = (char*)malloc((len1 + 1) * sizeof(char));

    int max_len = 0;
    int max_end = 0;

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                dp_table[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                dp_table[i][j] = dp_table[i - 1][j - 1] + 1;
                if (dp_table[i][j] > max_len) {
                    max_len = dp_table[i][j];
                    max_end = i;
                }
            }
            else {
                dp_table[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= len1; i++) {
        free(dp_table[i]);
    }
    free(dp_table);

    strncpy(*result, &str1[max_end - max_len], max_len);
    (*result)[max_len] = '\0';
    return max_len;
}

int main(int argc, const char* argv[]) {
    char input1[100];
    char input2[100];
    char* result = NULL;
    int length;

    while (1) {
        printf("입력1 : ");
        scanf("%99s", input1);

        if (strcmp(input1, "quit") == 0)
            break;

        printf("입력2 : ");
        scanf("%99s", input2);

        length = f_Substring(input1, input2, &result);
        printf("출력 : %s / %d\n", result, length);

        free(result);
        result = NULL;
    }
    return 0;
}
