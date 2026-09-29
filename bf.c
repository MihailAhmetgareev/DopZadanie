#include <stdio.h>

int Good(int a[10][10]) {
    int flag = 0;
    int cur = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] == 1) {
                flag = 1;
                cur += 1;
                break;
            }
        }
    }
    if (cur == 100) {
        flag = 0;
    }
    return flag;
}

int good(int a[10][10], int b[10][10]) {
    int flag = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] != b[i][j]) {
                flag = 0;
            }
        }
    }
    return flag;
}

void proverka(int a[10][10], int b[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j]) {
                if (i + 1 < 10 && i + 2 < 10 && a[i + 1][j] && a[i + 2][j]) {
                    a[i][j] = 0;
                    a[i + 1][j] = 0;
                    a[i + 2][j] = 0;
                }
                if (j + 1 < 10 && j + 2 < 10 && a[i][j + 1] && a[i][j + 2]) {
                    a[i][j] = 0;
                    a[i][j + 1] = 0;
                    a[i][j + 2] = 0;
                }
            }
            if (b[i][j]) {
                if (i + 1 < 10 && i + 2 < 10 && b[i + 1][j] && b[i + 2][j]) {
                    b[i][j] = 0;
                    b[i + 1][j] = 0;
                    b[i + 2][j] = 0;
                }
                if (j + 1 < 10 && j + 2 < 10 && b[i][j + 1] && b[i][j + 2]) {
                    b[i][j] = 0;
                    b[i][j + 1] = 0;
                    b[i][j + 2] = 0;
                }
            }
        }
    }
}

int x[8] = {0, 0, -1, 1, -1, 1, 1, -1};
int y[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

int flag(int b[10][10], int i, int j) {
    int cur = 0;
    for (int k = 0; k < 8; k++) {
        if (i + x[k] >= 0 && i + x[k] < 10 && j + y[k] >= 0 && j + y[k] < 10 && b[i + x[k]][j + y[k]]) {
            cur += 1;
        }
    }
    return cur;
}

int main() {
    int n = 10;
    char s[10][11];
    for (int i = 0; i < 10; i++) {
        scanf("%s", s[i]);
    }
    int a[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = s[i][j] - '0';
        }
    }
    int c = 0;
    while (Good(a) && c != 2) {
        int b[10][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int t = flag(a, i, j);
                if (a[i][j]) {
                    if (t >= 2 && t <= 3) {
                        b[i][j] = 1;
                    } else {
                        b[i][j] = 0;
                    }
                } else {
                    if (t == 3) {
                        b[i][j] = 1;
                    } else {
                        b[i][j] = 0;
                    }
                }
            }
        }
        printf("\n");
        int vec[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                vec[i][j] = b[i][j];
            }
        }
        if (good(a, b)) {
            c = 2;
            break;
        }
        proverka(a, b);
        int ready = good(a, b);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = vec[i][j];
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
        if (ready) {
            c = 2;
        }
    }
}
