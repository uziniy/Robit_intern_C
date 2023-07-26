//
//  main.c
//  로빛_5_5
//
//  Created by 최우진 on 2023/07/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f_CommonSubstring(const char* str1, const char* str2, const char* str3, char** result) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);

    int*** dp_table = (int***)malloc((len1 + 1) * sizeof(int**));
    for (int i = 0; i <= len1; i++) {
        dp_table[i] = (int**)malloc((len2 + 1) * sizeof(int*));
        for (int j = 0; j <= len2; j++) {
            dp_table[i][j] = (int*)malloc((len3 + 1) * sizeof(int));
        }
    }

    *result = (char*)malloc((len1 + 1) * sizeof(char));

    int max_len = 0;
    int max_end = 0;

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            for (int k = 0; k <= len3; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    dp_table[i][j][k] = 0;
                }
                else if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) {
                    dp_table[i][j][k] = dp_table[i - 1][j - 1][k - 1] + 1;
                    if (dp_table[i][j][k] > max_len) {
                        max_len = dp_table[i][j][k];
                        max_end = i;
                    }
                }
                else {
                    dp_table[i][j][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            free(dp_table[i][j]);
        }
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
    char input3[100];
    char* result = NULL;
    int length;

    while (1) {
        printf("입력1 : ");
        scanf("%99s", input1);

        if (strcmp(input1, "quit") == 0)
            break;

        printf("입력2 : ");
        scanf("%99s", input2);

        printf("입력3 : ");
        scanf("%99s", input3);

        length = f_CommonSubstring(input1, input2, input3, &result);
        printf("출력 : %s / %d\n", result, length);

        free(result);
        result = NULL;
    }
    return 0;
}

