#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>

using namespace std;

class EmpWageBuilder
{
    string companyName;
    int totalWage;
    int maxWorkingDayInMonth;
    int maxHoursPerMonth;
    int wagePerHr;

    public:
        EmpWageBuilder(string companyName, int wagePerHr, int maxWorkingDayInMonth, int maxHoursPerMonth);
        void setDetails(int totalWage);
        string getCompanyName();
        int getTotalWage();
        int getWagePerHr();
        int getMaxWorkingDayInMonth();
        int getMaxHoursPerMonth();
};

class CompanyEmpWage
{
    private:
        vector<EmpWageBuilder> companies;

    public:
        int getEmployeeWorkingHours();
        int calculateDailyWage(int wagePerHr);
        void calculateMonthWage(EmpWageBuilder details);
        void saveDetails(EmpWageBuilder details);
        void showSavedWage();
};

EmpWageBuilder::EmpWageBuilder(string companyName, int wagePerHr, int maxWorkingDayInMonth, int maxHoursPerMonth)
{
    this -> companyName = companyName;
    this -> wagePerHr = wagePerHr;
    this -> maxWorkingDayInMonth = maxWorkingDayInMonth;
    this -> maxHoursPerMonth = maxHoursPerMonth;
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

void EmpWageBuilder::setDetails(int totalWage)
{
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

int CompanyEmpWage::getEmployeeWorkingHours()
{
    const int IS_FULL_TIME = 1;
	const int IS_PART_TIME = 2;
    const int FULL_TIME = 8;
    const int PART_TIME = 4;
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

int CompanyEmpWage::calculateDailyWage(int wagePerHr)
{
    int dailyWage = 0;
    dailyWage = wagePerHr * getEmployeeWorkingHours();

	cout << "Employee Daily Wage: " << dailyWage << endl;
    return dailyWage;
}

void CompanyEmpWage::calculateMonthWage(EmpWageBuilder details)
{
    
    int totalEmpHrs = 0;
    int totalWorkingDays = 0;
    int dailyWage = 0;
    int monthWage = 0;

    while( totalEmpHrs < details.getMaxHoursPerMonth() && totalWorkingDays < details.getMaxWorkingDayInMonth() )
    {
        dailyWage = calculateDailyWage(details.getWagePerHr());
        monthWage = monthWage + dailyWage;
        totalWorkingDays++;
        sleep(1);
    }

    details.setDetails(monthWage);
    cout << details.getCompanyName() << ", Monthly Wage Of Employee: " << monthWage << endl;
    saveDetails(details);
}

void CompanyEmpWage::saveDetails(EmpWageBuilder details)
{
    companies.push_back(details);
}

void CompanyEmpWage::showSavedWage()
{
    for(EmpWageBuilder it : companies)
	{
		cout << it.getCompanyName() << ", Total Wage : " << it.getTotalWage() << endl; 
	}
}

int main()
{
    cout << "Hello Welcome To Employee Wage Computation Problem" << endl;
    EmpWageBuilder apple("Apple", 200, 22, 180), microsoft("Microsoft", 150, 24, 200);
    CompanyEmpWage companyEmpWage;
    companyEmpWage.calculateMonthWage(apple);
    companyEmpWage.calculateMonthWage(microsoft);
    companyEmpWage.showSavedWage();
    return 0;
}