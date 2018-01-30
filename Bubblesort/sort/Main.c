#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {

		srand(time(NULL));
		int i, j, length, temp, size, choice;
		unsigned long unsorted[100000], sorted[100000], max;

		// Declaring size of array
		printf("Enter size of array\n\n");
		scanf("%d", &length);

		// Choice between own array or generated array
		printf("\nDo you want to input own array(1) or generate array(2)?\n\n");
		scanf("%d", &choice);
		if (choice == true) {
			// Input of an array
			printf("Enter an array");
			for (i = 0; i < length; i++) {
				printf("\n");
				scanf("%d", &unsorted[i]);
			}
		}
		else {
			// Generating a random array
			size = sizeof(unsorted) / sizeof(unsorted[0]);
			max = size * 2;

			for (i = 0; i < size; i++) {
				unsorted[i] = rand() % max + 1;
			}
		}

		// Copying array
		for (i = 0; i < length; i++) {
			sorted[i] = unsorted[i];
		}

		// Measuring time to sort
		clock_t begin = clock();

		// Sorting array
		for (i = 0; i < length; i++) {
			for (j = i + 1; j < length; j++) {
				if (sorted[i] > sorted[j]) {
					temp = sorted[i];
					sorted[i] = sorted[j];
					sorted[j] = temp;
				}
			}
		}

		clock_t end = clock();
		double time_elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

		printf("\nDo you want to print sorted array?(Y / N)\n\n");
		scanf("%s", &choice);

		// Printing sorted array
		if (choice == 89 || 121) {
			printf("\nSorted array is: { ");
			for (i = 0; i < length; i++) {
				printf("%d", sorted[i]);
				while (i < length - 1) {
					printf(", ");
					break;
				}
			}
			printf(" }\n");
		}

		// Time elapsed during sorting
		printf("\nTime elapsed: %fs\n\n", time_elapsed);
	
	return 0;
}