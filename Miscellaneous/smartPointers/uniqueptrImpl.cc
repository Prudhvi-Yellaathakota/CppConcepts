#include<iostream>
using namespace std;
template<typename T>
class uniquePtr
{
    private: 
    T* resource;
    public:
    uniquePtr(T* arg = nullptr): resource(arg){}

    uniquePtr(const uniquePtr<T>& arg ) = delete;
    uniquePtr& operator= (const uniquePtr<T>& arg) = delete;

    uniquePtr(uniquePtr<T>&& ptr) //std::move ctor
    {
        resource = ptr.resource;
        ptr.resource = nullptr;
    }
    //move assignment
    uniquePtr& operator=(const uniquePtr<T>&& ptr)
    {
        if(this != &ptr)
        {
            if(resource) //if already resource allocated, kindly delete the resouce
            {
                delete res;
            }
            resource = ptr.resource;
            ptr = nullptr;
        }
        return *resource;
    }
    T* operator->()
    {
        return resource;
    }
    T& operator*()
    {
        return *resource;
    }
    T* get() { return resource;}

    void reset(T* res = nullptr)
    {
        if(resource) delete resource;
        resource = res;
    }
    ~uniquePtr()
    {
        if (resource)
        {
            delete resource;
            resource = nullptr;
        }
    }

};
int main()
{
    uniquePtr<int>ptr(new int (20));
    uniquePtr<int>ptr1(new int (21));

    uniquePtr<int>p2 = std::move(ptr);
    std::cout<<*p2; // it should points to 20;

    p2 = std::move(ptr1);  //p2 value already allocated, reallocated with new

    return 0;

}