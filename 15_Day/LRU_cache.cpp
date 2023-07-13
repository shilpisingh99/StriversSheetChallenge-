#include <bits/stdc++.h>
class Node{
public:
    int key;
    int data;
    Node* next;
    Node* prev;
    Node(){
        next = prev = NULL;
    }
    Node(int key,int data){
        next = prev = NULL;
        this->key = key;
        this->data = data;
    }
};

class LRUCache
{
public:
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* resNode = mp[key];
        int res = resNode->data;
        mp.erase(key);
        deleteNode(resNode);
        addNode(resNode);
        mp[key] = head->next;
        return res;
    }
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* resNode = mp[key];
            mp.erase(key);
            deleteNode(resNode);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
    }

    void deleteNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
};