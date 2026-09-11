class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        // Step1 : string ko left se right traverse karenge
        for( int  i = 0 ; i < n ; i++){
           // jab tak stack khali nahi , k bacha hai aur stack ka top digit current se bada hai
            while( !st.empty() &&  k > 0 && (st.top() - '0' ) > (num[i] - '0')) {
              st.pop();            // bade digit ko uada do
              k--;                 // k ko decrease karo
            }
            //  current digit ko satck me push karo
            st.push(num[i]); 
        }

        // step2 : edge case - agar string already choti ho rhe ho( eg ; 123456)
        while( !st.empty() && k > 0){
            st.pop();
            k--;
        }
        // step3 : Agar stack kahali ho chuka hai 
        if(st.empty()){
            return "0";
        }
        // step4 : Stack ke elements ko result string me nikalo
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        // step5 : edge case - Stack se hume number ulta milata hai
        //Agar original me leading zeros the( eg ; "001") , toh abhi wo traviling zeros ("100") honge
        // toh piche se zeros hata do
        while( res.length() > 0 && res.back() == '0'){
            res.pop_back();
        }
        // step6: string ko wapes seedhe(reverse) karo
        reverse(res.begin() , res.end());

        // step7 : Agar traverse karne k baad ( ya leading zeros hatane k baad) string khali ho gye ho
        if(res.empty()){
            return "0";
        }
        return res;
    }
};