#include <iostream>
#include "Print.h"

int main() {
    F_SUCCESS("Yes! You succesfully compiled FancyPrint!")
    F_INFO("FancyPrint makes your application prints to the terminal much nicer!")
    F_INFO("You can put in whatever you normally could put in a stream, such as integers: ", 10)
    F_INFO("There are all types of print types possible: ")
    F_DEBUG("This is a fancy debug message!")
    F_WARNING("Warnings are nicely visible")
    F_ERROR("Errors are even more visible")
    return 0;
}
