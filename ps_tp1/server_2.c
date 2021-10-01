/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmation système - TP n°1
 *
 * server_2.c
 */

//Lorsque le processus est kill depuis un autre terminal avec l'option -s INT, le message apparaît, toutefois, lorsqu'il
//n'y a pas les options, le message n'apparaît pas
//Handle SIGTERM permet d'afficher le message lorsque le processus est kill sans argument
//Avec les options -s KILL, le message n'apparaît pas


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

int main()
{   
    // TODO
    int pid;
    int ppid;
    int rand_nb;

    struct sigaction action;
    action.sa_handler = &stop_handler;
    action.sa_flags=0;


    while (running) {
        sigaction(SIGINT, &action, NULL);
        sigaction(SIGTERM, &action, NULL);
        pid = getpid();
        ppid = getppid();
        rand_nb = rand() % 99 + 1;

        printf("Current pid: %d \r\nParent pid: %d \r\n", pid, ppid) ;
        printf("Random number: %d \r\n", rand_nb);

        sleep(1);
    }
    

    return EXIT_SUCCESS;
}