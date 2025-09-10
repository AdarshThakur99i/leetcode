class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
           
          int bottlesdrunk=0;
          int emptybottles=0;
          int fullbottles=numBottles;
           while(fullbottles+emptybottles>=numExchange) {
           emptybottles+=fullbottles;
           bottlesdrunk+=fullbottles;
           fullbottles=0;
    //  while(emptybottles>0) {
        // if(numExchange > emptybottles) {
        //     emptybottles+=fullbottles;
        //     bottlesdrunk+=fullbottles;
        //     fullbottles=0;
        // }
        if(emptybottles>=numExchange) {
            emptybottles -= numExchange;
            numExchange++;
            fullbottles++; 
             }
     
        
           }
           if(fullbottles>0) bottlesdrunk+=fullbottles;
           return bottlesdrunk;
    }
};