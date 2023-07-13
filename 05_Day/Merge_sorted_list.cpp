#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* head=NULL,*tail=NULL;
    while(first and second){
        if(first->data<=second->data){
            if(!head){
                head=tail=first;
                first=first->next;
                tail->next=NULL;
            }
            else{
                tail->next=first;
                tail=tail->next;
                first=first->next;
                tail->next=NULL;
            }
        }
        else{
            if(!head){
                head=tail=second;
                second=second->next;
                tail->next=NULL;
            }
            else{
                tail->next=second;
                tail=tail->next;
                second=second->next;
                tail->next=NULL;
            }
        }
    }
    while(first){
        if(!head){
            head=tail=first;
            first=first->next;
            tail->next=NULL;
        }
        else{
            tail->next=first;
            tail=tail->next;
            first=first->next;
            tail->next=NULL;
        }
    }
    while(second){
        if(!head){
            head=tail=second;
            second=second->next;
            tail->next=NULL;
        }
        else{
            tail->next=second;
            tail=tail->next;
            second=second->next;
            tail->next=NULL;
        }
    }
    return head;
}