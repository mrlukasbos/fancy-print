# fancy-print
A simple header-only library for better c++ prints. Works with C++17 and up. 

This is a very simple library that enables fancy printing for your C++ application. Fancy prints are an extension of std::cout prints. Every print can be given a type which is displayed in a color. It also displays the filename and line number where the print is being called. After compilation these will just result in std::cout statements.

Recommended use:
F_INFO - useful information about your system, such as state switching, or executing relevant functions.
F_DEBUG - only for debugging prints, developer information. e.g. logging a variable value.
F_SUCCESS - indicate that a critical operation has succeeded
F_WARNING - indicate a recoverable problem
F_ERROR - indicate a non-recoverable problem
