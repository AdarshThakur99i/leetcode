class Solution {
public:
    double gain(int a,int b) {
      
        
        double x= ((double)a+1)/(b+1)- ((double)a/b); 
         return x;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        double n=classes.size();
      
        priority_queue<pair<double,pair<int,int>>> q;
        for(int i=0; i<classes.size(); i++) {
            int a=classes[i][0];
         
            int b=classes[i][1];
                
                  q.push({gain(a,b),{a,b}});
        
        }
        while(extra--) {
            auto x=q.top();
            q.pop();
            int a=x.second.first+1;
            int b=x.second.second+1;
         
            q.push({gain(a,b),{a,b}});
        }
        double sum=0;
        while(!q.empty()) {
             auto x=q.top();
               int a=x.second.first;
            int b=x.second.second;
            q.pop();
            sum+=(double)a/b;
        }
        sum=(sum)/n;
      return sum;
    }
};