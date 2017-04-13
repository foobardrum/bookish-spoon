// Tobias Egger, 16-728-016

#include <stdio.h>
#include <stdlib.h>

#define NIL 0

struct node {
	int val;
	struct node* next;
};

struct list {
	struct node* head;
};

struct list* init(){
	struct list* root;
	struct node* p;
	root = malloc(sizeof(struct list));
	// use Head as a guard knot
	root->head = malloc(sizeof(struct list));
	root->head->next = NIL;
	return root;	
}
void append(struct list *listA, int val){
	struct node* p;
	p = listA->head;
	while (p->next != NIL){
		p = p->next;
	}
	p->next = malloc(sizeof(struct node));
	p = p->next;
	p->val = val;
	p->next = NIL;
}
void print(struct list *listA){
	struct node* p;
	p = listA->head->next;
	printf("[ ");
	while (p != NIL){
		printf("%d ", p->val);
		p = p->next;
	}
	printf("]\n");
}

void delete(struct list *listA, int i){
	int j;
	struct node* p;
	struct node*q;
	if (i == 0){
		q = listA->head->next->next;
		free(listA->head->next);
		listA->head->next = q;
	}else{
		p = listA->head->next;
		j = 0;
		while (p->next->next != NIL && j<i-1){
			p = p->next;
			j++;
		}
		if (p->next->next == NIL){
			free(p->next);
			p->next = NIL; 
		}else{
			q = p->next->next;
			free(p->next);
			p->next = q;
		}
	}
	
}

int main(){
	struct list* list1 = init();
	
	append(list1, 9);
	append(list1, 4);
	append(list1, 5);
	append(list1, 3);
	append(list1, 1);
	append(list1, 2);
	append(list1, 0);
	
	print(list1);
	
	delete(list1,6);
	delete(list1,3);
	delete(list1,0);
	
	print(list1);
	
	return 0;
}


