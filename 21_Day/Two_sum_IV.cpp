#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
class BSTiterator{
private:
    bool reverse;
    stack<BinaryTreeNode<int>*> st;
public:
    BSTiterator(BinaryTreeNode<int>* root, bool reverse){
        this->reverse = reverse;
        while(root){
            st.push(root);
            if(reverse) root = root->right;
            else root = root->left;
        }
    }
    bool hasNext(BinaryTreeNode<int>* root){
        return !st.empty();
    }

    int next(){
        BinaryTreeNode<int>* top = st.top();
        st.pop();
        if(reverse){
            BinaryTreeNode<int>* curr = top->left;
            while(curr){
                st.push(curr);
                curr = curr->right;
            }
        }
        else{
            BinaryTreeNode<int>* curr = top->right;
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
        }
        return top->data;
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    BSTiterator it1(root, false), it2(root, true);
    int i = it1.next(), j = it2.next();
    while(i < j){
        if(i + j == k) return true;
        if(i + j < k){
            i = it1.next();
        }
        else{
            j = it2.next();
        }
    }
    return false;
}