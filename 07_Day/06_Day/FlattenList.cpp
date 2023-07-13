#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
 

Node* mergeTwoLists(Node* first,Node* second){
    Node* temp=new Node(-1);
    Node* res=temp;
    while(first and second){
        if(first->data<second->data){
            temp->child=first;
            first=first->child;
            temp=temp->child;
        }
        else{
            temp->child=second;
            second=second->child;
            temp=temp->child;
        }
    }
    if(first) temp->child=first;
    if(second) temp->child=second;
    return res->child;
}
Node* flatten(Node* head){
    if(!head or !head->next) return head;
    Node* head2=flatten(head->next);
    head->next=NULL;
    return mergeTwoLists(head,head2);
}
Node* flattenLinkedList(Node* head) 
{
	return flatten(head);
}