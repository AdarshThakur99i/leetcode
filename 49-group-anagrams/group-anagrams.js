/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let arr=[];

let mp=new Map();

    for(let i=0; i<strs.length; i++) {
          let x=strs[i];
          x=x.split("").sort().join("");
          if(mp.has(x)) {
            arr[mp.get(x)].push(strs[i]);
          }
          else {
            arr.push([strs[i]]);
            mp.set(x,arr.length-1);
          }
    }
    return arr;
};