class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;       // stack me hum array ke index store karenge , values nahi
        int maxArea = 0 ;

        for( int i = 0 ; i < n ; i++){
            // jab tak stack khali nahi hai aur current height stack ke top wale height se choti
            while(!st.empty() && heights[ st.top()] > heights[i]){
                int element = st.top();      // yeh wo element hai jeska area calculate hoga
                st.pop();

                int nse = i;   // current index (i) humara next smaller element(nse) hai
                int pse =  st.empty() ? -1 : st.top();     // pop karane k baad jo top par bacha , wo previous smaller element (pse) hai

                //  Area = height * width( width = nse - pse -1)
                maxArea = max( maxArea , heights[element] * ( nse -pse -1));
            }
            // jab right position mil jaye , tab index ko push kar do
             st.push(i);
        }

        // Array khatam hone k baad jo element stack mein bach gaye hain, unke leye
        //Unka right mein koi smaller element nahi hai , isleye unka NSE 'n' ( array ki size) hoga
        while( !st.empty()){
            int element = st.top();
            st.pop();

            int nse = n ;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max( maxArea , heights[element] * (nse - pse -1));
        }
        return maxArea;
    }
};