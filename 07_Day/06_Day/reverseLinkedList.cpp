LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head){
    if(!head) return head;
    LinkedListNode<int>* prev=NULL,*curr=head;
    while(curr){
        LinkedListNode<int>* curr_next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=curr_next;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(!head or !head->next) return true;
    LinkedListNode<int> *slow=head,*fast=head->next;
    while(fast and fast->next){
        fast=fast->next;
        if(fast) fast=fast->next;
        slow=slow->next;
    }
    LinkedListNode<int>* head2=slow->next;
    slow->next=NULL;
    head2=reverseLinkedList(head2);
    while(head and head2){
        if(head->data != head2->data) return false;
        head=head->next;
        head2=head2->next;
    }
    return true;
}