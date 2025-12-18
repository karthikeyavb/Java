class Solution {
    public int singleNumber(int[] nums) {
        int s=nums[0];
        for(int i=1;i<nums.length;i++){
            s=s ^ nums[i];
        }
        return s;
    }
}


class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer,Integer> hm=new HashMap<>();
        for(int s:nums){
           hm.put(s,hm.getOrDefault(s,0)+1); 
        }
        for(int s:nums){
            if(hm.get(s)==1){
                return s;
            }
        }
        return -1;
    }
}
