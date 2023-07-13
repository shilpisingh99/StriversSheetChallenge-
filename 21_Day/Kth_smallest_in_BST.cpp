#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int kthSmallest(TreeNode<int> *root, int k)
{
    TreeNode<int> *curr = root;
    int ans = 0;
    int count = 0;
	while(curr) {
        if(curr->left == NULL) {
            count++;
            if(count == k) {
                ans = curr->data;
            }
            curr = curr->right;
        } else {
            TreeNode<int> *pre = curr->left;
            while(pre->right && pre->right != curr) {
                pre = pre->right;
            }

            if(pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                count++;
                if(count == k) {
                    ans = curr->data;
                }
                curr = curr->right;
            }
        }
    }

    return ans;
}