class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Ek vector banayenge jisko hum stack ki tarah treat karenge.
        // vector es leye le rhe taaki last mein element nikal ke traverse na karana pde(direct answer ready ho)
        vector<int> st;

        // Har ek asteroid ko array se ek ek karke check karenge
        for( int i = 0 ; i < asteroids.size(); i++){

            // Agar asteroid positive hai( yaani right direction ki tarf ja raha hai)
            if( asteroids[i]  > 0){
                st.push_back(asteroids[i]);      //ise sedhe stack mein daal do kyuki ye aane walo se takrayega ya fir safe rahega
            }
            else{
                // Jab tak stack khali nahi hota , aur top ka element positive hai
                // aur uska size current left aaane wale asteroid se strictly chota hai( abs( asteroids[i]))
                while( !st.empty() && st.back() > 0 && st.back()  < abs(asteroids[i])){
                    st.pop_back();
                }
                // agar stack ke top wale asteroid ka size aur current negative asteroid ka size exactly same hai
                if(!st.empty() && st.back() == abs(asteroids[i])){
                    st.pop_back();    // Dono ek dusre ko cancle kar denge toh bas top wale ko pop karo aur current wale ko insert mat karo
                }
                // Agar ya toh stack khali ho ya gaya hai , ya  stack ke top par already koi left jane wala ( negative) asteroids he bacha hai
                else if( st.empty() || st.back() < 0){
                    st.push_back(asteroids[i]);   // yr dono same direction me move kar rahe , isleye collision nahi hoga , current ko push kar do
                }
            }
        }
        // Loop khatam hone ke baad jo final array bachi hai , usko seedhe return kar do
        return st;
    }
};