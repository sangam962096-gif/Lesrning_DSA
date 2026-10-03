class Solution {
public:
int possible(vector<int>&bloomDay ,int day ,int m , int k){
    int n = bloomDay.size();
     int cnt = 0 ;
     int noOfB = 0 ;

     for ( int i = 0 ; i <n ; i++ ){
        if( bloomDay[i] <= day){
            cnt++;
        }
        else{
            noOfB += (cnt/k);
            cnt  = 0; 
        }
     }
     noOfB += (cnt/k);

     return noOfB >= m;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1LL * k * 1LL;

        if( val > bloomDay.size()) return  -1;

        int mini =INT_MAX; int maxi =INT_MIN;
        for( int  i = 0 ; i < bloomDay.size(); i++){
            mini = min( mini , bloomDay[i]);
            maxi = max ( maxi , bloomDay[i]);
        }
        int low = mini , high = maxi;
        while( low <= high){
            int mid = low + (high - low)/2;

            if( possible( bloomDay ,mid,m ,k)){
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return low ;
    }
};
















// class Solution {
// public:
//     // Helper function: Check karta hai ki kya hum 'day' dino ke andar 'm' bouquets bana sakte hain ya nahi
//     int possible(vector<int>& bloomDay, int day, int m, int k) {
//         int cnt = 0;    // Lagataar (adjacent) khile hue phoolon ka count
//         int noOfB = 0;  // Ab tak kitne bouquets ban chuke hain

//         for (int i = 0; i < bloomDay.size(); i++) {
//             // Agar current phool 'day' ya usse pehle khil chuka hai
//             if (bloomDay[i] <= day) {
//                 cnt++; // Consecutive bloomed flowers ka count badhao
//             } 
//             else {
//                 // Agar sequence toot gaya (phool nahi khila hai):
//                 // Pichle lagataar khile phoolon se jitne complete bouquet ban sakte the, unhe add karo
//                 noOfB += (cnt / k);
//                 cnt = 0; // Agle sequence ke liye count reset kar do
//             }
//         }

//         // Loop khatam hone ke baad bache hue consecutive phoolon se bouquets banao
//         noOfB += (cnt / k);

//         // Agar bane hue bouquets 'm' ya usse zyada hain, toh return true, warna false
//         return noOfB >= m;
//     }

//     int minDays(vector<int>& bloomDay, int m, int k) {
//         // Base Condition: Total phool required = m * k
//         // 1LL overflow prevent karne ke liye lagaya hai (large numbers ke product me)
//         long long val = m * 1LL * k * 1LL;
        
//         // Agar zaroorat total phoolon se zyada hai, toh bouquets banana impossible hai
//         if (val > bloomDay.size()) return -1;

//         // Binary search ke liye minimum aur maximum possible days dhoond rahe hain
//         int mini = INT_MAX, maxi = INT_MIN;
//         for (int i = 0; i < bloomDay.size(); i++) {
//             mini = min(mini, bloomDay[i]); // Sabse pehla phool kab khilega
//             maxi = max(maxi, bloomDay[i]); // Sabse aakhiri phool kab khilega
//         }

//         // Range set ki: Answer 'mini' se chhota nahi ho sakta aur 'maxi' se bada nahi ho sakta
//         int low = mini, high = maxi;

//         // Binary Search on Answer
//         while (low <= high) {
//             int mid = (low + high) / 2; // Mid day par check karenge

//             // Agar 'mid' din me 'm' bouquets banana possible hai:
//             // Toh hume aur kam dino me dekhna chahiye (minimum days find karna hai)
//             if (possible(bloomDay, mid, m, k)) {
//                 high = mid - 1; // Left side search karo
//             } 
//             // Agar 'mid' din me nahi ban pa rahe, toh zyada din chahiye
//             else {
//                 low = mid + 1;  // Right side search karo
//             }
//         }

//         // Loop end hone par 'low' point karega minimum valid days par
//         return low;
//     }
// };