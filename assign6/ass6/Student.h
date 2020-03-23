
#ifndef Student_h
#define Student_h
#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    string ID;
    int units;
    double gpa;
    
public:
    
    Student(string n = " ", string I = " ", int u = 0, double GPA = 0.00) {          // default constructor
        name = n;
        ID = I;
        units = u;
        gpa = GPA;
    }
    Student(const Student &s) {                       // copy constructor
        name = s.name;
        ID = s.ID;
        units = s.units;
        gpa = s.gpa;
    };
    friend istream &operator>> (istream &in, Student &s);
    friend ostream &operator<< (ostream &out, const Student &s);          //prints student info
    //Student& operator=(Student &s);
    virtual void read();
    void set(string, string, int, double);
    virtual void print();
    string getName();
    double getGPA();
    //double averageGPA(int, Student*[]);
    ~Student() {};
};

class StuWorker : public Student {
private:
    int hours;
    double hourlyRate;
    
public:
    StuWorker(int h = 0, double rate = 0.00) {                    //default constructor
        hours = h;
        hourlyRate = rate;
    }
    StuWorker(const StuWorker &sw) {                             // copy constructor
        hours = sw.hours;
        hourlyRate = sw.hourlyRate;
    }
    void set(int, double);
    //StuWorker& operator=( StuWorker &sw);
    void read();
    void print();
    ~StuWorker() {};
};

#endif /* Student_h */
