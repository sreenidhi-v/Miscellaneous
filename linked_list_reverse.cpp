/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/

// Should reverse list and return new head.
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
  }
  return head;
}

/*function for linked list reversal */