#include "pit.h"

void Pit::read(const string &filename)
{
    fstream in;
    in.open(filename, ios::in);
    string line;
    while (getline(in, line)) depths.push_back(atoi(line.c_str()));
    cout << "#1\nNumber of lines: " << depths.size() << endl;
    in.close();
}

void Pit::getDepthAtLocation()
{
    cout << "#2\nEnter a location ";
    cin >> location;
    if (depths[location-1] == 0) cout << "No pits in this location" << endl;
    else cout << "At location (" << location << ") the depth of pit is " << depths[location-1] << endl;
}

void Pit::percentageOfNonPitArea() const
{
    double countOfNull = count_if(depths.cbegin(), depths.cend(), [](const int& depth){
        return depth == 0;
    });
    cout.precision(4);
    cout << "#3\nPercentage of non pit area is: " << (countOfNull / depths.size()) * 100 << endl;
}

void Pit::writePitsToFile(const string &filename)
{
    fstream out;
    out.open(filename, ios::out);
    bool isEndOfPit = true;
    pitNum = 0;
    for (auto& depth : depths) {
        if (depth > 0) {
            if (isEndOfPit) isEndOfPit = false;
            out << depth << " ";
        } else if (!isEndOfPit) {
            isEndOfPit = true;
            pitNum++;
            out << "\n";
        }
    }
    out.close();
}

void Pit::getPitNum() const
{
    cout << "#5\nNumber of pits: " << pitNum << endl;
}

void Pit::pitInfoByLocation() const
{
    if (depths[location-1] == 0) {
        cout << "No pits in this location" << endl;
        return;
    }
    int startOfPit = location-1, endOfPit = location-1;
    while (depths[startOfPit-1] != 0) startOfPit--;
    while (depths[endOfPit+1] != 0) endOfPit++;
    cout << "#6\na)\nStart of pit: " << startOfPit+1 << " - End of pit: " << endOfPit+1 << "\n";
    vector<int> pit;
    for (int i = startOfPit; i <= endOfPit; i++) pit.push_back(depths[i]);
    bool isConstantlyDeepening = false;
    for (size_t i = 0; i < pit.size(); i++) {
        if (pit[i] < pit[i+1] && !isConstantlyDeepening) isConstantlyDeepening = true;
        else if (pit[i] > pit[i+1] && isConstantlyDeepening) {
            isConstantlyDeepening = false;
            break;
        }
    }
    if (isConstantlyDeepening) cout << "b\nThe pit is constantly deepening\n";
    else cout << "b\nThe pit is not constantly deepening\n";
    cout << "c\nMaximum depth is: " << *(max_element(pit.cbegin(), pit.cend())) << "\n";
    cout << "d\nVolume is: " << accumulate(pit.cbegin(), pit.cend(), 0) * 10 << "\n";
    cout << "e\nPossible water's volume is: " << (accumulate(pit.cbegin(), pit.cend(), 0, [](int result, int current){
        if (current > 1) return result + current;
        return result;
    }) - pit.size() ) * 10<< endl;
}
