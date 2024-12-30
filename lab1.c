#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day
{
    char *name;
    int date;
    char *description;
};

struct Day create()
{
    struct Day day;
    char temp[100];
    printf("Enter day of the week: ");
    scanf("%s", temp);
    day.name = strdup(temp);
    printf("Enter date: ");
    scanf("%d", &day.date);
    printf("Enter activity description: ");
    scanf(" %[^\n]s", temp);
    day.description = strdup(temp);
    return day;
}
void read(struct Day *calendar, int numDays)
{
    int i;
    for (i = 0; i < numDays; i++)
    {
        printf("\nEnter details for Day %d:\n", i + 1);
        calendar[i] = create();
    }
}
void display(const struct Day *calendar, int numDays)
{
    printf("\nCalendar:\n");
    int i;
    for (i = 0; i < numDays; i++)
    {
        printf("Day %d: %s\n", i + 1, calendar[i].name);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].description);
        printf("\n");
    }
}
int main()
{
    int numDays;
    printf("Enter the number of days in the calendar: ");
    scanf("%d", &numDays);
    struct Day *calendar = (struct Day *)malloc(numDays * sizeof(struct Day));
    if (calendar == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    read(calendar, numDays);
    display(calendar, numDays);

    int i;
    for (i = 0; i < numDays; i++)
    {
        free(calendar[i].name);
        free(calendar[i].description);
    }
    free(calendar);
    return 0;
}