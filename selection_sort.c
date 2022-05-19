#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void selecionSort(int list[], int n) {

	int temp;			
	int count = 0;			

	int maxi = 0;	

	for (int i = n; i > 1; i--) {		
		maxi = 0;
		for (int j = 1; j < i; j++) {	

			if (list[j] > list[maxi]) {				
				maxi = j;
			}
		}
		temp = list[i - 1];			
		list[i - 1] = list[maxi];		
		list[maxi] = temp;			
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

	printf("배열에 저장할 수를 입력하세요 : ");
	for (int i = 0; i < n; i++) {			
		scanf("%d", &ary[i]);
	}

	printf("정렬을 시작합니다.\n");

	selecionSort(ary, n);

	printf("정렬을 완료했습니다.\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", ary[i]);
	}

	free(ary);

	return 0;
}