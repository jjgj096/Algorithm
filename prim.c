#include <stdio.h>
#pragma warining (disable : 4996)
#define INF 999 //���� ���̿� ������ �������� ���� ��� 
#define VERTEX_SIZE 10 //������ ����(����)

typedef struct Edge{
	int v1;
	int v2;
}Edge;

Edge edge[VERTEX_SIZE - 1];

int W[VERTEX_SIZE][VERTEX_SIZE] = {
	0, 32,INF, 17, INF, INF, INF, INF, INF, INF,
	32, 0, INF, INF, 45, INF, INF, INF, INF, INF,
	INF, INF, 0, 18, INF, INF, 5, INF, INF, INF,
	17, INF, 18, 0, 10, INF, INF, 3, INF, INF,
	INF, 45, INF, 10, 0, 28, INF, INF, 25, INF,
	INF, INF, INF, INF, 28, 0, INF, INF, INF, 6,
	INF, INF, 5, INF, INF, INF, 0, 59, INF, INF,
	INF, INF, INF, 3, INF, INF, 59, 0, 4, INF,
	INF, INF, INF, INF, 25, INF, INF, 4, 0, 12,
	INF, INF, INF, INF, INF, 6, INF, INF, 12, 0
};

void prim(int start); 
int IsVertex(int vertex[], int a); 


void main(void) {
	printf("----Minimum Spanning Tree----\n\n");
	printf("최소 신장 트리를 만드는 과정");
	prim(2);
	for (int i = 0; i < VERTEX_SIZE - 1; i++)
		printf("(v%d , v%d) is selected\n", edge[i].v1 + 1, edge[i].v2 + 1);
}

void prim(int start) {
	int vertex[VERTEX_SIZE] = { 0, };
	int p, q, adjacent, check = 0, index = 0;
	vertex[check++] = start; 
	while (check < VERTEX_SIZE) {
			adjacent = INF;
			for (int i = 0; i < check; i++) {
				p = vertex[i];
				for (int j = 0; j < VERTEX_SIZE; j++) {
						q = W[j][p];
					if (q > 0 && q < INF && !IsVertex(vertex, j)) {
							if (q < adjacent) { 
									adjacent = q; 
								edge[index].v1 = p; 
									edge[index].v2 = j; 
							}
					}
				}
			}
		vertex[check++] = edge[index].v2; 
			index++;
	}
}

int IsVertex(int vertex[], int tmp) {
	for (int i = 0; i < VERTEX_SIZE; i++) 
		if (vertex[i] == tmp) 
			return 1;
	return 0;
}