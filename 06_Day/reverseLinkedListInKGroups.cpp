#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Node
{
    public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node* reverseLinkedList(Node* head){
	if(!head) return head;
	Node* prev=NULL,*curr=head;
	while(curr){
		Node* curr_next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=curr_next;
	}
	return prev;
}
Node* solve(Node* head,int idx,int b[],int n){
    if(!head or idx==n) return head;
    Node* curr=head;
    int cntNodes=1,k=b[idx];
	if(k==0) return solve(head,idx+1,b,n);
    while(cntNodes<k and curr->next){
        curr=curr->next;
        cntNodes++;
    }
    if(cntNodes==k){
        Node *head1=head,*head2=curr->next;
        curr->next=NULL;
        head1=reverseLinkedList(head1);
        head2=solve(head2,idx+1,b,n);
        head->next=head2;
        return head1;
    }
    else{
        return reverseLinkedList(head);
    }
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return solve(head,0,b,n);
}