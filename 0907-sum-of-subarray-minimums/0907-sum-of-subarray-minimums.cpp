class Solution {
public:
   
      // funtion to find Next smaller Element(NSE)
      vector<int> findNSE( vector<int>& arr){
        int n = arr.size();
        vector<int>nse(n);
        stack<int>st;    // Indices store karne ke leye stack

        // Array ko right se left traverse karayenge(peeche se)
        for(int i = n-1 ; i >= 0 ; i--){
          // jab tak stack khale na ho aur top element current se bada ya barabar ho , pop karo
          while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
          }  
          // Agar stack empty hai , iska matlab right mein koi chota element nahi hain,toh boundary n assigh karo
          nse[i] = st.empty() ? n : st.top();
          st.push(i);
        }
        return nse ;
      }

      // function to find previous smaller or equal element(PSEE)
      vector<int> findPSEE(vector<int> & arr){
        int n = arr.size();
        vector<int>psee(n);
        stack<int> st;

        // Array ko left se right traverse karenge (aage se)
        for( int i = 0 ; i < n ; i++){
            // sirf strictly greater element ko pop karenge. Duplicate handle karne ke leye eyual ko pop nahi karenge
            while(!st.empty() && arr[st.top()] > arr[i]){
               st.pop();
            }
            // Agar stack empty hai toh left mein koe chota/equal element nahi hai
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
      }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int mod = 1e9 + 7;
        long long totalsum = 0;

        for( int i = 0 ; i < n ; i++){
            // left aur right un subarrays ki ginti hai jisme arr[i] minimum ban raha hai
            long long left = i - psee[i];
            long long right = nse[i] -i;

            // ek subarray combination mein arr[i] kitne baar aayega (left*right)
            //usko arr[i] se multiply kareke uska total contribution nikal lenge
            long long contribution = ( left * right % mod)* arr[i] % mod;

            // total answer mein result add karenge module ke sath
            totalsum =( totalsum + contribution) % mod;
        }
         return totalsum;
    }
};