# CAN Bus Simulation in C++

This project simulates a simple CAN (Controller Area Network) bus system in C++.

## 💡 Features
- Simulates CAN nodes (Engine, Dashboard, Brakes)
- Each node sends messages with a unique CAN ID
- Outputs data similar to a real CAN bus transmission

## 🧱 Structure
- `CANMessage`: Defines CAN message format
- `CANBus`: Simulates message broadcasting
- `CANNode`: Represents an ECU sending data

## 🚀 How to Run

```bash
g++ main.cpp -o can_sim
./can_sim
