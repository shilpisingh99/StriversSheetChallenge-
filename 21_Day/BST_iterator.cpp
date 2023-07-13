class BSTiterator
{
public:
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root)
    {
        while(root){
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        if(st.empty()) return -1;
        TreeNode<int>* node = st.top();
        st.pop();
        TreeNode<int>* curr = node->right;
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
        return node->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};