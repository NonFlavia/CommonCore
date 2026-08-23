Hi! This was made by flavides during the 42 Firenze Common Core.

### Disclaimer

All folders in this Common Core repository represent my personal learning journey at 42 Firenze.
I do not claim ownership of the project subjects, modules, curriculum, or educational methodology provided by 42. This repository exists solely as a portfolio of the projects I created during this journey.
I will not publish or redistribute the original project subjects.


### About Python modules
I am currently working through the Python modules, and I do not think every single one needs to be posted on GitHub.

Modules 0 through 4 are fairly approachable. Module 4 might deserve a little more attention, but we will see.

And then comes the real game changer: Module 5... Called Code Nexus.

My first impression is that the transition from the previous modules does not feel entirely gradual. Rather than simply expanding on familiar topics; Code Nexus introduces several new ideas at once, almost as if we were beginning a completely different subject. It is interesting and challenging but it can also be frustrating when its connection with the earlier material is not immediately clear.

<details>
<summary><strong> -> Milestone 02 —> Read this if you are struggling</strong></summary>

### Milestone 02 a lot to know, a lot to process.

Please do not get me wrong: I genuinely love 42 and this is my honest feedback based on personal experience. 
This milestone sometimes seems to expect students to absorb a large amount of unfamiliar material very quickly. 
However not everyone begins with the same background... And some of us need more time and repetition 
before everything starts to make sense. 
Milestone 02 can simply feel particularly demanding because it combines so many goals at once.
That is completely normal. 

If you are struggling with it, you are probably not alone. 
You might not understand something the first, second or even third time you encounter it. 
Keep going through it one piece at a time. Eventually, the pieces will begin to connect.

Seriously. Talk to your friends, compare your approaches and ask them to explain what you cannot understand yet.
Sometimes one sentence from someone who has faced the same difficulty can be more helpful than ten pages of documentation.
They might have to explain it to you ten times before it finally clicks. 
Well, those are ten explanations well spent and one day... You might do the same for them!

This time, let AI help you. It can find short video tutorials, introduce the foundations before you approach an exercise, explain difficult ideas in simpler language, and help you stay sane while you continue moving forward. Just remember to question its answers, and make sure you truly understand everything you submit.

</details>

## Module 5: Code Nexus

### Exercise 0: Data Processor 🐈
### Short videos before Exercise 0 (ENG) 🎥 ###
Before studying the code, these short videos can help with the main concepts:

1. [Learn Python abstract classes in 7 minutes](https://www.youtube.com/watch?v=97V7ICVeTJc)  
   `ABC` → `@abstractmethod` → rules for subclasses

2. [Python inheritance in 6 minutes](https://www.youtube.com/watch?v=u1be7Vele5o)  
   Parent classes → subclasses → inherited methods

3. [Learn polymorphism in 8 minutes](https://www.youtube.com/watch?v=tHN8I_4FIt8)  
   Method overriding → same rules → different behaviors
   
5. [Abstract classes in one minute](https://www.youtube.com/shorts/Loz0rZ1gQWY)  
   Optional English recap.

### Short videos before Exercise 0 (ITA with last video in ENG) 🎥 ###
Before studying the code, these short videos can help with the main concepts:

1. [Abstract classes in Python](https://www.youtube.com/watch?v=kUD9TokdKvg)  
   `ABC` → `@abstractmethod` → rules for subclasses

2. [Inheritance and polymorphism](https://www.youtube.com/watch?v=pmbRRJaplh0&t=535s)  
   Start at `8:55` → inheritance → overriding → different behaviors

3. [Abstract classes in one minute](https://www.youtube.com/shorts/Loz0rZ1gQWY)  
   Optional English recap.

Recommended order:

`Abstract classes → Inheritance and polymorphism → Exercise 0 code`

### My little explanation ###

`DataProcessor` → defines the common rules:

`validate` → Is the data acceptable?  
`ingest` → Transforms and stores the data  
`output` → Returns and removes the oldest stored item  

The subclasses (or childclasses) follow the same rules with different data:

- `NumericProcessor` → `[3, 4.5]` → `"3"`, `"4.5"`
- `TextProcessor` → `["Micio", "Luna"]` → `"Micio"`, `"Luna"`
- `LogProcessor` → `{"log_level": "INFO", "log_message": "Cat arrived"}` → `"INFO: Cat arrived"`

FIFO order:

`Micio enters → Luna enters → output()` → `Micio` leaves first.

In short:

*Same rules → different processors → specialized behaviors.*
