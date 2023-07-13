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
    void insert(string word){
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->contains(word[i])){
                temp->put(word[i]);
            }
            temp=temp->getNext(word[i]);
        }
        temp->setFlag();
    }
    bool search(string word){
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->contains(word[i])){
                temp=temp->getNext(word[i]);
            }
            else{
                return false;
            }
        }
        return temp->isFlagSet();
    }
    bool startsWith(string word){
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->contains(word[i])){
                temp=temp->getNext(word[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isCompleteString(string &s){
        Node* temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->contains(s[i])){
                temp=temp->getNext(s[i]);
                if(temp->isFlagSet()==false) return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie ds;
    for(auto &i:a){
        ds.insert(i);
    }
    string res="";
    for(auto &i:a){
        string s=i;
        if(ds.isCompleteString(s)==false) continue;
        if(s.size()>res.size()){
            res=s;
        }
        else if(s.size()==res.size() and s<res){
            res=s;
        }
    }
    return res==""?"None":res;
}