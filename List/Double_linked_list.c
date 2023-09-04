#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

//���� ���� ����Ʈ�� ���� ����ü ���� �κ�
typedef struct node {
	int elem; // �̰� �׻� �ٲ� �� �ִ�. ������ ���� �ڿ������� ��������
	struct node * prev;
	struct node * next;
}node;

typedef struct {
	node *header;
	node *trailer;
	int n; //��� ����
}double_linked_list;

double_linked_list* list;

//����Ʈ ADT
void initialize();
node * getnode();
int get(int r);  //r��° ���� ��ȯ
void add(int r, int e);
void addFisrt(int e);
void addLast(int e);
void element_set(int r, int e);//r��° ���� e�� ����
int element_remove(int r);
int element_romoveFisrt();
int element_removeLast();
void traverse();
void invalidRankException();
void FullListException();
void emptyListException();
//���Ḯ��Ʈ ������ �ʿ��� �Լ�
void addNodeBefore(node *p, int e);
int removeNode(node *p);

int main(){
	

}

//����Ʈ ADT
void initialize(){
	list->header=getnode();
	list->trailer=getnode();
	list->header->next=list->trailer;
	list->trailer->prev=list->header;
	list->n=0;
	return;
}
node* getnode(){
	node *newnode= (node *)malloc(sizeof(node));
	newnode->prev = NULL;
	newnode->elem = 0;
	newnode->next = NULL;
	return newnode;
}
int get(int r){
	node *p;

	if(r<1 || r>list->n){
		invalidRankException();
	}
	p = list->header;
	for(int i=1; i<=r; i++){
		p=p->next;
	}
	return p->elem;
} 
void add(int r, int e){
	node *p;

	if(r<1|| (r>list->n+1)){
		invalidRankException();
		return;
	}
	p=list->header;
	for(int i=1; i<=r; i++){
		p=p->next;
	}
	addNodeBefore(p,e);
	list->n+=1;
	return;
}
void addFisrt(int e){
	node* p;
	p=list->header->next;
	addNodeBefore(p,e);
	list->n+=1;
	return ;
}
void addLast(int e){
	node* p;
	p=list->header;
	for (int i = 1; i <= list->n; i++) {
		p = p->next;
	}
	addNodeBefore(p, e);
	list->n += 1;
	return;
}
void element_set(int r, int e){
	node* p;
	if (r<1 || (r > list->n)) {
		invalidRankException();
		return ;
	}
	p = list->header;
	for (int i = 1; i <= r; i++) {
		p = p->next;
	}
	p->elem=e;
}
int element_remove(int r){
	node* p;
	int e=0;
	if (r<1 || r > list->n) {
		invalidRankException();
		return;
	}
	if (list->n == 0) {
		emptyListException();
		return;
	}
	p = list->header;
	for(int i=1; i<=r; i++){
		p=p->next;
	}
	e=removeNode(p);
	list->n-=1;
	return e;
}
int element_romoveFisrt(){
	node* p;
	int e = 0;
	if (list->n == 0) {
		emptyListException();
		return;
	}
	p = list->header->next;
	e=removeNode(p, e);
	list->n -= 1;
	return e;
}
int element_removeLast(){
	node* p;
	p=list->header;
	int e = 0;
	if (list->n == 0) {
		emptyListException();
		return;
	}
	for (int i = 1; i <= list->n; i++) {
		p = p->next;
	}
	e = removeNode(p, e);
	list->n -= 1;
	return e;
}
void traverse(){
	node *p;
	p=list->header->next;
	while(p!=list->trailer){
		printf("%c", p->elem);
		//���� ���� ���� �湮 ���� �ڵ� �Է�
		p=p->next;

	}
	printf("\n");
	return;
}
void invalidRankException(){
	printf("���� �Ҽ� ���� ������ �����Ͽ����ϴ�. �ٽ� �õ��Ͻʽÿ�.");
}
void FullListException(){
	printf("����Ʈ�� �̹� �����Դϴ�. �ٽ� �õ��Ͻʽÿ�.");
}
void emptyListException(){
	printf("����Ʈ�� �ƹ��͵� �������� �ʽ��ϴ�. �ٽ� �õ��Ͻʽÿ�.");
}
//���Ḯ��Ʈ ������ �ʿ��� �Լ�
void addNodeBefore(node *p, int e){
	node *q;
	q=getnode();
	q->elem=e;
	q->prev=p->prev;
	q->next=p;
	p->prev->next=q;
	p->prev=q;
	return;
}
int removeNode(node* p){
	int e;
	e=p->elem;
	p->prev->next=p->next;
	p->next->prev=p->prev;
	free(p);
	return e;
}