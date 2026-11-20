#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t = time(NULL);
    struct tm *mytime = localtime(&t);
    char text[100];

    const char *days[] = {
        "воскресенье", "понедельник", "вторник",
        "среда", "четверг", "пятница", "суббота"
    };

    const char *months[] = {
        "января", "февраля", "марта", "апреля",
        "мая", "июня", "июля", "августа",
        "сентября", "октября", "ноября", "декабря"
    };

    sprintf(text, "День недели: %s", days[mytime->tm_wday]);
    printf("%s\n", text);

    sprintf(text, "%02d.%02d.%04d",
            mytime->tm_mday,
            mytime->tm_mon + 1,
            mytime->tm_year + 1900);
    printf("%s\n", text);

    sprintf(text, "%d %s",
            mytime->tm_mday,
            months[mytime->tm_mon]);
    printf("%s\n", text);

    return 0;
}