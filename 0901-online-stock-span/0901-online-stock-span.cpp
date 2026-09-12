class StockSpanner {
public:
// stack stores pairs of { price , index}
        stack<pair<int , int>> st;

        // global counter to track the current day's index
        int ind;
    StockSpanner() {
        // Initialize to -1 so the first element gets index 0
        ind = -1;
    }
    
    int next(int price) {
        ind = ind +1;

        // Step1 : pop element that are smaller than or equal to the current price
        // they can never be the "previous greater element" for any future day
        while( !st.empty() && st.top().first <= price){
            st.pop();
        }

        // step2 : Calculate the span;
        // If stack is empty , no previous greater element exists, so we subtract -1
        int prevgreaterInd =st.empty() ? -1 : st.top().second;
        int ans = ind - prevgreaterInd;

        // step3 : push the current price and its index for the future days to references
        st.push({ price , ind});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */