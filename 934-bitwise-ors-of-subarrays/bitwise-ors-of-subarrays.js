/**
 * @param {number[]} arr
 * @return {number}
 */
var subarrayBitwiseORs = function(arr) {
        let prev=new Set();
        let res= new Set();
        for(let i=0; i<arr.length; i++) {
            let curr=new Set();
            for(let val of prev) {
                curr.add(arr[i] | val);
                res.add(arr[i] | val);
            }

            curr.add(arr[i]);
            res.add(arr[i]);

            prev=curr;
        }

        return res.size;
};