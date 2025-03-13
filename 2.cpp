#include <stdio.h>

int binarySearch(int a[], int n, int x) {
	int left = 0, right = n - 1;
	int i, j;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (a[mid] == x) {
			return mid;
		} else if (a[mid] < x) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	i = right;
	j = left;
	return (i, j);
}

int main() {
	int a[] = {1, 3, 5, 7, 9, 11, 13, 15};
	int n = sizeof(a) / sizeof(a[0]);
	int x = 7;
	int i, j = binarySearch(a, n, x);
	printf("i: %d, j: %d\n", i, j);
	return 0;
} 
