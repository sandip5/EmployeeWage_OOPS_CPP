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
        EmpWageBuilder(){};
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

void constructEmployeeWage()
{
    cout << "Hello Welcome To Employee Wage Computation Problem" << endl;
    
    cout << "Enter Number Of Company You Want To Add: " << endl;
    int numberOfCompany;
    cin >> numberOfCompany;
    
    EmpWageBuilder *emp[numberOfCompany];
    
    for(int iterator_company = 0; iterator_company < numberOfCompany; iterator_company++)
    {
        if (iterator_company > 0)
        {
            cout << "Enter Next New Company Details" << endl;
        }
        
        cout << "Enter Company Name: " << endl;
        string companyName;
        cin >> companyName;
        cout << "Enter Wage Per Hour: " << endl;
        int wagePerHr;
        cin >> wagePerHr;
        cout << "Enter Number Of Working Days In A Month: " << endl;
        int numberOfWorkingDaysInMonth;
        cin >> numberOfWorkingDaysInMonth;
        cout << "Enter Maximum Hours For A Month: " << endl;
        int maxHoursInMonth;
        cin >> maxHoursInMonth;
        
        emp[iterator_company] = new EmpWageBuilder(companyName, wagePerHr, numberOfWorkingDaysInMonth, maxHoursInMonth);
    }

    CompanyEmpWage companyEmpWage;
    
    for(int calculateForEach = 0; calculateForEach < numberOfCompany; calculateForEach++)
        companyEmpWage.calculateMonthWage(*emp[calculateForEach]);
    
    companyEmpWage.showSavedWage();
}

int main()
{
    constructEmployeeWage();
    return 0;
}