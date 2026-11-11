class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int a = asteroids[i];
            if (a > 0) {
                st.push_back(a);
            } else {
                while (!st.empty() && st.back() > 0 && st.back() < abs(a)) {
                    st.pop_back();
                }
                if(!st.empty()&&st.back()==abs(a)){
                    st.pop_back();
                }
                else if(st.empty()||st.back() <0){
                    st.push_back(a);
                }
            }
        }
        return st;
    }
};