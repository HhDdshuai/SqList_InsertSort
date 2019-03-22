#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef int elemType;
typedef struct LNode{
	elemType data;
	struct LNode *next;
}LNode;
LNode *createList(elemType arr[],int n){
	LNode *L,*r,*s;
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL){
		printf("ƒ⁄¥Ê∑÷≈‰ ß∞‹.\n");
		exit(0);
	}
	r = L;
	for(int i = 0;i < n;i++){
		s = (LNode *)malloc(sizeof(LNode));
		if(s == NULL){
			printf("ƒ⁄¥Ê∑÷≈‰ ß∞‹.\n");
			exit(0);
		}
		s->data = arr[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}
void printList(LNode *L){
	LNode *p;
	p = L->next;
	while(p != NULL){
		printf("%d->",p->data);
		p = p->next;
	}
	printf("\n");
}
void SqList_InsertSort(LNode **L){
	LNode *p,*q,*pre;
	p = (*L)->next->next;
	(*L)->next->next = NULL;
	while(p != NULL){
		q = p->next;
		pre = (*L);
		while((pre->next != NULL) && (pre->next->data <= p->data))
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}
int main(){
	elemType a[] = {14,8,5,12,9,15,36,21,26,41,89,35,36,91,67};
	int len = sizeof(a)/sizeof(a[0]);
	LNode *L;
	L = createList(a,len);
	printList(L);
	SqList_InsertSort(&L);
	printf("After sort:\n");
	printList(L);
}