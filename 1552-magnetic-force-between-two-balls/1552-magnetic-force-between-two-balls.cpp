class Solution {
public:   
      // Helper function : ye check karega ki hum 'force' ( distanse) maintain karte huye sare 'm' balls basket me place kar skte hai ya nahi
        bool canWePlace(const vector <int> & position ,int force , int m ){
        int n = position.size();
        
        // Greedily pahele ball ko sabse pahele basket( position[0]) me palce kar skte hai
        int countBalls = 1;
        int lastPlacedposition = position[0];

        // Baki position traverse kar k dekhte hai agli ball kaha aa skte hai
        for( int i = 0 ;  i < n ; i++){
            // Agar  current basket aur last placed ball ke beech ka distance >= force hai
            if( position[i] - lastPlacedposition  >= force){
                countBalls++;     // Agli baal successfully place ho gaye
                lastPlacedposition = position[i];       // Last placed positon update kar do
            }
            // Agar required 'm' balls palced ho chuke hai to check katake ki jarurrat nahi hai
            if( countBalls >= m){
                return true;
            }
        }
        // Agar array khatam khtam hone k baad bhi 'm' baal placed nahi ho paye 
        return false;
        }
    int maxDistance(vector<int>& position, int m) {
         int n = position.size();

         // Step 1: Positions ko sort karna mandatory hai taaki consecutive baskets
        // ke beech ka distance order me check kiya ja sake.
         sort ( position.begin() , position.end());

         // Step 2: Binary search ki range define karte hai
         int low = 1 ;

         // maximum force first aur last basket k bech ka differnce ho skta hai
         int high = position[n-1] - position[0];

         // Step 3: Binary search on answer
          while ( low <= high){
            int mid = low + ( high - low )/2;

            // check karo: kya 'mid' jitni magnetic force maintain karke m balls place ho sakti hain?
            if( canWePlace( position,mid,m)){
                // Agar possible hai , toh hume force ko maximize karana  hai
                // isleye hum right half me jayenge( aur badi force dhoondhne)
                low = mid +1;
            } else {
                // Agar mid force ke sath m balls fit nahi ho pa rhe hai
                // toh force kam karane padege
                high = mid -1;
            }
          }
          // Loop terminate hone ke baad opposite polarity principle ke mutabiq
        // 'high' humesha maximum valid force par point karega.
         return high;
    }
};