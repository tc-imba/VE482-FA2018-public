# Final Pretest

Memory leaks and undefined behaviors are not tested in the final pretest.

All of the test cases are very basic input, and we'll give hints on many common errors.


## Tasks

### 10. Support quotes: \[5+2+3+5\]

#### 10.1. Handle single and double quotes (e.g. echo "de'f' ghi" '123"a"bc' a b c); \[5\]

+ Case: 1-2

#### 10.2. Extend 10.1 to support requirement 4. and subtasks 6.1 to 6.3; \[2\]

+ Case: 3-4

#### 10.3.  Extend 10.2 in the case of incomplete quotes (e.g. Input echo "de, hit enter and input cd"); \[3\]

+ Case: 5-6
+ You should output "> " before after user hitting enter

#### 10.4. Extend 10.3 to support requirements 4. and 6., together with subtask 9.3; \[5\]

+ Not tested in the final pretest

### 11. Wait for the command to be completed when encountering >, <, or |: \[3+2\]

#### 11.1. Support requirements 3. and 4. together with subtasks 6.1 to 6.3; \[3\]

+ Case: 7-8 on ">"
+ Case: 9-10 on "<"
+ Case: 11-12 on "|"
+ ">>" don't need to be supported
+ You should output "> " before after user hitting enter

#### 11.2. Extend 11.1 to support requirement 10.; \[2\]

+ Case: 13-14
+ Actually 10.3 already has this functionality, so only need to extend to 10.1, 10.2, 10.4

### 12. Handle errors for all supported features. \[10\]

+ Case: 15-22
+ At most one of these error occurs in a command
+ Non-existing program (Case 15)
    - input: `non-exist abc def`
    - input: `echo abc | non-exist`
    - output: `non-exist: command not found`
+ Non-existing file in input redirection (Case 16)
    - input: `cat < non-existing.txt`
    - output: `non-existing.txt: No such file or directory`
+ Failed to open file in output redirection (Case 17)
    - input: `echo abc > /dev/permission_denied`
    - output: `/dev/permission_denied: Permission denied`
+ Duplicated input redirection (Case 18)
    - input: `echo abc < 1.txt < 2.txt`
    - input: `echo abc | grep abc < 1.txt`
    - output: `error: duplicated input redirection`
+ Duplicated output redirection (Case 19)
    - input: `echo abc > 1.txt > 2.txt`
    - input: `echo abc > 1.txt >> 2.txt`
    - input: `echo abc > 1.txt | grep abc`
    - output: `error: duplicated output redirection`
+ Syntax Error (Case 20)
    - input: `echo abc > > > >`
    - output: ```syntax error near unexpected token `>'```
    - input: `echo abc > < 1.txt`
    - output: ```syntax error near unexpected token `<'```
    - input: `echo abc > | grep abc`
    - output: ```syntax error near unexpected token `|'```
+ Missing program (Case 21)
    - input: `> abc | | grep 123`
    - output: `error: missing program`
+ `cd` to non-existing directory (Case 22)
    - input: `cd non-existing`
    - output: `non-existing: No such file or directory`

### 13. A command ending with an & should be run in background. \[10+5\]

#### 13.1. For any background job, the shell should print out the command line, prepended with the job ID \[10\]

+ Case: 23
+ Do not print the process ID.
+ Do not print complete information and "mumsh $" after the job is finished (like `bash` or `zsh`).
+ The job ID starts from 1.
+ Example:

```
Input:
/bin/ls &
sleep 0.2
/bin/ls | cat &
sleep 0.2
exit

Output:
mumsh $ [1] /bin/ls &
mumsh $ driver
mumsh
mumsh_memory_check
mumsh $ [2] /bin/ls | cat &
mumsh $ driver
mumsh
mumsh_memory_check
mumsh $ exit
```

#### 13.2. Implement the command jobs which prints a list of background tasks together with their running states \[5\]

+ Case: 24
+ Print all of done and running background processes in this shell.
+ Example:

```
Input:
/bin/ls &
sleep 0.2
sleep 0.2 &
jobs
sleep 0.4
exit

Output:
mumsh $ [1] /bin/ls &
mumsh $ driver
mumsh
mumsh_memory_check
mumsh $ [2] sleep 0.2 &
mumsh $ [1] done /bin/ls &
[2] running sleep 0.2 &
mumsh $ mumsh $ exit
```






