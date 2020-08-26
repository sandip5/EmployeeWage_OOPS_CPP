#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

int getEmployeeWorkingHours()
{
    const int IS_FULL_TIME = 1;
	const int IS_PART_TIME = 2;
    const int FULL_TIME = 8;
    const int PART_TIME = 4;
    const int ABSENT = 3;
    int empWorkDuration = 0;

	srand( time(0) );
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

int calculateDailyWage(int empWorkingHrs)
{
    const int EMP_RATE_PER_HR = 20;
	int dailyWage = 0;

    dailyWage = EMP_RATE_PER_HR * empWorkingHrs;

	cout << "Employee Daily Wagre: " << dailyWage << endl;
    return dailyWage;
}

void calculateMonthWage()
{
    const int MONTH_TOTAL_WORKING_DAYS = 20;
    const int MAX_WORKING_HRS = 100;

    int dailyWage = 0;
    int monthWage = 0;
    int empHrs = 0;
    int totalEmpHrs = 0;
    int totalWorkingDays = 0;

    while( totalEmpHrs < MAX_WORKING_HRS && totalWorkingDays < MONTH_TOTAL_WORKING_DAYS )
    {
        empHrs = getEmployeeWorkingHours();
        dailyWage = calculateDailyWage(empHrs);
        monthWage = monthWage + dailyWage;
        totalEmpHrs = totalEmpHrs + empHrs;
        totalWorkingDays++;
        sleep(1);
    }

    cout << "Monthly Wage Of Employee: " << monthWage << endl;
}

int main()
{
    cout << "Hello Welcome To Employee Wage Computation Problem" << endl;
    calculateMonthWage();
    return 0;
}