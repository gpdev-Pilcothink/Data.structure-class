#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//이중 연결 리스트를 위한 구조체 선언 부분
typedef struct node {
	int elem; // 이건 항상 바뀔 수 있다. 문제에 따라 자연스럽게 조절하자
	struct node* prev;
	struct node* next;
}node;

typedef struct {
	node* header;
	node* trailer;
	int n; //노드 개수
}double_linked_list;

double_linked_list* list;

//리스트 ADT
void initialize();
node* getnode();
int get(int r);  //r번째 원소 반환
void add(int r, int e);
void addFisrt(int e);
void addLast(int e);
void element_set(int r, int e);//r번째 원소 e로 변경
int element_remove(int r);
int element_romoveFisrt();
int element_removeLast();
void traverse();
void invalidRankException();
void FullListException();
void emptyListException();
//연결리스트 구현시 필요한 함수
void addNodeBefore(node* p, int e);
int removeNode(node* p);

int main() {
	list=(double_linked_list *)malloc(sizeof(double_linked_list));
	initialize();
	free(list);
	return 0;
}

//리스트 ADT
void initialize() {
	list->header = getnode();
	list->trailer = getnode();
	list->header->next = list->trailer;
	list->trailer->prev = list->header;
	list->n = 0;
	return;
}
node* getnode() {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->prev = NULL;
	newnode->elem = 0;
	newnode->next = NULL;
	return newnode;
}
int get(int r) {
	node* p;

	if (r<1 || r>list->n) {
		invalidRankException();
		return 0;
	}
	p = list->header;
	for (int i = 1; i <= r; i++) {
		p = p->next;
	}
	return p->elem;
}
void add(int r, int e) {
	node* p;

	if (r < 1 || (r > list->n + 1)) {
		invalidRankException();
		return;
	}
	p = list->header;
	for (int i = 1; i <= r; i++) {
		p = p->next;
	}
	addNodeBefore(p, e);
	list->n += 1;
	return;
}
void addFisrt(int e) {
	node* p;
	p = list->header->next;
	addNodeBefore(p, e);
	list->n += 1;
	return;
}
void addLast(int e) {
	node* p;
	p = list->header;
	for (int i = 1; i <= list->n; i++) {
		p = p->next;
	}
	addNodeBefore(p, e);
	list->n += 1;
	return;
}
void element_set(int r, int e) {
	node* p;
	if (r < 1 || (r > list->n)) {
		invalidRankException();
		return;
	}
	p = list->header;
	for (int i = 1; i <= r; i++) {
		p = p->next;
	}
	p->elem = e;
}
int element_remove(int r) {
	node* p; 
	int e = 0;
	if (r<1 || r > list->n) {
		invalidRankException();
		return 0;
	}
	if (list->n == 0) {
		emptyListException();
		return 0;
	}
	p = list->header;
	for (int i = 1; i <= r; i++) {
		p = p->next;
	}
	e = removeNode(p);
	list->n -= 1;
	return e;
}
int element_romoveFisrt() {
	node* p;
	int e = 0;
	if (list->n == 0) {
		emptyListException();
		return 0;
	}
	p = list->header->next;
	e = removeNode(p);
	list->n -= 1;
	return e;
}
int element_removeLast() {
	node* p;
	p = list->header;
	int e = 0;
	if (list->n == 0) {
		emptyListException();
		return 0;
	}
	for (int i = 1; i <= list->n; i++) {
		p = p->next;
	}
	e = removeNode(p);
	list->n -= 1;
	return e;
}
void traverse() {
	node* p;
	p = list->header->next;
	while (p != list->trailer) {
		printf("%c", p->elem);
		//여기 위로 원소 방문 행위 코드 입력
		p = p->next;

	}
	printf("\n");
	return;
}
void invalidRankException() {
	printf("invalid position");
}
void FullListException() {
	printf("invalid position");
}
void emptyListException() {
	printf("invalid position");
}
//연결리스트 구현시 필요한 함수
void addNodeBefore(node* p, int e) {
	node* q;
	q = getnode();
	q->elem = e;
	q->prev = p->prev;
	q->next = p;
	p->prev->next = q;
	p->prev = q;
	return;
}
int removeNode(node* p) {
	int e;
	e = p->elem;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	return e;
}
