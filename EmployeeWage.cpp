#include <ctime>
#include <unistd.h>
#include "emp_utility.h"

using namespace company_emp_wage;

struct CompanyInitialInfo
{
    string companyName;
    int wagePerHr;
    int numberOfWorkingDaysInMonth;
    int maxHoursInMonth;
};

void presentEmpWageComputation();
CompanyInitialInfo takeUserInput();

int main()
{
    presentEmpWageComputation();
    return 0;
}

void presentEmpWageComputation()
{
    cout << "Hello Welcome To Employee Wage Computation Problem" << endl;

    CompanyEmpWage companyEmpWage;

    enum optionCategory
    {
        REGISTER_COMPANY,
        CALCULATE_WAGE,
        DISPLAY,
        SEARCH_TOTAL_WAGE,
        EXIT
    };

    bool isStart = false;

    while (!isStart)
    {
        cout << "Select Operation Which You Want To Perform:\n1. Register Company Details..."
             << "\n2. Calculate Wage For Company By Company Name...\n3. Display Wages Of All Company..."
             << "\n4. Search Total Wage By Company Name...\n5. Exit" << endl;
        int selectedOption;
        cin >> selectedOption;

        switch (selectedOption - 1)
        {
            case optionCategory::REGISTER_COMPANY:
            {
                cout << "Enter Number Of Company You Want To Add: " << endl;
                int numberOfCompany;
                cin >> numberOfCompany;
                
                CompanyInitialInfo initialInfo[numberOfCompany];
                
                for(int iterator_company = 0; iterator_company < numberOfCompany; iterator_company++)
                {
                    if (iterator_company > 0)
                    {
                        cout << "Enter Next New Company Details" << endl;
                    }

                    initialInfo[iterator_company] = takeUserInput();
                    companyEmpWage.saveDetails(emp_model_spc::EmpWageBuilder
                        (initialInfo[iterator_company].companyName, 
                        initialInfo[iterator_company].wagePerHr, 
                        initialInfo[iterator_company].numberOfWorkingDaysInMonth, 
                        initialInfo[iterator_company].maxHoursInMonth));
                }    
                break;
            }
            case optionCategory::CALCULATE_WAGE:
            {
                string calculateByName;
                cout << "Enter Valid Company Name For Which You Want to Calulate Wage: " << endl;
                cin >> calculateByName;
                companyEmpWage.calculateMonthWage(calculateByName);
                break;
            }
            case optionCategory::DISPLAY:
            {
                emp_std::displayCompanyWages(companyEmpWage);
                break;
            }
            case optionCategory::SEARCH_TOTAL_WAGE:
            {
                cout << "Enter Company Name: " << endl;
                string companyName;
                cin >> companyName;
                emp_std::searchTotalWage(companyEmpWage, companyName);
                break;
            }
            case optionCategory::EXIT:
            {
                isStart = true;
                break;
            }
            default:
                cout << "Please Enter Valid Input..." << endl; 
                break;
        }
    }
}

CompanyInitialInfo takeUserInput()
{
    CompanyInitialInfo companyInitialInfo;

    cout << "Enter Company Name: " << endl;
    cin >> companyInitialInfo.companyName;

    cout << "Enter Wage Per Hour: " << endl;
    cin >> companyInitialInfo.wagePerHr;

    cout << "Enter Number Of Working Days In A Month: " << endl;
    cin >> companyInitialInfo.numberOfWorkingDaysInMonth;

    cout << "Enter Maximum Hours For A Month: " << endl;
    cin >> companyInitialInfo.maxHoursInMonth;

    return companyInitialInfo;
}
