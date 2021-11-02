    /*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * Threads.cpp
 * c++ -std=c++20 Threads.cpp -o Threads -lpthread
 */

#include <iostream>
#include <sstream>
#include <thread>
 
 
#include "../Random.hpp"
#include "../osyncstream.hpp"

#include "Producer.hpp"
#include "Consumer.hpp"
#include "MessageBox.hpp"
 
/*
 * Test avec 1 producteur et 1 consommateur
 * On constate que le Consumer n'est pas synchronisé avec le Producer (donnant alors des messages -1)
 */
int main() {
    // Créer un générateur de nombres aléatoires
    // Créer une boîte à lettres
    // Créer un producteur et un consommateur
    // Créer les threads correspondants
    // Attendre la fin des threads

    // 20 messages will be transmitted between Producer and Consumer
    int nb_message_sent = 10;
    int nb_message_recieved = 20;

    Random engine( 100 );

    // Create the message box to send and recieve message
    MessageBox box;

    // Create proucers and consumers and their threads
    std::vector< std::thread > group;
    unsigned int i = 0;
    for (i=0; i<4; i++) {
        group.push_back( std::thread{ Producer { i, box, engine, 10}});
    }
    group.push_back( std::thread{ Consumer { ++i, box, engine, 20}});
    group.push_back( std::thread{ Consumer { ++i, box, engine, 20}});

    // Wait for other threads before ending
    for (int j=0;j<6; j++) {
        group[j].join();
    }

    return 0;
}

