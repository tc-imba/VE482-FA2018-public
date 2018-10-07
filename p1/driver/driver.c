//
// Created by liu on 18-9-20.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void kill_subprocess(int ppid, int dunno) {
    fprintf(stderr, "Scan child pids of ppid: %d\n", ppid);
    int fd[2];
    pipe(fd);
    int new_pid = fork();
    if (new_pid == 0) {
        char ppid_str[10];
        sprintf(ppid_str, "%d", ppid);
        close(fd[0]);
        close(STDOUT_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        char *const __argv[] = {"ps", "--ppid", ppid_str, NULL};
        execvp(__argv[0], __argv);
    } else {
        kill(ppid, dunno);
        fprintf(stderr, "Send signal %d to pid: %d\n", dunno, ppid);
        close(fd[1]);
        FILE *fp = fdopen(fd[0], "r");
        char buf[1024];
        fgets(buf, sizeof buf, fp);
        while (fgets(buf, sizeof buf, fp) != NULL) {
            int child_pid;
            sscanf(buf, "%d", &child_pid);
            kill_subprocess(child_pid ,dunno);
        }
        close(fd[0]);
    }
}

void sigroutine(int dunno) {
    if (dunno == SIGINT) {
        fprintf(stderr, "SIGINT\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        exit(1);
    }
    int fd[2];
    pipe(fd);
    int pid = fork();
    if (pid > 0) {
        signal(SIGINT, sigroutine);
        char buf[2048] = {0};
        int ppid = getpid();
        getcwd(buf, sizeof(buf));
        fprintf(stderr, " pwd: %s\n", buf);
        fprintf(stderr, "ppid: %d\n", ppid);
        close(fd[0]);
        close(STDOUT_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        size_t lineno = 0;
        while (fgets(buf, sizeof buf, stdin) != NULL) {
            usleep(100000);
            lineno++;
            size_t len = strlen(buf);
            if (buf[len - 1] == '\n') {
                buf[len - 1] = '\0';
            }
            char *line = strchr(buf, ' ');
            if (line) {
                *(line++) = '\0';
            } else {
                line = buf + len - 1;
            }
            char *command = buf;
            if (strcmp(command, "WRITE") == 0) {
                printf("%s", line);
                fprintf(stderr, "%4zu: WRITE %s\n", lineno, line);
            } else if (strcmp(command, "WRITELN") == 0) {
                printf("%s\n", line);
                fprintf(stderr, "%4zu: WRITELN %s\n", lineno, line);
            } else if (strcmp(command, "CTRL") == 0) {
                if (line[0] == 'C') {
                    fprintf(stderr, "%4zu: CTRL+C\n", lineno);
                    kill_subprocess(ppid, SIGINT);
                } else if (line[0] == 'D') {
                    fprintf(stderr, "%4zu: CTRL+D\n", lineno);
                }
            }
            fflush(stdout);
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        close(STDIN_FILENO);
        dup2(fd[0], STDIN_FILENO);
        dup2(STDOUT_FILENO, STDERR_FILENO);
//         dup2(STDERR_FILENO, STDOUT_FILENO);
        char *const _argv[] = {argv[1], NULL};
        execvp(_argv[0], _argv);
    }
    return 0;
}
