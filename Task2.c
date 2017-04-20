// Tobias Egger, 16-728-016

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	printf("]");
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
int getVal(struct list* listA){
	struct node* p;
	int i, sum, exp;
	sum = 0;
	exp = 1;
	p = listA->head->next;
	while(p != NIL){
		sum = sum+((p->val)*exp);
		p = p->next;
		exp = exp*10;
	}
	return sum;
}
struct list* addTwoLists (struct list* numA, struct list* numB){
	int a = getVal(numA);
	int b = getVal(numB);
	int sum = a+b;
	struct list* result = init();
	
	if (sum == 0){
		append(result, 0);
		return result;
	}else{
		while (sum > 0) {
			int	digit = sum % 10;
			append(result, digit);
			sum = sum/10;
		}
		return result;
	}
}

int main(){
	struct list* l1 = init();
	struct list* l2 = init();
	
	append(l1, 5);
	append(l1, 8);
	append(l1, 3);
	
	append(l2, 5);
	append(l2, 1);
//	printf("%d", getVal(l1));
	print(l1);
	printf(" + ");
	print(l2);
	printf(" = ");
	print(addTwoLists(l1,l2));
	
	return 0;
}


