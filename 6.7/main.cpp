#include <iostream>
#include <vector>

std::vector<int> runOneFamily()
{
    int boys = 0;
    int girls = 0;
    while(girls == 0){
        int newChild = rand() % 2;
        if(newChild){
            girls += 1;
        }
        else{
            boys += 1;
        }
    }
    std::vector<int> genders = {girls, boys};
    return genders;
}

double runFamilies(int n)
{
    int boys = 0, girls = 0;
    for(int i=1; i<=n; i++)
    {
        std::vector<int> familyReport = runOneFamily();
        girls += familyReport[0];
        boys += familyReport[1];
    }
    return (double) girls/(girls+boys)*100.0;
}

int main()
{
    double g = runFamilies(1000);
    double b = 100.0 - g;
    std::cout<<"Girls: "<<g<<"%\n"<<"Boys: "<<b<<"%\n";
    return 0;
}
