class Solution {
public:  

       void check(int n,unordered_map<int,int> &mp) {
        if(n==0) return;   
       int sum=0;
       int temp=n;
        while(temp!=0) {

            int val=temp%10;
            temp=temp/10;
            sum+=val;
        }
        mp[sum]++;

        check(n-1,mp);

       }
    
    int countLargestGroup(int n) {
     unordered_map<int,int> mp;
     check(n,mp);
     int maxi=1;
     int count=0;
     for(auto &it: mp) {

        if(it.second==maxi) {
             count++;
        }
        else if(it.second>maxi) {
            maxi=max(it.second,maxi);
            count=1;
        }
     }

     return count;

    }
};