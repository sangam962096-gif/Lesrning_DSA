class Solution {
public:
// Yeh function calculate karega ki ek specific 'capacity'ke sath
// sare packages ko ship karane me kitne din (days ) lagenge
int findDays(vector<int>& weights , int capacity){
    int days = 1 ;     // Pahele din se suru karenge
    int load = 0 ;     // Abhi tak current din mein ketna load dala hai

    for ( int i = 0 ; i < weights.size(); i++){
        // Agar next item dalane se capacity exceed ho jate hai
        if( load+ weights[i] > capacity){
            days += 1;         // Naya din ( next day) shuru karo
            load = weights[i];  // Naya din ke load is naye iten se start hoga
        }
        else {
            // Agar capacity ke ander hai, toh same day me item load kar do
            load += weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        // Kam se kam sabse bhare package ship hone jitne capacity hone chaheye
        int low = *max_element( weights.begin() , weights.end());

        // Worst case me 1 din me he sare packges ship kar skte hai
        int high = accumulate(weights.begin(), weights.end(), 0);

        // Binary search lagayenge range [ low , high ] par
        while( low <= high){
            int mid = low + ( high - low)/2;

            // Chech karte hai ki agr capacity mid ho to ketne din lagenge
            int numberOfDays = findDays( weights,mid);

            if( numberOfDays <= days){
                // agr given days ke ander packages ship ho jaye
                // toh hum aur choti capacity dhudhne ki koshish karenge 
                high = mid -1;
            }
            else {
                // Agar required days se jada din lag rahe hain,
                // matlab humari assumed capacity bohut choti hai, isko badhna padega

                low = mid + 1;
            }
        }
        return low;
    }
};