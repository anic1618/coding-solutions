class Employee
{
public:
    virtual void raiseSalary()
    {  /* common raise salary code */  }
 
    virtual void promote()
    { /* common promote code */ }
};
 
class Manager: public Employee {
    virtual void raiseSalary()
    {  /* Manager specific raise salary code, may contain
          increment of manager specific incentives*/  }
 
    virtual void promote()
    { /* Manager specific promote */ }
};
 
// Similarly, there may be other types of employees
 
// We need a very simple function to increment salary of all employees
// Note that emp[] is an array of pointers and actual pointed objects can
// be any type of employees. This function should ideally be in a class 
// like Organization, we have made it global to keep things simple
void globalRaiseSalary(Employee *emp[], int n)
{
    for (int i = 0; i < n; i++)
        emp[i]->raiseSalary(); // Polymorphic Call: Calls raiseSalary() 
                               // according to the actual object, not 
                               // according to the type of pointer                                 
}

like globalRaiseSalary(), there can be many other operations that can be appropriately done on a list of employees without even knowing the type of actual object.
Virtual functions are so useful that later languages like Java keep all methods as virtual by default.

How does compiler do this magic of late resolution?
Compiler maintains two things to this magic:
virtualFuns
vtable: A table of function pointers. It is maintained per class.
vptr: A pointer to vtable. It is maintained per object (See this for an example).

#Compiler adds additional code at two places to maintain and use vptr.
1) Code in every constructor. This code sets vptr of the object being created. 
This code sets vptr to point to vtable of the class.
2) Code with polymorphic function call (e.g. bp->show() in above code). 
Wherever a polymorphic call is made, compiler inserts code to first look for vptr using base class pointer or reference
(In the above example, since pointed or referred object is of derived type, vptr of derived class is accessed). 
Once vptr is fetched, vtable of derived class can be accessed. Using vtable, address of derived derived class function show() 
is accessed and called.
Is this a standard way for implementation of run-time polymorphism in C++?
The C++ standards do not mandate exactly how runtime polymophism must be implemented, but compilers generally 
use minor variations on the same basic model.
