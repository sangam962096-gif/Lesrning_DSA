class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = INT_MIN , maxfre = 0;
        int l = 0 , r = 0 ;
        int hash[26] = {0};
        while( r < n ){
          hash[s[r] -'A']++;
          maxfre = max( maxfre , hash[s[r] - 'A']);
          // window me changes k se jada hai tb
          if( r-l +1 - maxfre > k){
            hash[s[l] - 'A']--;
            l++;
          }
          maxlen = max(maxlen , r-l+1);
          r++;
        }
        return maxlen;
    }
};