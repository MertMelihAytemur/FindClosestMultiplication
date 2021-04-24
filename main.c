#include <stdio.h>
#include <math.h>
#include <limits.h>

void setMultiplicationIndexesLowerDistanceToTarget(const int array[], int target, int array_size, int *first_index, int *second_index);

#define SIZE_OF_ARRAY 7

int main() {
    int numbers_to_check[SIZE_OF_ARRAY] = {-1,-2,-3,-4,-5,-6,-7}; 
    int target = -3;
    int first_index, second_index;

    setMultiplicationIndexesLowerDistanceToTarget(numbers_to_check, target, SIZE_OF_ARRAY, &first_index, &second_index);
    printf("[%d,%d]", first_index, second_index);
}

void setMultiplicationIndexesLowerDistanceToTarget(
        const int array[],
        int target,
        int array_size,
        int *first_index,
        int *second_index) {
    int multiplication;
    int diff = INT_MAX;
    for (int i = 0; i < array_size; i++) {
        for (int j = i + 1; j < array_size; j++) {
            multiplication = array[i] * array[j];
            if (abs(target - multiplication) < diff) {
                diff = abs(target - multiplication);
                *first_index = i;
                *second_index = j;
            }
        }
    }
}
