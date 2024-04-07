package org.example;

class Solution {
    public boolean canJump(int[] nums) {
        int reachable = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > reachable) return false;
            reachable = Math.max(reachable, i + nums[i]);
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution r = new Solution();
        int[] tt = {1, 0, 5};
        r.canJump(tt);
        System.out.println("Hello world!");
        System.out.println(r.canJump(tt));
    }
}