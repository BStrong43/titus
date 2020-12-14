# .titus
## CSI 230 Final Project Repo

For my final project I created a digital assistant with a simple feature: read a file of calendar data, and within user specified parameters, format an output message containing events of certain details.

### To Use
Make sure the boost c++ library is installed.  Titus only requires boost for option parsing.
Pull the repository and run the executable in the bin folder titled "**main**". 

### Options
Titus has two options.

**--d**
>changes number of days beyond the present day in which calendar events will be compiled.  Default is 7.

**--f**
>name of the file that will contain the program output.  **This file will be overwritten entirely.** Default is "**OUTPUTcalendar.txt**".
