/*
 *
 *   ,------.                             ,------.        ,--.          ,--.
 *   |  .---',--,--.,--,--, ,---.,--. ,--.|  .--. ',--.--.`--',--,--, ,-'  '-.
 *   |  `--,' ,-.  ||      \ .--' \  '  / |  '--' ||  .--',--.|      \'-.  .-'
 *   |  |`  \ '-'  ||  ||  \ `--.  \   '  |  | --' |  |   |  ||  ||  |  |  |
 *   `--'    `--`--'`--''--'`---'.-'  /   `--'     `--'   `--'`--''--'  `--'
 *                              `---'
 *
 * ---------------------
 * FancyPrint 1.0
 * Created by Lukas Bos
 * January 2020
 * Requires C++17 or higher
 * ---------------------
 *
 * This is a very simple library that enables fancy printing for your C++ application.
 * Fancy prints are an extension of std::cout prints. Every print can be given a type which is displayed in a color.
 * It also displays the filename and line number where the print is being called.
 * After compilation these will just result in std::cout statements.
 *
 * Recommended use:
 * F_INFO - useful information about your system, such as state switching, or executing relevant functions.
 * F_DEBUG - only for debugging prints, developer information. e.g. logging a variable value.
 * F_SUCCESS - indicate that a critical operation has succeeded
 * F_WARNING - indicate a recoverable problem
 * F_ERROR - indicate a non-recoverable problem
 *
 */

#ifndef FANCY_PRINTS__PRINT_H_
#define FANCY_PRINTS__PRINT_H_

#include <iostream>
#include <iomanip>

////////////////////////////////////////////////////
// Settings for fancy prints

/*
 * Enable/disable fancy log levels
 */
#define F_DEBUG_LOGS 1
#define F_ERROR_LOGS 1
#define F_WARNING_LOGS 1
#define F_INFO_LOGS 1
#define F_SUCCESS_LOGS 1

/*
 * Enable/disable fancy printing
 * When enabled, logs are printed in columns, have filenames, linenumbers, are clickable and optionally have colors.
 * When disabled, logs are converted to simple cout statements.
 */
#define F_FANCY_LOGS 1

/*
 * Enable/disable colors in fancy logs.
 * useful if colors are not supported by your terminal.
 * read more about ansi escape codes: https://en.wikipedia.org/wiki/ANSI_escape_code
 */
#define F_COLORED_LOGS 1


////////////////////////////////////////////////////
// Settings for Fancy logs

// macro to get the filename from the full path
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#if F_FANCY_LOGS

#if F_DEBUG_LOGS
#define F_DEBUG(...) { Printer::fancy_print("\033[35m", "DEBUG", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__); }
#else
#define F_DEBUG(...)
#endif

#if F_WARNING_LOGS
#define F_WARNING(...) { Printer::fancy_print("\033[93;3m", "WARNING", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__); }
#else
#define F_WARNING(...)
#endif

#if F_ERROR_LOGS
#define F_ERROR(...) { Printer::fancy_print("\033[31;1m","ERROR", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__); }
#else
#define F_ERROR(...)
#endif

#if F_INFO_LOGS
#define F_INFO(...) { Printer::fancy_print("\033[37m", "INFO", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__); }
#else
#define F_INFO(...)
#endif

#if F_SUCCESS_LOGS
#define F_SUCCESS(...) { Printer::fancy_print("\033[32m", "SUCCESS", __FILENAME__, __FUNCTION__, __LINE__, __VA_ARGS__); }
#else
#define F_SUCCESS(...)
#endif

#else
#define F_DEBUG(...) { Printer::simple_print(__VA_ARGS__); }
    #define F_ERROR(...) { Printer::simple_print(__VA_ARGS__); }
    #define F_WARNING(...) { Printer::simple_print(__VA_ARGS__); }
    #define F_INFO(...) { Printer::simple_print(__VA_ARGS__); }
    #define F_SUCCESS(...) { Printer::simple_print(__VA_ARGS__); }
#endif

class Printer {
 public:
  template <typename...Args>
  static inline void fancy_print(const char * color, const char * type, const std::string& file, const char * func, int line, Args&&... args) noexcept {
      auto fileTxt = file + ":" + std::to_string(line);
#if F_COLORED_LOGS
      std::cout << color;
#endif
      std::cout << std::setw(10) << std::left;
      std::cout << type << std::setw(32) << std::left;
      std::cout << fileTxt << std::left;
      ((std::cout << std::forward<Args>(args)), ...);
#if F_COLORED_LOGS
      std::cout << "\033[0m"; // reset the string formatting
#endif
      std::cout << std::endl;
  }

  template <typename...Args>
  static inline void simple_print(Args&&... args) noexcept {
      ((std::cout << std::forward<Args>(args)), ...);
      std::cout << std::endl;
  }
};

#endif //FANCY_PRINTS__PRINT_H_
