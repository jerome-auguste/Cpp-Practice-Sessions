/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmation système - TP n°1
 *
 * server_5.c
 */

// for printf()
#include <stdio.h>
// For rand(), srand(), sleep(), EXIT_SUCCESS
#include <stdlib.h>
// For time()
#include <time.h>
// For getpid(), getppid()
#include <unistd.h>

#include <signal.h>
#include <stdbool.h>

// Wait for process
#include <sys/wait.h>

// For pipes
#include <unistd.h>

// For fifo
#include <fcntl.h>

bool running = true;

void stop_handler( int sig ) {
    printf("\nRecieved signal: %d \n", sig);
    running = false;
}

void exit_message() {
    printf("\nAllez bisous!\n");
}

int main() {   

    struct sigaction action;
    action.sa_handler = &stop_handler;
    action.sa_flags=0;

    // FIFO
    const char *fifopath = "/home/jerome/fifo";
    int fifofd = open(fifopath, O_WRONLY);
    int buf[3];

    //handling CTRL+C
    sigaction(SIGINT, &action, NULL);

    //handling 'kill' command
    sigaction(SIGTERM, &action, NULL);

    //handling pipe closing
    sigaction(SIGPIPE, &action, NULL);

    int pid = getpid();
    int ppid = getppid();
    int rand_nb;

    while (running) {

        rand_nb = rand() % 99 + 1;

        buf[0] = pid;
        buf[1] = ppid;
        buf[2] = rand_nb;

        if(write(fifofd, &buf, sizeof(buf))<0) {
            running=false;
        }

        sleep(1);

    }

    close(fifofd);

    atexit(exit_message);
    

    return EXIT_SUCCESS;
}