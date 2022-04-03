#include "pit.h"

int main()
{
    Pit pit = Pit();
    pit.read("melyseg.txt");
    pit.getDepthAtLocation();
    pit.percentageOfNonPitArea();
    pit.writePitsToFile("godrok.txt");
    pit.getPitNum();
    pit.pitInfoByLocation();
    return 0;
}
