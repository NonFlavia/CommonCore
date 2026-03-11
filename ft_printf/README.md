*This project has been created as part of the 42 curriculum by flavides.*

# ft_printf
![I_did_it](https://miro.medium.com/v2/resize:fit:640/format:webp/1*QGNEPxgD2svUFVnUiAHGuA.png)
## Description

ft_printf is a reimplementation of the standard C function `printf`.
The goal of this project is to understand how formatted output works internally
while learning how to manage variadic arguments and low level output functions.

The function prints formatted text to the standard output and returns the total
number of printed characters.

The implementation supports the following conversions:

%c  → character  
%s  → string  
%d  → signed decimal integer  
%i  → signed decimal integer  
%u  → unsigned decimal integer  
%x  → hexadecimal (lowercase)  
%X  → hexadecimal (uppercase)  
%p  → pointer address  
%%  → prints the percent symbol

The project focuses on understanding:

- variadic arguments
- format string parsing
- recursive number conversion
- modular program structure


---

## Instructions

### Compilation

Run:

make

This creates the static library:

libftprintf.a


### Cleaning files

make clean

Removes object files.


### Full clean

make fclean

Removes object files and the library.


### Recompile everything

make re


### Example usage

Example program:

#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s\n", "world");
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Hex: %x\n", 42);
    ft_printf("Pointer: %p\n", &main);
}

Compile with:

cc -Wall -Wextra -Werror main.c libftprintf.a


---

## Algorithm and Data Structure

The implementation is based on a simple parsing algorithm that scans the format
string character by character.

The main function `ft_printf` iterates through the format string.

If the current character is not `%`, it is immediately written to the output
using the `write` system call.

When the parser encounters `%`, the next character is interpreted as a format
specifier and passed to the function `ft_handlecases`.

`ft_handlecases` acts as a dispatcher: it identifies the conversion type and
calls the appropriate helper function.

The logic of the program is organized in three layers:

ft_printf.c  
Handles the parsing of the format string and manages the variadic argument list.

ft_handlecases.c  
Determines which type of conversion is required and retrieves the correct
argument using `va_arg`.

ft_utility.c  
Contains helper functions responsible for printing strings and numbers.


### Variadic arguments

The arguments passed to ft_printf are handled using the standard macros:

va_start  
va_arg  
va_end  

The argument list is passed by pointer to the helper functions so that the
correct element is extracted sequentially.


### Number conversion

Integer and hexadecimal printing use a recursive approach.

For decimal numbers:

- if the number is negative, a '-' is printed
- the number is divided by 10
- the higher digits are printed recursively
- the last digit is converted to a character and printed

For hexadecimal numbers:

- the number is divided by 16
- recursion prints the higher digits first
- the remainder selects the correct symbol from the hexadecimal table

This avoids using temporary buffers and prints the digits directly.


### Pointer handling

Pointers are retrieved as `void *` and cast to `unsigned long`.
If the pointer is `NULL`, the function prints `(nil)`.
Otherwise it prints the prefix `0x` followed by the hexadecimal representation.


### Data structures

This project does not require complex data structures.

The implementation relies on:

- iteration over the format string
- recursive number conversion
- the variadic argument list

This keeps the implementation simple and close to the behavior of the original
printf function.


---

## Resources

The following resources were used while working on this project:

- `man 3 printf`
- `man stdarg`
- `man write`
- C documentation and programming manuals
- the official 42 project subject PDF

Most of the learning process happened through peer-to-peer discussions with
other 42 students. Many problems were solved through collaborative debugging
and explanation between colleagues.

#### Use of AI

AI tools were used occasionally during the project as a support resource.
Before consulting AI, I first spent time trying to understand and solve the
problems on my own and discussing them with other 42 students through
peer-to-peer learning.

AI was mainly used for two purposes:
- helping clarify certain concepts related to variadic functions and formatted
  output when I realized there were fundamental details I had misunderstood or
  missed earlier in my learning process
- assisting with the writing and structure of the README documentation

The implementation of the project, the debugging process, and the overall
design of the solution were done manually after working through the problems
and discussing them with my colleagues.
