#include <iostream>
#include <vector>

using namespace std;

namespace emp_model_spc
{
    class EmpWageBuilder
    {
        string companyName;
        int totalWage;
        int maxWorkingDayInMonth;
        int maxHoursPerMonth;
        int wagePerHr;
        vector<int> storeDailyWage;

    public:
        EmpWageBuilder(){};
        EmpWageBuilder(string companyName, int wagePerHr, int maxWorkingDayInMonth, int maxHoursPerMonth);
        void setTotalWage(int totalWage);
        string getCompanyName();
        int getTotalWage();
        int getWagePerHr();
        int getMaxWorkingDayInMonth();
        int getMaxHoursPerMonth();
        void setDailyWage(vector<int> storeDailyWag);
    };

    EmpWageBuilder::EmpWageBuilder(string companyName, int wagePerHr, int maxWorkingDayInMonth, int maxHoursPerMonth)
    {
        this -> companyName = companyName;
        this -> wagePerHr = wagePerHr;
        this -> maxWorkingDayInMonth = maxWorkingDayInMonth;
        this -> maxHoursPerMonth = maxHoursPerMonth;
    }


    void EmpWageBuilder::setDailyWage(vector<int> storeDailyWage)
    {
        this -> storeDailyWage = storeDailyWage;
    }

    int EmpWageBuilder::getWagePerHr()
    {
        return wagePerHr;
    }

    int EmpWageBuilder::getMaxWorkingDayInMonth()
    {
        return maxWorkingDayInMonth;
    }

    int EmpWageBuilder::getMaxHoursPerMonth()
    {
        return maxHoursPerMonth;
    }

    void EmpWageBuilder::setTotalWage(int totalWage)
    {
        cout << totalWage << endl;
        this -> totalWage = totalWage;
    }

    string EmpWageBuilder::getCompanyName()
    {
        return companyName;
    }

    int EmpWageBuilder::getTotalWage()
    {
        return totalWage;
    }
}
