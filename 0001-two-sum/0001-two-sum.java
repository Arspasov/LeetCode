class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer > storage = new HashMap();
        for(int i = 0; i< nums.length; i++){
            storage.put(nums[i], i);
        }
        
        for(int i = 0; i< nums.length; i++){
            int toCheck = target - nums[i];
            if(storage.containsKey(toCheck)){
                if(storage.get(toCheck) == i){
                    continue;
                }
                
                int result [] = new int [2];
                result[0] = i;
                result[1] = storage.get(toCheck);
                return result;
            }    
        }

        return null;
    }
}