class Solution {
public:
     // Helper function : kisi sorted row me 1 ka pahala index ( lower bound ) find karane k leye 
     int lowerBound( vector<int>& arr , int m , int x){
        int low = 0  , high = m -1 ;
        int ans = m ;  // Agar 1 na mele to default answer m rahega

        while( low <= high){
            int mid = ( low + high) >> 1;

            // agar mid par element >= 1 hai , toh ye possible first occurrence ho skta hai
            if( arr[mid] >= x){
                ans = mid;
                // aur pahele ( left side ) check karane k leye high ko shift kro
                high = mid -1;

            }
            else {
                // Agar mid par 0 hai , toh 1 right side hi melega 
                low = mid + 1;

            }

        }
        return  ans ;
     }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int max_count = 0 ; // Abhi tak ka maximum 1's count 
        int best_row = 0 ;    //  // Agar koi 1 na mile toh [0, 0] return hona chahiye

        // har row par travese karenge 
        for( int i = 0 ; i < n ; i++){
           int count_ones = 0 ;
           for ( int j = 0 ; j < m ; j++){
            if( mat[i][j] == 1){
                count_ones++;
            }
           }

            
            //Step3 :  Agar current row me pahele se jada 1's hai, toh update karo
            // Note : hum sirf '>' use karenge taaki tie hone par smallest row index he rahe
            if ( count_ones > max_count){
                max_count = count_ones;
                best_row = i;
            }
        }
             
             return { best_row , max_count} ;
    }
};