# Milestone 2

Memory leaks and undefined behaviors are not tested in the milestone.

All of the test cases are very basic input, and we'll give hints on many common errors. You'll get -50% deduction of a certain (sub)task if you get a wrong answer in any of its cases.

## Tasks

### 6. Pipes: \[5+5+5+10\]

#### 6.1 Basic pipe support (e.g. echo 123 | grep 1); \[5\]

+ Case: 1-2

#### 6.2 Run all ‘stages’ of piped process in parallel. (e.g. yes ve482 | grep 482); \[5\]

+ Case: 3-4
+ Your shell is likely to get TLE (Time Limit Exceeded) if not running in parallel.

#### 6.3 Extend 6.2 to support requirements 4. and 5. (e.g. cat < 1.txt 2.txt | grep 1 > 3.txt); \[5\]

+ Case: 5-6
+ Input redirection can only be found in the first command, and output redirection can only be found in the last command.

#### 6.4. Extend 6.3 to support arbitrarily deep “cascade pipes” (e.g. echo 123 | grep 1 | grep 1 | grep 1) \[10\]

+ Case: 7-8

### 7. Support CTRL-D (similar to bash, when there is no/an unfinished command); \[5\]

+ Case: 9-10
+ Don't forget to print "exit" when exiting your shell

### 8. Internal commands: \[5+5+5\]

#### 8.1. Implement pwd as a built-in command; \[5\]

+ Case: 11

#### 8.2 Allow changing working directory using cd; \[5\]

+ Case: 12

#### 8.3. Allow pwd to be piped or redirected as specified in requirement 4.; \[5\]

+ Case: 13-14
+ eg. pwd | cat > 1.txt

### 9. Support CTRL-C: \[5+3+2+10\]

+ Your shell is likely to get TLE (Time Limit Exceeded) if CTRL-C is not handled correctly.
+ You should NOT use the kill syscall, especially kill(0, signal), it may destroy the judger. You will be sent to the honor council if you intentionally use it.

#### 9.1. Properly handle CTRL-C in the case of requirement 4.; \[5\]

+ Case: 15

#### 9.2. Extend 9.1 to support subtasks 6.1 to 6.3; \[3\]

+ Case: 16

#### 9.3. Extend 9.2 to support requirement 7., especially on an incomplete input; \[2\]

+ Case: 17

#### 9.4. Extend 9.3 to support requirement 6.; \[10\]

+ Case: 18



