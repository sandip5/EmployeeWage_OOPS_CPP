#include "CompanyEmpWage.h"

using namespace std;

namespace emp_std
{
    void displayCompanyWages(vector<emp_model_spc::EmpWageBuilder> companies)
    {
        for(emp_model_spc::EmpWageBuilder it : companies)
	    {
		    cout << it.getCompanyName() << ", Total Wage : " << it.getTotalWage() << endl; 
	    }
    }

    void searchTotalWage(vector<emp_model_spc::EmpWageBuilder> companies)
    {
        int companyTotalWage = 0;
	    cout << "================ Searching Result When We Input Company Name Provide Total Wage ===============" << endl;
        string companyName;
        cout << "Enter Company Name: " << endl;
        cin >> companyName;

	    for(emp_model_spc::EmpWageBuilder it : companies)
	    {
		    if(it.getCompanyName() == companyName)
		    {
			    companyTotalWage =companyTotalWage + it.getTotalWage();
		    }
	    }

	    cout << "Company Total Wage Of All Employees: " << companyTotalWage << endl;
    }
}