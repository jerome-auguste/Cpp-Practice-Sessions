/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmation système - TP n°1
 *
 * server_3.c
 */

//On peut distinguer les messages du père et du fils par leur PID, les deux processus s'arrêtent avec CTRL+C

//A l'aide de la commande kill sur le processus fils, le processus père continue de s'exécuter mais le processus fils n'est pas
//toujours visible ("[server_3] <defunct>"), lorsque l'on kill le père, les deux processus disparaissent

//Lorsque l'on tue le père en premier, le processus père disparaît et le processus fils continue de s'exécuter, on peut toujours
//kill le processus fils

//A l'aide de wait, on peut lancer le processus père lorsque le processus fils est kill.
//Le code renvoyé est 0 pour un kill ou un kill -s INT, et 9 pour un kill -9


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

bool running = true;

void stop_handler( int sig ) {
    printf("\nRecieved signal: %d \n", sig);
    running = false;
}

void exit_message() {
    printf("\nAllez bisous!\n");
}

int main()
{   
    //fork pid with error handling
    int cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    //Wait for child process to be ended before continuing
    int waitstatus;
    wait(&waitstatus);

    printf("\nwaitstatus: %d\n", waitstatus);

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

        printf("\nCurrent pid: %d\nParent pid: %d\n", pid, ppid) ;
        printf("Random number: %d\n", rand_nb);

        sleep(1);
    }
    int i = atexit(exit_message);
    

    return EXIT_SUCCESS;
}