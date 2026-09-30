class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n = nums.size();

       int j = -1;
       for( int  i = 0 ; i < n ; i++){
        if( nums[i] == 0){
            j = i ;
            break;
        }
       }
       if( j == -1) return ;

       for( int  i = j +1; i <n ; i++){
        if( nums[i] != 0){
            swap( nums[i] , nums[j]);
            j++;
        }
       }
    
    }

};


















// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
        
//         // Pointer 'j' represent karega pehle 0 ka index
//         // Starting me -1 rakhte hain taaki pata chale abhi tak zero mila ya nahi
//         int j = -1;

//         // Step 1: Array me scan karke sabse pehla '0' dhoondo
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0) {
//                 j = i; // Pehla 0 mil gaya, uska index note kar lo
//                 break; // Aage dekhne ki zarurat nahi, loop yahin roko
//             }
//         }

//         // Edge Case: Agar pure array me ek bhi 0 nahi mila (j abhi bhi -1 hai),
//         // iska matlab sabhi numbers non-zero hain, toh kuch swap karne ki zarurat nahi
//         if (j == -1) return;

//         // Step 2: Pehle 0 ke turant baad (j + 1) se start karke aage check karo
//         for (int i = j + 1; i < n; i++) {
//             // Agar current element non-zero hai, toh usko 'j' wale zero ke sath swap karo
//             if (nums[i] != 0) {
//                 swap(nums[i], nums[j]);
//                 // Swap karne ke baad 'j' index par non-zero aa gaya, 
//                 // aur agla zero (j + 1) par shift ho gaya, isliye j ko aage badhao
//                 j++;
//             }
//         }
//     }
// };