#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846
#define PLANET_COUNT 8

void printMenu();
void cleanInputBuffer();
void getScientistName(char *name);
void serbestDusme(double *g, char (*pNames)[15]);
void yukariAtis(double *g, char (*pNames)[15]);
void agirlikDeneyi(double *g, char (*pNames)[15]);
void potansiyelEnerji(double *g, char (*pNames)[15]);
void hidrostatikBasinc(double *g, char (*pNames)[15]);
void arsimetKaldirma(double *g, char (*pNames)[15]);
void basitSarkac(double *g, char (*pNames)[15]);
void ipGerilmesi(double *g, char (*pNames)[15]);
void asansorDeneyi(double *g, char (*pNames)[15]);

int main() {
    double gravity[PLANET_COUNT] = {3.7, 8.87, 9.807, 3.721, 24.79, 10.44, 8.87, 11.15};

    char planetNames[PLANET_COUNT][15] = {
        "Merkur", "Venus", "Dunya", "Mars",
        "jupiter", "Saturn", "Uranus", "Neptun"};

    char scientistName[50];
    int choice = 0;

    getScientistName(scientistName);

    do {
        printf("\n------------------------------------------------\n");
        printf("Bilim Insani: %s\n", scientistName);
        printMenu();
        printf("Seciminiz (-1 Cikis): ");

        (scanf("%d", &choice) != 1) ? (cleanInputBuffer(), choice = 0) : 0;

        (choice == -1) ? printf("Program sonlandiriliyor...\n") : 0;

        if (choice != -1) {
            switch (choice) {
                case 1: serbestDusme(gravity, planetNames); break;
                case 2: yukariAtis(gravity, planetNames); break;
                case 3: agirlikDeneyi(gravity, planetNames); break;
                case 4: potansiyelEnerji(gravity, planetNames); break;
                case 5: hidrostatikBasinc(gravity, planetNames); break;
                case 6: arsimetKaldirma(gravity, planetNames); break;
                case 7: basitSarkac(gravity, planetNames); break;
                case 8: ipGerilmesi(gravity, planetNames); break;
                case 9: asansorDeneyi(gravity, planetNames); break;
                case 0: printf("Hatali secim! Lutfen tekrar deneyin.\n"); break;
                default: printf("Hatali secim! Lutfen tekrar deneyin.\n");
            }
        }

    } while (choice != -1);

    return 0;
}

void cleanInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void getScientistName(char *name) {
    printf("Lutfen bilim insani adini giriniz: ");

    (fgets(name, 50, stdin) != NULL) ? 0 : 0;

    size_t len = strlen(name);

    name[len-1] = (len > 0 && name[len-1] == '\n') ? '\0' : name[len-1];
}

void printMenu() {
    printf("\n--- UZAY SIMULASYONU DENEY LISTESI ---\n");
    printf("1. Serbest Dusme Deneyi\n");
    printf("2. Yukari Atis Deneyi\n");
    printf("3. Agirlik Deneyi\n");
    printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5. Hidrostatik Basinc Deneyi\n");
    printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7. Basit Sarkac Periyodu Deneyi\n");
    printf("8. Sabit Ip Gerilmesi Deneyi\n");
    printf("9. Asansor Deneyi\n");
}

void serbestDusme(double *g, char (*pNames)[15]) {
    double t;
    printf("\n--- Serbest Dusme Deneyi ---\n");
    printf("Sureyi giriniz (t [saniye]): ");
    scanf("%lf", &t);

    t = (t < 0) ? -t : t;

    printf("\nSonuclar (t = %.2f s):\n", t);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double h = 0.5 * (*(g + i)) * t * t;
        printf("%-10s -> Yukseklik (h): %.2f m\n", *(pNames + i), h);
    }
}

void yukariAtis(double *g, char (*pNames)[15]) {
    double v0;
    printf("\n--- Yukari Atis Deneyi ---\n");
    printf("Firlatma hizini giriniz (v0 [m/s]): ");
    scanf("%lf", &v0);

    v0 = (v0 < 0) ? -v0 : v0;

    printf("\nSonuclar (v0 = %.2f m/s):\n", v0);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double current_g = *(g + i);
        double h_max = (v0 * v0) / (2 * current_g);
        printf("%-10s -> Maks. Yukseklik: %.2f m\n", *(pNames + i), h_max);
    }
}

void agirlikDeneyi(double *g, char (*pNames)[15]) {
    double m;
    printf("\n--- Agirlik Deneyi ---\n");
    printf("Kutleyi giriniz (m [kg]): ");
    scanf("%lf", &m);

    m = (m < 0) ? -m : m;

    printf("\nSonuclar (m = %.2f kg):\n", m);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double G = m * (*(g + i));
        printf("%-10s -> Agirlik: %.2f N\n", *(pNames + i), G);
    }
}

void potansiyelEnerji(double *g, char (*pNames)[15]) {
    double m, h;
    printf("\n--- Kutlecekimsel Potansiyel Enerji Deneyi ---\n");
    printf("Kutleyi giriniz (m [kg]): ");
    scanf("%lf", &m);
    printf("Yuksekligi giriniz (h [m]): ");
    scanf("%lf", &h);

    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;

    printf("\nSonuclar (m = %.2f kg, h = %.2f m):\n", m, h);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double Ep = m * (*(g + i)) * h;
        printf("%-10s -> Potansiyel Enerji: %.2f J\n", *(pNames + i), Ep);
    }
}

void hidrostatikBasinc(double *g, char (*pNames)[15]) {
    double rho, h;
    printf("\n--- Hidrostatik Basinc Deneyi ---\n");
    printf("Sivi yogunlugunu giriniz (rho [kg/m^3]): ");
    scanf("%lf", &rho);
    printf("Derinligi giriniz (h [m]): ");
    scanf("%lf", &h);

    rho = (rho < 0) ? -rho : rho;
    h = (h < 0) ? -h : h;

    printf("\nSonuclar (rho = %.2f, h = %.2f):\n", rho, h);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double P = rho * (*(g + i)) * h;
        printf("%-10s -> Basinc: %.2f Pa\n", *(pNames + i), P);
    }
}

void arsimetKaldirma(double *g, char (*pNames)[15]) {
    double rho, V;
    printf("\n--- Arsimet Kaldirma Kuvveti Deneyi ---\n");
    printf("Sivi yogunlugunu giriniz (rho [kg/m^3]): ");
    scanf("%lf", &rho);
    printf("Batan hacmi giriniz (V [m^3]): ");
    scanf("%lf", &V);

    rho = (rho < 0) ? -rho : rho;
    V = (V < 0) ? -V : V;

    printf("\nSonuclar (rho = %.2f, V = %.4f):\n", rho, V);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double Fk = rho * (*(g + i)) * V;
        printf("%-10s -> Kaldirma Kuvveti: %.2f N\n", *(pNames + i), Fk);
    }
}

void basitSarkac(double *g, char (*pNames)[15]) {
    double L;
    printf("\n--- Basit Sarkac Periyodu Deneyi ---\n");
    printf("Ip uzunlugunu giriniz (L [m]): ");
    scanf("%lf", &L);

    L = (L < 0) ? -L : L;

    printf("\nSonuclar (L = %.2f m):\n", L);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double current_g = *(g + i);
        double T = 2 * PI * sqrt(L / current_g);
        printf("%-10s -> Periyot: %.2f s\n", *(pNames + i), T);
    }
}

void ipGerilmesi(double *g, char (*pNames)[15]) {
    double m;
    printf("\n--- Sabit Ip Gerilmesi Deneyi ---\n");
    printf("Kutleyi giriniz (m [kg]): ");
    scanf("%lf", &m);

    m = (m < 0) ? -m : m;

    printf("\nSonuclar (m = %.2f kg):\n", m);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double T = m * (*(g + i));
        printf("%-10s -> Gerilme Kuvveti: %.2f N\n", *(pNames + i), T);
    }
}

void asansorDeneyi(double *g, char (*pNames)[15]) {
    double m, a;
    int direction;

    printf("\n--- Asansor Deneyi ---\n");
    printf("1. Yukari Hizlanan / Asagi Yavaslayan (Agirlasma)\n");
    printf("2. Asagi Hizlanan / Yukari Yavaslayan (Hafiflesme)\n");
    printf("Durumu seciniz (1 veya 2): ");

    (scanf("%d", &direction) != 1) ? (cleanInputBuffer(), direction = 1) : 0;

    printf("Kutleyi giriniz (m [kg]): ");
    scanf("%lf", &m);
    printf("Asansor ivmesini giriniz (a [m/s^2]): ");
    scanf("%lf", &a);

    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;

    printf("\nSonuclar (m = %.2f kg, a = %.2f m/s^2):\n", m, a);

    for (int i = 0; i < PLANET_COUNT; i++) {
        double current_g = *(g + i);
        double raw_N;
        double N;

        raw_N = (direction == 1) ? (m * (current_g + a)) : (m * (current_g - a));

        N = (raw_N < 0) ? 0 : raw_N;

        printf("%-10s -> Etkin Agirlik: %.2f N\n", *(pNames + i), N);
    }
}
