public class LeetCode918 {
    public static void main(String[] args) {
        System.out.println(new LeetCode918().maxSubarraySumCircular(new int[]{})); // 0
        System.out.println(new LeetCode918().maxSubarraySumCircular(new int[]{-5,-2,-3})); // -2
        System.out.println(new LeetCode918().maxSubarraySumCircular(
                new int[]{10, 20, -40, 50, -100, 10, 20, 30, 40})); // 140
        System.out.println(new LeetCode918().maxSubarraySumCircular(
                new int[]{10, 20, -40, 50, -100, 10, 20, 30, 40, -10})); // 130
        System.out.println(new LeetCode918().maxSubarraySumCircular(
                new int[]{-1000, 20, -40, 50, -100, 10, 20, 30, 40, -10})); // 100
        System.out.println(new LeetCode918().maxSubarraySumCircular(
                new int[]{5, -3, 5} // 10
        ));

    }

    public int maxSubarraySumCircular(int[] arr) {
        //if(allNegative(arr)) return max(arr);
        if (arr == null || arr.length == 0)
            return 0;
        int n = arr.length;
        Block[] blocks = new Block[n];
        for (int i = 0; i < n; i++)
            blocks[i] = new Block(i, i, arr[i]);
        int tempMax = arr[0];
        for (int i = 1; i < n; i++) {
            if (blocks[i - 1].sum + arr[i] > arr[i]) {
                // extending the block
                blocks[i].sum = blocks[i - 1].sum + arr[i];
                blocks[i].start = blocks[i - 1].start;
            }
            tempMax = Math.max(tempMax, blocks[i].sum);
        }
        for (int i = 0; i < n; i++) {
            if (blocks[i].start == 0 && blocks[i].end < blocks[n - 1].start) {
                tempMax = Math.max(tempMax, blocks[i].sum + blocks[n - 1].sum);
            }
        }
        int[] prefix = calPrefixSumMax(arr);
        int[] suffix = calSuffixSumMax(arr);
//        printArray(prefix);
//        printArray(suffix);
        for (int i = 0; i < n - 1; i++) {
            tempMax = Math.max(tempMax, prefix[i] + suffix[i + 1]);
        }
        return tempMax;
    }
    private void printArray(int[] suffix) {
        for(int i=0;i<suffix.length;i++)
            System.out.print(suffix[i] + " ");
        System.out.println();
    }

    private int[] calPrefixSumMax(int[] arr) {
        int n = arr.length;
        int[] prefix = new int[n];
        int[] max = new int[n];
        prefix[0] = arr[0];
        max[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
            max[i] = Math.max(max[i - 1], prefix[i]);
        }
        return max;
    }

    private int[] calSuffixSumMax(int[] arr) {
        int n = arr.length;
        int[] suffix = new int[n];
        int[] max = new int[n];
        suffix[n - 1] = arr[n - 1];
        max[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + arr[i];
            max[i] = Math.max(max[i + 1], suffix[i]);
        }
        return max;
    }

    private static class Block {
        int start, end;
        int sum; // as sum of integers can go beyond int-max

        public Block(int start, int end, int sum) {
            this.start = start;
            this.end = end;
            this.sum = sum;
        }
    }

}
