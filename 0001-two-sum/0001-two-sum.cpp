class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int>mpp;
        for( int i = 0 ; i < n; i++){
            int num = nums[i];
            int moreneed = target - num ;
            if( mpp.find(moreneed)  != mpp.end()){
                return { mpp[moreneed] ,i};
            }
            mpp[num] = i;
        }
        return { -1 , -1};
    }
};





       












//     // repeat one more time;
//     int n = nums.size();
//     map<int ,int>mpp;   //{element , index}
//     for( int i = 0 ; i < n ; i++){
//         int num = nums[i];
//         int need = target - num;

//         // agar required element map mein mil gaya tab
//         if( mpp.find(need) != mpp.end()){
//             return {mpp[need] , i};
//         }
//         // current element ko map mein me daal do
//         mpp[num] = i;
//     }
//         return { -1 , -1};
// }
// };