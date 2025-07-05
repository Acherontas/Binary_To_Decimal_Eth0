#ifndef STR_INT_STR_H
#define STR_INT_STR_H

#include <string>
#include <string.h>
using namespace std;

class Str_int_Str
{
    public:
        int num_zero,num_one,num_two,num_three;
        string returnme;
        int strtn=0;
        Str_int_Str();
        virtual ~Str_int_Str();
        Str_int_Str(const Str_int_Str& other);
        Str_int_Str& operator=(const Str_int_Str& other);
        string fnl_binary;
        int cnt=1;
        int pvt=0;
        int trn=1;
        int processit(int num,int tri);
        string returnstr();
        int process_of_string(string to_process);
        int prosfs=0;
    protected:

    private:
};

#endif // STR_INT_STR_H
