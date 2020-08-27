#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace emp_std
{
    void displayCompanyWages(vector<EmpWageBuilder> companies)
    {
        for(EmpWageBuilder it : companies)
	    {
		    cout << it.getCompanyName() << ", Total Wage : " << it.getTotalWage() << endl; 
	    }
    }

    void searchTotalWage(vector<EmpWageBuilder> companies)
    {
        int companyTotalWage = 0;
	    cout << "================ Searching Result When We Input Company Name Provide Total Wage ===============" << endl;
        string companyName;
        cout << "Enter Company Name: " << endl;
        cin >> companyName;

	    for(EmpWageBuilder it : companies)
	    {
		    if(it.getCompanyName() == companyName)
		    {
			    companyTotalWage =companyTotalWage + it.getTotalWage();
		    }
	    }

	    cout << "Company Total Wage Of All Employees: " << companyTotalWage << endl;
    }
}