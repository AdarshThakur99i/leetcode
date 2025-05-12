class Solution {
public:


    int minTimeToReach(vector<vector<int>>& moveTime) {
     int timeCount=0; 
    vector<vector<int>> result(moveTime.size(),vector<int>(moveTime[0].size(),INT_MAX));
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;

     result[0][0]=0;
     q.push({0,{0,0}});
     int delRow[]={1,0,-1,0};
     int delCol[]={0,1,0,-1};
    
  while(!q.empty()) {

    auto x=q.top();
    int time=x.first;
    int i=x.second.first;
    int j=x.second.second;
    q.pop();
  if(i==moveTime.size()-1 && j==moveTime[0].size()-1) {
    return time;
  }
    
  for(int p=0; p<4; p++) {
    int newRow=i+delRow[p];
    int newCol=j+delCol[p];
     
    if(newRow>=0 && newRow<moveTime.size() && newCol>=0 && newCol<moveTime[0].size()) {
        int wait=max(moveTime[newRow][newCol]-time,0);
        int totalTime=wait+time+1;

        if(result[newRow][newCol]>totalTime) {
            result[newRow][newCol]=totalTime;
   q.push({totalTime,{newRow,newCol}});
        }

     
    }
    
  }


  }



     return -1;
    }
};