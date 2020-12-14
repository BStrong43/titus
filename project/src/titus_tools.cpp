/**
* @file titus_tools.cpp
*
* @author Ben Strong
* @assignment Final Project
* @date 12/13/2020
* 
*/
#include "../include/titus_tools.h"

void sendCalendar(std::string fileName)
{
    //Get events
    std::vector<eventDet> events = fileToString(fileName);

    //Filter out events longer than a week away
    events = purgeEvents(events);

    std::stringstream outMsg = formatMsg(events);
    std::cout<<"\nmessage formatted";

    std::ofstream outFile;
    std::string outName = "OUTPUT" + fileName;

    outFile.open(outName);
    if(!outFile.bad())
    {
        outFile << outMsg.str();
    }
    else
    {
        std::cout << "File '" << outName << "' could not be opened\n";
    }
    outFile.close();
    
}

std::stringstream formatMsg(std::vector<eventDet> eventList)
{
    std::stringstream outText;
    //Add header to message
    outText << "Good day Ben\nHere is your schedule for the week\n_____\n";

    for (int i = 0; i < eventList.size(); i++)
    {
        //Create stream
        std::stringstream nextLine;
        //Write event data to stream
        nextLine << eventList[i].title << "\n";
        nextLine << dateToString(eventList[i].day, eventList[i].month, eventList[i].year, eventList[i].time) << "\n";
        nextLine << eventList[i].location << "\n";
        nextLine << "\n------\n";
        outText << nextLine.str();
    }

    outText << "\nBest Regards\n-Titus";

    return outText;
}

std::vector<eventDet> fileToString(std::string fileName)
{
    std::vector<eventDet> events = {}; //Variable to be returned
    
    //Create and open stream
    std::ifstream cal;
    cal.open(fileName);
    //Check if bad
    if(cal.is_open())
    {//keep going
        
        int eventNum;
        std::string eventNumStr;
        getline(cal, eventNumStr);

        if(cal.bad())
        { //bad read safety measure
            eventNum = 0;
            std::cout <<"\nBAD READ SOMETHING BIG WRONG\n";
        }
        else
        {//Everything is ok
            eventNum = atoi(eventNumStr.c_str());
        }

        //Calendar parsing & event data compilation
        for(int i = 0; i < eventNum;i++)
        {
            //Gives default values in case line from file cant be read
            eventDet newEvent = {};
            std::string d,m,y,t;
            //Extract values from file
            getline(cal, newEvent.title);
            getline(cal, newEvent.location);
            getline(cal, m);
            getline(cal, y);
            getline(cal, d);
            getline(cal, t);

            newEvent.month = atoi(m.c_str());
            newEvent.year = atoi(y.c_str());
            newEvent.day = atoi(d.c_str());
            newEvent.time = atoi(t.c_str());
            
            events.push_back(newEvent);
        }
    }
    else
    {//If bad dont do thing
        std::cout << "File '" << fileName << "' could not be opened\n";
    }

    cal.close();
    
    return events;
}

std::vector<eventDet> purgeEvents(std::vector<eventDet> allEvents)
{

    std::vector<eventDet> eventNotifications = {};

    //Get date -Confirmed works
    dateStruct curDate = whatsTheDate();

    //
    int daysSinceZero = ((curDate.month - 1) * 30) + curDate.day;

    for(int i=0; i<allEvents.size(); i++)
    {
        if(allEvents[i].year < curDate.year)
            continue;

        
        //must do a different calculation for event dates to ensure that events next month or year (yet still 
        //within a week from the present) are not purged
        int eventDaySinceZero = ((allEvents[i].month-1) * 30) + allEvents[i].day;
        
        //Get year difference in days and add it
        eventDaySinceZero += (365 * (allEvents[i].year - curDate.year));

        int dayDelta = eventDaySinceZero - daysSinceZero;

        if(dayDelta >=0 && dayDelta <=7)
        {
            eventNotifications.push_back(allEvents[i]);
        }
    }

    //Remember to replace this with eventNotifications
    return eventNotifications;
}

dateStruct whatsTheDate()
{
    //@credit next 2 lines from https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
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