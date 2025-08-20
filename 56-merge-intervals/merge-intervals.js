/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    intervals.sort((a,b) => {
        if(a[0]==b[0]) return a[1]-b[1];

        return a[0]-b[0];
    });
   let end=intervals[0][1];
   let start=intervals[0][0];
   let temp=[];
    for(let i=1; i<intervals.length; i++) {
            if(intervals[i][0]>end) {
                 temp.push([start,end]);
                 start=intervals[i][0];
                 end=intervals[i][1];
            }
            end=Math.max(end,intervals[i][1]);  
    }
    temp.push([start,end]);

    return temp;
};