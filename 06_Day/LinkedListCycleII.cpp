Node* floydsCycleDetect(Node* head){
    if(!head) return head;
    Node *slow=head,*fast=head;
    while(slow and fast and fast->next){
        fast=(fast->next)->next;
        slow=slow->next;
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
Node *firstNode(Node *head)
{
    Node* fast=floydsCycleDetect(head);
    if(!fast) return NULL;
    Node* slow=head;
    while(slow != fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}