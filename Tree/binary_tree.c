/*트리 용어 정리
* 내부노드: 한개의 자식을 가지는 노드
* 외부노드: 잎(leaf)라고도 불르며, 자식이 없는 노드
* 형제노드: 같은 부모를 가진 노드
* 조상노드: 해당 노드에서 루트를 따라 올라가며 만나게 되는 부모 이상의 노드들
* 자손노드: 해당 노드에서 잎(외부노드)를 따라 간선을 통해 내려가며 만나게 되는 자식 이하의 노드들
* 부트리: 노드와 그노드의 자손들로 구성된 트리
* 경로길이: 경로 내 간선의 수
* 노드깊이: 루트로부터 해당 노드에 이르는 유일한 경로의 길이
* 노드높이: 해당 노드에서 외부노드에 이르는 가장 긴 경로의 길이
*/

#include <stdio.h>
#include <stdbool.h> //c99에서 추가된 새로운 헤더파일
#pragma warning(disable:4996)

typedef struct node {
	int elem; // 이건 항상 바뀔 수 있다. 문제에 따라 자연스럽게 조절하자
	struct node* left;
	struct node* right;
}node;

//리스트 ADT
node* getnode();
//이진트리ADT
bool isInternal(node *v); 
bool isExternal(node *v);
void binaryPreOrder(node *v);//선위순회(재귀)
void binarypostOrder(node *v);//후위순회 (재귀)
void inOrder(node *v); //중위순회 ==> 이진트리에서 가능한 순회방식

int main(){

}


//리스트 ADT
node* getnode() {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->left = NULL;
	newnode->elem = 0;
	newnode->right = NULL;
	return newnode;
}
//이진트리ADT
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
	//노드 v의 원소값 방문
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
	//노드 v의 원소값 방문
}
void inOrder(node* v){ 
	if(isInternal(v))
		inOrder(v->left);
	//노드 v의 원소값 방문
	if(isInternal(v))
		inOrder(v->right);
}