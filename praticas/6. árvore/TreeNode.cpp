#include <cstdlib>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to determine what kind of binary tree the given tree is.
// It returns one of the following values:
// 0: Not a binary tree
// 1: Full binary tree
// 2: Complete binary tree
// 3: Perfect binary tree
// 4: Balanced binary tree
// 5: Degenerate (or pathological) tree
int determineTreeType(TreeNode* root) {
    // Check if the tree is a binary tree
    if (!root) return 0;

    // Degenerate tree
    int min_depth = INT_MAX;
    int max_depth = INT_MIN;

    // Perform a pre-order traversal to compute the min and max depths
    std::function<void(TreeNode*, int)> preorder = [&](TreeNode* node, int depth) {
        if (!node) return;
        min_depth = std::min(min_depth, depth);
        max_depth = std::max(max_depth, depth);
        preorder(node->left, depth + 1);
        preorder(node->right, depth + 1);
    };
    preorder(root, 1);

    // Degenerate tree
    if (max_depth - min_depth > 1) return 5;

    // Full binary tree
    if (!root->left && !root->right) return 1;
    if (root->left && root->right) {
        return determineTreeType(root->left) == 1 && determineTreeType(root->right) == 1 ? 1 : 4;
    }

    // Complete binary tree
    int nodes = 0;
    std::function<void(TreeNode*)> count = [&](TreeNode* node) {
        if (!node) return;
        ++nodes;
        count(node->left);
        count(node->right);
    };
    count(root);
    int h = 0;
    for (int i = 1; i < nodes; i *= 2, ++h)
        ;
    return h == max_depth ? 2 : 3;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Determine what kind of binary tree it is
    int treeType = determineTreeType(root);
    std::string treeTypeStr;
    switch (treeType) {
        case 0:
            treeTypeStr = "Not a binary tree";
            break;
        case 1:
            treeTypeStr = "Full binary tree";
            break;
        case 2:
            treeTypeStr = "Complete binary tree";
            break;
        case 3:
			treeTypeStr = "Perfect binary tree";
			break;
		case 4:
			treeTypeStr = "Balanced binary tree";
			break;
		case 5:
			treeTypeStr = "Degenerate (or pathological) tree";
			break;
	}
	std::cout << treeTypeStr << std::endl;
	return 0;
}