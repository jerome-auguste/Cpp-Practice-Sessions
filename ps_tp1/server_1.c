/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmation système - TP n°1
 *
 * server_1.c
 */

// for printf()
#include <stdio.h>
// For rand(), srand(), sleep(), EXIT_SUCCESS
#include <stdlib.h>
// For time()
#include <time.h>
// For getpid(), getppid()
#include <unistd.h>

int main()
{
    // TODO
    int pid;
    int ppid;
    int rand_nb;
    while (1) {
        pid = getpid();
        ppid = getppid();
        rand_nb = rand() % 99 + 1;

        printf("Current pid: %d \r\nParent pid: %d \r\n", (pid, ppid)) ;
        printf("Random number: %d \r\n", rand_nb);

        sleep(1);
    }
    

    return EXIT_SUCCESS;
}

