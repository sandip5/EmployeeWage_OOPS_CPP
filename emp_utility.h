#include "CompanyEmpWage.h"

using namespace std;

namespace emp_std
{
    void displayCompanyWages(company_emp_wage::CompanyEmpWage companyEmpWage)
    {
        for(emp_model_spc::EmpWageBuilder it : companyEmpWage.getSavedDetails())
	    {
		    cout << it.getCompanyName() << ", Total Wage : " << it.getTotalWage() << endl; 
	    }
    }

    void searchTotalWage(company_emp_wage::CompanyEmpWage companyEmpWage, string companyName)
    {
        int companyTotalWage = 0;
	    for(emp_model_spc::EmpWageBuilder it : companyEmpWage.getSavedDetails())
	    {
		    if(it.getCompanyName() == companyName)
		    {
			    companyTotalWage =companyTotalWage + it.getTotalWage();
		    }
	    }

	    cout << "Company Total Wage Of All Employees: " << companyTotalWage << endl;
    }
}