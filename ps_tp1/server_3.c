/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmation système - TP n°1
 *
 * server_3.c
 */

//On peut distinguer les messages du père et du fils par leur PID, les deux processus s'arrêtent avec CTRL+C

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

bool running = true;

void stop_handler( int sig ) {
    printf("\nRecieved signal: %d \n", sig);
    running = false;
}

void exit_message() {
    printf("Allez bisous!\n");
}

int main()
{   
    int cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    int pid;
    int ppid;
    int rand_nb;

    struct sigaction action;
    action.sa_handler = &stop_handler;
    action.sa_flags=0;


    while (running) {
        //handling CTRL+C
        sigaction(SIGINT, &action, NULL);
        //handling 'kill' command
        sigaction(SIGTERM, &action, NULL);


        pid = getpid();
        ppid = getppid();
        rand_nb = rand() % 99 + 1;

        printf("Current pid: %d \r\nParent pid: %d \r\n", pid, ppid) ;
        printf("Random number: %d \r\n", rand_nb);

        sleep(1);
    }
    int i = atexit(exit_message);
    

    return EXIT_SUCCESS;
}