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
    int nb_message = 20;

    Random engine( 100 );

    // Create the message box to send and recieve message
    MessageBox box;

    // Create proucer and consumer
    Producer prod = Producer(0, box, engine, nb_message);
    Consumer cons = Consumer(1, box, engine, nb_message);

    // Create producer thread and consumer thread
    std::thread producer_thread(prod);
    std::thread consumer_thread(cons);

    // Wait for other threads before ending
    producer_thread.join();
    consumer_thread.join();

    return 0;
}

