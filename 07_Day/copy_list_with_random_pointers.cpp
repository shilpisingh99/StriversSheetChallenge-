#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    //first round
    LinkedListNode<int>* curr=head;
    while(curr){
        LinkedListNode<int>* curr_next=curr->next;
        LinkedListNode<int>* copy=new LinkedListNode<int>(curr->data);
        curr->next=copy;
        copy->next=curr_next;
        curr=curr_next;
    }
    //second round
    curr=head;
    while(curr){
        curr->next->random = curr->random?curr->random->next:NULL;
        curr = curr->next->next;
    }
    //third round
    curr=head;
    LinkedListNode<int>* pseudoHead=new LinkedListNode<int>(0);
    LinkedListNode<int>* copy=pseudoHead;
    while(curr){
        LinkedListNode<int>* front=curr->next->next;
        copy->next=curr->next;
        curr->next=front;
        copy=copy->next;
        curr=front;
    }
    return pseudoHead->next;
}