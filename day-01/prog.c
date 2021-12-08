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

	int val;
	int temp;
	size_t count = 0;

	int ret = fscanf(fp, "%d", &val);
	while (ret != EOF) {
		temp = val;
		ret = fscanf(fp, "%d", &val);

		if (val > temp) count++;
	}

	fclose(fp);

	fp = fopen("ans.txt", "w");
	if (!fp) {
		perror("ans.txt");
		return -3;
	}

	fprintf(fp, "%zu\n", count);
	fclose(fp);

	return 0;
}
