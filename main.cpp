#include <iostream>
#include <iomanip>
using namespace std;

class CGPACalculator
{
private:
    int numCourses;
    string courseName[100];
    float grade[100], credit[100];
    float totalCredits = 0, totalGradePoints = 0, sgpa = 0;

public:
    void calculateSGPA()
    {
        totalCredits = 0;
        totalGradePoints = 0;

        cout << "\nEnter Number of Courses: ";
        cin >> numCourses;

        for (int i = 0; i < numCourses; i++)
        {
            cout << "\nCourse " << i + 1 << endl;

            cout << "Enter Course Name: ";
            cin >> courseName[i];

            cout << "Enter Grade Point: ";
            cin >> grade[i];

            cout << "Enter Credit Hours: ";
            cin >> credit[i];

            totalCredits += credit[i];
            totalGradePoints += grade[i] * credit[i];
        }

        sgpa = totalGradePoints / totalCredits;

        cout << "\nCourse Details\n";
        cout << left << setw(15) << "Course"
             << setw(10) << "Grade"
             << setw(10) << "Credits" << endl;

        for (int i = 0; i < numCourses; i++)
        {
            cout << left << setw(15) << courseName[i]
                 << setw(10) << grade[i]
                 << setw(10) << credit[i] << endl;
        }

        cout << "\nTotal Credits: " << totalCredits;
        cout << "\nSemester GPA: " << fixed << setprecision(2) << sgpa << endl;
    }

    void calculateCGPA()
    {
        if (totalCredits == 0)
        {
            cout << "\nPlease calculate Semester GPA first.\n";
            return;
        }

        float previousCGPA, previousCredits;

        cout << "\nEnter Previous CGPA: ";
        cin >> previousCGPA;

        cout << "Enter Previous Total Credits: ";
        cin >> previousCredits;

        float overallCGPA = ((previousCGPA * previousCredits) + totalGradePoints) /
                            (previousCredits + totalCredits);

        cout << "\nOverall CGPA: " << fixed << setprecision(2) << overallCGPA << endl;
    }
};

int main()
{
    CGPACalculator obj;
    int choice;

    do
    {
        cout << "\n1. Calculate Semester GPA" << endl;
        cout << "2. Calculate Overall CGPA" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.calculateSGPA();
            break;

        case 2:
            obj.calculateCGPA();
            break;

        case 3:
            cout << "Thank You!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}