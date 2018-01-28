#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {

		srand(time(NULL));
		int i, j, length, temp, size, choice;
		unsigned long unsorted[100000], sorted[100000], max;

		printf("Enter size of array\n\n");		// Declaring size of array
		scanf("%d", &length);

		printf("\nDo you want to input own array(1) or generate array(2)?\n\n"); // Choice between own array or generated array
		scanf("%d", &choice);
		if (choice == true) {
			printf("Enter an array");				// Input of an array
			for (i = 0; i < length; i++) {
				printf("\n");
				scanf("%d", &unsorted[i]);
			}
		}
		else {
			size = sizeof(unsorted) / sizeof(unsorted[0]);	// Generating a random array
			max = size * 2;

			for (i = 0; i < size; i++) {
				unsorted[i] = rand() % max + 1;
			}
		}

		for (i = 0; i < length; i++) {			// Copying array
			sorted[i] = unsorted[i];
		}

		clock_t begin = clock();				// Measuring time to sort

		for (i = 0; i < length; i++) {			// Sorting array
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

		if (choice == 89) {
			printf("\nSorted array is: { ");			// Printing sorted array
			for (i = 0; i < length; i++) {
				printf("%d", sorted[i]);
				while (i < length - 1) {
					printf(", ");
					break;
				}
			}
			printf(" }\n");
		}

		printf("\nTime elapsed: %fs\n\n", time_elapsed);	// Time elapsed during sorting
	
	return 0;
}