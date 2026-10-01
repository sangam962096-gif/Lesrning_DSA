class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int n = nums.size();
      if( n == 1) return 0;
      if( nums[0] > nums[1]) return 0;
      if( nums[n-1] > nums[n-2]) return n-1;

      int low = 1 , high = n-2;
      while( low <= high){
        int mid = low + ( high - low)/2;

        if(nums[mid] > nums[mid -1]  && nums[ mid] > nums[mid+1]){
            return  mid;
        }
        else if ( nums[mid] > nums[mid-1]){
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}














                  
};


// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();

//         // Edge Case 1: Agar array me sirf 1 hi element hai, toh wahi peak hai
//         if (n == 1) return 0;

//         // Edge Case 2: Agar pehla element apne agle element se bada hai,
//         // toh index 0 hi peak hai (kyunki index -1 par -infinity hai)
//         if (nums[0] > nums[1]) return 0;

//         // Edge Case 3: Agar aakhiri element apne pichle element se bada hai,
//         // toh index n-1 hi peak hai (kyunki index n par -infinity hai)
//         if (nums[n - 1] > nums[n - 2]) return n - 1;

//         // Boundaries ko 1 se (n - 2) set kiya taaki 'mid - 1' aur 'mid + 1'
//         // access karte waqt kabhi "Index Out of Bounds" error na aaye
//         int low = 1, high = n - 2;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             // Step 1: Check karo kya 'mid' hi peak element hai?
//             // Agar mid apne left aur right dono padosi se bada hai, toh yahi peak hai
//             if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
//                 return mid;
//             }
//             // Step 2: Increasing slope check (chadhayi par hain)
//             // Agar mid apne left wale se bada hai, iska matlab curve upar ja raha hai,
//             // toh pakka right side me koi na koi peak zaroor milega
//             else if (nums[mid] > nums[mid - 1]) {
//                 low = mid + 1; // Right side me dhoondo
//             }
//             // Step 3: Decreasing slope check (dhalan par hain ya trough me hain)
//             // Agar mid apne left wale se chhota hai, iska matlab left side me curve upar tha,
//             // toh left side me peak pakka milega
//             else {
//                 high = mid - 1; // Left side me dhoondo
//             }
//         }

//         // Dummy return (valid inputs ke liye execution loop ke andar se hi return ho jayega)
//         return -1;
//     }
// };