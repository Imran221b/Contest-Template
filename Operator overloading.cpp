//overloading comparator sign for struct manually
//usually used for priority queue
 
struct node
{
    int val;
    //some other variables here
 
    bool operator < (const node& p) const {
        return val > p.val;
    }
};
