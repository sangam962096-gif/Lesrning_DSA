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
//      // yeh hamara helper function hai jo recursion k through tree traverse karega
//      //'node' current node ko point karega
//      // 'vector <int> postorder' mein & ( pass by references) isliye lagate hai taki 
//      // har recursive call mein naya vector copy na bane aur hum direct original vector mein changes kar sakein
//      void dfs(TreeNode* node , vector<int>& postorder){
//         // Base case : Agar hum aese node par pahuch gaye jo exist hi nahi karta 
//         // iska  matlab hum leaf node ke neeche aa gye hai , toh yaha se wapas laut jao ( return)
//          if ( node == nullptr)  {
//             return;
//          }
//            //Step 1 : ( left) : Sabse pahele node  ke left subtree ko poora traverse karo.
//            dfs ( node->left , postorder);

//            // Step 2 : jab left side poori tarh khatam ho jaye, toh right subtree mein jao
//            dfs( node->right , postorder);

//            // Step 3 : ( root) : jab current node ka left and right dono visit kar chuke hon
//            // tab aakhir me current node me value ( node-value) ko apne answer vector meon dall do
//            postorder.push_back( node->val);

//      }
//     vector<int> postorderTraversal(TreeNode* root) {
//         // Ek khali ( empty) vector banaya jisme hum final postorder sequence store karenge
//          vector <int> postorder;

//          // Apne recursive helper function ko call keya ,  starting from root node
//          dfs( root , postorder);

//          // jab pura tree traverse ho jaye , return
//          return postorder;

//     }
// };

class Solution {
public:
     void dfsPostorder( TreeNode* node , vector<int> & result){
        if( node == nullptr){
            return ;
        }
        dfsPostorder( node->left , result);
        dfsPostorder( node->right , result);
        result.push_back(node->val);
     }
    vector<int> postorderTraversal(TreeNode* root) {
        
         vector <int> result ;
          
          dfsPostorder( root , result);

          return result ;
    }
};