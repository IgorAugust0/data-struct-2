// C# Solution
public class Solution {
    public bool IsCompleteTree(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        int total = CountNodes(root);
        int startIndex = 1; 
        
        return IsCompleteTree(root, total, startIndex);
    }
    
    private static bool IsCompleteTree(TreeNode root, int total, int expectedIndex) {
        if (root == null) {
            return true;
        }
        
        if (expectedIndex > total) {
            return false;
        }
        
        return IsCompleteTree(root.left, total, expectedIndex * 2) && IsCompleteTree(root.right, total, expectedIndex * 2 + 1);
    }
    
    private static int CountNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        return CountNodes(root.left) + 1 + CountNodes(root.right);
    }
}