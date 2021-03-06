/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmation système - TP n°1
 *
 * server_4.c
 */

//Lors d'un kill, bien que les fd soient close, l'un des processus n'envoie pas tous les signaux. Lorsque le child est kill,
//seuls ses signaux sont print, lorsqu'un parent est kill, ses signaux et le atexit du child sont print (mais il ne passe pas par
//le stop_handler)

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
    struct sigaction action;
    action.sa_handler = &stop_handler;
    action.sa_flags=0;

    //handling CTRL+C
    sigaction(SIGINT, &action, NULL);

    //handling 'kill' command
    sigaction(SIGTERM, &action, NULL);

    //handling pipe closing
    sigaction(SIGPIPE, &action, NULL);

    //pipe between parent and child
    int pipefd[2];
    int buf[3];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }


    //fork pid
    int cpid = fork();

    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {
        close(pipefd[1]);

        while (running) {

            if (read(pipefd[0], &buf, sizeof(buf))>0){
                printf("\nCurrent pid: %d\nParent pid: %d\n", buf[0], buf[1]) ;
                printf("Random number: %d\n", buf[2]);
                sleep(1);
            }
            else {
                running=false;
            }
        }

        close(pipefd[0]);
        
        
    }

    else {
        int pid = getpid();
        int ppid = getppid();
        int rand_nb;
        close(pipefd[0]);

        while (running) {

            rand_nb = rand() % 99 + 1;

            buf[0] = pid;
            buf[1] = ppid;
            buf[2] = rand_nb;
            write(pipefd[1], &buf, sizeof(buf));

            sleep(1);


        }

        close(pipefd[1]);

    }
    
    //Wait for child process to be ended before continuing
    //int waitstatus;
    //if (pid != cpid){
    //    wait(&waitstatus);
    //    printf("\nwexitstatus: %d\n", WEXITSTATUS(waitstatus));
    //}

    atexit(exit_message);
    

    return EXIT_SUCCESS;
}