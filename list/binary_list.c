/*Ʈ�� ��� ����
* ���γ��: �Ѱ��� �ڽ��� ������ ���
* �ܺγ��: ��(leaf)��� �Ҹ���, �ڽ��� ���� ���
* �������: ���� �θ� ���� ���
* ������: �ش� ��忡�� ��Ʈ�� ���� �ö󰡸� ������ �Ǵ� �θ� �̻��� ����
* �ڼճ��: �ش� ��忡�� ��(�ܺγ��)�� ���� ������ ���� �������� ������ �Ǵ� �ڽ� ������ ����
* ��Ʈ��: ���� �׳���� �ڼյ�� ������ Ʈ��
* ��α���: ��� �� ������ ��
* ������: ��Ʈ�κ��� �ش� ��忡 �̸��� ������ ����� ����
* ������: �ش� ��忡�� �ܺγ�忡 �̸��� ���� �� ����� ����
*/

#include <stdio.h>
#include <stdbool.h> //c99���� �߰��� ���ο� �������
#pragma warning(disable:4996)

typedef struct node {
	int elem; // �̰� �׻� �ٲ� �� �ִ�. ������ ���� �ڿ������� ��������
	struct node* left;
	struct node* right;
}node;

//����Ʈ ADT
node* getnode();
//����Ʈ��ADT
bool isInternal(node *v); 
bool isExternal(node *v);
void binaryPreOrder(node *v);//������ȸ(���)
void binarypostOrder(node *v);//������ȸ (���)
void inOrder(node *v); //������ȸ ==> ����Ʈ������ ������ ��ȸ���

int main(){

}


//����Ʈ ADT
node* getnode() {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->left = NULL;
	newnode->elem = 0;
	newnode->right = NULL;
	return newnode;
}
//����Ʈ��ADT
bool isInternal(node* v){
	if(v->right!=NULL || v->left!=NULL)
		return true;
	else
		return false;
}
bool isExternal(node* v){
	if (v->right == NULL && v->left == NULL)
		return true;
	else
		return false;
}
void binaryPreOrder(node* v){
	//��� v�� ���Ұ� �湮
	if(isInternal(v)){
		binaryPreOrder(v->left);
		binaryPreOrder(v->right);
	}
	
}
void binarypostOrder(node* v){
	if (isInternal(v)) {
		binaryPreOrder(v->left);
		binaryPreOrder(v->right);
	}
	//��� v�� ���Ұ� �湮
}
void inOrder(node* v){ 
	if(isInternal(v))
		inOrder(v->left);
	//��� v�� ���Ұ� �湮
	if(isInternal(v))
		inOrder(v->right);
}