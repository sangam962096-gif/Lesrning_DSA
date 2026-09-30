class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  n = nums.size();
if( nums.size() == 0 ) return 0;
int  i = 0 ;
for( int j = i +1 ; j < n; j++ ){
    if( nums[i]  != nums[j]){
        i++;
        nums[i] = nums[j];
    }
}
 return i + 1;
    }
};






















//  // again repeat ;
//        if( nums.size() == 0) return 0 ;
//        int i = 0;             // i point karega last unique element par
//        for( int  j = i +1; j < nums.size() ; j++){
//         if( nums[i] != nums[j]){
//             i++;
//             nums[i] = nums[j];
           
//         }
//        }
//        return i+1;  // Number of unique element
//     }
// };