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


	printf("�迭�� ũ�⸦ �Է��ϼ��� :");
	scanf("%d", &n);	//�迭�� ũ�⸦ �Է¹ް�, n�� ����.

	ary = (int*)malloc(sizeof(int) * n);	//�Է¹��� n���� ũ���� �迭�� ������.

	printf("�迭�� ������ ���� �Է��ϼ��� : ");
	for (i = 0; i < n; i++) {				//n���� ���� ������� �迭�� ������.
		scanf("%d", &ary[i]);
	}

	int key;								//ã�� ��ǥ�� ����

	printf("ã�� ���� �Է��ϼ��� : ");		//ã�� Ÿ���� �Է¹���.
	scanf("%d", &key);

	printf("���� Ž���� �����մϴ�.");

	int index;								//recur_search �Լ��� ������ ���� int ����
	index = recur_search(0, n, ary, key);	//����Լ� ȣ��

	if (index == -1)						//���ϰ��� ���� ��Ȳ�� ����.
		printf("����");
	else
		printf("%d", index+1);


	free(ary);			//�����Ҵ��� ������.

	return 0;

}