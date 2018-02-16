#ifndef DS1820_H
#define DS1820_H
#include <vector>
#include <string>
using namespace std;

typedef struct {
    string id;
    float temp;
} sensor;

class ds1820
{
public:
    ds1820();
    void showTemp();
private:
    vector<sensor> m_sensor;
    void getTemp();
 };

#endif // DS1820_H
