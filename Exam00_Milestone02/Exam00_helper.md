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

- [first_word.c](work in progress)

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

**search and replace:**
be carefull to check that argv[2] and argv[3] are made by only one character.

- [search_and_replace.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/search_and_replace.c)

**last word:**
my tip here is very simple. After we found the end of the string, we have to skip possible ending spaces after the word we need to reach. 

I suggest to save the position after skipped spaces making a new int called "end". 

- [last_word.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/last_word.c)

## level 1
### Resources
**sort in tab**
- [sort_int_tab](https://github.com/example/sort_int_tab](https://www.youtube.com/watch?v=qLVrwCvVPGo))


## level 3
**fprime**
- [fprime.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/fprime.c)
