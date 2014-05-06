#include "animal.h"

int
main(void)
{
    CFish fish;
    fish.eat();

    CTiger tiger;
    tiger.eat();

    CPerson person;
    person.eat();
    person.feed_fish(fish);
    person.feed_tiger(tiger);

    return 0;
}