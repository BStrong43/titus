//Strings for calendar data storage
#include <string>
#include <sstream>
#include <vector>

//IO
#include <iostream>
#include <fstream>

//Misc
#include <ctime>

struct dateStruct
{
    int day;
    int month;
    int year;
};

//Event struct to save the useful data with
struct eventDet/*ails*/
{
    int day = 0;
    int month = 0;
    int year = 0;
    std::string title = "";
    std::string location = "";
};

void sendCalendar();

// Utility Functions
std::stringstream formatMsg(std::vector<eventDet> eventList);
std::vector<eventDet> fileToString(std::string fileName = "");
std::string monthFromNum(int month);