/*
 * Calculated max depth of binary tree
 * 	Copyright: github.com/hiyouthinker/leetcode
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define LEETCODE_PLATFORM
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *root;

#ifdef LEETCODE_PLATFORM 
static int max_level;
static int maxDepthOfBiTree(struct TreeNode* root, int level)
{
	if (!root) {
		if (level > max_level)
			max_level = level;
		return 0;
	}
	maxDepthOfBiTree(root->left, level + 1);
	maxDepthOfBiTree(root->right, level + 1);
	return max_level;
}

int maxDepth(struct TreeNode* root) {
    max_level = 0; /* MUST be initialized, this is bug for leetcode? */
    return maxDepthOfBiTree(root, 0);
}
#endif

/* create a binary tree by pre-order traverse */
static void CreateBinaryTree(struct TreeNode **node)
{
	int value;

	scanf("%d", &value);

	if (value == 0)
		*node = NULL;
	else {
		*node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		if (!*node) {
			printf("malloc failed!\n");
			exit(0);
		}
		(*node)->val = value;
		CreateBinaryTree(&(*node)->left);
		CreateBinaryTree(&(*node)->right);
	}
}

static int leetcode_func_call(void)
{
	int depth;
	depth = maxDepth(root);
	printf("max depth: %d\n", depth);
}
/*
 * valid input:
 *		1 0 0
 *		1 2 4 0 0 0 3 0 0
 *		1 2 4 0 0 0 0 0
 *		1 2 0 0 3 4 0 0 0
 *				--youThinker/2018
 */
int main(int argc, char *argv[])
{
	printf("Please input by pre-order traverse:\n");
	CreateBinaryTree(&root);

	leetcode_func_call();
	return 0;
}
