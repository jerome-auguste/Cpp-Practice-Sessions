/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * Consumer.hpp
 */

#pragma once

#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdio.h>

#include "../osyncstream.hpp"

#include "ProdOrCons.hpp"
 
/*
 * Consommateur de messages
 */
class Consumer : public ProdOrCons {
public:
    // Le constructeur de ProdOrCons sera utilisé comme constructeur de Consumer
    using ProdOrCons::ProdOrCons;
 
    void operator()() override {
        // TODO : déposer dans box nb_messages nombres entiers positifs avec attente
        // aléatoire entre chaque. Afficher des messages, via un osyncstream,
        // pour suivre l'avancement.
        for (int i=0; i<=nb_messages_; i++) {
            std::this_thread::sleep_for( std::chrono::milliseconds( random_engine_() ));
            { osyncstream( std::cout ) << name_ << " recieved " << box_.get() << "\n";}
        }
        

    }
};

