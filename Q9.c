#include <stdio.h>
#include <string.h>

void readMarks(int *m1, int *m2, int *m3) {
    printf("Enter mark 1 (0-100): ");
    scanf("%d", m1);
    while (*m1 < 0 || *m1 > 100) {
        printf("Re-Enter mark 1 (0-100): ");
        scanf("%d", m1);
    }

    printf("Enter mark 2 (0-100): ");
    scanf("%d", m2);
    while (*m2 < 0 || *m2 > 100) {
        printf("Re-Enter mark 2 (0-100): ");
        scanf("%d", m2);
    }

    printf("Enter mark 3 (0-100): ");
    scanf("%d", m3);
    while (*m3 < 0 || *m3 > 100) {
        printf("Re-Enter mark 3 (0-100): ");
        scanf("%d", m3);
    }
}

void swapMarks(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addGraceMarks(int *mark, int grace) {
    if (*mark >= 35 && *mark <= 39) {
        if (grace > 5) {
            grace = 5;
        }
        *mark = *mark + grace;
        if (*mark > 40) {
            *mark = 40;
        }
    }
}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest) {
    *total = m1 + m2 + m3;
    *average = *total / 3.0;

    if (m1 < m2) {
        swapMarks(&m1, &m2);
    }
    if (m1 < m3) {
        swapMarks(&m1, &m3);
    }
    if (m2 < m3) {
        swapMarks(&m2, &m3);
    }

    *highest = m1;
    *lowest = m3;
}

void findGrade(double avg, char *grade, char remarks[]) {
    if (avg >= 80) {
        *grade = 'A';
        strcpy(remarks, "Excellent");
    }
    else if (avg >= 60) {
        *grade = 'B';
        strcpy(remarks, "Good");
    }
    else {
        *grade = 'C';
        strcpy(remarks, "Needs Improvement");
    }
}

void incrementByValue(int x) {
    x = x + 10;
}

void incrementByReference(int *x) {
    *x = *x + 10;
}

int main() {
    int total[5];
    double average[5];
    char grade[5];
    char remarks[5][30];

    for (int i = 0; i < 5; i++) {
        printf("\n=== Student %d ===\n", i + 1);
        int m1, m2, m3, highest, lowest;

        readMarks(&m1, &m2, &m3);

        addGraceMarks(&m1, 5);
        addGraceMarks(&m2, 5);
        addGraceMarks(&m3, 5);

        calculateStats(m1, m2, m3, &total[i], &average[i], &highest, &lowest);
        findGrade(average[i], &grade[i], remarks[i]);
    }

    printf("\n=== Semester Result Table ===\n");
    printf("Student   Total     Average   Grade   Remarks\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%-9d %-9d %-9.2f %-7c %s\n", i + 1, total[i], average[i], grade[i], remarks[i]);
    }

    int num = 50;
    printf("\n=== Comparison Demo ===\n");
    printf("Original value: %d\n", num);

    incrementByValue(num);
    printf("After incrementByValue: %d\n", num);

    incrementByReference(&num);
    printf("After incrementByReference: %d\n", num);

    return 0;
}
