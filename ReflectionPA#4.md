# Reflection - Milestone #4

**_Goals for this milestone (in order of importance)_**

***1. Use the stronger design of the PPM viewer to my advantage***

***2. Try to learn what is going wrong with a function and how to fix it.***

This project felt like the catalyst that I needed to open my eyes to code that is designed for future implementation. When we first learned
about classes, I thought I understood what they were meant for but I did not truly understand until I saw how effective implementing them
into a program could be. So, when I was having a hard time trying to figure out how to implement the effects from the previous milestone
into this milestone. I realized that getHeight and getWidth would allow me to form the necessary connection from the .hpp file containing
the effect to the desired location in the EffectFactory. At this point, the previous solution that I had feels so obsolete that I could not
imagine a better solution than to use class definitions for calling functions from different .hpp and .cpp files in a program.

My second point and why I changed my second goal was the implementation of functions for the image effects. In the last project, I 
struggled to come up with a solution for each function. After using the advice given to me by the tutors, I was able to come up with what
looked like good code for each effect. This lead me to the hardest part of working on the PPM viewer, dealing with all of the vector 
subscript errors. As someone who had little experience with vectors, seeing that error message horrified me. The code would compile just 
fine and I was greeted with a happy bunny. However, when I clicked on the effect button the program would crash with a vector subscript 
error at line 1455. After talking with other students about their problems, they told me that they had gone through the same thing and that
the error likely meant that I had a variable or two that was out of place. With a fresh night's sleep and the help of the debugger, I was
able to determine surprisingly quickly that my fellow student's were right. I then repeated this process for the rest of the project. 
Needless to say, if I had not asked the tutors and other students for help and advice, I would have not completed this assignment and would
have doubted my skills as a programmer. However, they helped me turn it around and understand that the struggle was necessary for the 
learning process. 
