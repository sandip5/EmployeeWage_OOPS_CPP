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

void calculateDailyWage(int empWorkingHrs)
{
    const int EMP_RATE_PER_HR = 20;
	int dailyWage = 0;

    dailyWage = EMP_RATE_PER_HR * empWorkingHrs;

	cout << "Employee Daily Wage: " << dailyWage << endl;
}

int main()
{
    calculateDailyWage(getEmployeeWorkingHours());
    return 0;
}