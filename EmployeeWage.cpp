#include <ctime>
#include <unistd.h>
#include "emp_utility.h"

using namespace company_emp_wage;

CompanyEmpWage takeUserInput()
{
    cout << "Enter Number Of Company You Want To Add: " << endl;
    int numberOfCompany;
    cin >> numberOfCompany;
    
    emp_model_spc::EmpWageBuilder *emp[numberOfCompany];
    
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
        
        emp[iterator_company] = new emp_model_spc::EmpWageBuilder(companyName, wagePerHr, numberOfWorkingDaysInMonth, maxHoursInMonth);
    }

    CompanyEmpWage companyEmpWage;
    
    for(int calculateForEach = 0; calculateForEach < numberOfCompany; calculateForEach++)
        companyEmpWage.calculateMonthWage(*emp[calculateForEach]);

    return companyEmpWage;
}

void presentEmpWageComputation()
{
    cout << "Hello Welcome To Employee Wage Computation Problem" << endl;
    
    CompanyEmpWage companyEmpWage = takeUserInput();
    
    emp_std::displayCompanyWages(companyEmpWage.getSavedDetails());
    
    emp_std::searchTotalWage(companyEmpWage.getSavedDetails());
}

int main()
{
    presentEmpWageComputation();
    return 0;
}