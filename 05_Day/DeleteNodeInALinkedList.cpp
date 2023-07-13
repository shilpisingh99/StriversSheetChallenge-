void deleteNode(LinkedListNode<int> * node) {
        LinkedListNode<int>* next=node->next;
        node->data=next->data;
        node->next=next->next;
        next->next=NULL;
        delete next;
}