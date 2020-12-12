#include "titus_tools.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Next 2 lines from https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
    time_t t = time(0);
    tm *date = localtime(&t);

    //Date setup
    dateStruct curDate;
    curDate.day = date->tm_mday;
    curDate.month = date->tm_mon + 1;
    curDate.year = date->tm_year + 1900;

    sendCalendar();


    return EXIT_SUCCESS;
}