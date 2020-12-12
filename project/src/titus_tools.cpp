#include "titus_tools.h"

std::stringstream formatMsg(std::vector<eventDet> eventList)
{
    std::stringstream outText;
    outText << "Happy Sunday Ben\nHere is your schedule for the week";

    for (int i = 0; i < eventList.size(); i++)
    {
        //Create stream
        std::stringstream nextLine;
        //Write event data to stream
        nextLine << "Event #" + (i+1);
        nextLine << eventList[i].title << "\n";
        nextLine << eventList[i].day << " " << monthFromNum(eventList[i].month) << " " << eventList[i].year << "\n";
        nextLine << eventList[i].location << "\n";
        nextLine << "\n------\n";
        outText << nextLine.str();
    }

    outText << "\nBest Regards\n-Titus/n";

    return outText;
}

std::vector<eventDet> fileToString(std::string fileName)
{
    std::vector<eventDet> events = {};

    return events;
}

void sendCalendar(std::string fileName = "calendar.txt")
{
    std::ofstream outCal;
    outCal.open(fileName);
    if(!outCal.fail())
    {
        
    }
    else
    {
        std::cout << "File '" << fileName << "' could not be opened\n";
    }


}