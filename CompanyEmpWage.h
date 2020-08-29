#include <ctime>
#include <unistd.h>
#include "emp_model.h"

namespace company_emp_wage
{
    class CompanyEmpWage
    {
        private:
            vector<emp_model_spc::EmpWageBuilder> companiesList;
            vector<int> storeDayWage;

        public:
            int getEmployeeWorkingHours();
            int calculateDailyWage(int wagePerHr);
            void calculateMonthWage(string companyName);
            void saveDetails(emp_model_spc::EmpWageBuilder details);
            vector<emp_model_spc::EmpWageBuilder> getSavedDetails();
    };

    vector<emp_model_spc::EmpWageBuilder> CompanyEmpWage::getSavedDetails()
    {
        return companiesList;
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
        storeDayWage.push_back(dailyWage);
        return dailyWage;
    }

    void CompanyEmpWage::calculateMonthWage(string companyName)
    {
        int totalEmpHrs = 0;
        int totalWorkingDays = 0;
        int dailyWage = 0;
        int monthWage = 0;
        emp_model_spc::EmpWageBuilder* company;

        for(emp_model_spc::EmpWageBuilder &companyIterator : companiesList)
	    {
            if (companyIterator.getCompanyName() == companyName)
            {
                while( totalEmpHrs < companyIterator.getMaxHoursPerMonth() && totalWorkingDays < companyIterator.getMaxWorkingDayInMonth() )
                {
                    dailyWage = calculateDailyWage(companyIterator.getWagePerHr());
                    monthWage = monthWage + dailyWage;
                    totalWorkingDays++;
                    sleep(1);
                }
                
                companyIterator.setDailyWage(storeDayWage);
                companyIterator.setTotalWage(monthWage);
                cout << companyIterator.getCompanyName() << ", Monthly Wage Of Employee: " << monthWage << endl;
            }

	    }        
    }

    void CompanyEmpWage::saveDetails(emp_model_spc::EmpWageBuilder details)
    {
        companiesList.push_back(details);
    }
}