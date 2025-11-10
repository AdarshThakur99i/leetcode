class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
               unordered_map<int,int> mp1;
               unordered_map<int,int> mp2;
               for(int i=0; i<tops.size(); i++) {
                        mp1[tops[i]]++;
                        mp2[bottoms[i]]++;
               }
               int maxi1=0;
               int maxi2=0;
               int num1=0;
               int num2=0;
               
            for(auto it: mp1) {
                 if(it.second > maxi1) {
                    maxi1=it.second;
                    num1=it.first;
                 }
            }
             for(auto it: mp2) {
                 if(it.second > maxi2) {
                    maxi2=it.second;
                    num2=it.first;
                 }
            }
            int cnt1=0;
            int cnt2=0;
           bool flag1=true;
           bool flag2=true;
            for(int i=0; i<tops.size(); i++) {
                if(tops[i] !=  num1 && bottoms[i]==num1) {
                    cnt1++;
                }
                else if(tops[i] !=  num1 && bottoms[i]!= num1) {
                    flag1=false;
                    break;
                }
            }
            
             for(int i=0; i<bottoms.size(); i++) {
                if(bottoms[i] != num2 && tops[i]==num2) {
                    cnt2++;
                }
                else if(bottoms[i] !=  num2 && tops[i]!= num2) {
                    flag2=false;
                    break;
                }
            }
            int maxi=INT_MAX;
            if(flag1==true) maxi=min(maxi,cnt1);
            if(flag2==true) maxi=min(maxi,cnt2);
            if(flag1==false  && flag2==false) return -1;
            return maxi;



    }
};