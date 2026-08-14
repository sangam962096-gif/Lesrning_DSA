class Solution {
public:
    string minWindow(string s, string t) {
       int m = s.size(); int n = t.size(); int hash[256] = {0};
       int l = 0 , r = 0 ,minlen = INT_MAX , cnt = 0 , sindex = -1;
       for ( int i = 0 ; i < n; i++ ){
        hash[t[i]]++; // t k char ko map me store kar deya
       }
       while(r < m){
        if(hash[s[r]] > 0) cnt = cnt +1;
        hash[s[r]]--;
       while(cnt == n){
        if(r-l+1 < minlen){
            minlen = r-l+1;
            sindex = l;
        }
        hash[s[l]]++;
        if(hash[s[l]] > 0) {
            cnt = cnt -1;}
            l++;
        }
        r++;
       }
       return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};