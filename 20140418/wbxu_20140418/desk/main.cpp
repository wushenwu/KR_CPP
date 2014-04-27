#include <iostream>
using namespace std;

#include "desk.h"
#include "computer.h"
#include "person.h"

void
test_desk(void)
{
    CDesk desk;
    
    //desk.SetDesk(1.0f, 1.0f, 1.0f, "yellowwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
    desk.SetDesk(1.0f, 1.0f, 1.0f, CDesk.YELLOW);
    
    cout << desk.GetLen() << " "
        << desk.GetWidth() << " "
        << desk.GetWidth() << " "
        << desk.GetColor() << endl;
    
    desk.SetColor(CDesk.RED);
    cout << desk.GetColor() << endl;
}

void
test_computer(void)
{
    CComputer computer;

    computer.SetComputer(8000, 14.7f, CComputer::DELL);

    cout << computer.GetPrice() << " "
         << computer.GetSize() << " "
         << computer.GetBrand() << endl;

    computer.SetBrand(CComputer::LENOVO);

    cout << computer.GetBrand() << endl;
}

void
test_person(void)
{
    CPerson person;
    
    person.SetPerson("test", "xxxxxxxxxxxxxxxxx", 30, 'M');

    cout << person.GetName() << " "
         << person.GetAddress() << " "
         << person.GetAge() << " "
         << person.GetGender() << endl;

    person.SetAddress("yyyyyyyyyyyyyyyyyyy");

    cout << person.GetAddress() << endl;
}

int
main(void)
{
    test_desk();

    test_computer();

    test_person();

    return 0;
}