class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size();
       
       int l = 0 , r = n-1 , maxwater = 0 ; 
       while( l <r){
 int w = r-l;
 int h = min(height[l] , height[r]);
 int area = w *h;
 maxwater = max( maxwater , area);
 height[l] <height[ r] ? l++ : r--;
       }
       return maxwater;
    }
    
};