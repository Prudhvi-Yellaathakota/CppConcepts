#include<iostream>
#include<string.h>
using namespace std;
class String{
private:
	char* m_ptr;
public:
	String(): m_ptr(NULL){}
	String(const char* _ptr)
	{
		m_ptr=new char(strlen(_ptr)+1);
		strcpy(m_ptr, _ptr);
	}
	String(String& s_obj)
	{
		//char* temp =s_obj.m_ptr;
		m_ptr=new char(strlen(s_obj.m_ptr)+1);
		strcpy(m_ptr, s_obj.m_ptr);
		
	}
	String& operator=(String& s_obj)
	{
		if(this != &s_obj )
		{
		    std::cout<<"CAS\n";
			char* temp=this->m_ptr;
			m_ptr=new char(strlen(s_obj.m_ptr)+1);
			strcpy(m_ptr,s_obj.m_ptr);
			delete[] temp;
		}
		return *this;
	}
	//std::move constructor ..to call the move constructor it requires new object to store the earlier temporary required copied object
	String (String&& other)
	{
	    m_ptr=other.m_ptr;
	    other.m_ptr=nullptr;
	}
	void Print()
	{
	    std::cout<<"obj: "<<this->m_ptr<<std::endl;
	}
	~String()
	{
		if(m_ptr)
		{
			delete[] m_ptr;
			m_ptr=nullptr;
		}
	}
};
int main()
{
	String obj1;
	String obj2("Rilee Rossouw");
//	obj2.Print();
	String obj3(obj2);   //Copy Consructor
//	obj3.Print();
	String obj4;
	obj4=obj2;          //CAS
	
    String obj5((String("Move Constructor Paramter")));
   String  abc=std::move(obj5);
   abc.Print();

	return 0;
}
