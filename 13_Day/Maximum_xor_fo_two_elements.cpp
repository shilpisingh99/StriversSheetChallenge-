#include <bits/stdc++.h> 
class Node{
  private:
    bool flag;
    Node* arr[2];
  public:
    Node(){
        arr[0]=arr[1]=NULL;
        flag=false;
    }
    void put(int bit){
        arr[bit]=new Node();
    }
    Node* get(int bit){
        return arr[bit];
    }
    Node* getNext(int bit){
        return arr[bit];
    }
    bool isContains(int bit){
        return arr[bit] != NULL;
    }
    bool isFlagSet(){
        return flag;
    }
    void setFlag(){
        flag=true;
    }
};
class Trie{
  private:
    Node* root;
  public:
    Trie(){
        root=new Node();
    }
    bool getIthBit(int num,int i){
        return ((num>>i)&1)!=0;
    }
    void insert(int num){
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=getIthBit(num,i);
            if(!curr->isContains(bit)){
                curr->put(bit);
            }
            curr=curr->getNext(bit);
        }
        curr->setFlag();
    }
    int getMaximumXorWith(int num){
        int res=0;
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=getIthBit(num,i);
            if(curr->isContains(!bit)){
                res+=(1<<i);
                curr=curr->getNext(!bit);
            }
            else{
                curr=curr->getNext(bit);
            }
        }
        return res;
    }
};
int maximumXor(vector<int> A)
{
    Trie ds;
    for(auto &i:A){
        ds.insert(i);
    }
    int res=0;
    for(auto &i:A){
        res=max(res,ds.getMaximumXorWith(i));
    }
    return res;
}