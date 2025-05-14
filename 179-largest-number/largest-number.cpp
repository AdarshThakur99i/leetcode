class Solution {
public:

   static bool comparatore(string &a ,string &b) {

    return (a+b)>(b+a);
   }
    string largestNumber(vector<int>& nums) {
        vector<string> st;

        for(int i=0; i<nums.size(); i++) {
       st.push_back(to_string(nums[i]));

        }
    
      sort(begin(st),end(st),comparatore);
      if(st[0]=="0") return "0";
      string res="";

      for(auto it: st) {
             res+=it;
      }

     
  return res;


    }
};