class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n ,-1);  // answer store karne k leye
        stack<int>st;

        // array ko hypothetically double karke (2*n -1) se 0 tak traverse karenge
        for( int i = 2*n -1 ; i >= 0 ; i--){

            // current index ke leye modulo(i%n) ka use karenge
            int currentIndex = i % n ;

            // stack se un element ko hatao jo chote ya barabar hai
            while( !st.empty() && st.top() <= nums[currentIndex]){
                st.pop();
            }

            // Hum sirf unhi index (0 to n -1 ) ka answer store karenge jo real array mein hai
            if( i < n){
                if(!st.empty()) {
                    nge[i] = st.top();
                }
                else{
                    nge[i] = -1;
                }
            }

            // current element ko stack mein push kar do future calculation k leye
            st.push(nums[currentIndex]);
        }
         return nge ;
    }
};