#include "pathfind.h"

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::string;
using std::vector;

int waterValue = 1;
bool driveableOnWater = true;
vector<string> obstacles{};

void ActivateDC()
{
    cout << "DC Active, Road Mode Activated\n";
}
void ActivatePropeller()
{
    cout << "Propeller Active, Water Mode Activated\n";
}

void Drive()
{
    if (driveableOnWater)
    {
        if (waterValue <= 0)
        {
            ActivateDC();
        }
        else
        {
            ActivatePropeller();
        }
    }
    else
    {
        //Define Water as an obstacle
        obstacles.emplace_back("Water");
        cout << "Cannot Drive on Water\n";
    }
}

int main()
{
    Drive();
    auto driveMap = ReadBoardFile("environment.board");
    int init[2]{0, 0};
    int goal[2]{4, 5};
    auto drivePath = (Search(driveMap, init, goal));
    PrintDriveMap(drivePath);
}
