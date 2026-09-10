class Solution {
public:

 // Helper function to calculate the sum of the sum of subarray minimum
  long long sumSubnumsMins(vector<int>&arr){
    int n = arr.size();
    vector<int> nse(n) , psee(n);
    stack<int>st;

    // 1. Next greater element (nse)
    for( int i = n-1 ; i >= 0 ; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
        while(!st.empty()) st.pop();

        // 2 .previous smaller or equal element (psee)
         for( int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
         }

         // Calculate total sum of the minimums
          long long totalmin = 0;
          for( int  i = 0; i <n ; i++){
            long long left = i - psee[i];
            long long right = nse[i] -i;
            totalmin += (left*right)* arr[i];

          }
          return totalmin;
  }

  // Helper function to calculate the sum of the subarray maximums
  long long sumSubnumsMaxs(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n) , pgee(n);
    stack<int>st;

    // 1. next greater element
    for( int i = n -1 ; i >= 0 ; i--){
        while(!st.empty() && arr[st.top()] <=  arr[i]){
            st.pop();
        }
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    // 2 . previous gretest or equal element 
    
    for( int  i = 0 ; i < n ; i++){
        while( !st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    // Calculate sum of the maximums
    long long totalmax = 0 ;
    for( int i = 0 ; i < n; i++){
        long long left = i - pgee[i];
        long long right = nge[i] - i;
        totalmax += (left*right) * arr[i];
    }
    return totalmax;
  }
    long long subArrayRanges(vector<int>& arr) {
        // range sum = (sum of subarray maximums) - ( sum of subarray minimums)
        return sumSubnumsMaxs(arr) - sumSubnumsMins(arr);
        
    }
};