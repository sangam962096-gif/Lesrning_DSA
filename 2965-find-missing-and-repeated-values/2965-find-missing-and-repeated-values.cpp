class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n*n ;
        // s - sn = x- y 
        // s2 - s2n 
        long long SN = (N*(N+1))/2;
        long long S2N = (N *(N+1)*(2*N+1))/6;
        long long  s = 0 , s2 = 0;
for( int i= 0; i < n; i++){
    for( int j = 0 ; j  <n ; j++){

    
s += grid[i][j];
s2 += (long long)grid[i][j] *( long long) grid[i][j];
}
}
long long val1 = s - SN;
long long val2 = s2 - S2N;
val2 = val2 / val1;
long long x = ( val1 + val2) / 2;
long long y = x -val1;
return {(int)x , (int)y};
    }
};