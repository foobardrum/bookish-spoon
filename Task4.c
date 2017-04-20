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

int main(){
	struct queue* q1 = init();

	enqueue(q1,4);
	enqueue(q1,7);
	enqueue(q1,1);
	enqueue(q1,2);

	print(q1);
	
	printf("Dequeued: %d\n",dequeue(q1));
	printf("Dequeued: %d\n",dequeue(q1));
	
	print(q1);
	
	return 0;
}
