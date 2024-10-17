#include "Course.h"

using namespace std;

Course::Course (string code, string name, unsigned int sem)
{
    Code = code;
    Subject = name;
    Sem = sem;
}

void Course::Set_Code (string code)
{
    Code = code;
}

void Course::Set_Subject (string sub)
{
    Subject = sub;
}
 
void Course::Set_Sem (unsigned int sem)
{
    Sem = sem;
}
 
string Course::Get_Code () const
{
    return Code;
}

string Course::Get_Subject () const
{
    return Subject;
}
 
unsigned int Course::Get_Sem () const
{
    return Sem;
}
