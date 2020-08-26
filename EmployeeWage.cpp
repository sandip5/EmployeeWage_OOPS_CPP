#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

int getEmployeeWorkingHours()
{
    cout << "Hello Welcome To Employee Wage Computation Problem" << endl;
    
    const int IS_FULL_TIME = 1;
	const int IS_PART_TIME = 2;
    const int FULL_TIME = 8;
    const int PART_TIME = 4;

	srand( time(0) );
	int checkWorkingHours = rand() % 3 + 1;
	
    if( checkWorkingHours == IS_FULL_TIME )
		return FULL_TIME;

	if( checkWorkingHours== IS_PART_TIME )
	    return PART_TIME;
    
    if( checkWorkingHours == 3)
        cout << "Employee Is Absent." << endl;
    return 0;
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
    int dailyWage = 0;
    int monthWage = 0;

    for( int day = 1; day <= MONTH_TOTAL_WORKING_DAYS; day++ )
    {
        dailyWage = calculateDailyWage(getEmployeeWorkingHours());
        monthWage = monthWage + dailyWage;
        sleep(1);
    }

    cout << "Monthly Wage Of Employee: " << monthWage << endl;
}

int main()
{
    calculateMonthWage();
    return 0;
}