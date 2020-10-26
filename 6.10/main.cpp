#include <iostream>
#include <vector>
using namespace std;

class Bottle{
private:
    bool poisoned = false;
    int id;
public:
    Bottle(int id){ this->id = id; }
    int getId(){ return id; }
    bool isPoisoned() { return poisoned; }
    void setAsPoisoned() { poisoned = true; }
};

class TestStrip{
public:
    const int DAYS_FOR_RESULT = 7;
    TestStrip(int id) { this->id = id; }
    int getId() { return id; }
    void addDropOnDay(int day, Bottle bottle){
        sizeDropsForDay(day);
        dropsByDay[day].push_back(bottle);
    }
    vector<Bottle> getLastWeeksBottles(int day){
        if(day < DAYS_FOR_RESULT){
            vector<Bottle> emptyVector;
            return emptyVector;
        }
        return dropsByDay[day-DAYS_FOR_RESULT];
    }
    bool isPositiveOnDay(int day){
        int testDay = day - DAYS_FOR_RESULT;
        if(testDay < 0 || testDay >= dropsByDay.size()){
            return false;
        }
        for(int d = 0; d<=testDay; d++){
            vector<Bottle> bottles = dropsByDay[d];
            if(hasPoison(bottles)){
                return true;
            }
        }
        return false;
    }
private:
    vector<vector<Bottle>> dropsByDay;
    int id;
    void sizeDropsForDay(int day){
        while(dropsByDay.size() <=day ){
            vector<Bottle> emptyVector;
            dropsByDay.push_back(emptyVector);
        }
    }
    bool hasPoison(vector<Bottle>& bottles){
        for(Bottle b: bottles){
            if(b.isPoisoned()){
                return true;
            }
        }
        return false;
    }
};

void runTests(vector<Bottle>& bottles, vector<TestStrip>& testStrips){
    for(Bottle bottle: bottles){
        int id = bottle.getId();
        for(int i=0; (1<<i) <= id; i++){
            if(id & (1<<i)){
                testStrips[i].addDropOnDay(0, bottle);
            }
        }
    }
}

vector<int> getPositiveOnDay(vector<TestStrip>& testStrips, int day){
    vector<int> positive;
    for(TestStrip testStrip: testStrips){
        int id = testStrip.getId();
        if(testStrip.isPositiveOnDay(day)){
            positive.push_back(id);
        }
    }
    return positive;
}

int setBits(vector<int>& positive){
    int result = 0;
    for(int bitIndex: positive){
        result |= 1<<bitIndex;
    }
    return result;
}

int findPoisonedBottle(vector<Bottle>& bottles, vector<TestStrip>& testStrips){
    runTests(bottles, testStrips);
    vector<int> positive = getPositiveOnDay(testStrips, 7);
    return setBits(positive);

}

int main()
{
    vector<Bottle> bottles;
    vector<TestStrip> testStrips;
    for(int i=0; i<1000; i++){
        bottles.push_back(Bottle(i));
    }
    bottles[124].setAsPoisoned();
    for(int i=0; i<10; i++){
        testStrips.push_back(TestStrip(i));
    }
    cout<<findPoisonedBottle(bottles, testStrips);
    return 0;
}
