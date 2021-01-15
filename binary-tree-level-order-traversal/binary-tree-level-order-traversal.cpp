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
    vector<vector<int>> levelOrder(TreeNode* root) {
    queue <TreeNode*> frontier;
        frontier.push(root);
        queue<TreeNode*> next_frontier;
        
        vector<vector<int>> levels;
        levels.push_back(vector<int>());
        while(!frontier.empty()){
            TreeNode* current = frontier.front();
            frontier.pop();
            if(current){
                levels[levels.size() - 1].push_back(current -> val); 
                next_frontier.push(current-> left);
                next_frontier.push(current -> right);
                }
            if(frontier.empty()){
                frontier = queue<TreeNode*>(move(next_frontier));
                levels.push_back(vector<int>());
            }
            }
        levels.pop_back();
        levels.pop_back();
    return levels;
    }
};
