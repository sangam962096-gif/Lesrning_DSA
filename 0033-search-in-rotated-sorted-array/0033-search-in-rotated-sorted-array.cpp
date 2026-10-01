class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0  ;
        int high = n-1;

        while( low <= high){
            int mid = ( low + high) /2;
            if(nums[mid] == target ) return mid;
            if( nums[low] <= nums[mid]){
             if( nums[low] <= target &&  target <= nums[mid] ){
                high = mid -1;
             }
             else {
                low = mid+1;
             }
            }
             else{
             if( nums[mid] <= target && target <= nums[high]){
                low = mid +1;
             }
             
             else {
                high = mid - 1;
             }


             }
            }  
            return -1;
        }      
};
























// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
        
//         // Step 1: Binary search ke liye do pointers define kiye
//         int low = 0, high = n - 1; 

//         // Step 2: Loop tab tak chalega jab tak search space valid hai
//         while (low <= high) {
//             // Middle index nikaalo (overflow se bachne ke liye low + (high - low) / 2 bhi likh sakte hain)
//             int mid = (low + high) / 2;

//             // Step 3: Agar target directly mid par mil gaya, toh uska index return kar do
//             if (nums[mid] == target) return mid;

//             // Step 4: Check karo ki LEFT HALF sorted hai ya nahi
//             if (nums[low] <= nums[mid]) {
//                 // Agar left half sorted hai, toh check karo: kya target left half ke range me exist karta hai?
//                 if (nums[low] <= target && target <= nums[mid]) {
//                     // Agar target left side me hai, toh right side ko ignore karo aur high ko peeche lao
//                     high = mid - 1;
//                 }
//                 else {
//                     // Agar target left side me nahi hai, toh pakka right side me hoga, isliye low ko aage badhao
//                     low = mid + 1;
//                 }
//             } 
//             // Step 5: Agar left half sorted nahi tha, toh pakka RIGHT HALF sorted hoga
//             else {
//                 // Check karo: kya target right half ke range me exist karta hai?
//                 if (nums[mid] <= target && target <= nums[high]) {
//                     // Agar target right side me hai, toh left side ko ignore karo aur low ko aage badhao
//                     low = mid + 1;
//                 }
//                 else {
//                     // Agar target right side me nahi hai, toh left side me dhoondo aur high ko peeche lao
//                     high = mid - 1;
//                 }
//             }
//         }

//         // Step 6: Agar pura loop khatam ho gaya aur element nahi mila, toh -1 return karo
//         return -1;
//     }
// };