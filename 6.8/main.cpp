#include <iostream>

using namespace std;

int breakingPoint = 9;
int countDrops = 0;

bool crack(int floor){
    countDrops++;
    cout<<countDrops<<' '<<floor<<'\n';
    return floor >= breakingPoint;
}

int findBreakingPoint(int floors){
    int interval = 14;
    int previousFloor = 0;
    int egg1 = interval;

    while(egg1 <= floors && !crack(egg1)){
        interval -= 1;
        previousFloor = egg1;
        egg1 += interval;
    }

    int egg2 = previousFloor+1;
    while(egg2 < egg1 && egg2 <= floors && !crack(egg2)){
        egg2++;
    }

    return egg2 > floors ? -1 : egg2;
}

int main()
{
    int result = findBreakingPoint(100);
    cout<<"Breaking point is "<<result<<"\nNumber of drops is "<<countDrops;
    return 0;
}
