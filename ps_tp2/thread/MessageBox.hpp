/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * MessageBox.hpp
 */

#pragma once

#include <array>
#include <algorithm>
#include <mutex>
#include <condition_variable>

#include "../BasicMessageBox.hpp"

/*
 * FIFO d'echange de messages entre producteurs et consommateurs
 * Version pour synchronisation entre threads
 */
class MessageBox : public BasicMessageBox {
public:
    void put( int message ) {
        // TODO : ajouter les mecanismes de synchronisation
        std::unique_lock<std::mutex> lock(mutex_);

        // Wait for a free space
        if (nb_msg_ == box_size_) {
            free_space_.wait(lock);
        }

        // Send message
        basic_put( message );

        // One new message in the box
        nb_msg_++;
        
        // New message notification
        lock.unlock();
        new_msg_.notify_one();
    }
 
    int get() {
        // TODO : ajouter les mecanismes de synchronisation
        std::unique_lock<std::mutex> lock(mutex_);

        // Wait for a message to enter
        if (nb_msg_ == 0) {
            new_msg_.wait(lock);
        }

        // Read the message
        int message{ basic_get() };

        // One message removed from box
        nb_msg_--;

        // New free space
        free_space_.notify_one();
        return message;
    }
private:
    // TODO : ajouter les objets de synchronisation
    std::mutex mutex_;
    std::condition_variable new_msg_;
    std::condition_variable free_space_;
    int nb_msg_ = 0;

};
 
