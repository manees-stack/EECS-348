#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void monthly_data(char months[][10], float sales[])
{
    printf("%-15s%s\n\n", "Month", "Sales");
    for (int i = 0; i < 12; i++)
    {

        printf("%-15s$%0.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

void sorted(float values[], char months[][10], int n)
{
    float tempf = 0.0f;
    char temps[10];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (values[j] < values[j + 1])
            {
                tempf = values[j + 1];
                values[j + 1] = values[j];
                values[j] = tempf;
                strcpy(temps, months[j + 1]);
                strcpy(months[j + 1], months[j]);
                strcpy(months[j], temps);
            }
        }
        printf("\n");
    }

    printf("Sales Report (Ordered from highest to lowest)\n\n");
    printf("%-15s%s\n", "Month", "Sales");

    for (int i = 0; i < n; i++)
    {
        printf("%-12s$%.2f\n", months[i], (float)values[i]);
    }
    printf("\n");
}
void summary(float sales[], char months[][10])
{
    float highest = sales[0];
    float lowest = sales[0];
    int highest_month_index = 0;
    int lowest_month_index = 0;
    float sum = 0;

    for (int i = 0; i < 12; i++)
    {
        if (sales[i] > highest)
        {
            highest = sales[i];
            highest_month_index = i;
        }
        if (sales[i] < lowest)
        {
            lowest = sales[i];
            lowest_month_index = i;
        }
        sum += sales[i];
    }

    float average = (float)sum / 12;

    printf("\nMaximum Sales: %s - $%.2f\n", months[highest_month_index], highest);
    printf("Minimum Sales: %s - $%.2f\n", months[lowest_month_index], lowest);
    printf("Average Sales: $%.2f\n", average);
    printf("\n");
}

void six_month_report(char months[][10], float sales[], int n)
{
    printf("Six-Month Average Report:\n\n");

    for (int i = 0; i < n - 6; i++)
    {
        float sum = 0;

        for (int j = i; j < i + 6; j++)
        {
            sum += sales[j];
        }

        float avg = sum / 6;

        printf("%s - %s $%.2f\n", months[i], months[i + 5], avg);
    }
}
int main()
{
    float sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int n = 12;
    printf("12-month Sales Report\n\n");
    monthly_data(months, sales);

    six_month_report(months, sales, n);

    sorted(sales, months, n);
    summary(sales, months);

    return 0;
}