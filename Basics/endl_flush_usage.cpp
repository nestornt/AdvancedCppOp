#include <iostream>
#include <iomanip>
#include <cstring>
#include <chrono>

using namespace std::chrono;

class Corporation {
public:
    int id;
    int pay;
    int elig_raise;
    std::string name;
    std::string jobc;
    char hire[3];
};

int main() {
    Corporation emp;
    emp.id = 1;
    emp.pay = 30000;
    emp.elig_raise = 5000;
    emp.name = "brand";
    emp.jobc = "sales";
    strcpy(emp.hire, "Yes");

    /* SECTION 1  --------------------------------------------------- */
    auto start = high_resolution_clock::now();

    //! This isn´t efficient
    std::cout << "Employee ID:  " << emp.id   << std::endl
              << "Name:         " << emp.name << std::endl
              << "Job Category: " << emp.jobc << std::endl
              << "Hire date:    " << emp.hire << std::endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop-start);

    std::cout << "The first section with multiple endl took: " << duration.count()
              << " nanoseconds" << '\n' << std::flush;
    
    /* SECTION 2  --------------------------------------------------- */
    start = high_resolution_clock::now();

    //! This are efficient ways
    std::cout << "Employee ID:  " << emp.id  
              << "\nName:         " << emp.name
              << "\nJob Category: " << emp.jobc
              << "\nHire date:    " << emp.hire << std::endl;

    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop-start);

    std::cout << "The second section took: " << duration.count()
              << " nanoseconds" << '\n' << std::flush;

    // You can include the new-line character as the start of the
    // character string that immediately follows the location where
    // the endl manipulator would have been placed, or as a separate
    // character enclosed in single quotation marks:
    std::cout << "Salary:       " << emp.pay        << '\n'
              << "Next raise:   " << emp.elig_raise << std::endl;
              
    return 0;
}

//! Flushing a stream generally involves a high overhead. If you are
//! concerned about performance, only flush a stream when necessary