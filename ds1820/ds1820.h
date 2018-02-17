#ifndef DS1820_H
#define DS1820_H
#include <vector>
#include <string>
using namespace std;

class ds1820
{
public:
    ds1820();
    vector<string> getIds();
    float getTemp(string id);
private:
    vector<string> m_id;
};

#endif // DS1820_H
