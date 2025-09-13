class Solution {
public:
    int trap(vector<int>& height) {
          vector<int> maxLeft(height.size(),INT_MIN);
          vector<int> maxRight(height.size(),INT_MIN);
          maxLeft[0]=height[0];          
          for(int i=1; i<height.size(); i++) {
            maxLeft[i]=max(maxLeft[i-1],height[i]);
          }
          maxRight[height.size()-1]=height.back();
          for(int i=height.size()-2; i>=0; i--) {
            maxRight[i]=max(maxRight[i+1],height[i]);
          }
          int area=0;
          for(int i=0; i<height.size(); i++) {
            area += min(maxLeft[i],maxRight[i])-height[i];
          }

          return area;
    }
};