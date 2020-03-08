# fancy-print
A simple header-only library for better c++ prints. Works with C++17 and up. 


![FancyPrint screenshot]("./doc/output.png" "Fancy logging screenshot")

The above screenshot is created using the following statements:
```
    F_SUCCESS("Yes! You succesfully compiled FancyPrint!")
    F_INFO("FancyPrint makes your application prints to the terminal much nicer!")
    F_INFO("You can put in whatever you normally could put in a stream, such as integers: ", 10)
    F_INFO("There are all types of print types possible: ")
    F_DEBUG("This is a fancy debug message!")
    F_WARNING("Warnings are nicely visible")
    F_ERROR("Errors are even more visible")
```

This is a very simple library that enables fancy printing for your C++ application. Fancy prints are an extension of std::cout prints. Every print can be given a type which is displayed in a color. It also displays the filename and line number where the print is being called. After compilation these will just result in std::cout statements.

Recommended use:
F_INFO - useful information about your system, such as state switching, or executing relevant functions.
F_DEBUG - only for debugging prints, developer information. e.g. logging a variable value.
F_SUCCESS - indicate that a critical operation has succeeded
F_WARNING - indicate a recoverable problem
F_ERROR - indicate a non-recoverable problem

### Why this library?
In some projects I recently worked on I noticed that people would often write their print statements like this:
```
std::cerr << "[Classname::functionname] ERROR! this is not allowed!" << std::endl;
```
This was vulnerable for refactors, as function/class names would sometimes change.
Therefore, automating this process makes logging easier, and makes logs easier to find. 

### Why macro's?
Under the hood, the __function__ and __file__ macro's are used to properly determine the location of the function call. 
When compiled and inlined, the function will simply be the same as std::cout calls. 