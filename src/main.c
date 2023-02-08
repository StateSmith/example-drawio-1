#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "light.h"
#include "Tutorial1Sm.h"
#include "Display.h"

////////////////////////////////////////////////////////////////////////////////
// global vars
////////////////////////////////////////////////////////////////////////////////

static Tutorial1Sm g_state_machine;


////////////////////////////////////////////////////////////////////////////////
// prototypes
////////////////////////////////////////////////////////////////////////////////

static void read_input_run_state_machine(void);
static char read_char_from_line_and_clear_user_input(void);
static void show_sm_info(void);
static void were_going_need_another_timmy(void);


////////////////////////////////////////////////////////////////////////////////
// functions
////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    Display_setup();

    Display_print("---------------------------------------\n\n");

    Display_attribute_cyan();
    Display_print("This example C program uses VT100 codes. Will work on *nix and Windows 10+.\n\n");
    Display_attribute_yellow();
    Display_print("USAGE:\n");
    Display_print("  type i <enter> to send INCREASE event to state machine.\n");
    Display_print("  type d <enter> to send DIM event to state machine.\n");
    Display_print("  type o <enter> to send OFF event to state machine.\n");
    Display_print("\n");
    Display_attribute_green();
    Display_print("Hit <enter> to start\n");
    Display_attribute_reset();

    read_char_from_line_and_clear_user_input();

    // advance enough lines to get to bottom of terminal
    for (size_t i = 0; i < 200; i++)
    {
        Display_print("\n");
    }

    Display_clear_screen();


    // setup and start state machine
    Tutorial1Sm_ctor(&g_state_machine);
    Tutorial1Sm_start(&g_state_machine);

    show_sm_info();

    while (g_state_machine.state_id != Tutorial1Sm_StateId_BOOM3)
    {
        read_input_run_state_machine();
    }

    were_going_need_another_timmy();
    return 0;
}


static void read_input_run_state_machine(void)
{
    bool valid_input = true;
    enum Tutorial1Sm_EventId event_id = Tutorial1Sm_EventId_OFF;

    char c = read_char_from_line_and_clear_user_input();
    switch (c)
    {
        case 'i': event_id = Tutorial1Sm_EventId_INCREASE; break;
        case 'd': event_id = Tutorial1Sm_EventId_DIM; break;
        case 'o': event_id = Tutorial1Sm_EventId_OFF; break;
        default: valid_input = false; break;
    }

    if (valid_input)
    {
        Tutorial1Sm_dispatch_event(&g_state_machine, event_id);
        show_sm_info();
    }
}


static void show_sm_info(void)
{
    Display_erase_previous_line();

    Display_attribute_reset();
    Display_print("state ID: ");

    Display_attribute_green();
    Display_print(Tutorial1Sm_state_id_to_string(g_state_machine.state_id));
    
    Display_attribute_reset();
    Display_print(", vars.count: ");

    Display_attribute_green();
    Display_printf("%i\n", g_state_machine.vars.count);
    Display_attribute_reset();

    Display_println("");
    Display_cursor_up_one();
}


// blocks while waiting for input
static char read_char_from_line_and_clear_user_input(void)
{
    static char s_buf[100];

    char* c_ptr = fgets(s_buf, sizeof(s_buf), stdin);
    Display_erase_previous_line();

    if (c_ptr == NULL)
    {
        return '\0';
    }

    return *c_ptr;
}


static void were_going_need_another_timmy(void)
{
    Display_println("");
    Display_attribute_red();
    Display_println("We're going to need another Timmy...");
    Display_attribute_blue();
    Display_println("https://www.youtube.com/watch?v=wsGnYuQwsOI");
    Display_println("https://www.youtube.com/watch?v=nNxsclnYN4A");
    Display_println("");
    Display_attribute_reset();
}
