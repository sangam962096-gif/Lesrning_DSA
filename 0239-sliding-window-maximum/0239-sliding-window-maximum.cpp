class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
         deque<int>dq;     //yeh deque element ke INDICES ko store karega

         for( int i =0 ; i < n; i++){
            // step1 : out of bound element ko remove karo
            // agr front wala index current window ke boundary se bahar chala gya hai,
            // toh use aage se nekal do ( pop_front)
            if( !dq.empty() && dq.front()  <= i-k){
                dq.pop_front();
            }

            // step 2 : monotonic decreasing order maintain karo
            // agr current element (nums[i]) pichle element se bada ya barabar hai,
            // toh pichale element ka ab koi use nahi hai ,unhe peche se nekal do ( pop_back).
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            // step 3: current index ko dq me push karo
            dq.push_back(i);

            // step 4 : answer store karo 
            // pehli valid window (size k) index k -1 par khtam hoti hai.
            // usake baaad har step par deque ke front me current window ka maximum hoga
            if( i >= k-1){
                ans.push_back( nums[dq.front()]);
            }
         }
         return ans ;
    }
};