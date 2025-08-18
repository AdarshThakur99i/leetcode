class Solution {
public:
   double epsilon=1e-6;
   bool check(vector<double>& cards) {
          if(cards.size()==1) {
            if(abs(cards[0]-24) <= epsilon) return true;
            return false;
          }
          for(int i=0; i<cards.size(); i++) {
            for(int j=0; j<cards.size(); j++) {
                if(i==j) continue;
           double a=cards[i];
           double b=cards[j];
                vector<double> temp;
                for(int k=0; k<cards.size(); k++) {
                    if(k != i && k!=j) {
                        temp.push_back(cards[k]);
                    }
                }
                vector<double> possible={a-b,a+b,b-a,a*b,b*a};
                if(abs(b)>0.0) {
                    possible.push_back(a/b);
                }
                if(abs(a)>0.0) {
                    possible.push_back(b/a);
                }
                for(auto it: possible) {

                    temp.push_back(it);
                    if(check(temp)==true) return true;
                    temp.pop_back();
                }
            }
          }

    
    return false;
   }
    bool judgePoint24(vector<int>& cards) {
       vector<double> arr;
       for(int i=0; i<cards.size(); i++) {
        arr.push_back(1.0 * cards[i]);
       }
         return check(arr);
    }
};