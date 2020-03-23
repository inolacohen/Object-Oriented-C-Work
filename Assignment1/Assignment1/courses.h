
#ifndef courses_h
#define courses_h
using namespace std;

class Course
{
private:
    string title;
    int units;
    char grade;
    
public:
    Course() {}
    Course(string t, int u, char g)
    {
        title = t;
        units = u;
        grade = g;
    }
    void setTitle(string);
    string getTitle();
    void setUnits(int);
    int getUnits();
    void setGrade(char);
    char getGrade();
    void edit(Course*[], int);
    void displayGPA(Course*[], int);
    ~Course();
};
#endif /* courses_h */
