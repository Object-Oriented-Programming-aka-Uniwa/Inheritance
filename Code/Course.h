#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
    private :
        std::string Code;
        std::string Subject;
        unsigned int Sem;
    public :
        Course (std::string, std::string, unsigned int);
        void Set_Code (std::string);
        void Set_Subject (std::string);
        void Set_Sem (unsigned int);
        std::string Get_Code () const;
        std::string Get_Subject () const;
        unsigned int Get_Sem () const;
};

#endif
