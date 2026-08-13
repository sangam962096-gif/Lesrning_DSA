class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        // s1 ki frequency ko store krenge
        for(char c : s1){
            freq1[c- 'a']++;
        }
        // windows ki frequecny count krnege
        for( int i =  0 ; i < s1.length(); i++){
            freq2[ s2[i] - 'a']++;
        }
        // window ko slide karege
        for( int i = s1.length(); i < s2.length(); i++){
            if(freq1 == freq2) return true;
            freq2[s2[i] -'a']++;
            freq2[s2[i - s1.length()]  - 'a']--;
        }
 // last window check
  return freq1 == freq2;
    }
};