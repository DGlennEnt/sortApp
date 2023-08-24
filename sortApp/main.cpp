#include <iostream>
#include <QCoreApplication>
#include <QFile>
#include <QVector>

// sortApp by David Glenn david@dglenn.com
//
//Preamble:
// For what it is worth, This is a doodle code where I was given a set of numbers and I was asked to come up with
// a Count, Median, Standard Deviation, Min and Max.
// This program calculates that data for each line and passes it out as a string in the console for how many lines they are.
// The I don't pretend for a second that I know anything about statistics, so much of this was cleaved from google and
// I used most of the tools I know and even use Qt functions to get things done.
// Given that I was not paid for any of this is scored by the shortness of time I put into it!
// The downside of these assignments is this don't showcase my work. It just show you what I can do on the cheep.
// In the end they say that I might get an interview. I see it as do me some stuff and it will get my foot in the door.
// Artists call it: Work for exposure.
// I just took it on as something that would fill a Wensday afternoon and maybe I would learn something.
// For the best way to get good at code is to expand mind and like they say at
// Carnegie Hall: Practice, Practice, Practice or code, code, code.
//
// Notes:
// This was written on a QT IDE on a windows box. It was set up to be used with CMake and with the proper commands
// you can create the make file for your system.
// I am not going to lie. This code may require the Qt Libraries to operate and any good Linux package will have
// the libraries installed if they are included in the system.
// You may have to install the build libraries to get this program to work.
// I'm sorry, but I didn't have a Linux box at the time to develop this.
// I know that in Red Hat you can go into Yum and select the build libraries for Qt5Core and you should have
// what you need to compile it.
//
// Usage: sortApp <filemame.csv>
//
// Notes for Test Data:
// Name: random_numbers.csv
//
// Thank You and I hope you enjoy the show! :)

int main(int argc, char *argv[])
{
    QStringList wordList;
    QCoreApplication a(argc, argv);
    QFile fp(argv[1]);
    if( !fp.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        if (argc < 2)
        {
            std::cout << "sortApp by David Glenn david@dglenn.com \n";
            std::cout << "Usage: sortApp <filemame.csv> \n";
        }
        else std::cout <<"Sorry,no such file: " << argv[1] << "\n";
        return(-1);
    }
    else
    {
        while (!fp.atEnd())
        {
            QString line = fp.readLine();
            QStringList list = line.split(QLatin1Char(','));
            if (list.first().toDouble())
            {
                int count = list.count();
                QVector<double> vect;
                for(int i = 0; i < list.count();i++)
                {
                    double numSet = list[i].toDouble();
                    vect.append(numSet);
                }
                 QString setstring;
                 setstring.setNum(count);
                 double median = 0;
                 if(vect.count() % 2 == 0)
                 {
                    median = static_cast<double>((vect[vect.count() / 2 - 1] + vect[vect.count() / 2])) / 2;
                 }
                 else
                 {
                    median = vect[vect.count() / 2];
                 }

                 double standDevCont =0.0;
                 double minVal = vect[0];
                 double maxVal = 0.0;
                 for(int i = 0; i < vect.count(); ++i)
                 {
                     standDevCont += pow(vect[i] - median, 2);
                     if(vect[i] < minVal ) minVal = vect[i];
                     if(vect[i] > maxVal ) maxVal = vect[i];
                 }
                 double standDev = sqrt(standDevCont / vect.count());

                 setstring.append(" ");
                 QString workingStr;
                 workingStr.setNum(median);
                 setstring.append(workingStr);
                 setstring.append(" ");
                 workingStr.setNum(standDev);
                 setstring.append(workingStr);
                 setstring.append(" ");
                 workingStr.setNum(minVal);
                 setstring.append(workingStr);
                 setstring.append(" ");
                 workingStr.setNum(maxVal);
                 setstring.append(workingStr);
                 setstring.append(" \n");
                 wordList.append(setstring);
            }
          }
        }
    for(int i = 0; i < wordList.count(); ++i)
    {
        std::cout << wordList[i].toStdString();
    }
    fp.close();
    return a.exec();
}
