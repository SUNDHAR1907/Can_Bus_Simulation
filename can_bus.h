#pragma once
#include "can_message.h"
#include <iostream>
#include <vector>
#include <functional>

class CANNode; // Forward declaration

class CANBus {
    std::vector<CANNode*> subscribers;

public:
    void subscribe(CANNode* node) {
        subscribers.push_back(node);
    }

    void transmit(const CANMessage& msg) {
        std::cout << "[CAN Bus] Transmitting ID: 0x" 
                  << std::hex << msg.id << " Data:";
        for (auto byte : msg.data) {
            std::cout << " 0x" << std::hex << static_cast<int>(byte);
        }
        std::cout << std::dec << std::endl;

        // Broadcast to all nodes
        for (auto* node : subscribers) {
            node->receive(msg);
        }
    }
};
