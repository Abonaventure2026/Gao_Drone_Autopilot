// Copyright (c) 2026 Yongji Gao. All Rights Reserved.
// License: Commercial Proprietary - See LICENSE file.
// Project: Gao_Drone_Autopilot | UUID: d616a335eb10
// Build: 2026-06-05_19-22-25

#include <iostream>
#include <signal.h>
#include <thread>
#include <chrono>
volatile sig_atomic_t keep_running = 1;
void signal_handler(int) { keep_running = 0; }
int main() {
    signal(SIGINT, signal_handler);
    std::cout << "Gao Autopilot " << __VERSION__ << " - Build successful\n";
    while (keep_running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return 0;
}
