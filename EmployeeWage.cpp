#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

class EmpWageBuilder
{
    private:
        const int FULL_TIME = 8;
        const int PART_TIME = 4;
        int maxWorkingDayInMonth = 20;
        int maxHoursPerMonth = 100;
        int wagePerHr = 20;
	    int dailyWage = 0;
        int monthWage = 0;
        int empHrs = 0;
        int totalEmpHrs = 0;
        int totalWorkingDays = 0;
        string companyName;

    public:
        EmpWageBuilder(string companyName, int wagePerHr, int maxWorkingDayInMonth, int maxHoursPerMonth);
        int getEmployeeWorkingHours();
        int calculateDailyWage();
        void calculateMonthWage();
};

EmpWageBuilder::EmpWageBuilder(string companyName, int wagePerHr, int maxWorkingDayInMonth, int maxHoursPerMonth)
{
    this -> companyName = companyName;
    this -> wagePerHr = wagePerHr;
    this -> maxWorkingDayInMonth = maxWorkingDayInMonth;
    this -> maxHoursPerMonth = maxHoursPerMonth;
}

int EmpWageBuilder::getEmployeeWorkingHours()
{
    const int IS_FULL_TIME = 1;
	const int IS_PART_TIME = 2;
    const int ABSENT = 3;
    int empWorkDuration = 0;
	
    srand( time(NULL) );
	int checkWorkingHours = rand() % 3 + 1;

    switch (checkWorkingHours)
    {
        case IS_FULL_TIME:
            empWorkDuration = FULL_TIME;
            break;
        case IS_PART_TIME:
            empWorkDuration = PART_TIME;
            break;
        case ABSENT:
            break;
        default:
            cout << "Invalid Result" << endl;
    }

    return empWorkDuration;
}

int EmpWageBuilder::calculateDailyWage()
{
    dailyWage = wagePerHr * getEmployeeWorkingHours();

	cout << "Employee Daily Wage: " << dailyWage << endl;
    return dailyWage;
}

void EmpWageBuilder::calculateMonthWage()
{
    while( totalEmpHrs < maxHoursPerMonth && totalWorkingDays < maxWorkingDayInMonth )
    {
        dailyWage = calculateDailyWage();
        monthWage = monthWage + dailyWage;
        totalEmpHrs = totalEmpHrs + empHrs;
        totalWorkingDays++;
        sleep(1);
    }

    cout << companyName << ", Monthly Wage Of Employee: " << monthWage << endl;
}

int main()
{
    cout << "Hello Welcome To Employee Wage Computation Problem" << endl;
    EmpWageBuilder *emp;
    emp = new EmpWageBuilder("Apple", 200, 22, 180);
    emp -> calculateMonthWage();
    emp = new EmpWageBuilder("Microsoft", 150, 24, 200);
    emp -> calculateMonthWage();
    delete emp;
    return 0;
}