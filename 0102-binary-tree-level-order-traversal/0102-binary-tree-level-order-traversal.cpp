/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //2d vector to store the final level order traversal result 
         vector <vector<int>> ans;

         // Edge case : if the tree is empty , return an empty result
         if( root == nullptr){
            return ans;
         }

         // Oueue to help us traverse the tree level by level(bfs)
         queue<TreeNode*> q; 

         // Push the root node into the queue to kick off the traversal
         q.push(root);

         // Loopt until all levels and nodes have been processed
         while( !q.empty()){
            // Find the number of nodes at the current level
            int size = q.size();

            // Temporary vector to store node values of the current level
            vector<int> level;

            // Iterate through all nodes present in the current level
            for( int i = 0 ; i < size ; i++){
                // Get the front node from the queue 
                 TreeNode* node = q.front();

                 // Remove the node from the queue
                 q.pop();

                 //If the left child exist , push it into the queue for the next level
                 if( node->left != nullptr){
                    q.push(node->left);
                 }
                 // if the right child exists , push it into the queue for the next level
                 if( node->right != nullptr){
                    q.push(node->right);
                 }
                 // Add the current node value to the level vector
                 level.push_back( node->val);
            }
            // After finishing the current level, add the level vector to the final answer
             ans.push_back(level);
         }
         // Return the final 2D vector containing level order traversal
         return ans;
    }
};