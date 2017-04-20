//Maximilian Böker ; 16-706-137
#include <stdio.h>
#include <stdlib.h>
#define NIL 0

struct list {
struct node* head;
};

struct node {
	int val;
	struct node* next;
};

struct list* init(){
	struct list* root;
	root = malloc(sizeof(struct list));
	root->head = malloc(sizeof(struct node));
	root->head->next = NIL;
	return root;
}

void append(struct list *listA, int val){
	struct node* p = listA->head;
	while(p->next != NIL){
		p = p->next;
	}
	p->next = malloc(sizeof(struct node));
	p->next->val = val;
	p = p->next;
	p->next = NIL;
}

void print(struct list* listA){
	struct node* p = listA->head->next;
	while(p != NIL){
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

void delete(struct list* listA, int i){
	struct node* p = listA->head;
	while(i!=0){
		p = p->next;
		i--;
	}
	if(p->next->next == NIL){
		free(p->next);
		p->next = NIL;
	}
	else{
		struct node* tmp = p->next;
		p->next = tmp->next;
		free(tmp);
	}	
}

int main(){
	struct list* l1 = init();
	append(l1, 9);
	append(l1, 4);
	append(l1, 5);
	append(l1, 3);
	append(l1, 1);
	append(l1, 2);
	append(l1, 0);
	
	print(l1);
	
	delete(l1,6);
	delete(l1,3);
	delete(l1,0);
	
	print(l1);

	return 0;
}
