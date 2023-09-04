#include <stdio.h>
#pragma warning(disable:4996)

int cnt=0;
int N;//q�� ũ��
int q_tail = 0, q_head = 1;

void enqueue(int queue[], int n);
int dequeue(int queue[]);
int size(); //ť�� ��� �ִ� ������ ����
int empty(); //ť�� ����ִ��� Ȯ��(�������1 �ƴϸ� 0)
int front(int queue[]); //ť�� �Ǿ� ���
int back(int queue[]); //ť�� �ǵ� ���

int main() {
	int N;
	int* queue;
	char command[6] = { 0 };
	scanf("%d", &N);
	queue = (int*)malloc(sizeof(int) * N+1); 
	for (int i = 0; i < N; i++) {
		int num = 0;
		scanf("%s", command);
		if (strcmp(command, "push") == 0) {
			scanf("%d", &num);
			enqueue(queue,num);
		}
		else if (strcmp(command, "pop") == 0) {
			printf("%d\n", dequeue(queue));
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", size());
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(command, "front") == 0) {
			printf("%d\n", front(queue));
		}
		else if (strcmp(command, "back") == 0) {
			printf("%d\n", back(queue));
		}
	}
	free(queue);
	return 0;
}


void enqueue(int queue[], int n) {
	queue[q_tail+1] = n;
	if (q_tail == N) //tail�� �迭 ���� �ִ°��
		q_tail = 1;
	else q_tail = q_tail + 1;
	cnt++;
}
int dequeue(int queue[]) {
	if (cnt == 0)
		return -1;
	int x = queue[q_head];
	if (q_head == N)
		q_head = 1;
	else q_head = q_head + 1;
	cnt--;
	return x;
}
int size() {
	return cnt;
}
int empty() {
	if (cnt == 0)
		return 1;
	else
		return 0;
}
int front(int queue[]) {
	if (cnt == 0)
		return -1;
	return queue[q_head];
}
int back(int queue[]) {
	if (cnt == 0)
		return -1;
	return queue[q_tail];
}