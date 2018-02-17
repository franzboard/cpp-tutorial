#include <iostream>
#include "ds1820.h"
#include <vector>
using namespace std;

int main()
{
    cout << "Sensorwerte" << endl;
    ds1820 onewire;
    vector<string> sensors = onewire.getIds();
    for(;;) {
		for (size_t i = 0; i < sensors.size(); i++)
			cout << sensors[i] << "->" << onewire.getTemp(sensors[i]) << endl;
    }
    return 0;
}
