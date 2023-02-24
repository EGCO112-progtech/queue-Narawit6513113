#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;
  Queue  q;
  q.headPtr=NULL;
  q.tailPtr=NULL;
  q.size=0;

   int i,price,Cash,Customer_count = 0,order_count = 0;
   

 for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0)
        {
            Customer_count++;
            printf("Customer no : %d\n",Customer_count);
            price = dequeue_struct(&q);
            printf("\nYou have to pay %d\n",price);
            if(price > 0)
            {
              do
              {
                printf(":Cash: ");
                scanf("%d",&Cash);
              }while(Cash<price);
            }
            printf("Thank you\n");
            if(Cash>price)printf("Change is : %d\n",Cash-price);
        }
        else 
        {
          enqueue_struct( &q , atoi(argv[i]) , atoi(argv[i+1]) );
          printf("My order is %d\n",atoi(argv[i]));
          i++;
        }
 }
 printf("=============================================================\n");
if(q.size == 0) printf("No ppl left in the queue");
else if(q.size != 0 && q.size > 1) printf("There are %d ppl left in the queue\n",q.size);
else printf("There is %d ppl left in the queue\n",q.size);
printf("Clearing queue\n");
while(q.size>0) dequeue_struct(&q);
  return 0;
}
