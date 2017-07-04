/*
  LOGIC for question on geeks for geeks
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *reverse (struct node *head, int k)
{ 
  // Complete this method
  struct node *tmp=head,*prev,*nextp,*headMain,*oldhead=NULL;
  int i = 0;
  while(tmp!=NULL)
  {
      //printf("At: %d\n",tmp->data);
      
      //printf("Head is:%d\n",head->data);
      
      //if(oldhead!=NULL)printf("Old head: %d\n",oldhead->data);
      //else printf("oldhead is NULL\n");
      
      if(tmp==head)
      {
          nextp=tmp->next;
          tmp->next=NULL;
          prev=tmp;
      }
      else
      {
          nextp=tmp->next;
          tmp->next=prev;
          prev=tmp;
      }
      tmp=nextp;
      i++;
      if(i%k==0)
      {
          if(i!=k){ oldhead->next=prev; oldhead=head; head=tmp; }
          else { headMain=prev; oldhead=head; head=tmp; }
      }
  }
  
  if(i%k!=0)
  {
      oldhead->next=prev; oldhead=head; head=tmp;
  }
  //printf("FINAL oldhead %d\n",oldhead->data);
  //printf("FINAL head %d\n",head->data);
  return headMain;
}
