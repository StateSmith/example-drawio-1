#pragma once

void Display_setup(void);

void Display_clear_screen(void);
void Display_cursor_up_one(void);

void Display_erase_current_line(void);
void Display_erase_previous_line(void);

void Display_print(const char * const str);
void Display_println(const char * const str);
void Display_printf(const char * format, ...);

void Display_attribute_reset(void);
void Display_attribute_blue(void);
void Display_attribute_cyan(void);
void Display_attribute_green(void);
void Display_attribute_yellow(void);
void Display_attribute_magenta(void);
void Display_attribute_red(void);
