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
};