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
        cout << "Employee Is Present";
		return true;
	}
	else if( checkAttendance == 2 )
	{
		cout << "Employee Is Absent" << endl;
        return false;
	}
    
    return false;
}

int main()
{
    isPresent();
    return 0;
}