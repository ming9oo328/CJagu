#include <stdio.h>

void SelSort(int arr[], int len) {
	int i, j, tmp, minIdx;

	for (i = 0; i < len - 1; i++) {
		minIdx = i;
		for (j = i+1; j < len ; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		tmp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = tmp;
	}
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}
int main() {
	int arr[4] = { 3,2,4,1 };
	SelSort(arr, sizeof(arr) / sizeof(int));

	return 0;
}