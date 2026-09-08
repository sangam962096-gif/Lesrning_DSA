class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int ,int> ngeMap;
        vector<int>result;

        // step1 nums2 par same logic lagayenge(right to left traversal)
        for( int  i = nums2.size() -1 ; i >=0 ; i--){

            // stack se un element  ko hatao jo chote aur barabr hai
             while( !st.empty() && st.top() <= nums2[i]){
                st.pop();
             }

             // agar stack khali nahi hai , toh top element next greater hoga
             if(!st.empty()){
                ngeMap[nums2[i]] = st.top();
             }
             else{
                ngeMap[nums2[i]] = -1; // agar koi bada element nahi mila 
             }

             // current element ko stack me push kar do
             st.push(nums2[i]);
        }

        // step2 : nums1 ke element ka answer hash map se nikal kar result array mein dalo
        for( int i = 0 ; i < nums1.size() ; i++){
            result.push_back(ngeMap[nums1[i]]);
        }
        return result;
    }
};