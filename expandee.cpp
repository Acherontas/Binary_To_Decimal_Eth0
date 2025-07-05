#include "expandee.h"
#include <vector>
#include <thread>
expandee::expandee(){}//ctor

expandee::~expandee(){}//dtor

expandee::expandee(const expandee& other){} //copy ctor

expandee& expandee::operator=(const expandee& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string cnvte;
int expandee::cnv_to_sting(int value_one,int value_two,int value_three,int value_four){
//cout<<"cnv " << value_one;
cnvte.clear();
//if(cnvt.size()-1>0){cnvt.clear();}
cnvte+=to_string(value_one);
cnvte+=".";
cnvte+=to_string(value_two);
cnvte+=".";
cnvte+=to_string(value_three);
cnvte+=".";
cnvte+=to_string(value_four);
return 0;
}

int expandee::prkl(int begingw[],int firste[],int laste[],int bde[]){
cout<<"Network is " << cnvte <<" \n";
//firste       -- laste
//128.0.0.1    -- 255.255.255.254
//128.0.0.1 -- 128.0.0.255
//128.0.1.0 -- 128.0.1.255
//128.0.2.0 -- 128.0.2.255
//128.1.0.0 -- 128.1.255.255
//128.2.0.0 -- 128.2.255.255

//firste[0][3] -- laste[0][3]
vector<int> frt;
vector<int> scd;
vector<int> thr;
vector<int> fur;

int i=0,j=0,k=0,u=0;int yu=0;
for(i=0;i<=255;i++){j=0;
  for(j=0;j<=255;j++){k=0;
    for(k=0;k<=255;k++){u=0;
     for(u=0;u<=255;u++){
       if(u<=254){
          frt.push_back(firste[0]+i);scd.push_back(firste[1]+j);thr.push_back(firste[2]+k);fur.push_back(firste[3]+u);
          //std::this_thread::sleep_for(std::chrono::milliseconds(10));
       }

       if(firste[0]+i==bde[0] && firste[1]+j==bde[1] && firste[2]+k==bde[2] && firste[3]+u==bde[3]){goto R;}
   }//E:cout<<"";
  }
 }
}
R:cout<<"End";

int cnt=0;
for(int l=0;l<=frt.size()-1;l++){
if(cnt%1==0){cout<<"\n";}
cout<<" "<<frt.at(l)<<"."<<scd.at(l)<<"."<<thr.at(l)<<"."<<fur.at(l)<<" ";
std::this_thread::sleep_for(std::chrono::milliseconds(50));
cnt+=1;
}
return 0;
}




