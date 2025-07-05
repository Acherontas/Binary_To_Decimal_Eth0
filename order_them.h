#ifndef ORDER_THEM_H
#define ORDER_THEM_H

#include <vector>
using namespace std;
class order_them
{
    public:
        order_them();
        virtual ~order_them();
        order_them(const order_them& other);
        order_them& operator=(const order_them& other);
        int nmb_of_sb=0;
        vector<int> myvls;
        vector<int> rd_vls;
        int minni=0;
        int maxxi=0;
        int x_order(int sbs,int mini,int maxi);
        int loop_them(int mvm);
    protected:
    private:
};

#endif // ORDER_THEM_H
