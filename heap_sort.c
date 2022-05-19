#include <stdio.h>
#include <stdlib.h>

void heapsort(int ary[], int size) {			
	for (int i = 1; i < size; i++) {
		int child = i;
		do {
			int parent = (child - 1) / 2;	

			if (ary[parent] < ary[child]) {	
				int temp = ary[parent];
				ary[parent] = ary[child];
				ary[child] = temp;
			}
			child = parent;
		} while (child != 0);				
	}

	for (int i = size - 1; i > 0; i--) {	
		int temp = ary[0];
		ary[0] = ary[i];
		ary[i] = temp;
		int parent = 0;
		int child = 1;
		int count = 0;

		do {							
			child = parent * 2 + 1;
			if (ary[child] < ary[child + 1] && child < i - 1) 
				child++;
			if (ary[parent] < ary[child] && child < i) {			
				temp = ary[parent];
				ary[parent] = ary[child];
				ary[child] = temp;
			}parent = child;
		} while (child < i);
		count++;
		if (count <= 3) {
			for (int a = 0; a < size; a++)
				printf("%d ", ary[a]);
		}
		printf("\n");
	}
}
int main(void) {
	int ary[8] = { 12, 30, 21, 55, 25, 72, 45, 50 };
	printf("정렬을 시작합니다.\n");
	heapsort(ary, 8);
	printf("정렬을 완료했습니다. ");
	for (int i = 0; i < 8; i++)
		printf("%d ", ary[i]);
}
