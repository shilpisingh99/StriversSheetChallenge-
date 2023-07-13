pair<int,Node*> getLength(Node* head){//returns no of nodes and the last node in the list
     int cnt=0;
     Node* lastNode=NULL;
     while(head){
          lastNode=head;
          head=head->next;
          cnt++;
     }
     return {cnt,lastNode};
}
Node *rotate(Node *head, int k) {
     auto res=getLength(head);
     int n=res.first;
     Node* tail=res.second;
     k%=n;
     if(k==0) return head;
     int cntNodes=1;
     Node* curr=head;
     while(cntNodes<n-k){
          curr=curr->next;
          cntNodes++;
     }
     Node* head2=curr->next;
     curr->next=NULL;
     tail->next=head;
     return head2;
}