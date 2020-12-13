
//Strings for calendar data storage
#include <string>
#include <sstream>
#include <vector>

//IO
#include <iostream>
#include <fstream>

//Misc
#include <ctime>

//Struct used to hold the useful current time data
struct dateStruct
{
    int day;
    int month;
    int year;
};

//Event struct to save the useful data with
struct eventDet/*ails*/
{
    //Date stored as ints - will be converted to proper strings for output file
    int day = 0;
    int month = 0;
    int year = 0;
    int time = 0;
    std::string title = "";
    std::string location = "";
};

void sendCalendar(std::string filename = "calendar.txt");
std::stringstream formatMsg(std::vector<eventDet> eventList);
std::vector<eventDet> fileToString(std::string fileName = "calendar.txt");
std::vector<eventDet> purgeEvents(std::vector<eventDet> allEvents);

// Simple Utility Functions
std::string monthFromNum(int month);
std::string dateToString(int d, int m, int y, int t);
dateStruct whatsTheDate();