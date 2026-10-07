class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        

        // Binary search ke pointer initialise kar rahe hain
        int low = 0 ;
        int high = n -1;

        while( low <= high){
            int mid = low + ( high - low)/2;

            // Mid index tak kitane number miss hue hain wo calculate karate hai
            // Ideally arr[mid] ki jagah(mid +1) hona chaheye tha
            int missing = arr[mid] - (mid + 1);

            // Agar  missing count se chota hai , iska mtalb kth misssing number 
            // mid ke right side me lie karega ,isleye left side eliminate karenge
            if( missing < k){
                low = mid +1;
            }
            // Agar missing count >= k hai , toh target left half me hoga
            else {
              high = mid -1;
            }
        }
        // Loop ke end me :
        // high us element par hoga jo target se pahele tha
        // Formula derivation ke according : ans = high +1+k ya low + k
        // kyuki binary seacrh k end me low = high +1  ho jata hai
         return low + k;
    }
};