#ifndef Queue_h
#define Queue_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x,int order_quantity){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){ 
  /*Finish enqueue */
  if(q->size==0) q->headPtr=new_node;
  else q->tailPtr->nextPtr=new_node;
  q->tailPtr=new_node;
  q->tailPtr->data=x;
  q->tailPtr->quantity=order_quantity;
  q->size++;
 }
}


void dequeue_struct(Queue *q){
   NodePtr t=q->headPtr;
   int cash,price,sum=0;
   if(t){
   int value= t->data;
   int order_quantity=t->quantity;
   /* Finish dequeue*/
   q->headPtr=q->headPtr->nextPtr;
   free(t);
   if(q->size==0) q->tailPtr=NULL;
   switch(value){
    case 1 : 
        printf("Ramen\n");
        price = 100*order_quantity;
        break;
    case 2 : 
        printf("Somtum\n");
        price = 20*order_quantity;
        break;
    case 3 : 
        printf("Fried Chicken\n");
        price = 50*order_quantity;
        break;
    default:
        break;
    }
    printf("You have to pay %d\n",price);
    do
    {
        printf(":Cash:");
        scanf("%d",&cash);
        sum+=cash;
    }while(sum<price);
    printf("Thank you\n");
    if(sum>price) printf("Change is:%d\n",sum-price);

    q->size--;
   //return value;
   }
   //return 0;
}
#endif

