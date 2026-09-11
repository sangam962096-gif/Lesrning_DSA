class Solution {
public:
// pichali problem ( largest rectangle in Histogram) ka logic  yahan use karenge
 int largestRectanglearea(vector<int> & heights){
    int n = heights.size();
    stack<int> st;         // stack me indexes store karenge
     int maxarea = 0 ;

     for( int i = 0 ; i < n ; i++){
        while( !st.empty() && heights[st.top()] > heights[i]){
            int element = st.top();
            st.pop();

            int nse = i ; 
            int pse = st.empty() ? -1 : st.top();

            maxarea = max( maxarea , heights[element] *(nse - pse -1));
        }
        st.push(i);
     }

     while(!st.empty()){
        int element = st.top();
        st.pop();

        int nse = n ;
        int pse = st.empty() ? -1 : st.top();

        maxarea = max( maxarea , heights[element]*(nse-pse-1));
     }
     return maxarea;
 }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0 ;

        int n = matrix.size();
        int m = matrix[0].size();

        // 2D array/matrix jismein hum row-wise histogram bars ki heights compute karenge
        vector<vector<int>> prefixsum( n , vector<int>(m,0));

        // step1 : prefix sum technique se har(i , j) par upper consecutive 1's ki height nikalo
        for( int j = 0 ; j < m ; j++){
            int sum = 0 ;
            for( int i = 0 ; i <n ;i++){
                if(matrix[i][j] == '0'){
                    sum =0 ;           // Agar 0 mila toh connection toot gaya , so base zero
                }
                else{
                    sum += 1;          // ya sum += matrix[i][j] - '0'
                }
                prefixsum[i][j] = sum;
            }
        }
        // step2 : Har ek row ko as a histogram pass karo max area find out karane ke leye
        int maxarea = 0 ;
        for( int i = 0 ; i <n; i++){
            maxarea = max(maxarea , largestRectanglearea(prefixsum[i]));
        }
        return maxarea;
    }
};