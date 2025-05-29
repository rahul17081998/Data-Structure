/*
Problem: Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.
Approach:
- Use a HashMap to count occurrences of each integer. If count equals the number of arrays, add to result.
*/
import java.util.*;

public class IntersectionOfMultipleArrays {
    static List<Integer> intersection(List<List<Integer>> nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (List<Integer> v : nums) {
            for (int val : v) mp.put(val, mp.getOrDefault(val, 0) + 1);
        }
        List<Integer> ans = new ArrayList<>();
        int n = nums.size();
        for (Map.Entry<Integer, Integer> p : mp.entrySet()) {
            if (p.getValue() == n) ans.add(p.getKey());
        }
        Collections.sort(ans);
        return ans;
    }
    public static void main(String[] args) {
        List<List<Integer>> nums = new ArrayList<>();
        nums.add(Arrays.asList(1, 2, 3));
        nums.add(Arrays.asList(2, 3, 4));
        nums.add(Arrays.asList(2, 3));
        System.out.println(intersection(nums));
    }
} 