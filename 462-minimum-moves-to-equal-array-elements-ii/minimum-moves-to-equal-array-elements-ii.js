/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
        nums.sort((a,b) => a-b);
        let cnt=0;
let n=nums.length;
        if(n%2 !==0) {
            let idx=Math.floor(n/2);
            for(let i=0; i<n; i++) {
                cnt+= Math.abs(nums[i]-nums[idx]);
            }
        }
        else {
            let idx=Math.floor(n/2);
            let idx2=idx-1;
            let temp1=0;
            let temp2=0;
            for(let i=0; i<n; i++) {
              temp1+=Math.abs(nums[i]-nums[idx]);
              temp2+=Math.abs(nums[i]-nums[idx2]);
            }
            return Math.min(temp1,temp2);        }
  return cnt;

};