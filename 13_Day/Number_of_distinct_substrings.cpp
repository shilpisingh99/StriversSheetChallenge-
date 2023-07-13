#include <bits/stdc++.h> 

class Node{
private:
    Node* arr[26];
    bool flag;
public:
    Node(){
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        }
        flag=false;
    }
    bool contains(char ch){
        return (arr[ch-'a']!=NULL);
    }
    void put(char ch){
        arr[ch-'a']=new Node();
    }
    void setFlag(){
        flag=true;
    }
    Node* getNext(char ch){
        return arr[ch-'a'];
    }
    bool isFlagSet(){
        return flag;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    int insert(string word){
        int count=0;
        for(int i=0;i<word.size();i++){
            Node* temp=root;
            for(int j=i;j<word.size();j++){
                if(!temp->contains(word[j])){
                    temp->put(word[j]);
                    count++;
                }
                temp=temp->getNext(word[j]);
            }
            temp->setFlag();
        }
        return count;
    }
};

int distinctSubstring(string &word) {
    Trie ds;
    return ds.insert(word);
}