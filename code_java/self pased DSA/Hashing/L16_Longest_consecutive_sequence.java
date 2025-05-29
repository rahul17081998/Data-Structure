/*
Problem: Find the length of the longest consecutive elements sequence in an unsorted array.
Approach:
- Sort the array and count the longest streak of consecutive numbers. O(n log n)
- (Optimal: Use HashSet for O(n), but here we use the sort-based approach as in the C++ code.)
*/
import java.util.*;

public class L16_Longest_consecutive_sequence {
    static int longConSeqCount(int[] arr) {
        if (arr.length == 0) return 0;
        Arrays.sort(arr);
        int res = 1, curr = 1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == arr[i - 1] + 1) {
                curr++;
            } else if (arr[i] != arr[i - 1]) {
                res = Math.max(res, curr);
                curr = 1;
            }
        }
        return Math.max(res, curr);
    }
    public static void main(String[] args) {
        int[] arr = {1, 9, 3, 4, 2, 20};
        System.out.println(longConSeqCount(arr));
    }
} 