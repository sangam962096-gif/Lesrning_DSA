class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int  low = 0 , high = n -1;
        int ans = INT_MAX;

        while( low <= high){
            int mid =low + (high - low)/2;

            if( nums[low] <= nums[mid]){
                ans = min( ans,nums[low]);
                low = mid +1;
            }
            else {
                ans = min ( ans , nums[mid]);
                high = mid -1;
            }

        }
        return ans ;
    }



















};

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int n = nums.size();
        
//         // Pointers setup: 
//         // low = 0 (start), high = n-1 (end)
//         // ans ko maximum possible value (INT_MAX) se initialize kiya taaki minimum track ho sake
//         int low = 0, high = n - 1, ans = INT_MAX;

//         // Binary Search tab tak chalega jab tak valid search space hai
//         while (low <= high) {
//             // Middle index nikaalo (overflow se bachne ke liye low + (high - low) / 2 safer hota hai)
//             int mid = low + (high - low) / 2;

//             // Case 1: Check karo kya LEFT HALF sorted hai?
//             if (nums[low] <= nums[mid]) {
//                 // Agar left half sorted hai, toh is half ka sabse chhota element hamesha 'nums[low]' hoga.
//                 // Usko apne current 'ans' ke sath compare karke minimum update kar lo.
//                 ans = min(ans, nums[low]);

//                 // Left half ka minimum humne le liya hai, ab right half me dhoondhne ke liye low aage badhao
//                 low = mid + 1;
//             }
//             // Case 2: Agar left half sorted nahi hai, toh pakka RIGHT HALF sorted hoga
//             else {
//                 // Agar right half sorted hai, toh 'nums[mid]' is sorted part ka sabse chhota element ho sakta hai.
//                 // Isko 'ans' ke sath compare karke minimum update karo.
//                 ans = min(ans, nums[mid]);

//                 // Baki smaller elements (rotation point) left side me ho sakte hain, isliye high ko peeche lao
//                 high = mid - 1;
//             }
//         }

//         // Search space khatam hone par 'ans' me array ka absolute minimum hoga
//         return ans;
//     }
// };