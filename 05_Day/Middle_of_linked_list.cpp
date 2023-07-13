Node *findMiddle(Node *head) {
    Node *slow=head,*fast=head;
    while(slow and fast->next){
        fast=fast->next;
        fast=fast->next?fast->next:fast;
        slow=slow->next;
    }
    return slow;
}