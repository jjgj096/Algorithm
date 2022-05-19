#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int recur_search(int low, int high, int* list, int target) {		//����Լ��� ����� ����Ž�� �Լ� ����
	int mid;

	if (low > high)		//target�� �迭�� �������� �ʴ� ���
		return -1;

	mid = (low + high) / 2;		//�߰��������� Ž�� ����.

	if (target == list[mid])	//target�� ã�� ���
		return mid;				//�ش� mid�� ��ȯ

	else if (target < list[mid])	//target�� �߰������� ���� ���
		return recur_search(low, mid - 1, list, target);	//�� ���ʿ��� ã�� ���� high�� ����

	else {				//target�� �߰������� Ŭ ���
		return recur_search(mid + 1, high, list, target);	//�� �����ʿ��� ã�� ���� low�� ����
	}
}

int main(void) {
	int n;			//�迭�� ũ�⸦ ������ ����.
	int i;
	int* ary;


	printf("배열 크기를 입력하세요 :");
	scanf("%d", &n);	//�迭�� ũ�⸦ �Է¹ް�, n�� ����.

	ary = (int*)malloc(sizeof(int) * n);	//�Է¹��� n���� ũ���� �迭�� ������.

	printf("배열에 들어갈 수를 입력하세요: ");
	for (i = 0; i < n; i++) {				//n���� ���� ������� �迭�� ������.
		scanf("%d", &ary[i]);
	}

	int key;								//ã�� ��ǥ�� ����

	printf("찾을 수를 입력하세요 : ");		//ã�� Ÿ���� �Է¹���.
	scanf("%d", &key);

	printf("이진 탐색을 시작합니다.");

	int index;								//recur_search �Լ��� ������ ���� int ����
	index = recur_search(0, n, ary, key);	//����Լ� ȣ��

	if (index == -1)						//���ϰ��� ���� ��Ȳ�� ����.
		printf("실패");
	else
		printf("%d", index+1);


	free(ary);			//�����Ҵ��� ������.

	return 0;

}