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
// class Solution {
// public:
// void dfsInorder( TreeNode* node , vector<int> & result){
            
//             if ( node == nullptr){
//                 return;
//             }
//             dfsInorder( node->left , result);
//             result.push_back(node->val);

//             dfsInorder( node->right , result);
// }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;

//         dfsInorder( root , result);

//         return result ;
        
//     }
// };


class Solution {
public:

   void dfsInorder( TreeNode* node , vector<int> & result){
     if( node == nullptr){
        return ;
     }
      dfsInorder( node->left , result);

      result.push_back( node->val);

      dfsInorder( node->right , result);

        }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        dfsInorder( root , result);

        return result;
        
    }
};