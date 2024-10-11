public class Solution {
    public int MaxWidthRamp(int[] nums) {
        int n = nums.Length;
        Stack<int> stack = new Stack<int>();
        
        // Push indices of the elements into the stack
        for (int i = 0; i < n; i++) {
            // Only push the index if it's the smallest so far
            if (stack.Count == 0 || nums[stack.Peek()] > nums[i]) {
                stack.Push(i);
            }
        }

        int maxWidth = 0;

        // Iterate from the end to the start
        for (int j = n - 1; j >= 0; j--) {
            // Check if we can find a valid ramp
            while (stack.Count > 0 && nums[stack.Peek()] <= nums[j]) {
                maxWidth = Math.Max(maxWidth, j - stack.Pop());
            }
        }

        return maxWidth;
    }
}