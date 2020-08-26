#include <iostream>
#include <ctime>

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

void calculateDailyWage(int empWorkingHrs)
{
    const int EMP_RATE_PER_HR = 20;
	int dailyWage = 0;

    dailyWage = EMP_RATE_PER_HR * empWorkingHrs;

	cout << "Employee Daily Wagre: " << dailyWage << endl;
}

int main()
{
    calculateDailyWage(getEmployeeWorkingHours());
    return 0;
}