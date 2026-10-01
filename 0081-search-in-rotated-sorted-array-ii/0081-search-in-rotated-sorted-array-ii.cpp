class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
         int low = 0 ;
         int high = n -1;

         while( low <= high){
            int mid = ( low + high)/2;
            
            if( nums[mid] == target) return true;

            if( nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            if( nums[low] <= nums[mid]){
                if( nums[low] <= target && target <= nums[mid]){
                    high = mid -1;
                }
                else{
                    low = mid +1;
                }
            }
            else {
                if( nums[mid] <= target && target <= nums[high]){
                    low = mid +1;
                }
                else {
                    high = mid -1;
                }
            }

         }
         return false ;
    }
};































// class Solcution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int n = nums.size();
        
//         // Pointers setup: low start me aur high end me
//         int low = 0, high = n - 1;

//         while (low <= high) {
//             // Middle index nikaalo (integer overflow se bachne ke liye standard tarika)
//             int mid = low + (high - low) / 2;

//             // Step 1: Agar mid par hi target mil gaya, toh turant true return kar do
//             if (nums[mid] == target) return true;

//             // Step 2: Sabse important duplicate edge case!
//             // Agar low, mid aur high teeno ki values barabar hain (jaise [3, 1, 2, 3, 3, 3, 3]),
//             // toh hum decide nahi kar sakte ki kaunsa half sorted hai.
//             if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
//                 // Mid already target nahi hai (Step 1 me check ho gaya),
//                 // isliye safe hokar dono ends ko 1-1 step shrink kar do
//                 low++;
//                 high--;
//                 continue; // Next iteration par jao, niche ka check skip karo
//             }

//             // Step 3: Check karo kya LEFT HALF sorted hai
//             if (nums[low] <= nums[mid]) {
//                 // Agar target left sorted range [nums[low], nums[mid]] ke andar lie karta hai
//                 if (nums[low] <= target && target <= nums[mid]) {
//                     high = mid - 1; // Left side me dhoondo, high ko peeche lao
//                 } else {
//                     low = mid + 1;  // Right side me jao, low ko aage badhao
//                 }
//             }
//             // Step 4: Agar left half sorted nahi hai, toh pakka RIGHT HALF sorted hoga
//             else {
//                 // Agar target right sorted range [nums[mid], nums[high]] ke andar lie karta hai
//                 if (nums[mid] <= target && target <= nums[high]) {
//                     low = mid + 1;  // Right side me dhoondo, low ko aage badhao
//                 } else {
//                     high = mid - 1; // Left side me jao, high ko peeche lao
//                 }
//             }
//         }

//         // Step 5: Pura array check ho gaya aur target nahi mila
//         return false;
//     }
// };