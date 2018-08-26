/*
 * has cycle in singly-linked list?
 * 	Copyright: github.com/hiyouthinker/leetcode
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define LEETCODE_PLATFORM

struct ListNode {
	int val;
	struct ListNode *next;
};

static struct ListNode *head;

enum {
	false = 0,
	true = 1
};
typedef int bool;

#ifdef LEETCODE_PLATFORM
struct NListNode {
    struct NListNode *pointer;
    struct NListNode *next;
};

static int free_nodes(struct NListNode *head)
{
    struct NListNode *tmp;

    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct NListNode *node, *h;
    int first = 1;

    h = NULL;
    if (!head)
        return false;
    while (head) {
        struct NListNode *p = h, *tmp, *prev;

        node = (struct NListNode *)malloc(sizeof(struct NListNode));
        if (!node) {
            free_nodes(h);
            return false;
        }
        node->pointer = (struct NListNode *)head;
        node->next = NULL;

        if (first == 1) {
            h = node;
            first = 0;
        } else {
            while (p) {
                if ((struct NListNode *)head == p->pointer) {
                    free(node);
                    free_nodes(h);
                    return true;
                }
                prev = p;
                p = p->next;
            }
            prev->next = node;
        }
        head = head->next;
    }
    free_nodes(h);
    return false;
}
#endif

static int leetcode_func_call(void)
{
	printf("hasCycle: %d\n", hasCycle(head));
}

static int InsertNodeToTail(struct ListNode *node)
{
	struct ListNode *tmp = head, *dup = NULL;
	if (!head)
		head = node;
	else {
		while (tmp->next) {
			if (!dup) {
				
			}
			if (node->val == tmp->val)
				dup = tmp;
			tmp = tmp->next;
		}
		if (node->val == tmp->val)
			dup = tmp;
		tmp->next = node;
	}
	if (dup) {
		node->next = tmp;
		return -1;
	}
	return 0;
}

static void readFromStdinAndCreateList(void)
{
	int value;
	while (1) {
		struct ListNode *node;
		if (scanf("%d", &value) < 0 || value < 0)
			break;
		node = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (!node)
			exit(1);
		node->val = value;
		if (InsertNodeToTail(node) < 0)
			break;
	}
}

/*
 * valid input:
 *		-1
 *		1 5 -1
 *		1 5 2 7 3 5 -1
 *		9 2 7 4 3 2 8 -1
 *				--youThinker/2018
 */
static void readFromStdin(void)
{
	printf("Please input and finish with -1:\n");
	readFromStdinAndCreateList();
}

static void cleanMemory(void)
{
	/* FIXME: cleaup memory for LIST --youThinker/2018 */
}

int main(int argc, char *argv[])
{
	readFromStdin();
	leetcode_func_call();
	cleanMemory();
	return 0;
}
