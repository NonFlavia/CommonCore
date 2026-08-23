*This project has been created as part of the 42 curriculum by flavides.*

# 🐱 get_next_line

## 🧩 Description

`get_next_line` is a function that reads from a file descriptor and returns **one line at a time**, including the newline (`\n`) when present.

At first glance, it looks simple.  
It is not.

The goal of this project is to understand:
- how reading from a file actually works (`read`)
- how to manage memory dynamically
- how to preserve data between function calls
- how to deal with partial reads and incomplete lines

The real difficulty comes from the fact that you **cannot read everything at once**, and you must carefully reconstruct each line step by step.

---

## ⚙️ Instructions

### Compilation

Firstly you have to take the main from commented section

```bash
cc -Wall -Wextra -Werror  -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c
```

For the bonus:

```bash
cc -Wall -Wextra -Werror  -D BUFFER_SIZE=n get_next_line_bonus.c get_next_line_utils_bonus.c
```


---

## 🧠 Algorithm explanation

The core idea of my implementation is based on **progressive reading + accumulation**.

1. Read from the file using `read` into a buffer
2. Append the buffer to a persistent string
3. Stop reading when a newline is found
4. Extract the current line from the stash
5. Save the remaining part for the next call

Example -> BUFFER_SIZE = 3
in txt file -> 'F' ''\n'' 'a' 'v' 'i' 'a'
static *string = 'F' '\n' 'a' '\0'
we have to ret F'\n'... but what about the 'a'?
we save the a for the next read so that we can add it to 
the next line to return. 

This logic is implemented mainly in:
- `ft_readandsave`
- `ft_getline`
- `ft_getrest`

The most important part is the static variable:

```c
static char *str;
```

(or an array in bonus)

This variable allows the function to **remember what was read but not yet returned**.
The concept i coudn't seem to understand was that... 
when you read in a static variable (static char*)
the static char* allows it to remember when it stopped reading! 

---

## 🐱 How I actually understood it (real explanation)

There are MANY ways to implement this project.  
Too many.

And that can honestly lead to a kind of paralysis where you keep asking:
👉 *“what is the best way to do this?”*

The truth is:

👉 **the best way is the one you understand.**

Personally:
- I wrote a lot of **pseudocode first**
- I split everything into **small functions**
- because when functions get too long, I completely lose the thread

And most importantly:

I literally drew **cats on paper**.

### 🐱 The cat model

- The cat eats until it finds a newline → that's one line  
- Then it stops  
- But there is still food left  
- So the cat hides it for later  

That hidden food is called `stash`.

No joke, this is what made it click.

---

## ⚠️ Technical choices

- Small, focused functions (easier to debug and reason about)
- Custom string utilities instead of libc helpers
- Loop stops only when newline is found or EOF is reached
- Memory is freed progressively to avoid leaks

---

## 🧪 Edge cases handled

- `BUFFER_SIZE = 1`
- Empty files
- Files without newline at the end
- Invalid file descriptors
- Read errors

---

## 📚 Resources

### 📖 Documentation
- https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line  
- https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/
- 📘 *Come vincere la paura della matematica* – Sheila Tobias

### 🎥 Videos
- https://www.youtube.com/watch?v=kR4FyNzVDBE  
- https://www.youtube.com/watch?v=wa1HzkMqY9A  
- https://youtube.com/shorts/2wSjkWHht-k  

### For bonuses
- I asked to my friend how he did that (eheh)
---

### 🤖 AI usage

AI was used for:
- reviewing explanations for memory leak and improving understanding
- helping structure the README

AI was **not used to generate codes**, which was written and understood step by step through practice and debugging.

---

## 💬 Final thoughts

This project is where things stop being “just code” and start being about:
- memory
- flow
- understanding what actually happens under the hood

At some point:
- you stop copying patterns
- you start reasoning

And weirdly enough…

drawing cats helps.
