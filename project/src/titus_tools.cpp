#include "titus_tools.h"

void sendCalendar(std::string fileName)
{
    //Get date
    dateStruct curDate = whatsTheDate();
    std::cout<< "\nDate Created";

    //Get events
    std::vector<eventDet> events = fileToString(fileName);
    std::cout<< "\nEvent Vector Created";
    
    //Filter out events longer than a week away
    events = purgeEvents(events);
    std::cout<<"\nEvents Purged";

    std::stringstream outMsg = formatMsg(events);
    std::cout<<"\nmessage formatted";

    std::ofstream outFile;
    std::string outName = "OUTPUT" + fileName;

    outFile.open(outName);
    if(!outFile.bad())
    {
        outFile << outMsg.str();
        std::cout<< "\nCalendar Sent";
    }
    else
    {
        std::cout << "File '" << outName << "' could not be opened\n";
    }
}

std::stringstream formatMsg(std::vector<eventDet> eventList)
{
    std::stringstream outText;
    //Add header to message
    outText << "Good day Ben\nHere is your schedule for the week";

    for (int i = 0; i < eventList.size(); i++)
    {
        //Create stream
        std::stringstream nextLine;
        //Write event data to stream
        nextLine << "Event #" + (i+1);
        nextLine << eventList[i].title << "\n";
        nextLine << dateToString(eventList[i].day, eventList[i].month, eventList[i].year, eventList[i].time) << "\n";
        nextLine << eventList[i].location << "\n";
        nextLine << "\n------\n";
        outText << nextLine.str();
    }

    outText << "\nBest Regards\n-Titus/n";

    return outText;
}

std::vector<eventDet> fileToString(std::string fileName)
{
    std::vector<eventDet> events = {}; //Variable to be returned
    
    //Create and open stream
    std::ifstream cal;
    cal.open(fileName);

    //Check if bad
    if(!cal.bad())
    {//keep going

        //Calendar parsing & event data compilation
        while(!cal.eof())
        {
            //Gives default values in case line from file cant be read
            eventDet newEvent = {};

            //Extract values from file
            getline(cal, newEvent.title);
            getline(cal, newEvent.location);
            cal >> newEvent.month;//month
            cal >> newEvent.year;//year
            cal >> newEvent.day;//day
            cal >> newEvent.time;//time

            events.push_back(newEvent);
        }
    }
    else
    {//If bad dont do thing
        std::cout << "File '" << fileName << "' could not be opened\n";
    }

    

    return events;
}

std::vector<eventDet> purgeEvents(std::vector<eventDet> allEvents)
{

    std::vector<eventDet> eventNotifications = {};

    return eventNotifications;
}

dateStruct whatsTheDate()
{
    //Next 2 lines from https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
    time_t t = time(0);
    tm *date = localtime(&t);

    //Date setup
    dateStruct curDate;                 //Convert values to proper calendar info that we can use
    curDate.day = date->tm_mday;        //Day from 1-31
    curDate.month = date->tm_mon + 1;   //Month from 0-11
    curDate.year = date->tm_year + 1900;//tm_year: Number full of years passed since 1900

    return curDate;
}

//compiles
std::string dateToString(int d, int m, int y, int t)
{
    std::string inAM = "am";
    
    //Morning/Afternoon check
    if(t > 12)
    {
        t -= 12;
        inAM = "pm";
    }

    std::string date = monthFromNum(m) + " " + std::to_string(d) 
    + ", " + std::to_string(y) + " at " + std::to_string(t) + inAM;

    return date;
}

std::string monthFromNum(int month)
{
    std::string monthStr = "Invalid Month";

    switch(month)
    {
        case 1:
            monthStr = "January";
            break;
        case 2:
            monthStr = "February";
            break;
        case 3:
            monthStr = "March";
            break;
        case 4:
            monthStr = "April";
            break;
        case 5:
            monthStr = "May";
            break;
        case 6:
            monthStr = "June";
            break;
        case 7:
            monthStr = "July";
            break;
        case 8:
            monthStr = "August";
            break;
        case 9:
            monthStr = "September";
            break;
        case 10:
            monthStr = "October";
            break;
        case 11:
            monthStr = "November";
            break;
        case 12:
            monthStr = "December";
            break;
    }

    return monthStr;
}