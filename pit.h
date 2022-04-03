#ifndef PIT_H
#define PIT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>


using namespace std;

class Pit
{
    vector<int> depths;
    int location;
    int pitNum;
public:
    void read(const string& filename);
    void getDepthAtLocation();
    void percentageOfNonPitArea() const;
    void writePitsToFile(const string& filename);
    void getPitNum() const;
    void pitInfoByLocation() const;
};

#endif // PIT_H
