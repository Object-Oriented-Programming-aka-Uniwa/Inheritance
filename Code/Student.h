#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include <iostream>
#include <vector>

class Student
{
    private :
        char *Id;
        std::string Name;
        unsigned int Semester;
        std::vector <Course *> Declared_Subs;
        std::vector <std::pair<Course *, float>> Passed_Subs;
    public :
        Student (const char *, std::string, unsigned int, std::vector <Course *> &, std::vector <std::pair<Course *, float>> &);
        Student (const Student &);
       ~Student ();
        void Set_Id (const char *);
        void Set_Name (std::string);
        void Set_Semester (unsigned int);
        void Set_Declared_Subs (std::vector <Course *> &);
        void Set_Passed_Subs (std::vector <std::pair<Course *, float>> &);
        char *Get_Id () const;
        std::string Get_Name () const;
        unsigned int Get_Semester () const;
        Course *Get_Declared_Subs (int) const;
        Course *Get_Passed_Sub (int) const;
        float Get_Passed_Grade (int) const;
        int Get_Size_Declared_Subs () const;
        int Get_Size_Passed_Subs () const;
        Student operator+= (Course *);
        Student operator= (const Student &);
        bool operator== (const Student &);
        bool operator!= (const Student &);
        bool operator< (const Student &);
        bool operator<= (const Student &);
        bool operator> (const Student &);
        bool operator>= (const Student &);
        void Fill_Passed_Subs ();
        float Grades_Average ();
        void File_Grades (std::string, Student &);
};

std::ostream &operator<< (std::ostream &, Student &);
std::ostream &operator<< (std::ostream &, Course *);

#endif
