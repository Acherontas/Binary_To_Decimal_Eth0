#include "order_them.h"
#include <list>
#include <vector>
#include <iostream>
using namespace std;
order_them::order_them(){}//ctor
order_them::~order_them(){}//dtor
order_them::order_them(const order_them& other){}//copy ctor
order_them& order_them::operator=(const order_them& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

int order_them::x_order(int sbs,int mini,int maxi){
    cout<<"using space " << sbs <<"\n";
    int tbl[sbs];
    for(int i=0;i<=sbs-1;i++){tbl[i]=myvls.at(i);}
    int lsti=sbs;
    cout<<"---------------------------------------------------------\n";
    for(int i=0;i<=lsti-1;i++){cout<<"@pos " << i << " with value " << tbl[i] <<"\n";}
    cout<<"---------------------------------------------------------\n";
    int mvm=0;
    int lst=sbs-1;
    int minn;
    int maxx;
    minn=tbl[0];
    maxx=tbl[0];
    int newtbl[sbs];
    int ntb_s=0;
    int ntb_n=sbs-1;
    int tss=0;
    int loc_s=0;
    int loc_n=0;
    int lx=0;
    for(;;){lx=0;
    //cout<<"using minn " << minn << " and maxx " << maxx <<"\n";
    for(int i=0;i<=lst;i++){
       if(tbl[i]<=minn && tbl[i]!=0){minn=tbl[i];loc_s=i;
      // cout<<"setting minn " << minn << " with " << tbl[i] <<"\n";
       }
       if(tbl[i]>=maxx && tbl[i]!=0){maxx=tbl[i];loc_n=i;
       //cout<<"setting maxx "<< maxx << " with " << tbl[i] <<"\n";
       }
    }
    tbl[loc_s]=0;
    tbl[loc_n]=0;
    tss+=1;
    if(ntb_s<ntb_n){
    //cout<<"min " << minn << " and max " << maxx <<"\n";
    newtbl[ntb_s]=minn;
   // cout<<"so far " << newtbl[ntb_s] <<" @ pos " << ntb_s <<" ";
    ntb_s+=1;
    newtbl[ntb_n]=maxx;
    //cout<<"with " << newtbl[ntb_n] << " @ pos " << ntb_n <<"\n";
    ntb_n-=1;
    }
    if(minn==maxx){newtbl[ntb_s]=minn; goto A;}
    if(ntb_s==ntb_n){newtbl[ntb_s]=minn;goto A;}
    A:
    //if(ntb_s>ntb_n){goto A;}
    //cout<<"----------------------------------------\n";
    //selecting some random without using random or pseudorandom and avoiding zero using 1 time to avoid same number
    for(int i=0;i<=lst;i++){
      // cout<<i << " with value " << tbl[i] << " \n" ;
       if(i!=loc_s && tbl[i]!=0 && lx<=2){minn=tbl[i];loc_s=i;lx=1;} //lx<=2
       if(i!=loc_n && tbl[i]!=0 && lx<=2){maxx=tbl[i];loc_n=i;lx=2;} //lx<=2 without tbl[i]!=minn
       //if(lx==2){break;} //remove this
    }
    //cout<<"----------------------------------------\n";
    if(tss==lst){cout<<"breaking\n";break;}
    }
    for(int i=0;i<=lst;i++){
   // cout<<i << " with value " << newtbl[i] << " \n" ;
    rd_vls.push_back(newtbl[i]);
    }
  return 0;
}

int order_them::loop_them(int mvm){
    return 0;
}
