#include <iostream>

class MyBaseClass
{
    public:
        int publicVar;
    
    protected:
        int protectedVar;

    private:
        int privateVar;
};

class MyDerivedClsss : public MyBaseClass
{
    public:
    MyDerivedClsss()
    {
        // publicVar is accessible here
        this->publicVar = 123;
        
        // protectedVar is accessible here
        this->protectedVar = 123;

        // privateVar is NOT accessible here
        this->privateVar = 123; /*ERROR*/
    }
};

int main()
{
    MyDerivedClsss obj;

    obj.publicVar = 123;
    obj.protectedVar = 123;     /* Error: protectedVar is protected within this context  */
    obj.privateVar = 123;       /* Error: privateVar is private within this context  */

    return 0;
}


