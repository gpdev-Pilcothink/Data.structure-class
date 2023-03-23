#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int Stack_Empty(int s_top);
void Push(int *stack, int *s_top, int N,int num); //N==최대배열, num=들어갈 숫자.
int pop(int* stack, int *s_top);
int size(int s_top);
int top(int *stack, int s_top);

int main() {
	int *stack;
	int s_top = 0;
	int N; 
	scanf("%d", &N); 
	stack = (int*)malloc(sizeof(int) * N);
	return 0;
}
int Stack_Empty(int s_top) {
	if (s_top == 0)
		return 1; //비었음
	else
		return 0; //안 비어있음
}
void Push(int* stack, int *s_top, int N,int num) {
	if (s_top == N)
		return 0; //배열이 다 차있음
	*(stack + *s_top) = num;
	*s_top+=1;
	return 1;
}
int pop(int* stack, int *s_top) {
	if (*s_top == 0)
		return -1; //비었음
	*s_top-=1;
	return *(stack + *s_top);
}
int size(int s_top) {
	return s_top;
}
int top(int *stack, int s_top) {
	if (s_top == 0)
		return -1;
	return *(stack + (s_top-1));
}