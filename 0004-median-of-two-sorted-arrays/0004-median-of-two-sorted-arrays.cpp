class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1 = nums1.size();
       int n2 = nums2.size();

       if( n1 > n2)  return findMedianSortedArrays( nums2 , nums1);

       int low = 0 ; 
       int high = n1;
        
        int left = ( n1 + n2 +1 ) /2;
        int n = n1 + n2;

        while( low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;

            if( mid1 < n1) r1 = nums1[mid1] ;
            if( mid2 < n2) r2 = nums2[mid2];
            if( mid1 -1 >= 0) l1 = nums1[mid1 -1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 -1];

            if( l1 <= r2 && l2 <= r1) {
                if( n % 2 == 1){
                return max( l1 , l2);
                }
                return ( (double)(max( l1 ,l2) + min ( r1 , r2))) / 2.0;

            }
            else if ( l1 > l2 ){
                high = mid1 -1 ;
            }
            else { 
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();

//         // Step 1 : Hamesa smaller array par binaray search apply karenge 
//         // Agar nums1 badi hai , toh function ko swap karake call kar do
//         //Isse time comlexity 0 ( log ( n1 , n2)) rahege
//         if( n1 > n2 ) return findMedianSortedArrays ( nums2 , nums1);

//         // Step2 : Binaray search ka bound define karate hai
//         // low = 0 ; nums1 se minimum 0 element pick kar skta hai
//         // high n1 : nums1 se maximum sare element pick kar skta hai
//         int low = 0 ;
//         int high = n1;

//         // total element jo left half me hone chaheye 
//         // +1 off aur evev dono cases ko seamlessly handle karat ahi
//         int left = ( n1 + n2 + 1)/2;
//         int n = n1 + n2;

//          while ( low <= high) {
//             // Mid1 : nums1 se ketane element left half me aaynge 
//             int mid1 = ( low + high) >> 1;

//             // mid2 : bache huye element nums2 me aayenge 
//             int mid2 = left - mid1;

//             // Step 3 : boundaray element ( l1 ,l2 , r1 , r2) calcualte karate hai 
//             //Agar koe element exist nahi karat hai to dummy boundary values  assign  karte hai
//              int l1 = INT_MIN , l2 = INT_MIN;
//              int r1 = INT_MAX , r2 = INT_MAX;

//              if( mid1 < n1) r1 =nums1[mid1];
//              if( mid2 < n2) r2 = nums2[mid2];
//              if( mid1 -1 >= 0) l1 = nums1[mid1 - 1];
//              if( mid2 - 1 >= 0) l2 = nums2[mid2 -1];

//              // Step 4 : check karo ki partitions valid hai ya nahi 
//              // Valid partitions tab hota hai jab left half k sare element right half se choti hai
//              if( l1 <= r2 && l2 <= r1){
//                // Aagr total element odd ho to , left partitons ka maximum element he median hoga 
//                if ( n % 2 == 1){
//                 return max( l1 , l2);
//                }
//                // Agar even hai , toh left ke max aur right k min ka average median hoga
//                return ((double)(max(l1,l2) + min(r1,r2))) / 2.0;
//              }
//              // step 5 : binaray search space ko trim/shift karana 
//              else if( l1 > r2) {
//                 // nums1 se zyada element le leye hai,isleye left side search karo
//                 high = mid1 -1 ;

//              }
//              else {
//                 // nums2 se zyda elemment chale gye hain ( l2 < r1) , nums1 se aur element pick karo
//                 low = mid1 + 1;
//              }

//          }
//          return 0.0;    }
// };