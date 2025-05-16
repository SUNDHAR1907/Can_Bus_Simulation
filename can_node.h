#pragma once
#include "can_bus.h"
#include <string>
#include <set>
#include <iostream>

class CANNode {
    std::string name;
    CANBus& bus;
    std::set<unsigned int> filterIDs; // Acceptable message IDs

public:
    CANNode(std::string nodeName, CANBus& can) : name(nodeName), bus(can) {
        bus.subscribe(this);
    }

    void addFilterID(unsigned int id) {
        filterIDs.insert(id);
    }

    void send(unsigned int id, std::vector<uint8_t> data) {
        std::cout << "[" << name << "] Sending message...\n";
        CANMessage msg(id, data);
        bus.transmit(msg);
    }

    void receive(const CANMessage& msg) {
        if (filterIDs.count(msg.id)) {
            std::cout << "[" << name << "] Received message with ID: 0x" 
                      << std::hex << msg.id << " Data:";
            for (auto byte : msg.data) {
                std::cout << " 0x" << std::hex << static_cast<int>(byte);
            }
            std::cout << std::dec << "\n";
        }
    }
};
