// C program to Check if a given array contains duplicate
// elements within k distance from each other

#include <stdbool.h>
#include <stdio.h>

bool containsNearbyDuplicate(int nums[], int numsSize, int k) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize && j <= i + k; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

// Driver method to test above method
int main()
{
	int arr[] = { 10, 5, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	if (containsNearbyDuplicate(arr, n, 3))
		printf("Yes");
	else
		printf("No");
}

// This code is contributed by Aditya Kumar (adityakumar129)

