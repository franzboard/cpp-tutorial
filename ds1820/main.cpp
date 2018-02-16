#include <iostream>
#include "ds1820.h"
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Sensorwerte" << endl;
    ds1820 onewire;
    onewire.showTemp();
    return 0;
}
