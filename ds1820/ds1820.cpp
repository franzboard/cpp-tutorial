#include "ds1820.h"
#include <iostream>
#include <fstream>
#include <string>

// get ids of all sensors from file
ds1820::ds1820()
{
    string id;
    ifstream myfile ("/sys/devices/w1_bus_master1/w1_master_slaves");
    if (!myfile)
        cerr << "no devices" << endl;
    else {
        while ( getline (myfile, id) )
            m_id.push_back(id);
        myfile.close();
    }
}


vector<string> ds1820::getIds()
{
    return m_id;
}

// return float value read from sensor file
// in error case -999 is returned
float ds1820::getTemp(string id)
{
    string devfile;
    string line;
    size_t pos;
    float temp = -999;

    devfile = "/sys/bus/w1/devices/" + id + "/w1_slave";
    ifstream myfile(devfile);
    if (myfile) {
        getline (myfile, line);
        if (line.find("YES") != string::npos) {
            getline (myfile, line);
            pos = line.find("=");
            temp =  std::stof(line.substr(pos + 1)) / 1000.0;
        }
        myfile.close();
    }
    else
        cerr << "device file error" << endl;
    return temp;
}

