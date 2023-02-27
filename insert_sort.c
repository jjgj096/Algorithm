#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertSort(int list[], int n) {

	int j; 
	int num;	
	int count = 0; 

	for (int i = 1; i < n; i++) { 
		num = list[i];			

		for (j = i - 1; j >= 0 && list[j] > num; j--) {  
			list[j + 1] = list[j]; 
		}
		list[j + 1] = num;	
		count++;
		if (count <= 3) {
			for (int k = 0; k < n; k++)
				printf("%d ", list[k]);
			printf("\n");
		}
	}
}

int main(void) {
	int n;			
	int* ary;

	printf("배열의 크기를 입력하세요 :");
	scanf("%d", &n);	

	ary = (int*)malloc(sizeof(int) * n);	

	printf("배열에 저장될 수를 입력하세요 : ");
	for (int i = 0; i < n; i++) {				
		scanf("%d", &ary[i]);
	}

	printf("정렬을 시작합니다.\n");

	insertSort(ary, n);

	printf("정렬을 완료했습니다.\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", ary[i]);
	}

	free(ary);

	return 0;
}
