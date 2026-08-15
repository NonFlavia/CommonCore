work in progress...
# Milestone 02 – Resources

A collection of study resources for the Milestone 02 exam.

I'm creating this repository to organize useful materials, improve my understanding of the topics, and find faster and more efficient ways to approach exercises during the exam.
It is important to understand logic behind an argument... You cannot remember how you solved an exercise but if you understood the logic behind it...
You may find a new way to do it. 

## C - our first love and our enemy.
## level 0 - Some tips.
**first word:**
Just remember to skip every space or tab at the beginning of the string. argc MUST be equal to 2.

- [first_word.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/first_word.c))

**fizz buzz:**
You can use math or you can brute-force it (yea, you can use a lot of "write", why not?). It doesn't matter: the fastest way is the best way.

- [fizz_buzz.c](work in progress)

**ft putstr:**
You can use the pointer to the string character directly with write, or use an int to loop through the string. Choose the method you remember best.
- [ft_putstr.c](work in progress)

**ft strcpy:**
Okay, maybe the man page can help, but in my opinion it can be a little confusing during the exam! 
A very short way to remember it: strcpy(dst, src) → copy src into dst.
strcpy does not check whether dest has enough space! So if dest is too small, it HAS to cause a buffer overflow.
You can compare your strcpy using the strcpy function in the library #include <string.h>
- [ft_strcpy.c](work in progress)

**ft strlen:**
ft_strlen counts the length of a string without including the null terminator \0. Remember this when using malloc in other exercises.
- [ft_strlen.c](work in progress)

**ft swap:**
Exchanges the values of two integers using pointers. A common confusion may be *:
int *a → a is a pointer to an int.
*a → the actual value stored at the address pointed to by a.
So you should not write a = int_to_swap, because in that case you are assigning a value to the pointer itself.
In ft_swap(int *a, int *b), remember to swap *a and *b: not the pointers themselves, but the values they point to.
- [ft_swap.c](work in progress)

**repeat alpha:**
My suggestion is to use an int to store the position in the alphabet of the character we are printing.
If 'a' is in str[i] 
→ value = str[i] - 'a' + 1.
That +1 is important because 'a' - 'a' is 0, but a must be printed once.
[repeat_alpha.c](work in progress)

**rev print:**
Make your own ft_strlen then use the length of the string to start from the last character and print backwards!
Remember: string indexes start from 0, so if len = ft_strlen(str), the last character is at str[len - 1]. str[len] is the null terminator \0.
little example: 
| char  | c | a | t | \0 |
|-------|---|---|---|----|
| index | 0 | 1 | 2 | 3  |
`len = 3`
Last char: `str[len - 1]` → `str[2]` → `'t'`
- [rev_print.c](work in progress)

**rot13:**
| Original | ROT13 |
|----------|-------|
| a        | n     |
| b        | o     |
| c        | p     |
| m        | z     |
| n        | a     |
| o        | b     |
| z        | m     |

% 26 makes the alphabet restart from a after z! So... keep it in mind!
- [rot13.c](work in progress)

**rotone:**
Same logic as rot_13 but move each letter only one position forward. % 26 makes z become a and Z become A!

Another way to do it is simply to handle z and Z as special cases, then use + 1 for every other letter.
- [rotone.c](work in progress)

**search and replace:**
be carefull to check that argv[2] and argv[3] are made by only one character.

- [search_and_replace.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/search_and_replace.c)

**last word:**
my tip here is very simple. After we found the end of the string, we have to skip possible ending spaces after the word we need to reach. 

I suggest to save the position after skipped spaces making a new int called "end". 

- [last_word.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/last_word.c)

**ulstr:**
Do not be afraid of that name. Lowercase letters become uppercase and uppercase letters become lowercase. Other characters stay unchanged!
That's all.
Easy trick: lowercase and uppercase letters are 32 positions apart in ASCII

- [ulstr.c](work in progress)


## level 1
### Resources
**sort in tab**
- [sort_int_tab](https://github.com/example/sort_int_tab](https://www.youtube.com/watch?v=qLVrwCvVPGo))


## level 3
**fprime**
- [fprime.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/fprime.c)
