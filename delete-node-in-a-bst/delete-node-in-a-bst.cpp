/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }
        if(key < root ->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key>root->val){
         root->right = deleteNode(root->right,key);
        }
        else{
        if(!root ->left  and !root->right){
            //delete
            return nullptr;
        }
        else if(!root->left){
            //delete
            return root->right;
        }
        else if(!root->right){
            //delete;
            return root->left;
        }
        else{
            TreeNode* right_min = root -> right;
            while(right_min->left){
                right_min = right_min->left;
            }
            root->val = right_min->val;
            root->right = deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};