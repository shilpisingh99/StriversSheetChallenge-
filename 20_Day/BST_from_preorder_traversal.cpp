#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* solve(int start, int end, vector<int>& preOrder, vector<int>& nge){

    if(start > end) return NULL;
    if(end == start) return new TreeNode<int>(preOrder[start]);

    TreeNode<int>* root = new TreeNode<int>(preOrder[start]);
    int idx = nge[start];
    root->left = solve(start+1, idx-1, preOrder, nge);
    root->right = solve(idx, end, preOrder, nge);

    return root;
}

vector<int> nextGreaterElement(vector<int>& preOrder){
    int n = preOrder.size();
    vector<int> res(n, n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() and preOrder[st.top()] <= preOrder[i]) st.pop();
        res[i] = st.empty() ? n: st.top();
        st.push(i);
    }

    return res;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    vector<int> nge = nextGreaterElement(preOrder);
    cout<<endl;
    return solve(0, preOrder.size()-1, preOrder, nge);
}