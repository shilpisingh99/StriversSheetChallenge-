LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *prev=NULL,*curr=head;

    while(curr){
        LinkedListNode<int> *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    return prev;
}