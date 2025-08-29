class Solution {
public:
    long long flowerGame(int n, int m) {
           if(n==1 && m==1) return 0;

        long long even1=0;
        long long odd1=0;
        long long even2=0;
        long long odd2=0;
        if(n%2 !=0) {
            even1=(n/2);
            odd1=(n/2)+1;
        }
        else {
             even1=(n/2);
            odd1=(n/2);
        }
         if(m%2 !=0) {
            even2=(m/2);
            odd2=(m/2)+1;
        }
        else {
             even2=(m/2);
            odd2=(m/2);
        }
        long long evensum=(even1*odd2);
        long long oddsum=(odd1*even2);

        return (evensum+oddsum);
       


    }
};

//1 2 3 
// 1 2
// 
