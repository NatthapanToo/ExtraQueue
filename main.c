#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#include "queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;
  Queue  q;
  q. headPtr=NULL;
  q.tailPtr=NULL;
  q.size=0;
  int i,x,j=1;
  int order_quantity;
  int order_num;
 for(i=1;i<argc;i++){
    if(strcmp(argv[i],"x")!=0){
        order_num = atoi(argv[i]);
        if(order_num>=1&&order_num<=3){
            order_quantity = atoi(argv[i+1]); 
            enqueue_struct(&q, order_num,order_quantity);
            printf("My order is %d\n",order_num);
            //printf("%c",argv[i][0]);
        }else printf("No Food\n");
        i++;
    }
    else{
        if(q.size!=0) {
            printf("Customer no: %d\n",j);
            dequeue_struct(&q);
            j++;

        }else printf("the queue is empty\n");
    }
 }
 printf("============================================\n");
 printf(" There are %d ppl left in the queue",q.size);
 return 0;
}
