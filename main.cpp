#include "can_node.h"
#include <thread>
#include <chrono>

int main() {
    CANBus bus;

    CANNode engine("Engine ECU", bus);
    CANNode dashboard("Dashboard", bus);
    CANNode brake("Brake System", bus);

    // Set filters so only relevant nodes receive messages
    dashboard.addFilterID(0x101); // RPM
    dashboard.addFilterID(0x201); // Brake
    engine.addFilterID(0x301);    // Speed feedback
    brake.addFilterID(0x401);     // Warnings

    // Simulate sending messages
    engine.send(0x101, { 0x0F, 0xA0 }); // RPM = 4000
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    brake.send(0x201, { 0x01 }); // Brake applied
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    dashboard.send(0x301, { 0x00, 0x64 }); // Speed = 100 km/h
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    engine.send(0x401, { 0x55 }); // Warning code
}
