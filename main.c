#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Provera da li je broj prost.
int is_prime(int n) {
    int i;
    if (n == 0 || n == 1) {
        return 1;
    }

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 1;
        }
    }

    return 0;
}

// 1. Napisati funkciju koja prima jedan parametar a zatim izracunava:
// 1 - (1/2^2 + 1/3^2 - 1/4^2 ... +- 1/n^2)
double zadatak_1(int n) {
    double s = 0;
    int i, x = 1;

    for (i = 0; i < n; i++) {
        if (x) {
            s += 1/pow(2+i, 2);
        } else {
            s -= 1/pow(2+i, 2);
        }

        x *= -1;
    }

    return 1 - s;
}

// 2. Napisati funkcija koja iscrtava semu:
/*
      1
    2 1
  3 2 1
4 3 2 1
*/
void zadatak_2(int n) {
    int i, j, blank, full;

    for (i = 0; i < n; i++) {
        blank = n - i - 1;
        full = n - blank;

        while(blank-- > 0) {
            printf(" ");
        }

        for (j = 0; j < full; j++) {
            printf("%d", (i+1) - j);
        }

        printf("\n");
    }
}

// 3. Napisati funckiju koja vraca broj u opsegu 10-20
int zadatak_3() {
    return (rand() % 11) + 10;
}

// 4. Napisati funkciju u koj se:
// a. definise matrica 10x10
// b. matricu je potrebno popuniti rezultatima zadatka 3
// c. ispis elemenata
// d. ispis elemenata ispod glavne dijagonale
// e. ispis elemenata koji su prosti brojevi
void zadatak_4() {
    int m[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            m[i][j] = zadatak_3();
        }
    }

    printf("Ispis matrice:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\nElemeni ispod glavne dijagonale:\n");
    for (i = 1; i < 10; i++) {
        for (j = 0; j < i; j++) {
            printf("%d ", m[i][j]);
        }
    }

    printf("\nSamo prosti elementi: \n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (is_prime(m[i][j])) {
                printf("%d ", m[i][j]);
            }
        }
    }

    printf("\n");
}

// 5. Napisati funkciju koja sortira niz koristeci selection sort
void zadatak_5(int n[5]) {
    int i, j, m, t;

    printf("Ne-sortiran niz: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", n[i]);
    }

    printf("\n");

    for (i = 0; i < 4; i++) {
        m = i;
        for (j = i + 1; j < 5; j++) {
            if (n[j] < n[i]) {
                m = j;
            }
        }

        if (m != i) {
            t = n[m];
            n[m] = n[i];
            n[i] = t;
        }
    }

    printf("Sortiran niz: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", n[i]);
    }

    printf("\n");
}

// 6. Napisati funkciju koja prima ceo broj i ispisuje cifre jednu ispod druge
void zadatak_6(int n) {
    int i = 0, r, m[100];
    while (n != 0) {
        r = n % 10;
        m[i++] = r;
        n /= 10;
    }

    i--;

    for (; i >= 0; i--) {
        printf("%d\n", m[i]);
    }

    printf("\n");
}

// Main menu za odabir zadatka
int menu() {
    int op;
    do {
        printf("Unesite broj zadatka (1-7) ili 8 za izlaz: ");
        scanf("%d", &op);
    }
    while(op < 1 || op > 8);

    return op;
}

int main(int argc, char **argv) {
    int n, m[5];

    srand(time(NULL));

    while (1) {
        switch (menu()) {
            case 1:
                printf("Unesite broj: ");
                scanf("%d", &n);
                printf("Rezultat: %lf\n", zadatak_1(n));
                break;
            case 2:
                printf("Unesite broj: ");
                scanf("%d", &n);
                zadatak_2(n);
                break;
            case 3:
                printf("Rezultat: %d\n", zadatak_3());
                break;
            case 4:
                zadatak_4();
                break;
            case 5:
                for (n = 0; n < 5; n++) {
                    printf("Unesite broj: ");
                    scanf("%d", &m[n]);
                }
                zadatak_5(m);
                break;
            case 6:
                printf("Unesite broj: ");
                scanf("%d", &n);
                zadatak_6(n);
                break;
            case 8:
                return 0;
        }
    }

    return 0;
}