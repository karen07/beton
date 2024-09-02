#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *CB_file = fopen("cb.txt", "r");
    int CB_count = 0;
    double *CB_values = (double *)malloc(sizeof(double) * 1000);
    while (fscanf(CB_file, "%lf\n", &CB_values[CB_count++]) != EOF) {
    }

    FILE *price_file = fopen("price.txt", "r");
    int price_count = 0;
    double *price_values = (double *)malloc(sizeof(double) * 1000);
    while (fscanf(price_file, "%lf\n", &price_values[price_count++]) != EOF) {
    }

    FILE *inf_file = fopen("inf.txt", "r");
    int inf_count = 0;
    double *inf_values = (double *)malloc(sizeof(double) * 1000);
    while (fscanf(inf_file, "%lf\n", &inf_values[inf_count++]) != EOF) {
    }

    FILE *salary_file = fopen("salary.txt", "r");
    int salary_count = 0;
    double *salary_values = (double *)malloc(sizeof(double) * 1000);
    while (fscanf(salary_file, "%lf\n", &salary_values[salary_count++]) != EOF) {
    }

    printf("%d %d %d %d\n", CB_count, price_count, inf_count, salary_count);

    FILE *CB_price = fopen("cb_price.txt", "w");
    for (int i = 0; i < CB_count - 1; i++) {
        double tmp = price_values[i];
        for (int j = i; j < CB_count; j++) {
            tmp *= (1 + CB_values[j] / 100.0 / 12.0);
        }
        fprintf(CB_price, "%lf\n", tmp);
    }

    FILE *inf_price = fopen("inf_price.txt", "w");
    for (int i = 0; i < inf_count - 1; i++) {
        double tmp = price_values[i];
        for (int j = i; j < inf_count; j++) {
            tmp *= (1 + inf_values[j] / 100.0);
        }
        fprintf(inf_price, "%lf\n", tmp);
    }

    FILE *salary_price = fopen("rent_price.txt", "w");
    for (int i = 0; i < salary_count - 1; i++) {
        double tmp = 0;
        for (int j = i; j < salary_count; j++) {
            tmp += salary_values[i] / 3 / 35;
            tmp *= (1 + CB_values[j] / 100.0 / 12.0);
        }
        fprintf(salary_price, "%lf\n", tmp + 271500);
    }

    return 0;
}
