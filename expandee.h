#ifndef EXPANDEE_H
#define EXPANDEE_H
#include <string>
#include "string.h"
#include <iostream>
using namespace std;
class expandee
{
    public:
        int tmp_cnvt[4];
        int num_of_users=0;
        int firstt=0;
        int fomt=0;
        int fodt=0;
        int lastt=0;
        expandee();
        virtual ~expandee();
        expandee(const expandee& other);
        expandee& operator=(const expandee& other);
        int prkl(int begingw[],int firste[],int laste[],int bde[]);
        int cnv_to_sting(int value_one,int value_two,int value_three,int value_four);
    protected:

    private:
};

#endif // EXPANDEE_H
