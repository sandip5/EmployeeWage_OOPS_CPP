#include <iostream>
#include <ctime>

using namespace std;

bool isPresent()
{
    cout << "Hello Welcome To Employee Wage Computation Problem" << endl;
	srand( time(0) );
	int checkAttendance = rand() % 2 + 1;
	
    if( checkAttendance == 1 )
	{
        cout << "Employee Is Present" << endl;
		return true;
	}

	if( checkAttendance == 2 )
	{
		cout << "Employee Is Absent" << endl;
        return false;
	}

    return false;
}

void calculateDailyWage(bool attendeeStatus)
{
    if(attendeeStatus)
    {
        const int EMP_RATE_PER_HR = 20;
	    const int EMP_HRS = 8;
	    int dailyWage = 0;

        dailyWage = EMP_RATE_PER_HR * EMP_HRS;
		cout << "Employee Daily Wagre: " << dailyWage << endl;
    }
}

int main()
{
    calculateDailyWage(isPresent());
    return 0;
}