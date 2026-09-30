class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = m -1;
    int  right = 0;

    while( left >= 0 && right < n){
        if(nums1[left] > nums2[right]){
            swap( nums1[left] , nums2[right]);
            left-- , right++;
        }
        else{
            break;
        }
    }
    sort( nums1.begin() , nums1.begin()+m);
    sort(nums2.begin(), nums2.begin()+n);
     
     for( int  i = 0 ; i < n; i++){
        nums1[m+i] = nums2[i];
     }
    }
};

















//     //repeat the question

//     int left = m-1;   // nums1 ke aakhari number par point karega( sabse bada number idher ho skta hai)
//     int right = 0 ;   // nums2 ke sabse pahele number par point karega ( sabse chota number idhar hoga)


//     // jab tak dono array mein hum boundary k ander hai
//     while( left >= 0 && right < n){

//         // kya nums1 ka bada number , nums2 k chote number se bada hai?
//         if( nums1[left] > nums2[right]){
//             swap(nums1[left] ,nums2[right]);  // haan! toh  galat jagah hai , unhe aaps mein badal do
//             left--; right++;
//         }
//         else{
//             break;  // nahi! agar nums1 wala chota hai he hai , toh array already set hain , swapping rok do
//         }
//     }

//     // swaping ki wajah se numbers aage -peche gaye honge , isliye  wapas sort karana padega
//     sort(nums1.begin() ,nums1.begin()+m); // sirt nums1 ke pahele M element ko sort karo
//     sort( nums2.begin() , nums2.begin()+ n); //  nums2 ke sare n element ko sort karo


//     // Leetcode chahta hai ki final answer poora ka poora nums1 mein hi ho
//     for( int  i = 0 ; i < n ; i++){
//         nums1[m+i] = nums2[i];   // sorted nums2 ke element ko nums1 ke end mein(zeroes hata kar) chipka do
//     }
//     }
// };