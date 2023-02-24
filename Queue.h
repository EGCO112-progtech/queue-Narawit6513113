#define price_somtum 20
#define price_ramen 100
#define price_FriedChicken 50

typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x ,int y){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node)
{
  new_node->order_number = x;
  new_node->qty = y;
  new_node->nextPtr = NULL;
  if(q->headPtr == NULL) q->headPtr = new_node;
  else q->tailPtr->nextPtr = new_node;
  q->tailPtr = new_node;
  q->size++;

  /*Finish enqueue */
 }
}


int dequeue_struct(Queue *q){
   NodePtr t=q->headPtr;
   int price ;
   if(q->size > 0)
   {
     switch(t->order_number)
     {
       case 1 : printf("Ramen");
       price = 100*(t->qty);
       break;
       case 2 : printf("Somtum");
       price = 20*(t->qty);
       break;
       case 3 : printf("Fried Chicken");
       price = 50*(t->qty);
       break;
       default : printf("No food");
       break;
     }

   }
   q->headPtr = t->nextPtr;
   if(q->headPtr == NULL) q->tailPtr = NULL;
   free(t);
   q->size--;
   return price;
}

