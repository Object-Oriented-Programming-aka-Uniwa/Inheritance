#include "Student.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <exception>

using namespace std;

Student::Student (const char *Mat, string name, unsigned int sem, vector <Course *> &dec_subs, vector <pair<Course *, float>> &passed_subs)
{
    int i, j;
    try
    {
        Id = new char [strlen (Mat) + 1];
        strcpy (Id, Mat);
        Name = name;
        Semester = sem;
        for (i = 0; i < dec_subs.size (); i++)
            Declared_Subs.push_back (dec_subs[i]);
        for (j = 0; j < passed_subs.size (); j++)
            Passed_Subs.push_back (passed_subs[j]);
    }
    catch (bad_alloc x)
    {
        cout << "Memory allocation problem" << endl;
        exit (1);
    }
}

Student::Student (const Student &st)
{
    int i, j;
    try
    {
        Id = new char [strlen (st.Id) + 1];
        strcpy (Id, st.Id);
        Name = st.Name;
        Semester = st.Semester;
        for (i = 0; i < st.Declared_Subs.size (); i++)
            Declared_Subs.push_back (st.Declared_Subs[i]);
        for (j = 0; j < st.Passed_Subs.size (); j++)
            Passed_Subs.push_back (st.Passed_Subs[j]);
    }
    catch (bad_alloc x)
    {
        cout << "Memory allocation problem" << endl;
        exit (1);
    }
}

Student::~Student ()
{
    delete [] Id;
}

void Student::Set_Id (const char *Mat)
{
    if (Id != NULL)
        delete [] Id;
    
    try
    {
        Id = new char [strlen (Mat) + 1];
        strcpy (Id, Mat);
    }
    catch (bad_alloc x)
    {
        cout << "Memory allocation problem" << endl;
        exit (1);
    }
}

void Student::Set_Name (string name)
{
    Name = name;
}

void Student::Set_Semester (unsigned int sem)
{
    Semester = sem;
}

void Student::Set_Declared_Subs (vector <Course *> &dec_subs)
{
    int i, j;
    for (i = 0; i < Declared_Subs.size (); i++)
    {
        Declared_Subs.pop_back ();
    }
    for (j = 0; j < dec_subs.size (); j++)
    {
        Declared_Subs.push_back (dec_subs[j]);
    }
}

void Student::Set_Passed_Subs (vector <pair<Course *, float>> &passed_subs)
{
    int i, j;
    for (i = 0; i < Passed_Subs.size (); i++)
    {
        Passed_Subs.pop_back ();
    }
    for (j = 0; j < passed_subs.size (); j++)
    {
        Passed_Subs.push_back (passed_subs[j]);
    }
}
    
char *Student::Get_Id () const
{
    return Id;
}

string Student::Get_Name () const
{
    return Name;
}

unsigned int Student::Get_Semester () const
{
    return Semester;
}

Course *Student::Get_Declared_Subs (int i) const
{
    return Declared_Subs[i];
}

Course *Student::Get_Passed_Sub (int i) const
{
    return Passed_Subs[i].first;
}

float Student::Get_Passed_Grade (int i) const
{
    return Passed_Subs[i].second;
}

int Student::Get_Size_Declared_Subs () const
{
    return Declared_Subs.size ();
}

int Student::Get_Size_Passed_Subs () const
{
    return Passed_Subs.size ();
}

Student Student::operator+= (Course *st)
{
    Declared_Subs.push_back (st);
    return *this;
}

Student Student::operator= (const Student &st)
{
    int i = 0;
    int j = 0;
    int k, l;    
    
    if (&st == this)
            return *this;
    try
    {
        delete [] Id;
        Id = new char [strlen (st.Id) + 1];
        strcpy (Id, st.Id);
        Name = st.Name;
        Semester = st.Semester;
        while (i < Declared_Subs.size ())
            Declared_Subs.erase (Declared_Subs.begin () + i);
        while (j < Passed_Subs.size ())
            Passed_Subs.erase (Passed_Subs.begin () + j);
        for (k = 0; k < st.Declared_Subs.size (); k++)
            Declared_Subs.push_back (st.Declared_Subs[k]);
        for (l = 0; l < st.Passed_Subs.size (); l++)
            Passed_Subs.push_back (st.Passed_Subs[l]);
        
        return *this;
    }
    catch (bad_alloc x)
    {
        cout << "Memory allocation problem" << endl;
        exit (1);
    }
}
    
    

bool Student::operator== (const Student &st)
{
    if (Semester == st.Semester)
        return true;
    return false;
}

bool Student::operator!= (const Student &st)
{
    if (Semester != st.Semester)
        return true;
    return false;
}

bool Student::operator< (const Student &st)
{
    if (Semester < st.Semester)
        return true;
    return false;
}

bool Student::operator<= (const Student &st)
{
    if (Semester <= st.Semester)
        return true;
    return false;
}

bool Student::operator> (const Student &st)
{
    if (Semester > st.Semester)
        return true;
    return false;
}

bool Student::operator>= (const Student &st)
{
    if (Semester >= st.Semester)
        return true;
    return false;
}

void Student::Fill_Passed_Subs ()
{
    int i = 0;
    while (i < Passed_Subs.size ())
    {
        try
        {
            if (Passed_Subs[i].second < 5.0f || Passed_Subs[i].second > 10.0f)
                throw i;
            i++;
        }
        catch (int j)
        {
            Passed_Subs.erase (Passed_Subs.begin () + j);
        }
    }
}

float Student::Grades_Average ()
{
    float avg = 0.0f;
    float sum = 0.0f;
    int i;
    for (i = 0; i < Passed_Subs.size (); i++)
        sum = sum + Passed_Subs[i].second;
    avg = sum / static_cast <float> (Passed_Subs.size ());
    
    return avg;
}

void Student::File_Grades (string filename, Student &st)
{
    ofstream Grades_Student;
    try
    {
        Grades_Student.open (filename);
        if (!Grades_Student.is_open ())
            throw Id;
        else
        {
            Grades_Student << st;
            Grades_Student.close ();
        }
    }
    catch (char *id)
    {
        cout << "Problem opening the file for the student's grades with ID : " << id << endl;
        exit (1);
    }
}

ostream &operator<< (ostream &C1, Student &S1)
{
    int i, j;
    C1 << "______________________________________________________________________________________________" << endl;
    C1 << "STUDENT INFORMATION" << endl;
    C1 << "______________________________________________________________________________________________" << endl;
    C1 << "First Name" << "     " << "Last Name" << "   " << "ID" << " " << " Semester" << endl << "Student" << "   " << "Student" << "   " << "ID" << " " << " Student" << endl;
    C1 << "-------------------------------------------------------------------------" << endl;
    C1 << S1.Get_Name () << " " << S1.Get_Id () << " " << S1.Get_Semester () << endl << endl;
    C1 << "______________________________________________________________________________________________" << endl;
    C1 << "DECLARED COURSES" << endl;
    C1 << "______________________________________________________________________________________________" << endl;
    C1 << "Course Code" << "   " << "Title" << "                            " << "Semester" << "   " << endl << "Course" << " " << "Title" << "                          " << "Course" << " " <<  endl;
    C1 << "-------------------------------------------------------------------------" << endl << endl; 
    for (i = 0; i < S1.Get_Size_Declared_Subs (); i++)
        C1 << S1.Get_Declared_Subs (i) << endl;
    C1 << endl;
    C1 << "____________________________________________________________________________________________" << endl;
    C1 << "PASSED COURSES" << endl;
    C1 << "____________________________________________________________________________________________" << endl;
    C1 << "Course Code" << "   " << "Title" << "                            " << "Semester" << "   " << "Grade" << endl << "Course" << " " << "Title" << "                          " << "Course" << " " << "Course" << endl;
    C1 << "-------------------------------------------------------------------------" << endl;
    for (j = 0; j < S1.Get_Size_Passed_Subs (); j++)
        C1 << S1.Get_Passed_Sub (j)  << "         " << S1.Get_Passed_Grade (j) << endl;
    C1 << "-------------------------------------------------------------------------" << endl;
    C1 << "Grade Average                                             " << S1.Grades_Average () << endl << endl;

    return C1;
}

ostream &operator<< (ostream &C1, Course *Sub)
{
    C1 << Sub->Get_Code () << " " << Sub->Get_Subject () << " " << Sub->Get_Sem ();
    
    return C1;
}
