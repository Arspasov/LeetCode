class Solution {
    public static boolean isAnagram(String s, String t) {
        boolean allUsed = true;
        HashMap<Character, Integer> map = new HashMap();
        for (int i = 0; i < s.length(); i++) {
            Character value = s.charAt(i);
            if (map.containsKey(value)) {
                map.put(s.charAt(i), map.get(value) + 1);
            } else {
                map.put(s.charAt(i), 1);
            }
        }

        for (int i = 0; i < t.length(); i++) {
            Character value = t.charAt(i);
            if (!map.containsKey(value)) {
                allUsed = false;
                break;
            } else {
                if (map.get(value) == 1) {
                    map.remove(value);
                } else {
                    int newValue = map.get(value) - 1;
                    map.put(value, newValue);
                }
            }
        }
        if (map.isEmpty() && allUsed) {
            return true;
        }

        return false;
    }
}