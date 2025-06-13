class NumArray {
public:
int n;
vector<int> segmentTree;
   void buildTree(int i,int l,int r,vector<int> &segmentTree,vector<int> &nums) {
    if(l==r) {
        segmentTree[i]=nums[l];
        return;
    } int mid=l+(r-l)/2;
    buildTree(2*i+1,l,mid,segmentTree,nums);
    buildTree(2*i+2,mid+1,r,segmentTree,nums);
    segmentTree[i]=segmentTree[2*i+1] +segmentTree[2*i+2];

   }
    void update(int idx,int val,int i,int l,int r,vector<int>& segmentTree) {

        if(l==r) {
            segmentTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid) {
            update(idx,val,2*i+1,l,mid,segmentTree);
        }
        else {
            update(idx,val,2*i+2,mid+1,r,segmentTree);
        }
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];

        
    }
    int Query(int start,int end,int l,int r,int i,vector<int>& segmentTree) {
        if(l>end || r<start) {
            return 0;
        }
        if(l>=start && r<=end) {
            return segmentTree[i];
        }

        int mid=l+(r-l)/2;
        return 
        Query(start,end,l,mid,2*i+1,segmentTree)+
        Query(start,end,mid+1,r,2*i+2,segmentTree);
     }

    
    
    NumArray(vector<int>& nums) {
        n=nums.size();
       segmentTree.resize(4*nums.size(),0);
       buildTree(0,0,nums.size()-1,segmentTree,nums);
        
    }
    
    void update(int index, int val) {
         update(index,val,0,0,n-1,segmentTree);
         
        
    }
    
    int sumRange(int left, int right) {
       return Query(left,right,0,n-1,0,segmentTree);
        
    }
};     
        
  

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */