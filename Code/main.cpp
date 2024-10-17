#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

int main (int argc, char **argv)
{
    Course Crs1 ("1004     ", "Computer Programming               ", 1);
    Course Crs2 ("1005     ", "Mathematical Analysis I            ", 1);
    Course Crs3 ("1006     ", "Linear Algebra                    ", 1);
    Course Crs4 ("2003     ", "Mathematical Analysis II           ", 2);
    Course Crs5 ("2004     ", "Object-Oriented Programming        ", 2);
    Course Crs6 ("2006     ", "Circuit Theory                    ", 2);
    Course Crs7 ("3001     ", "Algorithms and Complexity          ", 3);
    Course Crs8 ("3004     ", "Computer Networks I               ", 3);
    Course Crs9 ("3005     ", "Operating Systems I               ", 3);
    Course Crs10 ("4003     ", "Operating Systems II              ", 4);
    Course Crs11 ("4006     ", "Signals and Systems               ", 4);
    Course Crs12 ("4007     ", "Technical Writing                 ", 4);
    Course Crs13 ("5002     ", "Network Programming               ", 5);
    Course Crs14 ("5004     ", "Artificial Intelligence           ", 5);
    Course Crs15 ("5005     ", "Digital Signal Processing         ", 5);
    Course Crs16 ("6001     ", "Software Engineering              ", 6);
    Course Crs17 ("6003     ", "Compilers                         ", 6);
    Course Crs18 ("6004     ", "Microelectronics                  ", 6);

    vector <Course *> v1_Dec = {&Crs16, &Crs17, &Crs18};
    vector <pair<Course *, float>> v1_Pass = {make_pair (&Crs1, 8.2f), make_pair (&Crs2, 7.0f), make_pair (&Crs3, 7.0f), make_pair (&Crs4, 5.0f), make_pair (&Crs5, 2.0f), make_pair (&Crs6, 5.0f), make_pair (&Crs7, 1.0f), make_pair (&Crs8, 6.7f), make_pair (&Crs9, 9.5f), make_pair (&Crs10, 5.5f), make_pair (&Crs11, 7.4f), make_pair (&Crs12, 5.0f), make_pair (&Crs13, 4.9f), make_pair (&Crs14, 6.2f), make_pair (&Crs15, 3.5f)};

    vector <Course *> v2_Dec = {&Crs10, &Crs11, &Crs12, &Crs14};
    vector <pair<Course *, float>> v2_Pass = {make_pair (&Crs1, 5.2f), make_pair (&Crs2, 6.0f), make_pair (&Crs3, 1.0f), make_pair (&Crs4, 7.8f), make_pair (&Crs5, 5.0f), make_pair (&Crs6, 4.0f), make_pair (&Crs7, 5.5f), make_pair (&Crs8, 10.0f), make_pair (&Crs9, 8.5f)};

    vector <Course *> v3_Dec = {&Crs10, &Crs11, &Crs12, &Crs17, &Crs18};
    vector <pair<Course *, float>> v3_Pass = {make_pair (&Crs1, 0.2f), make_pair (&Crs2, 8.0f), make_pair (&Crs3, 5.0f), make_pair (&Crs4, 7.5f), make_pair (&Crs5, 0.0f), make_pair (&Crs6, 5.5f), make_pair (&Crs7, 0.0f), make_pair (&Crs8, 7.0f), make_pair (&Crs9, 4.5f)};

    vector <Course *> v4_Dec = {&Crs4, &Crs5, &Crs6, &Crs7, &Crs8, &Crs11, &Crs12};
    vector <pair<Course *, float>> v4_Pass = {make_pair (&Crs1, 6.5f), make_pair (&Crs2, 5.0f), make_pair (&Crs3, 5.5f), make_pair (&Crs4, 6.5f), make_pair (&Crs5, 1.5f), make_pair (&Crs6, 4.0f)};

    Student S1 ("19390005", "Vasileios Athanasiou", 6, v1_Dec, v1_Pass);
    Student S2 ("20390134", "Evangelia Oikonomou", 4, v2_Dec, v2_Pass);
    Student S3 ("20390001", "Athanasios Angelidis", 4, v3_Dec, v3_Pass);
    Student S4 ("21390024", "Georgios Georgiadis", 2, v4_Dec, v4_Pass);
    Student S5 (S1);
    Student S6 ("18390244", "Theofanis Floisvos", 8, v1_Dec, v1_Pass);

    S6 = S2;

    S1.Fill_Passed_Subs(); 
    S2.Fill_Passed_Subs(); 
    S3.Fill_Passed_Subs();
    S4.Fill_Passed_Subs();
    S6.Fill_Passed_Subs();

    cout << S1;
    cout << "************************************************************************************************************************" << endl << endl;
    cout << S2;
    cout << "************************************************************************************************************************" << endl << endl;
    cout << S3;
    cout << "************************************************************************************************************************" << endl << endl;
    cout << S4;
    cout << "************************************************************************************************************************" << endl << endl;
    cout << S6;
    cout << "************************************************************************************************************************" << endl << endl;
/********** Using the "+=" operator to add courses to the student's declared courses vector.
            The updated list of declared courses for each student is stored in the respective file (lines 87-91),
            while the cout displays the list of declared courses before additions are made (lines 69-72). **********/
    S2 += &Crs13;
    S2 += &Crs16;
    S3 += &Crs16;
    S6 += &Crs15;

    if (S1 > S2)
        cout << "Student \"" << S1.Get_Name () << "\" is in a higher semester (" << S1.Get_Semester () << ") than student \"" << S2.Get_Name () << "\" (" << S2.Get_Semester () << ")." << endl;
    if (S6 < S2)
        cout << "Student \"" << S6.Get_Name () << "\" is in a lower semester (" << S6.Get_Semester () << ") than student \"" << S2.Get_Name () << "\" (" << S2.Get_Semester () << ")." << endl;
    if (S2 == S3)
        cout << "Student \"" << S2.Get_Name () << "\" is in the same semester (" << S2.Get_Semester () << ") as student \"" << S3.Get_Name () << "\" (" << S3.Get_Semester () << ")." << endl;
    if (S1 != S3)
        cout << "Student \"" << S1.Get_Name () << "\" is not in the same semester (" << S1.Get_Semester () << ") as student \"" << S2.Get_Name () << "\" (" << S2.Get_Semester () << ")." << endl;
    if (S1 >= S6)
        cout << "Student \"" << S1.Get_Name () << "\" is in a higher or equal semester (" << S1.Get_Semester () << ") as student \"" << S6.Get_Name () << "\" (" << S6.Get_Semester () << ")." << endl;
    if (S3 <= S2)
        cout << "Student \"" << S3.Get_Name () << "\" is in a lower or equal semester (" << S3.Get_Semester () << ") as student \"" << S2.Get_Name () << "\" (" << S2.Get_Semester () << ")." << endl;

    S1.File_Grades ("Grades-19390005.txt", S1);
    S2.File_Grades ("Grades-20390134.txt", S2);
    S3.File_Grades ("Grades-20390001.txt", S3);
    S4.File_Grades ("Grades-19390005-Copy.txt", S4);
    S6.File_Grades ("Grades-20390134-Copy.txt", S6);

    return 0;
}
