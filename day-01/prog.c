#include <stdio.h>

int main(int argc, char* argv[argc + 1]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <FILE>\n", argv[0]);
		return -1;
	}

	FILE* fp = fopen(argv[1], "r");
	if (!fp) {
		perror(argv[1]);
		return -2;
	}

	int arr[2000];
	int psum = 0;
	int sum;

	size_t countA = 0;
	size_t countB = -1;

	int i = 2;
	int ret = fscanf(fp, "%d", &arr[0]);
	if (ret != EOF) ret = fscanf(fp, "%d", &arr[1]);

	if (arr[1] > arr[0]) countA++;

	ret = fscanf(fp, "%d", &arr[2]);
	while (ret != EOF) {
		if (arr[i] > arr[i - 1]) countA++;

		sum = arr[i] + arr[i - 1] + arr[i - 2];
		if (sum > psum) countB++;
		psum = sum;

		i++;
		ret = fscanf(fp, "%d", &arr[i]);
	}

	fclose(fp);

	fp = fopen("ans.txt", "w");
	if (!fp) {
		perror("ans.txt");
		return -3;
	}

	fprintf(fp, "Answer for 1st part:\n%zu\n\nAnswer for 2nd part:\n%zu\n", countA, countB);
	fclose(fp);

	return 0;
}
