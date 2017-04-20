// Tobias Egger, 16-728-016

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NIL 0

struct queue {
	int arr[16];
	int head;
	int tail;
};
struct stack {
	struct queue* q1;
	struct queue* q2;
};


struct queue* init(){
	struct queue* root;
	root = malloc(sizeof(struct queue));
	root->head = 0;
	root->tail = 0;
	return root;	
}
int isempty(struct queue* q){
	if (q->head == q->tail){
		return 1;
	}else{
		return 0;
	}
}
void enqueue(struct queue* q, int val){
		q->arr[q->tail] = val;
		q->tail = (q->tail+1) % 16;
}
int dequeue(struct queue* q){
	if(!isempty(q)){
		int val;
		val = q->arr[q->head];
		q->head = (q->head+1) % 16;
		return val;
	}
}
void print(struct queue* q){
	if(isempty(q)){
		printf("\nQueue is empty!\n");
	}else{
		int i=0;
		printf("Stack: [ ");
		while(((q->head)+i)%16 != q->tail){
			printf("%d ",q->arr[(q->head+i)%16]);
			i += 1;
		}
		printf("] \n");
	}
}
struct stack* initStack(){
	struct stack* root = malloc(sizeof(struct stack));
	root->q1 = init();
	root->q2 = init();
}
void swap(struct stack *s){
	struct queue* t = s->q1;
	s->q1 = s->q2;
	s->q2 = t;
}
void push(struct stack* s, int val){
//	printf("Q1\nHead:%d\nTail:%d\n\nQ2\nHead:%d\nTail:%d\n\n",s->q1->head,s->q1->tail,s->q2->head,s->q2->tail);
	enqueue(s->q1, val);
	while (!isempty(s->q2)){
		enqueue(s->q1, dequeue(s->q2));
	}
	swap(s);
}
int pop(struct stack* s){
	return dequeue(s->q2);
}
void printStack(struct stack* s){
	print(s->q2);
}


int main(){
	struct stack* s1 = initStack();
	push(s1,8);
//	printf("Q1\nHead:%d\nTail:%d\n\nQ2\nHead:%d\nTail:%d\n\n",s1->q1->head,s1->q1->tail,s1->q2->head,s1->q2->tail);
	push(s1,9);
	push(s1,12);
	push(s1,3);
	push(s1,5);
	printStack(s1);
	printf("Popped: %d\n",pop(s1));
	printf("Popped: %d\n",pop(s1));
	printf("Popped: %d\n",pop(s1));	
	printStack(s1);
	push(s1,11);
	push(s1,4);
	push(s1,21);
	push(s1,6);
	push(s1,2);
	push(s1,5);
	push(s1,13);
	push(s1,14);
//	printf("%d", s1->q2->arr[s1->q2->tail-1]);
	printStack(s1);
//	printf("Head: %d, Tail: %d\n", s1->q2->head, s1->q2->tail);

//	printf("Head: %d, Tail: %d", s1->q2->head, s1->q2->tail);
//	printf("Popped: %d\n",pop(s1));	
//	printStack(s1);
//	print(s1->q2);


	
	return 0;
}
