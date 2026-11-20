#include <stdio.h>
#include <time.h>

struct car {
    char brand[100];
    char manufacturer[100];
    char type[100];
    int year;
    int reg_day;
    int reg_month;
    int reg_year;
};

int main(void)
{
    struct car a;
    time_t t = time(NULL);
    int current_year = localtime(&t)->tm_year + 1900;

    printf("Марка автомобиля: ");
    scanf(" %99[^\n]", a.brand);

    printf("Производитель: ");
    scanf(" %99[^\n]", a.manufacturer);

    printf("Тип: ");
    scanf(" %99[^\n]", a.type);

    printf("Год выпуска: ");
    scanf("%d", &a.year);

    printf("Дата регистрации (дд.мм.гггг): ");
    scanf("%d.%d.%d", &a.reg_day, &a.reg_month, &a.reg_year);

    if (a.year <= 2005 && a.reg_year == current_year) {
        printf("\nМарка автомобиля: %s\n", a.brand);
        printf("Производитель: %s\n", a.manufacturer);
        printf("Тип: %s\n", a.type);
        printf("Год выпуска: %d\n", a.year);
        printf("Дата регистрации: %02d.%02d.%04d\n",
               a.reg_day, a.reg_month, a.reg_year);
    }

    return 0;
} 