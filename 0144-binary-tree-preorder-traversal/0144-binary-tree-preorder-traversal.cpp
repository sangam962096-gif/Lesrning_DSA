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
//    // Helper function to perform recursion
//    void dfsPreorder( TreeNode* node , vector<int> & result){
//     // Step 1 : Base case 
//     // if the current node is null , return and backtrack
//     if ( node == nullptr){
//         return ;
//     }
//    // Step 2: process the root
//     // Add the current node's value to our result vector 
//       result.push_back( node->val);
     
//      // Step  3: Traverse left 
//      // Move to the left child and repeat the process
//       dfsPreorder( node->left , result);

//      // Step 4 : Traverse Right 
//       // Once the left subtree is completed processed , move to the right child
//       dfsPreorder( node->right , result);

//    }
//     vector<int> preorderTraversal(TreeNode* root) {
//         // Create a vector to store the final traversal order
//         vector<int> result;

//         // Start the recursive traversal from the root node
//         dfsPreorder( root , result);

//         // return the populated list of node valuse
//         return result;
//     }
// };
class Solution {
public:
   void dfsPreorder ( TreeNode* node , vector <int>& result){
    if( node == nullptr){
        return ;
    }
    result.push_back( node->val);

    dfsPreorder ( node->left , result);

    dfsPreorder( node->right , result); 
   }
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> result ;
        dfsPreorder( root , result);
        return result ;
        

    }
};