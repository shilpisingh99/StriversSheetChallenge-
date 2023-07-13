#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* removeKthNode(Node* head, int K)
{
    Node* newHead=head;
    Node *res=head,*prev=NULL;
    while(head){
        K--;
        if(K<0){
            prev=res;
            res=res->next;
        }
        head=head->next;
    }
    if(res){
        if(prev==NULL){
            Node* temp=newHead;
            newHead=newHead->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            prev->next=res->next;
            res->next=NULL;
            delete res;
        }
    }
    return newHead;
}