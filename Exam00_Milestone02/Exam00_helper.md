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

- [first_word.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/first_word.c)

**fizz buzz:**
You can use math or you can brute-force it (yea, you can use a lot of "write", why not?). It doesn't matter: the fastest way is the best way.

- [fizz_buzz.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/fizz_buzz.c)
- [fizz_buzz_hardcoded.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/fizz_buzz_hardcoded.c)

**ft putstr:**
You can use the pointer to the string character directly with write, or use an int to loop through the string. Choose the method you remember best.
- [ft_putstr.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/ft_putstr.c)

**ft strcpy:**
Okay, maybe the man page can help, but in my opinion it can be a little confusing during the exam! 
A very short way to remember it: strcpy(dst, src) → copy src into dst.
strcpy does not check whether dest has enough space! So if dest is too small, it HAS to cause a buffer overflow.
You can compare your strcpy using the strcpy function in the library #include <string.h>
- [ft_strcpy.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/ft_strcpy.c)

**ft strlen:**
ft_strlen counts the length of a string without including the null terminator \0. Remember this when using malloc in other exercises.
- [ft_strlen.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/ft%20strlen.c)

**ft swap:**
Exchanges the values of two integers using pointers. A common confusion may be *:
int *a → a is a pointer to an int.
*a → the actual value stored at the address pointed to by a.
So you should not write a = int_to_swap, because in that case you are assigning a value to the pointer itself.
In ft_swap(int *a, int *b), remember to swap *a and *b: not the pointers themselves, but the values they point to.
- [ft_swap.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/ft_swap.c)



**repeat alpha:**
My suggestion is to use an int to store the position in the alphabet of the character we are printing.
If 'a' is in str[i] 
→ value = str[i] - 'a' + 1.
That +1 is important because 'a' - 'a' is 0, but a must be printed once.
- [repeat_alpha.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/repeat_alpha.c)

**rev print:**
Make your own ft_strlen then use the length of the string to start from the last character and print backwards!
Remember: string indexes start from 0, so if len = ft_strlen(str), the last character is at str[len - 1]. str[len] is the null terminator \0.
little example: 
| char  | c | a | t | \0 |
|-------|---|---|---|----|
| index | 0 | 1 | 2 | 3  |
`len = 3`
Last char: `str[len - 1]` → `str[2]` → `'t'`
- [rev_print.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/rev_print.c)

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
- [rot13.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/rot_13.c)

**rotone:**
Same logic as rot_13 but move each letter only one position forward. % 26 makes z become a and Z become A!

Another way to do it is simply to handle z and Z as special cases, then use + 1 for every other letter.
- [rotone.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/rotone.c)

**search and replace:**
be carefull to check that argv[2] and argv[3] are made by only one character.

- [search_and_replace.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/search_and_replace.c)


**ulstr:**
Do not be afraid of that name. Lowercase letters become uppercase and uppercase letters become lowercase. Other characters stay unchanged!
That's all.
Easy trick: lowercase and uppercase letters are 32 positions apart in ASCII

- [ulstr.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_0/ulstr.c)

## level 1 - okay, a little more logic

**alpha mirror:** every letter becomes its opposite in the alphabet. a → z, b → y, c → x and so on.

- [alpha_mirror.c]((https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/alpha_mirror.c)

**camel to snake:** if you find an uppercase letter, print _ and then the same letter in lowercase.

helloWorld → hello_world

- [camel_to_snake.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/camel_to_snake.c)

**do op:** you have two numbers and an operator. check which operation you have to do and print the result. that's it.

- [do_op.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/do_op.c)

**ft atoi:** turn a string into an int. skip spaces, check the sign and then read the numbers one by one.

remember: result = result * 10 + digit

- [ft_atoi.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/ft_atoi.c)

**ft strcmp:** compare the two strings char by char. when you find something different, return the difference.

- [ft_strcmp.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/ft_strcmp.cs)

**ft strcspn:** keep counting until you find a char that is also inside the second string.

- [ft_strcspn.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/ft_strcspn.c)

**ft strdup:** basically make a copy of a string using malloc. remember to leave space for \0!

- [ft_strdup.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/ft_strdup.c)

**ft strpbrk:** find the first char of the first string that also exists in the second one. return where you found it.

- [ft_strpbrk.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/ft_strpbrk.c)

**ft strrev:** reverse the string by swapping chars from the outside to the inside.

left → ← right

- [ft_strrev.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/ft_strrev.c)

**ft strspn:** keep counting while the chars are inside the second string. if one is not there, stop.

- [ft_strspn.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/ft_strspn.c)

**is power of 2:** keep dividing by 2. if you reach 1, good.

8 → 4 → 2 → 1

- [is_power_of_2.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/is_power_of_2.c)

**inter:** scan the first string and check if each char also exists in the second one. if yes, print it, but only once. the order comes from the first string.

example: padinton + paqefwiatgopsnh → padinto

- [inter.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/iter.c)

**last word:**
my tip here is very simple. After we found the end of the string, we have to skip possible ending spaces after the word we need to reach. 

I suggest to save the position after skipped spaces making a new int called "end". 

- [last_word.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/last_word.c)

**max:** keep the biggest number you found. if you find something bigger, update it. be careful with negative numbers eheh.

- [max.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/max.c)

**print bits:** print the 8 bits of an unsigned char.

2 → 00000010

- [print_bits.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/print_bits.c)

**reverse bits:** same bits, opposite order.

00100110 → 01100100

- [reverse_bits.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/reverse_bits.c)

**snake to camel:** when you find _, skip it and make the next letter uppercase.

hello_world → helloWorld

- [snake_to_camel.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/snake_to_camel.c)

**swap bits:** take the first 4 bits and the last 4 bits and swap them.

1010 0011 → 0011 1010

- [swap_bits.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/swap_bits.c)

**union:** read the first string and then the second one. print every char only once. no doubles!

- [union.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/union.c)

**wdmatch:** scan the second string looking for the chars of the first one in the right order. every time you find one, move to the next. if you reach the end of the first string, print it.

- [wdmatch.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/level_1/wdmatch.c)



## level 3
**fprime**
- [fprime.c](https://github.com/NonFlavia/CommonCore/blob/main/Exam00_Milestone02/fprime.c)
