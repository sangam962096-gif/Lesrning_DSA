class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { 
       int n = nums.size();
        if( n == 1) return nums[0];
        if( nums[0]  != nums[1])  return nums[0];
        if( nums[n-1]  != nums[n-2]) return nums[ n -1];

        int low = 1 , high = n-2;
        while( low <= high){
         int mid = low + ( high - low)/2;

         if( nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
            return nums[mid];
         }
         if( ( mid % 2 == 1 && nums[mid -1] == nums[mid]) || ( mid % 2 == 0 && nums[mid +1] == nums[mid] ))  {
           low = mid +1; 
         }
         else {
            high = mid -1;
         }
        }
        return -1;
    }












};


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) { 
//         int n = nums.size();

//         // Edge Case 1: Agar array me sirf ek hi element hai
//         if (n == 1) return nums[0];

//         // Edge Case 2: Agar sabse pehla element hi unique hai
//         // (Agla element match nahi karta toh yahi single element hai)
//         if (nums[0] != nums[1]) return nums[0];

//         // Edge Case 3: Agar sabse aakhiri element hi unique hai
//         // (Pichla element match nahi karta toh yahi single element hai)
//         if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

//         // Boundaries ko 1 se (n - 2) set kiya taaki 'mid - 1' ya 'mid + 1'
//         // check karte waqt kabhi index out of bounds na ho
//         int low = 1, high = n - 2;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             // Step 1: Check karo kya 'mid' hi unique element hai?
//             // Unique element apne pichle (mid-1) aur agle (mid+1) dono se alag hoga
//             if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
//                 return nums[mid];
//             }

//             // Step 2: Elimination logic (Check karo ki hum unique element ke LEFT side hain ya RIGHT side)
//             // Normal pairs ka pattern (even, odd) hota hai:
//             // - Agar mid ODD hai aur nums[mid - 1] == nums[mid] hai -> pattern follow ho raha hai
//             // - Agar mid EVEN hai aur nums[mid + 1] == nums[mid] hai -> pattern follow ho raha hai
//             if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) || 
//                 (mid % 2 == 0 && nums[mid + 1] == nums[mid])) {
//                 // Iska matlab hum single element ke LEFT side par khade hain.
//                 // Single element aage (right half) me milega, isliye low ko aage badhao
//                 low = mid + 1;
//             } 
//             else {
//                 // Pattern break ho chuka hai, matlab hum single element ke RIGHT side par hain.
//                 // Single element peeche (left half) me chhut gaya hai, isliye high ko peeche lao
//                 high = mid - 1;
//             }
//         }

//         // Agar array valid tha toh loop ke andar hi return ho jayega
//         return -1;
//     }
// };