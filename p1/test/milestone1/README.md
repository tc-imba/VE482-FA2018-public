# Milestone 1

Memory leaks and undefined behaviors are not tested in the milestone.

All of the test cases are very basic input, and we'll give hints on many common errors. You'll get -50% deduction of a certain (sub)task if you get a wrong answer in any of its cases.

For example, if you get accepted in task 4.1 - 4.3, but get wrong answer in task 4.4, you will get a deduction of one mark (half of the total 2 marks).

## Tasks

### 1. Write a working read/parse/execute loop and an exit command; \[5\]

+ Case: 1
+ Don't forget to print "exit" when exiting your shell

### 2. Handle single commands without arguments (e.g. ls); \[5\]

+ Case: 2-4
+ One of test command is exactly "ls"

### 3. Support commands with arguments (e.g. apt-get update or pkgin update); \[5\]

+ Case: 5-6
+ One of test command is exactly "ls -al"

### 4. File I/O redirection: \[5+5+5+2\]

#### 4.1 Output redirection by overwriting a file (e.g. echo 123 > 1.txt); \[5\]

+ Case: 7-8

#### 4.2 Output redirection by appending to a file (e.g. echo 465 >> 1.txt); \[5\]

+ Case: 9-10

#### 4.3 Input redirection (e.g. cat < 1.txt) \[5\]

+ Case: 11-12
+ Should complete task 4.1 before this task

#### 4.4 Combine 4.1 and 4.2 with 4.3; \[2\]

+ Case: 13-14
+ Should complete task 4.1 - 4.3 before this task

### 5 Support for bash style redirection syntax (e.g. cat < 1.txt 2.txt > 3.txt 4.txt); [8]

+ Case: 15-18
+ Space are not needed between <,>,>> and other characters  (16)
+ The position of <,>,>> can be arbitrary (17)
