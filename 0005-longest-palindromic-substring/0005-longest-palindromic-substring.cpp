class Solution {
public:
    string longestPalindrome(string s) {
       int n = s.size();
       if(n <= 1)
       return s;
       int start = 0;
       int maxlen =1;
       for( int i = 0 ; i < n; i++){
        // odd lenght
        int l = i;
        int r = i;
        while(l >= 0 && r <n  && s[l] == s[r]){
            if(r-l+1 > maxlen){
                start = l;
                maxlen = r-l+1;
            }
            l--;
            r++;
        }
        // even lengh
        l = i;
        r = i +1;
        while(l>=0 && r < n && s[l] == s[r]){
            if(r-l+1 > maxlen){
                start = l;
                maxlen = r-l+1;
            }
            l--;
            r++;
        }
       }
       return s.substr(start , maxlen); 
    }
};