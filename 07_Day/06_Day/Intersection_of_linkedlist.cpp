Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* a=firstHead,*b=secondHead;
    while(a != b){
        a=a==NULL?secondHead:a->next;
        b=b==NULL?firstHead:b->next;
    }
    return a;
}