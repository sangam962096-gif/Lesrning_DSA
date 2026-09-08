class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if( n == 0) return 0;    // agr array empty hai , toh water trap nahi ho skta 
        int lmax = 0;           //  left side se ab tak ka maximum height
        int rmax = 0 ;          // right side se ab tak ka maximum height
        int total = 0 ;
        int l = 0 ;             // left pointer array ke shuruwat mein
        int r = n-1;              // right pointer array k aakhir me
        while( l < r){            // jan tak dono pointer mil nahi jate

            // hamesa chota wale (smaller) building ko process karenge
            if(height[l] <= height[r]){

                // agar current building leftmax se choti hai , matlab water trap ho skta hai
                if(lmax > height[l]){
                total += lmax - height[l];
                }
                // nahi to current building he naya leftmax ban jayega 
                else {
                lmax = height[l];
                
                }
                l++;     // left pointer ko aage badhao
            }
            else {        // agr height[right] chota ya barabr hai

                // agar current building rightmax se choti , matlab water trap ho skta hai
                if( rmax > height[r]){
                total += rmax - height[r];
                }
                // nahi to current building hi naya rightmax ban jayegi
                else {
                rmax = height[r];
                }
                r--;          // right pointer ko peeche le aao
            }
        }
        return total ;
    }
};