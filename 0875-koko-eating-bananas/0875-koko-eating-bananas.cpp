class Solution {
public:
int findMax( vector<int> & piles){
            int maxi = INT_MIN;
            int n = piles.size();
            for( int  i = 0  ; i < n ; i++){
                maxi = max(maxi , piles[i]);
            }
            return maxi;
        }
        long long calculateTotalHours(vector<int>& piles, int hourly){
            long long totalH = 0 ;
            int n = piles.size();
            for( int i = 0 ; i < n ; i++){
                totalH += ceil((double)piles[i] / (double)hourly);
            }
            return totalH;
        }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = findMax(piles);

        while( low <= high){
            int mid = low + ( high - low)/2;

            long long totalH = calculateTotalHours( piles , mid);

            if( totalH <= h){
               high = mid -1;

            }
            else {
                low = mid +1;
            }
        }
      return low;
    }
};























// class Solution {
// public:
//     // Helper Function 1: Array me sabse bada pile (maximum bananas) dhoondhne ke liye
//     int findMax(vector<int>& piles){
//         int maxi = INT_MIN;
//         int n = piles.size(); 
//         // Har pile ko loop karke maximum value find out karo
//         for(int i = 0; i < n; i++){
//             maxi = max(maxi, piles[i]);
//         }
//         return maxi; 
//     } 

//     // Helper Function 2: Agar Koko 'hourly' speed se khaye, toh total kitne ghante lagenge?
//     int calculateTotalHours(vector<int>& piles, int hourly){
//         long long totalH = 0; // Edge case: Agar total hours bohot zyada ho jaye, toh long long use karna safe hota hai
//         int n = piles.size();
//         for(int i = 0; i < n; i++){
//             // ceil() use kiya hai kyunki agar pile me speed se kam bananas bhi bache hain, 
//             // toh bhi Koko us pile ko khatam karne ke baad bacha hua ghanta aaram karti hai.
//             // (double) me typecast karna zaroori hai taaki division decimal me ho aur ceil sahi se kaam kare.
//             totalH += ceil((double)piles[i] / (double)hourly);
//         }
//         return totalH;
//     }

//     // Main Function: Minimum speed nikaalni hai taaki h hours me sab khatam ho jaye
//     int minEatingSpeed(vector<int>& piles, int h) {
//         // Koko kam se kam 1 banana per hour kha sakti hai (low = 1)
//         // Aur maximum use utni speed chahiye jitna sabse bada pile hai (high = max pile)
//         int low = 1, high = findMax(piles);
        
//         // Binary Search ka loop
//         while(low <= high){
//             int mid = low + (high - low) / 2; // mid yahan 'current eating speed' ko darshata hai
            
//             // Pata karo ki agar 'mid' ki speed se khaye, toh kitne ghante lagenge
//             long long totalH = calculateTotalHours(piles, mid);
            
//             // Agar lagne wale total ghante limit 'h' ke andar hain (<= h)
//             if(totalH <= h){
//                 // Yeh speed valid hai, par hume aur choti (MINIMUM) speed dhoondhni hai
//                 // Isliye speed kam karne ke liye high ko peeche (left side) laao
//                 high = mid - 1;
//             } 
//             // Agar limit 'h' se zyada ghante lag rahe hain (bohot dheere kha rahi hai)
//             else {
//                 // Toh speed badhani padegi, isliye low ko aage (right side) bhejo
//                 low = mid + 1;
//             }
//         }
        
//         // Loop khatam hone ke baad 'low' hamesha minimum valid speed par point karega
//         return low;
//     }
// };