class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      if (gas.size() == 1)
    return gas[0] >= cost[0] ? 0 : -1;

        int totalCost=0;
      vector<int> idx;
        for(int i=0; i<cost.size(); i++) {      
            gas[i]=gas[i]-cost[i];
            if(gas[i]>0) {
               idx.push_back(i);
            }
        }


        if(idx.size()==0) return -1;

   


        for(int i=0; i<idx.size(); i++) {
            int j=idx[i];
            int temp=0;
            int store=0;
            while(temp<gas.size()) {
                store+=gas[j];


j++;
temp++;
                if(j==gas.size()) {
                    j=0;
                }
                if(store<0) break;
            }
            if( store>=0) {
                return idx[i];
            }
        
        }



          return -1;
       
    }
};