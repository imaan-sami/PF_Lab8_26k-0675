#include <stdio.h>

int findMax(int *p, int n) {
    int max = *p;
    for (int i = 1; i < n; i++) {
        if (*(p + i) > max) {
            max = *(p + i);
        }
    }
    return max;
}

int findMin(int *p, int n) {
    int min = *p;
    for (int i = 1; i < n; i++) {
        if (*(p + i) < min) {
            min = *(p + i);
        }
    }
    return min;
}

double findAverage(int *p, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + *(p + i);
    }
    return (double)sum / n;
}

int countAbove(int *p, int n, double avg) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(p + i) > avg) {
            count++;
        }
    }
    return count;
}

void reverseArray(int *p, int n) {
    int *start = p;
    int *end = p + n - 1;
    int temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(p + i) == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int marks[10];
    int n = 10;

    for (int i = 0; i < n; i++) {
        printf("Enter marks for student %d (0-100): ", i + 1);
        scanf("%d", &marks[i]);

        while (marks[i] < 0 || marks[i] > 100) {
            printf("Re-Enter marks for student %d (0-100): ", i + 1);
            scanf("%d", &marks[i]);
        }
    }

    int highest = findMax(marks, n);
    int lowest = findMin(marks, n);
    double avg = findAverage(marks, n);
    int above_avg = countAbove(marks, n, avg);

    int pass_count = 0;
    for (int i = 0; i < n; i++) {
        if (marks[i] >= 40) {
            pass_count++;
        }
    }

    printf("\n=== Class Result ===\n");
    printf("Highest Mark:       %d\n", highest);
    printf("Lowest Mark:        %d\n", lowest);
    printf("Class Average:      %.2f\n", avg);
    printf("Above Average:      %d\n", above_avg);
    printf("Pass Count (>=40):  %d\n", pass_count);

    int key;
    printf("\nEnter a mark to search: ");
    scanf("%d", &key);

    int index = searchMark(marks, n, key);
    if (index != -1) {
        printf("Mark found at position: %d (index %d)\n", index + 1, index);
    }
    else {
        printf("Mark not found in the class.\n");
    }

    printf("\n=== Marks Before Reverse ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    reverseArray(marks, n);

    printf("\n\n=== Marks After Reverse ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");

    return 0;
}
