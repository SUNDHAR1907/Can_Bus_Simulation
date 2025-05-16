#pragma once
#include <vector>

struct CANMessage {
    unsigned int id;
    std::vector<uint8_t> data;

    CANMessage(unsigned int id, std::vector<uint8_t> data)
        : id(id), data(data) {}
};
