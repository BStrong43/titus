/**
* @file titus_main.cpp
*
* @author Ben Strong
* @assignment Final Project
* @date 12/13/2020
* @credits
* 
*/
#include "../include/titus_tools.h"
#include "boost/program_options.hpp"

using namespace std;
using namespace boost::program_options;

int main(int argc, const char *argv[])
{
    //option variables given default values when options are created
    int daysOut;
    std::string outFile;

    //Option Parsing in order to do the thing
    try
  {
    options_description desc{"Options"};
    //add options/notifiers
    desc.add_options()
      ("help,h", "Help screen")
      ("d", value<int>(&daysOut)->default_value(7), "Days out")
      ("f", value<std::string>(&outFile)->default_value("OUTPUTcalendar.txt"));

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }

    //Do the thing - finally
    sendCalendar(daysOut, outFile); 

    cout << "\n";

    return EXIT_SUCCESS;
}