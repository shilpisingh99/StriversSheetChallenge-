#include <bits/stdc++.h> 

static bool comp(vector<int>& a,vector<int>& b){
	return a[1]<b[1];
}

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
	bool isEmpty;
  public:
    Trie(){
        root=new Node();
		isEmpty=true;
    }
    bool getIthBit(int num,int i){
        return ((num>>i)&1)!=0;
    }
    void insert(int num){
        Node* curr=root;
		if(isEmpty) isEmpty=false;
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
	bool isTrieEmpty(){
		return isEmpty;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	int n=queries.size();
	for(int i=0;i<n;i++){
		queries[i].push_back(i);
	}
	sort(arr.begin(),arr.end());
	sort(queries.begin(),queries.end(),comp);
	vector<int> res(n,0);
	Trie ds;
	int idx=0;
	for(int i=0;i<n;i++){
		int X=queries[i][0],A=queries[i][1],j=queries[i][2];
		while(idx<arr.size() and arr[idx]<=A){
			ds.insert(arr[idx++]);
		}
		if(ds.isTrieEmpty()){
			res[j]=-1;
		}
		else{
			res[j]=ds.getMaximumXorWith(X);
		}
	}
	return res;
}