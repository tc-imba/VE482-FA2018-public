# VE482 Project 1

The project have three stages:

+ Milestone 1: tasks 1 to 5 must be completed by September 25th;
+ Milestone 2: tasks 6 to 9 must be completed by October 6th;
+ Final shell: due on October 11th;

You can resubmit your code to test the previous stages, but it doesn't count into grades.
(eg. You can submit both milestone 1 and 2 in stage 2, but only the score of milestone 2 will be admitted.)

If you are using GNU Make and you meet an compile error like
```
error: implicit declaration of function 'xxx' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
```
It is because you didn't use the gnu standard of c. Add `-std=gnu11` instead of `-std=c11` to resolve this problem.
