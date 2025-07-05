#include <iostream>
#include "str_int_str.h"
#include "masks.h"
#include "bin_to_dec.h"
#include "vlsm.h"
#include <thread>
#include <vector>
#include <bits/stdc++.h>
#include "order_them.h"
using namespace std;

int main()
{
    Str_int_Str *stri=new Str_int_Str();
    masks *msk=new masks();
    bin_to_dec *btd=new bin_to_dec();
    vlsm *vlms=new vlsm();
    order_them *ordt=new order_them();
    string fnl;
    int prc=0;
    cout<<"enter 1 ip addr segment : ";
    cin>>stri->num_zero;
    prc=stri->processit(stri->num_zero,1); //decimal 192 to binary 10XYZ
    if(prc==-1){return 0;}
    cout<<"enter 2 ip addr segment : ";
    cin>>stri->num_one;
    prc=stri->processit(stri->num_one,2);
    if(prc==-1){return 0;}
    cout<<"enter 3 ip addr segment : ";
    cin>>stri->num_two;
    prc=stri->processit(stri->num_two,3);
    if(prc==-1){return 0;}
    cout<<"enter 4 ip addr segment : ";
    cin>> stri->num_three;
    prc=stri->processit(stri->num_three,4);
    fnl=stri->returnstr(); //full binary string of 192.168.1.15
    if(prc==-1){return 0;}
    cout<<"Ur ip Addr : " <<  fnl <<"\n";
    cout<<"Choose what u want to do \n";
    cout<<"1. Ur Ip Addr with a specific mask \n";
    cout<<"2. Ur Ip Addr with all masks \n";
    cout<<"3. Generating VLSM/CIDR subnets \n";
    int choise=0;
    cin>>choise;
    string mask_number;
    int lmsk=0;
    string mlri=btd->convert_bdec(fnl); //converting the binary of 192.168.1.5 to decimal
    if(choise==1){
    mask_number.clear();
    cout<<"enter ur mask : " ;
    cin>>mask_number;
    lmsk=0;
    cout<<"With Mask /"<<mask_number <<"\n";
    cout<<"@Masks @ one_to_one ::= ur ip addr : "<< fnl <<" (" << mlri <<")\n";
    lmsk=msk->one_to_one(fnl,mask_number);
    }
    if(choise==2){
    for(int i=1;i<=32;i++){
       lmsk=0;
       mask_number.clear();
       mask_number+=to_string(i);
       cout<<"-------------------------------------------------\n";
       cout<<"With Mask /"<<mask_number <<"\n";
       cout<<"@Masks @ one_to_many ::= ur ip addr : "<< fnl <<" (" << mlri <<")\n";
       lmsk=msk->one_to_one(fnl,mask_number);
       //if(i<=28){lmsk=msk->one_to_one(fnl,mask_number);}
      // if(i>28){masks *newmsk = new masks();lmsk=newmsk->one_to_one(fnl,mask_number);}
       cout<<"-------------------------------------------------\n";
       //std::this_thread::sleep_for(std::chrono::milliseconds(200));
       }
    }
    if(choise==3){
    int my_ip_addr[5];
    cout<<"give me a mask without '/' : ";
    int user_mask=0;
    cin>>user_mask ;
    cout<<"\n";
    lmsk=0;
    string kus=to_string(user_mask);
    for(int i=0;i<=4;i++){msk->arip[i]=0;}
    lmsk=msk->one_to_one(fnl,kus);
    my_ip_addr[0]=msk->arip[0];
    my_ip_addr[1]=msk->arip[1];
    my_ip_addr[2]=msk->arip[2];
    my_ip_addr[3]=msk->arip[3];
    my_ip_addr[4]=user_mask;
    int number_of_subnets=0;
    cout<<"using ip as " << my_ip_addr[0] << "." << my_ip_addr[1] << "." << my_ip_addr[2] << "." << my_ip_addr[3] << " /" << my_ip_addr[4] <<"\n";
    cout<<"give me number of subnets : ";
    cin>>number_of_subnets;
    cout<<"\n";
    vector<string> size_of_each; string xsoe;int xseo;
    cout<<"Give me number of users from bigger to smallest \n";
    ordt->nmb_of_sb=number_of_subnets;
    for(int i=0;i<=number_of_subnets-1;i++){
       cout<<"for subnet " << i << " give me number of users : ";
       cin>>xseo;
       //cin>>xsoe;
       xsoe.clear();
       xsoe+=to_string(xseo);
       ordt->myvls.push_back(xseo);
       //size_of_each.push_back(xsoe);
       if(i==0){ordt->minni=xseo;ordt->maxxi=xseo;}
       if(i>0){
          if(xseo<=ordt->minni){ordt->minni=xseo;}
          if(xseo>=ordt->maxxi){ordt->maxxi=xseo;}
       }
    }
    //we order then we add the values @ size_of_each vector
    cout<<"fixing sizes.From bigger to smaller\n";
    ordt->x_order(ordt->nmb_of_sb,ordt->minni,ordt->maxxi);
    string slim;
    cout<<"Inserting @ sizes with order from bigger to smaller :\n";
    for(int i=ordt->rd_vls.size()-1;i>=0;--i){
      slim.clear();
      slim+=to_string(ordt->rd_vls.at(i));
      cout << slim << " @ pos " << i <<" with integer value of " << ordt->rd_vls.at(i)<<"\n";
      size_of_each.push_back(slim);
    }
    //for(int i=0;i<=size_of_each.size()-1;i++){cout<<i << " with  " << size_of_each.at(i)<<"\n";}
    string lkm;
    vector<string> vvlsm_masks;
    vector<string> vvlsm_mask_bd;
    vector<string> vlkm;
    vector<string> vsize_of_each;
    for(int i=0;i<=number_of_subnets-1;i++){
    msk->vlsm_mask.clear();
    msk->vlsm_mask_bd.clear();
    lkm=msk->return_users(size_of_each.at(i));
   // cout<<"max number of users " << lkm <<" users asked for " << size_of_each.at(i)<<" ";
   // cout<<"network mask to use is " << " /" << msk->vlsm_mask << " with " << msk->vlsm_mask_bd << " \n";
    vlkm.push_back(lkm);
    vsize_of_each.push_back(size_of_each.at(i));
    vvlsm_masks.push_back(msk->vlsm_mask);
    vvlsm_mask_bd.push_back(msk->vlsm_mask_bd);
    }
    //vlms->gen_them(my_ip_addr,size_of_each,user_can_hold,arr_of_smask,mask_as_zone);
    cout<<"\n";
    vlms->gen_them(my_ip_addr,vsize_of_each,vlkm,vvlsm_masks,vvlsm_mask_bd);
    }
    return 0;
}
