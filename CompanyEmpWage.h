#include <ctime>
#include <unistd.h>
#include "emp_model.h"

namespace company_emp_wage
{
    class Company
    {
        virtual int getEmployeeWorkingHours() = 0;
        virtual int calculateDailyWage(int wagePerHr) = 0;
        virtual void calculateMonthWage(emp_model_spc::EmpWageBuilder details) = 0;
        virtual void saveDetails(emp_model_spc::EmpWageBuilder details) = 0;
        virtual vector<emp_model_spc::EmpWageBuilder> getSavedDetails() = 0;
    };

    class CompanyEmpWage : public Company
    {
        private:
            vector<emp_model_spc::EmpWageBuilder> companies;
            vector<int> storeDayWage;

        public:
            int getEmployeeWorkingHours();
            int calculateDailyWage(int wagePerHr);
            void calculateMonthWage(emp_model_spc::EmpWageBuilder details);
            void saveDetails(emp_model_spc::EmpWageBuilder details);
            vector<emp_model_spc::EmpWageBuilder> getSavedDetails();
    };

    vector<emp_model_spc::EmpWageBuilder> CompanyEmpWage::getSavedDetails()
    {
        return companies;
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

    void CompanyEmpWage::calculateMonthWage(emp_model_spc::EmpWageBuilder details)
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

        details.setDailyWage(storeDayWage);
        details.setTotalWage(monthWage);
        cout << details.getCompanyName() << ", Monthly Wage Of Employee: " << monthWage << endl;
        saveDetails(details);
    }

    void CompanyEmpWage::saveDetails(emp_model_spc::EmpWageBuilder details)
    {
        companies.push_back(details);
    }
}