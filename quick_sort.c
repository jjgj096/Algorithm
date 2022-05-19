#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int partition(int ary[], int left, int right) {
	int pivot = ary[left];	
	int low = left + 1;
	int high = right;
	int tmp;

	while (low <= high) {	
		while (pivot >= ary[low] && low <= right) 
			low++;
		while (pivot <= ary[high] && high >= (left + 1))
			high--;				
		if (low <= high) {	
			tmp = ary[low];
			ary[low] = ary[high];
			ary[high] = tmp;
		}
	}
	tmp = ary[left];			
	ary[left] = ary[high];
	ary[high] = tmp;
	for (int a = left; a <= right; a++)
		printf("%d ", ary[a]);
	printf("\n");
	return high;
}

void quicksort(int ary[], int left, int right) {
	if (left <= right) {
		int pivot = partition(ary, left, right); 
		quicksort(ary, left, pivot - 1);		
		quicksort(ary, pivot + 1, right);	
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

	quicksort(ary, 0, n - 1);

	printf("정렬을 완료했습니다.\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", ary[i]);
	}

	free(ary);

	return 0;
}
