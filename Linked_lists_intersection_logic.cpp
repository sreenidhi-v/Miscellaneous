/*
ENTIRE PROBLEM ON GEEKSFORGEEKS
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node* findIntersection(struct node* head1, struct node* head2)
{
    // code here
    int flag,n=0,i;
    struct node *p=head1,*q=head2,*temp,*prev;
    
    n=0;
    while(q!=NULL)
    {
        q=q->next;
        n++;
    }
    int *b = new int[n];
    for(i=0;i<n;i++)b[i]=0;
    
    n=0;
    while(p!=NULL)
    {
        flag = 0;
        q = head2;
        i = 0;
        while(q!=NULL)
        {
            if(p->data==q->data && b[i]==0)
            {
                b[i]=1;
                flag = 1;
                break;
            }
            q=q->next;
            i++;
        }
        
        if(flag)
        {
                prev = p;
                p=p->next;
        }
        else
        {
            if(p==head1)
            {
                head1=head1->next;
                p->next=NULL;
                free(p);
                p = head1;
            }
            else
            {
                prev->next=p->next;
                p->next = NULL;
                free(p);
                p = prev->next;
            }
        }
         n++;
    }
    
    p = head1;
    int *arr=new int[n];
    i=0;
    
    while(p!=NULL)
    {
     arr[i++]=p->data;
     p=p->next;
    }
    
    sort(arr,arr+i);
    
    p = head1;
    i = 0;
    while(p!=NULL)
    {
        p->data=arr[i++];
        p=p->next;
    }
    
    //if(head1 == NULL)printf("null it is");
    return head1;
}
