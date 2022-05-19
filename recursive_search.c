#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int recur_search(int low, int high, int* list, int target) {		
	int mid;

	if (low > high)		
		return -1;

	mid = (low + high) / 2;		

	if (target == list[mid])	
		return mid;				

	else if (target < list[mid])	
		return recur_search(low, mid - 1, list, target);	

	else {				
		return recur_search(mid + 1, high, list, target);	
	}
}

int main(void) {
	int n;			
	int i;
	int* ary;


	printf("배열 크기를 입력하세요 :");
	scanf("%d", &n);	

	ary = (int*)malloc(sizeof(int) * n);	

	printf("배열에 들어갈 수를 입력하세요: ");
	for (i = 0; i < n; i++) {				
		scanf("%d", &ary[i]);
	}

	int key;								

	printf("찾을 수를 입력하세요 : ");		
	scanf("%d", &key);

	printf("이진 탐색을 시작합니다.");

	int index;								
	index = recur_search(0, n, ary, key);	

	if (index == -1)						
		printf("실패");
	else
		printf("%d", index+1);


	free(ary);			

	return 0;

}
