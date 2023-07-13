#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* head=new Node(-1);
    Node* tail=head;
    int carry=0;
    while(num1 or num2){
        int sum=(num1?num1->data:0)+(num2?num2->data:0)+carry;
        carry=sum/10;
        tail->next=new Node(sum%10);
        tail=tail->next;
        if(num1) num1=num1->next;
        if(num2) num2=num2->next;
    }
    if(carry){
        tail->next=new Node(carry);
        tail=tail->next;
    }
    return head->next;
}