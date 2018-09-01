#include <stdio.h>
#include <stdlib.h>

void swap(int* nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

int partition(int* nums, int i, int j, int k) {
  if(j - i <= 1) {
    return nums[i];
  }
  int l = i + 1, r = j;
  int pivot = nums[i];
  while(l < r) {
    if(nums[l] < pivot) {
      swap(nums, l, r - 1);
      r--;
    }
    else l++;
  }
  swap(nums, i, l - 1);
  if(l - 1 - i == k) return nums[l - 1];
  else if(l - 1 - i > k) return partition(nums, i, l - 1, k);
  return partition(nums, l, j, k - l + i);
}

int findKthLargest(int* nums, int numsSize, int k) {
  int ans = partition(nums, 0, numsSize, k - 1);
  return ans;
}


int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: ./test k n1 n2...\n");
        exit(-1);
    }

    int i, count = argc - 2;
    int *nums = malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        nums[i] = atoi(argv[i + 2]);
    }
    printf("%d\n", findKthLargest(nums, count, atoi(argv[1])));
    return 0;
}
