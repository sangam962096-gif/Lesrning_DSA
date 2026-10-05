class Solution {
public:
  // Yeh helper function calculate karega ki agr har element ko divisor se
  //divide karenge ceil value lein ,toh total  sum kitna aayega

  long long calculateSum( const vector<int> & nums , int divisor){
    long long totalSum = 0 ;
    for( int num : nums){
        // ( num + divisor -1)/ divisor integer arithmetic ka use karake ceil value deta hai
        // Isse floating point ya ceil () function ke overhead bachate hai
        totalSum += ( num + divisor -1) / divisor;
    }
    return totalSum;
  }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Step 1: minimum divisor 1 ko skta hai kyuki 0 se divide nahi kar skate
        int low = 1;
        
        // step 2 : Maximum divisor array ka maximum element hoga
        int high = *max_element( nums.begin(), nums.end());

        // Step 3: Binaray seacrh on answer suru karate hai
        while( low <= high){
            // Overflow se bachane k leye safe mid calculation keya
            int mid = low + ( high  - low )/ 2;

            // check karo ki mid divisor se sum threshold ke barabr hai ya chota hai
            if( calculateSum(nums,mid) <= threshold){
                //Agar condition satisfy kar raha hai to ye possible answer ho skta hai
                // Lekin hme smallest divisor chaheye , isleye left half me check karenege 
                high = mid -1;
            }
            else{
                // Agar sun threshold se bada ho gaya , mtlb divisor bahut chota hai
                // Hume sum kam karane k leye divisor ko bada karana padega
                low = mid +1;
            }
        }
        // Loop terminate hone ke baad 'low' hamesa  smallest wale part par point karega
         return low ;
    }
}; 