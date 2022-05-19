#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int list[], int left, int mid, int right, int tmp[]) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {		
		if (list[i] <= list[j])
			tmp[k++] = list[i++];
		else
			tmp[k++] = list[j++];
	}
	while (i <= mid)					
		tmp[k++] = list[i++];
	while (j <= right)					
		tmp[k++] = list[j++];

	for (int l = left; l <= right; l++)		
		list[l] = tmp[l];

	for (int a = left; a <= right; a++)
		printf("%d ", tmp[a]);
	printf("\n");
}

void mergesort(int list[], int p, int r) {
	int left, right, k;
	left = p;
	right = r;
	int store;
	store = r + 1;										
	int* tmp;
	tmp = (int*)malloc(sizeof(int) * store);			

	if (left < right) {
		k = (left + right) / 2;				
		mergesort(list, left, k);			
		mergesort(list, k + 1, right);		
		merge(list, left, k, right, tmp);		
	}
	free(tmp);
}

int main(void) {
	int n;			
	int* ary;		

	printf("배열의 크기를 입력하세요:");
	scanf("%d", &n);	

	ary = (int*)malloc(sizeof(int) * n);	


	printf("배열에 저장할 수를 입력하세요 : ");
	for (int i = 0; i < n; i++) {				
		scanf("%d", &ary[i]);
	}

	printf("정렬을 시작합니다.\n");

	mergesort(ary, 0, n - 1);

	printf("정렬을 완료했습니다.\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", ary[i]);
	}

	free(ary);

	return 0;
}
