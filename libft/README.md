*This project has been created as part of the 42 curriculum by flavides.*

# Libft (42 corsus) 
![I_did_it](https://pbs.twimg.com/media/EaK0F4XXgAUm-W_.jpg)
### Description 
Libft is a personal library designed with functions made to be the basis for more complex works that will follow into the 42course.  
Starting by understanding simple steps like ft_strlen (calculating the length of a string),  
and then using those simple steps to make it to the moon -> more complex function like ft_split ~~(no one loves you, split)~~.  
Last but not least, this project builds the fundamental programming skills that open the door to becoming part of the programming  community.  
The fundamental principles covered in this project include:
- Makefile  
- Readable code  
- Comments to remember what to do and how  

### Overview
* (1) Type of functions
* (2) Compilation
* (3) Makefile 
* (4) Detailed library description
* (5) Resources

### 1: Type of functions
External functions used: free, malloc, read write 

| Char Checks&Conversions | Memory                 | Handling Strings                                               | Conversion (strings) | File descriptor output          | Linked List functions            |
|--------------------------------|--------------------------------|---------------------------------------------------------------|--------------------|---------------------------------|----------------------------------------|
| ft_isalpha                      | ft_memset                       | ft_strlen                                                     | ft_atoi            | ft_putchar_fd                   | ft_lstnew                              |
| ft_isdigit                       | ft_bzero                        | ft_strdup                                                     | ft_itoa            | ft_putstr_fd                    | ft_lstadd_front                        |
| ft_isalnum                       | ft_memcpy                       | ft_strlcpy                                                    |                    | ft_putendl_fd                   | ft_lstadd_back                         |
| ft_isascii                       | ft_memmove                      | ft_strlcat                                                    |                    | ft_putnbr_fd                    | ft_lstsize                             |
| ft_isprint                       | ft_memchr                       | ft_strchr                                                     |                    |                                 | ft_lstlast                             |
| ft_toupper                       | ft_memcmp                       | ft_strrchr                                                    |                    |                                 | ft_lstdelone                           |
| ft_tolower                       | ft_calloc                       | ft_strncmp                                                    |                    |                                 | ft_lstclear                            |
|                                  |                                | ft_strnstr                                                    |                    |                                 | ft_lstiter                             |
|                                  |                                | ft_substr                                                     |                    |                                 | ft_lstmap                              |
|                                  |                                | ft_strjoin                                                    |                    |                                 |                                        |
|                                  |                                | ft_strtrim                                                    |                    |                                 |                                        |
|                                  |                                | ft_split                                                      |                    |                                 |                                        |
|                                  |                                | ft_strmapi                                                    |                    |                                 |                                        |
|                                  |                                | ft_striteri                                                   |                    |                                 |                                        |

### Compilation
Clone the repository:
```bash
git clone git@vogsphere.42firenze.it:vogsphere/intra-uuid-69ecb7cc-231a-438e-a012-978e3372252d-7201106-flavides
```

Build the library:
```bash
make
```
make -> it will create a libft.a


Clean object files:
```bash
make clean
```
make clean -> to clean all .o files

A better clean
```bash
make fclean
```
make fclean -> removes .o files + libft.a

Clean and remake
```bash
make re
```
make re -> fclean + make

Use the library in your own code base:
- Include the header:
```c
#include "libft.h"
```
- Compile linking the library:
```bash
cc -Wall -Wextra -Werror main.c libft.a
```
- How to use the library in other projects
```bash
gcc main.c -L. -lft
```

### Makefile
Makefile rules 🔧
- To compile libft with mandatory files: `make`
- To clean the working directory of object files (.o): `make clean`
- To clean the working directory of object files (.o) and archive (.a) files: `make fclean`
- To rebuild everything from scratch: `make re`

### Detailed library description
This project produces a static library called `libft.a` plus a header `libft.h`.  
The library contains re-implementations of common libc utilities and additional helpers.

**Character checks & conversions**  
Functions to validate and transform ASCII characters:
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_toupper`, `ft_tolower`

**Memory utilities**  
Functions that work on raw memory blocks (not necessarily strings):
- Set/zero memory: `ft_memset`, `ft_bzero`
- Copy/Move: `ft_memcpy`, `ft_memmove`
- Search/Compare: `ft_memchr`, `ft_memcmp`
- Allocate: `ft_calloc`

**String handling**  
Functions to measure, copy, join, trim, split and iterate over strings:
- Basic: `ft_strlen`, `ft_strdup`, `ft_strlcpy`, `ft_strlcat`
- Search: `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
- Substrings & composition: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- Functional helpers: `ft_strmapi`, `ft_striteri`

**Conversions**  
- `ft_atoi`: string to int  
- `ft_itoa`: int to string (allocates memory)

**File descriptor output**  
Helpers that write to a given fd (useful with `1` stdout, `2` stderr):
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

**Linked list functions**  
 `t_list` (defined in `libft.h`):
- Create & inspect: `ft_lstnew`, `ft_lstsize`, `ft_lstlast`
- Add nodes: `ft_lstadd_front`, `ft_lstadd_back`
- Delete & clear: `ft_lstdelone`, `ft_lstclear`
- Iterate & map: `ft_lstiter`, `ft_lstmap`

### Resources
Classic references used for this topic:
- `man malloc`, `man free`, `man write`, `man read`
- `man 3 strlen`, `man 3 memcpy`, `man 3 memmove`, `man 3 memset`, `man 3 calloc`
- The Manual (Makefile rules and targets)
- Great video tutorials
- Reaching out to colluegues for help
- 42 subject PDF 

>Using of AI: I used AI to calm my anxiety.


---
```bash
When I was at the beginning of the project,

I though it would've been an easy-peasy work to be done...

it was not Easy-peasy. Had to admit that took me more than I expected

but I'm glad I took my time to understand what I was doing

I m fully aware the codes may be still not perfect but they work

To not be lost in the rabbit-hole of perfectionism,

I decided to simply go on at my pace

> "Do or not do, there is no try"

And I did it!

So proud of my self sob sob 
```
![no_idea_but_it_works](https://scottdeluzio.com/wp-content/uploads/2017/08/i-dont-know-what-im-doing-cat-computer.gif)