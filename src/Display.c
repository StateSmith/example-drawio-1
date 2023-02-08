#include "Display.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef _MSC_VER
#include <Windows.h>
#endif


#ifdef _MSC_VER
void Display_setup(void)
{
    system(" "); // enable VT100 commands for Windows 10+
}
#else
void Display_setup(void)
{
    // nothing to do
}
#endif

void Display_clear_screen(void)
{
    printf("\33[2J");   // VT100 - Erases the screen with the background colour and moves the cursor to home.
}

void Display_erase_previous_line(void)
{
    Display_cursor_up_one();
    Display_erase_current_line();
    fflush(stdout);
}

void Display_printf(const char * format, ...)
{
  static char buffer[256];
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, sizeof(buffer), format, args);
  va_end (args);

  Display_print(buffer);
}

void Display_print(const char * const str)
{
    printf("%s", str);
}

void Display_println(const char * const str)
{
    printf("%s\n", str);
}

void Display_cursor_up_one(void)
{
    printf("\033[A");   // VT100 - move cursor up one line
}

void Display_erase_current_line(void)
{
    printf("\033[2K");   // VT100 - Erases the entire current line
}

void Display_attribute_blue(void)
{
    printf("\033[34m");
}

void Display_attribute_cyan(void)
{
    printf("\033[36m");
}

void Display_attribute_green(void)
{
    printf("\033[32m");
}

void Display_attribute_yellow(void)
{
    printf("\033[33m");
}

void Display_attribute_magenta(void)
{
    printf("\033[35m");
}

void Display_attribute_red(void)
{
    printf("\033[31m");
}

void Display_attribute_reset(void)
{
    printf("\033[0m");
}
