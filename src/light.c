#include "light.h"
#include <stdio.h>
#include <stdlib.h>
#include "Display.h"

static int boom3_count = 0;

static const char* off_string = 
"    _------_   \n" \
"  -~        ~-   \n" \
" -     _      -   \n" \
"-      ||      -   \n" \
"-      ||      -   \n" \
" -     ||     -   \n" \
"  -    ||    -   \n" \
"   -   ||   -   \n" \
"    -__||__-   \n" \
"    |______|   \n" \
"    <______>   \n" \
"    <______>   \n" \
"       \\/   \n";

static const char* on1_string = 
"    _------_   \n" \
"  -~  .   . ~-   \n" \
" - .   _    . -   \n" \
"-      ||      -   \n" \
"-  .   ||   .  -   \n" \
" -    .||.    -   \n" \
"  -  .<||>.  -   \n" \
"   - .<||>. -   \n" \
"    -__||__-   \n" \
"    |______|   \n" \
"    <______>   \n" \
"    <______>   \n" \
"       \\/   \n";

static const char* on2_string = 
"    _------_   \n" \
"  -~.  .  . ~-   \n" \
" -.  . _ .  . -   \n" \
"- .  .^||^.  . -   \n" \
"-...<<<||>>>.. -   \n" \
" -..<<<||>>>.-   \n" \
"  -..<<||>>..-   \n" \
"   -.<<||>>.-   \n" \
"    -__||__-   \n" \
"    |______|   \n" \
"    <______>   \n" \
"    <______>   \n" \
"       \\/   \n";

static const char* on3_string = 
"    _------_   \n" \
"  -~^^^^^^^^~-   \n" \
" -<<<<<^^>>>>>-   \n" \
"-<<<<<<{}>>>>>>-   \n" \
"-<<<<<<{}>>>>>>-   \n" \
" -<<<<<{}>>>-   \n" \
"  -<<<<{}>>>>-   \n" \
"   -<<<{}>>>-   \n" \
"    -__||__-   \n" \
"    |______|   \n" \
"    <______>   \n" \
"    <______>   \n" \
"       \\/   \n";

static const char* boom_string1 = 
" `     ^     '   \n" \
"                 \n" \
"`  ! ! ! ! !   '   \n" \
"  ! !! KA !! !      \n" \
"   ! ! ! ! !  .    \n" \
"                  \n" \
"  `   `   '  '    \n" \
"                 \n" \
"    -__||__-   \n" \
"    |______|   \n" \
"    <______>   \n" \
"    <______>   \n" \
"       \\/   \n";

static const char* boom_string2 = 
" ` ! ` ! ` ! '   \n" \
" ! ` : : : ` !   \n" \
"!  : . . . :  !'   \n" \
"! :  !BOOM!  : !    \n" \
"!  : . . . :  !'   \n" \
" ! ` : : : ` !   \n" \
" ` ! ` ! ` ! '   \n" \
"                 \n" \
"    -__||__-   \n" \
"    |______|   \n" \
"    <______>   \n" \
"    <______>   \n" \
"       \\/   \n";

static const char* boom_string3 = 
"    -__||__-   \n" \
"    |______|   \n" \
"    <______>   \n" \
"    <______>   \n" \
"       \\/   \n";


static void print_bulb(const char * const bulb)
{
    Display_clear_screen();
    Display_println(bulb);
    Display_attribute_reset();
    Display_cursor_up_one();
    fflush(stdout);
}

void light_off(void)
{
    Display_attribute_blue();
    print_bulb(off_string);
}

void light_on1(void)
{
    Display_attribute_cyan();
    print_bulb(on1_string);
}

void light_on2(void)
{
    Display_attribute_green();
    print_bulb(on2_string);
}

void light_on3(void)
{
    Display_attribute_yellow();
    print_bulb(on3_string);
}

void light_boom1(void)
{
    Display_attribute_yellow();
    print_bulb(boom_string1);
}

void light_boom2(void)
{
    Display_attribute_red();
    print_bulb(boom_string2);
}

void light_boom3(void)
{
    if (boom3_count == 0)
    {
        print_bulb(boom_string3);
    }
    else
    {
        Display_println("\n\n");
        Display_cursor_up_one();
    }

    boom3_count++;
}