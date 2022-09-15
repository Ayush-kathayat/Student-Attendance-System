#include<iostream>
#include<fstream>
#include <vector>
#include<string>
#include <unordered_set>


class studentsAttendanceSystem {
private:
    std::ifstream& students;
    std::ifstream& attendance;
    std::unordered_set <std::string> attendanceSet;
    std::string output;
private:
    void generateAttendanceSet () {
        std::string tmp;
        while (std::getline (attendance, tmp))
        {
            attendanceSet.insert (tmp);
        }
    }
    void calculateOutput () {
        std::string tmp;
        while (std::getline (students, tmp))
        {
            if (attendanceSet.find (tmp) != attendanceSet.end ()) {
                output += tmp + " present\n";
            }
            else {
                output += tmp + " absent\n";
            }
        }
    }
public:
    studentsAttendanceSystem () = delete;
    studentsAttendanceSystem (std::ifstream& students, std::ifstream& attendance)  // we have recieved the stream here by reference so it will not copy the stream cause copy is a 
        : students (students), attendance (attendance) 
        {
            generateAttendanceSet (); 
            calculateOutput ();
        }
    std::string getOutput () {
        return output;
    }
};

int main(int argv , char* args[])
{
    std::ifstream students (args[1]);
    std::ifstream attendance (args[2]);   // attendence file 

    std::ofstream output ("./result.txt");

    std::string out = studentsAttendanceSystem(students, attendance).getOutput ();   // rvalue will not be converted to the lvalue 
    // we are directly getting our output through 
    // by using the rvalue reference

    
    output << out;

    students.close ();
    attendance.close ();
    output.close ();

    return 0;
}