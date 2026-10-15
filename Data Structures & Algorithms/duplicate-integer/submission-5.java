class Solution {
    public boolean hasDuplicate(int[] nums) {
        Map<Integer, Integer> hash = new HashMap<Integer, Integer>();

        for (int num : nums) {
            Integer n = Integer.valueOf(num);
            if (hash.get(n) != null) hash.put(num, hash.get(num) + 1);
            else hash.put(num, 1);
        }

        for (Integer freq : hash.values()) {
            if (freq > 1) return true;
        }

        return false;
    }
}