#include "masks.h"
#include <iostream>
#include <chrono>
#include <string>
#include <string.h>
#include <thread>
#include "bin_to_dec.h"
#include "str_int_str.h"
#include "start_of.h"
#include <vector>
using namespace std;

masks::masks(){} //ctor
masks::~masks(){}//dtor
masks::masks(const masks& other){}//copy ctor
masks& masks::operator=(const masks& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string mlri;
int gw_user_array[4];
int first_user_array[4];
int last_user_array[4];
int bd_user_array[4];
vector<string> nxt_network_bnr;
vector<string> nxt_network_dcm;
bin_to_dec *bdec=new bin_to_dec();
start_of *sof = new start_of();  int bg=-1;

int masks::check_ip_addr(string ip_to_check){
cout<<"checking ip " << ip_to_check << " ";
this->x_ones=0;
this->z_zeros=0;
this->sum=0;
this->gen_char='\0';
this->return_check=0;
for(int i=0;i<=ip_to_check.size()-1;i++){
  this->gen_char=ip_to_check.at(i);
  if(this->gen_char=='0'){this->x_ones+=1;}
  if(this->gen_char=='1'){this->z_zeros+=1;}
}
this->sum=this->x_ones+this->z_zeros;
if(this->sum==32){this->return_check=1;}
if(this->sum!=32){this->return_check=0;}
cout<<"with return status " << this->return_check <<"\n";
return 0;
}

//@one_to_one user_ip_addr is in binary form
//choise_of_mask is in string form
int masks::one_to_one(string user_ip_addr,string choise_of_mask){
cout<<"ur ip addr is : " << user_ip_addr <<" with mask of " << choise_of_mask <<"\n";
retrieve_mask.clear();
int lri=0;char lrk='\0';int ii=0;
int x=stoi(choise_of_mask);
this->expose_mask=x;
this->expd_mask.clear();
this->expd_mask+=choise_of_mask;
x=x*2;
//cout << x << "\n";
retrieve_mask+=maskone[x-1];
mlri.clear();
bdec->clear_tmparr();
mlri=bdec->convert_bdec(retrieve_mask);
cout<<"@Masks @ one_to_one will use mask :   " << retrieve_mask <<" (" << mlri <<")\n";
reverse_mask(retrieve_mask);
fnli.clear();
int userk=0;char kuser;
int maskk=0;char kmask;
int resulte=0;
for(int i=0;i<=retrieve_mask.size()-1;i++){
  if(user_ip_addr.at(i)!='.'){  //user_ip_addr
  kuser=user_ip_addr.at(i);
  kmask=retrieve_mask.at(i);
  if(kuser=='1'){userk=1;}if(kuser=='0'){userk=0;}
  if(kmask=='1'){maskk=1;}if(kmask=='0'){maskk=0;}
  resulte=userk & maskk ;
  fnli+=to_string(resulte);}
  if(user_ip_addr.at(i)==*"."){fnli+=".";}
}
mlri.clear();
bdec->clear_tmparr();
mlri=bdec->convert_bdec(fnli);
copy(begin(bdec->rev_one_ver),end(bdec->rev_one_ver),begin(gw_user_array)); //transferring array to this->mask instance
cout<<"@Masks @ one_to_one ::= ur ip gw(?) : " << fnli <<" (" << mlri << ")\n";
this->mygw.clear();
this->mygw+=user_ip_addr;
//cout<<"sending myGW                         " << mygw << "\n";
//passing the gw for use with vlsm
if(bg==-1){
sof->ip_to_arr(mlri);
arip[0]=sof->arr_of_ip[0];
arip[1]=sof->arr_of_ip[1];
arip[2]=sof->arr_of_ip[2];
arip[3]=sof->arr_of_ip[3];
sof_fir.clear();
sof_fir+=to_string(arip[0]);sof_fir+=".";
sof_fir+=to_string(arip[1]);sof_fir+=".";
sof_fir+=to_string(arip[2]);sof_fir+=".";
sof_fir+=to_string(arip[3]);
cout<<"Strogilopoiisi (ti mlkies leo) :" << sof_fir <<"\n"; bg=2;
}
first_user(fnli);
last_user(fu,rvm);
return 0;
}

//44.147.45.12
int masks::first_user(string gw){
fu.clear();
fu+=gw;
if(fu.at(34)=='0'){fu.at(34)='1';}
bin_to_dec *bdec=new bin_to_dec();
mlri.clear();
bdec->clear_tmparr();
mlri=bdec->convert_bdec(fu);
copy(begin(bdec->rev_one_ver),end(bdec->rev_one_ver),begin(first_user_array));
cout<<"First user is :                       "<<fu << " (" << mlri <<")\n";
return 0;
}

int masks::reverse_mask(string gw){
rvm.clear();
for(int i=0;i<=gw.size()-1;i++){
if(gw.at(i)=='0'){rvm+="1";goto A;}
if(gw.at(i)=='.'){rvm+=".";goto A;}
if(gw.at(i)=='1'){rvm+="0";goto A;}
A:cout<<"";
}
mlri.clear();
bdec->clear_tmparr();
mlri=bdec->convert_bdec(rvm);
cout<<"Reverse mask is :                     " << rvm << " (" << mlri <<")\n";
return 0;
}

string masks::nxt_network(int expose_maske,string mgw){
//not work as intended xD
cout<<"nxt network using mask                " << expose_maske <<"\n";
this->nxt_neti.clear();
cout<<"\n";
cout<<"-------------------------------------------------------------------\n";
cout<<"next network before                   " << mgw <<"\n";
for(int i=0;i<=mgw.size()-1;i++){
  if(i<expose_maske+2 && mgw.at(i)!='.'){this->nxt_neti+=mgw.at(i);}
  if(mgw.at(i)=='.'){this->nxt_neti+=".";}
  if(i>expose_maske+2 && mgw.at(i)!='.'){this->nxt_neti+="0";}
  if(i==expose_maske+2 && mgw.at(i)!='.'){this->nxt_neti+="1";}
}
//cout<<"after change                          " << this->nxt_neti << "\n";
cout<<"-------------------------------------------------------------------\n";
cout<<"\n";
mlri.clear();
bdec->clear_tmparr();
mlri=bdec->convert_bdec(this->nxt_neti);
cout<<"Next NetWork is :                     " << this->nxt_neti << " ("<<mlri <<")\n";
this->fnext_net.clear();
this->fnext_net+=this->nxt_neti;
return fnext_net;
}

int masks::last_user(string fu,string rvm){
lu.clear();
bdc.clear();
int userk=0;char kuser;
int maskk=0;char kmask;
int resulte=0;
for(int i=0;i<=fu.size()-1;i++){
  if(fu.at(i)!='.' && i<=33){
  kuser=fu.at(i);
  kmask=rvm.at(i);
  if(kuser=='1'){userk=1;}if(kuser=='0'){userk=0;}
  if(kmask=='1'){maskk=1;}if(kmask=='0'){maskk=0;}
  resulte=userk | maskk ;
  lu+=to_string(resulte);}
  if(fu.at(i)!='.' && i==34){
  bdc+=lu;
  kuser=fu.at(i);kmask=rvm.at(i);
  if(kuser=='1'){userk=1;}if(kuser=='0'){userk=0;}
  if(kmask=='1'){maskk=1;}if(kmask=='0'){maskk=0;}
  resulte=userk | maskk ;
  bdc+=to_string(resulte);
  }
  if(fu.at(i)!='.' && i==34){resulte=0;lu+=to_string(resulte);}
 if(fu.at(i)==*"."){lu+=".";}
}
mlri.clear();
bdec->clear_tmparr();
mlri=bdec->convert_bdec(lu);
copy(begin(bdec->rev_one_ver),end(bdec->rev_one_ver),begin(last_user_array));
cout<<"Last user is :                        " << lu << " (" << mlri <<")\n";
mlri.clear();
bdec->clear_tmparr();
mlri=bdec->convert_bdec(bdc);
copy(begin(bdec->rev_one_ver),end(bdec->rev_one_ver),begin(bd_user_array));
cout<<"Broadcast Ip Addr :                   " << bdc <<" ("<<mlri <<")\n";
start_of *stof=new start_of();
stof->dvn_net(mlri);
Str_int_Str *sis=new Str_int_Str();
sis->process_of_string(stof->ndvn);
string lsis;
lsis.clear();
lsis=sis->returnstr();
cout<<"ur next network maybe is              " << lsis <<" ("<<stof->ndvn <<")\n";
this->sof_fir=stof->ndvn;
this->sof_fir_as_bn=lsis;
return 0;
}

int masks::one_to_oneip(string user_ip_addrone,string user_ip_addrtwo){
int userk=0;char kuser;
int maskk=0;char kmask;
int resultei=0;
string fnli;fnli.clear();
for(int i=0;i<=user_ip_addrone.size()-1;i++){
 if(user_ip_addrone.at(i)!='.'){
  kuser=user_ip_addrone.at(i);
  kmask=user_ip_addrtwo.at(i);
  if(kuser=='1'){userk=1;}if(kuser=='0'){userk=0;}
  if(kmask=='1'){maskk=1;}if(kmask=='0'){maskk=0;}
  resultei=userk & maskk ;
  fnli+=to_string(resultei);}
 if(user_ip_addrone.at(i)==*"."){fnli+=".";}
}
mlri.clear();
bdec->clear_tmparr();
mlri=bdec->convert_bdec(fnli);
cout<<"@Masks @ one_to_one ::= ur su msk(?) :" << fnli <<" (" << mlri << ")\n";
return 0;
}

string masks::return_mask(string mskk){
//for(int i=0;i<=100;i++){
//cout<<mskk << " " << maskone[i]<<"\n";
//if(mskk==this->maskone[i]){
//mskk.clear();
//mskk+=this->maskone[i-1];}
//}
int x=stoi(mskk);
x=x*2;
vlsm_mask_bd+=masks_conce[x-1];
return mskk;
}

string masks::return_users(string users){
string ruser;int ct=0;
for(int i=91;i>=0;i-=3){
//cout<< " vl of " << mask_users[i] <<" of i " << i <<" of users "<< users<<"\n";
if(stoi(mask_users[i])>=stoi(users) ){
   ruser+=mask_users[i];
   ct+=1;
  // cout<<"fnd " <<ruser << " " << mask_users[i];
   }
if(ct==1){vlsm_mask=mask_users[i+2];break;}
}
this->return_mask(vlsm_mask);
return ruser;
}
