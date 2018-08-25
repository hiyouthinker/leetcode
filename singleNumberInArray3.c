/*
 * Find the number that appears only once in array
 * 	Copyright: github.com/hiyouthinker/leetcode
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define LEETCODE_PLATFORM

static int array[512], length;

#ifdef LEETCODE_PLATFORM
int singleNumber(int* nums, int numsSize) {
    int i, j, found = 0, count = 0;

    /* 0 is special number */
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            count++;
        if (count == 2)
            break;
    }
    if (count == 1)
        return 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            goto found;
        found = 0;
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                nums[j] = 0;
                found = 1;
                break;
            }
        }
        if (!found) {
            return nums[i];
        }
found:
        ;
    }
    return -1;
}
#endif

static int leetcode_func_call(void)
{
	printf("single number: %d\n", singleNumber(array, length));
}

/*
 * valid input:
 *		1 5 5 -1
 *		1 5 2 7 3 1 3 2 5 -1
 *		9 2 7 4 3 2 9 8 4 3 8 -1
 *				--youThinker/2018
 */
static void readFromStdin(void)
{
	int value, i = 0;
	for (; i < sizeof(array)/sizeof(array[0]); i++) {
		if (scanf("%d", &value) < 0 || value < 0)
			break;
		array[i] = value;
	}
	length = i;
}

int main(int argc, char *argv[])
{
	printf("Please input and finish with -1:\n");
	readFromStdin();

	leetcode_func_call();
	return 0;
}
