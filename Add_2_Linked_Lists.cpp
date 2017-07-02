/*struct Node
{
    int data;
   Node* next;
}; */

Node* reverse(Node *head)
{
  // Your code here
  if(head == NULL)return head;
  else if(head->next == NULL)return head;
  else
  {
      struct Node *p = head,*next=NULL,*prev;
      while(p!=NULL)
      {
          next = p->next;
          
         if(p == head)
         {
             p->next = NULL;
             prev = p;
         }
         else
         {
             //do something
             p->next = prev;
             prev = p;
         }
         p=next;
      }
      head = prev;
       p = head;
      printf("reversed list: \n");
      while(p!=NULL)
      {
            printf("%d ",p->data);
            p = p->next;
      }
  }
 
  return head;
}
//write a function returns the resultant linked list
Node*  addTwoLists(Node* first, Node* second){
  // Code here
  //struct Node *first = reverse(first);
  //struct Node *second = reverse(second);
  struct Node *res,*prev,*headRes;
  int carry = 0,i=0;
  while(first!=NULL && second!=NULL)
  {
      res = (struct Node*)malloc(sizeof(Node));
      if(i==0)
      headRes = res;
      else if(i > 0)
      {
          prev->next = res;
      }
      res->data = first->data + second->data + carry;
      carry = 0;
    //   printf("first data: %d\n",first->data);
    //   printf("second data: %d\n",second->data);
    //   printf("res data: %d\n",res->data);
      if(res->data>9)
      {
          carry = res->data / 10;
          res->data = res->data % 10;
      }
    //   printf("carry: %d\n",carry);
      res->next=NULL;
      first=first->next;
      second=second->next;
      prev = res;
      i++;
  }
  if(first == NULL && second!=NULL)
  {
      while(second!=NULL)
      {
        res = (struct Node*)malloc(sizeof(Node));
        prev->next = res;
        res->data = second->data + carry;
        carry = 0;
        if(res->data>9)
        {
            carry = res->data / 10;
            res->data = res->data % 10;
        }
        res->next=NULL;
        second = second->next;
        prev = res;
      }
  }
  else if(first!=NULL && second==NULL)
  {
      while(first!=NULL)
      {
        res = (struct Node*)malloc(sizeof(Node));
        prev->next = res;
        res->data = first->data + carry;
        carry = 0;
        if(res->data>9)
        {
            carry = res->data / 10;
            res->data = res->data % 10;
        }
        res->next=NULL;
        first = first->next;
        prev = res;
      }
  }
  if(carry)
  {
      res = (struct Node*)malloc(sizeof(Node));
      res->data = carry;
      prev->next = res;
  }
  res->next =NULL;
  
  return headRes;
}