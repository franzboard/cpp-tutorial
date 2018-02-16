#include "ds1820.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ds1820::ds1820()
{
    string id;
    ifstream myfile ("/sys/devices/w1_bus_master1/w1_master_slaves");
    if (!myfile)
        cerr << "no devices" << endl;
    else {
        while ( getline (myfile, id) )
            m_sensor.push_back({id, 0});
        myfile.close();
    }
}

void ds1820::getTemp()
{
    string devfile;
    string line;
    size_t pos;

    for (size_t i = 0; i < m_sensor.size(); i++) {
        devfile = "/sys/bus/w1/devices/" + m_sensor[i].id + "/w1_slave";
        ifstream myfile(devfile);
        if (myfile) {
            getline (myfile, line);
            if (line.find("YES") != string::npos) {
                getline (myfile, line);
                pos = line.find("=");
                m_sensor[i].temp =  std::stof(line.substr(pos + 1)) / 1000;
            }
            myfile.close();
        }
        else
             cerr << "device file error" << endl;
    }
}

void ds1820::showTemp()
{
    getTemp();
    for (size_t i = 0; i < m_sensor.size(); i++)
        cout << m_sensor[i].id << " -> " << fixed << setprecision(1) << m_sensor[i].temp <<endl;
}
