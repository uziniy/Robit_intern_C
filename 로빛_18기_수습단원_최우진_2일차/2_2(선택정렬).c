//
//  main.c
//  선택정렬
//
//  Created by 최우진 on 2023/07/19.
//

#include <stdio.h>

//값 변환해주는 함수
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//선택정렬 알고리즘
void selectionSort(int arr[]) {
    for (int i = 7; i > 0; i--) {
        int max = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        if (max != i) {
            swap(&arr[i], &arr[max]);
        }
        for(int j = 0; j < 8; j++){
            printf("%d ",arr[j]);
        }
        printf("\n");
        
        //다 변환 했으면 바꾸는 조건문
        if(arr[0]<arr[1] && arr[1]<arr[2] && arr[2]<arr[3] && arr[3]<arr[4] && arr[4]<arr[5] && arr[6]<arr[7] ){
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    int array[8] = {0};
    for(int i = 0; i< 8; i++){
        printf("%d : ",i);
        scanf("%d",&array[i]);
    }
    for(int j = 0; j < 8; j++){
        printf("%d ",array[j]);
    }
    printf("\n");
    selectionSort(array);
    
    for (int i=0; i<8; i++) {
        printf("%d : %d",i,array[i]);
        printf("\n");
    }
}
