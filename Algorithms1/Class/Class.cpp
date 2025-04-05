#include <iostream>
#include <unordered_map>
#include <string>
#include <thread>
#include <chrono>
#include <random>

class TrafficLightController {
private:
    struct Lane {
        int traffic;
        bool emergency;
    };

    std::unordered_map<std::string, Lane> lanes;
    std::string current_green;
    std::vector<std::string> cycle_order = { "North", "South", "East", "West" };
    int current_index = 0;
    std::chrono::time_point<std::chrono::steady_clock> last_update;
    std::mt19937 rng;

public:
    TrafficLightController() : rng(std::random_device{}()) {
        std::uniform_int_distribution<int> traffic_dist(5, 25);
        for (const auto& direction : cycle_order) {
            lanes[direction] = { traffic_dist(rng), false };
        }
        last_update = std::chrono::steady_clock::now();
    }

    void update_traffic() {
        std::cout << "\n--- Adding new traffic ---" << std::endl;
        std::uniform_int_distribution<int> new_traffic_dist(1, 3);
        for (auto& [lane, data] : lanes) {
            if (lane != current_green) {
                int new_vehicles = new_traffic_dist(rng);
                data.traffic += new_vehicles;
                std::cout << lane << ": +" << new_vehicles << " → " << data.traffic << std::endl;
            }
        }
    }

    void switch_light(const std::string& new_lane) {
        if (!current_green.empty()) {
            std::cout << "\n" << current_green << " → YELLOW (3s)" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << current_green << " → RED" << std::endl;
        }
        std::cout << "\n" << new_lane << " → GREEN (Initial traffic: " << lanes[new_lane].traffic << " vehicles)" << std::endl;
        current_green = new_lane;
    }

    void run_phase(int duration) {
        auto start_time = std::chrono::steady_clock::now();
        while (std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::steady_clock::now() - start_time)
            .count() < duration) {
            lanes[current_green].traffic = std::max(0, lanes[current_green].traffic - 2);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    void run() {
        try {
            while (true) {
                auto emergency_lane = std::find_if(lanes.begin(), lanes.end(), [](const auto& pair) {
                    return pair.second.emergency;
                    });

                if (emergency_lane != lanes.end()) {
                    std::cout << "\nEMERGENCY IN " << emergency_lane->first << "! Overriding signals..." << std::endl;
                    switch_light(emergency_lane->first);
                    run_phase(15);
                    emergency_lane->second.emergency = false;
                    continue;
                }

                std::string next_lane = cycle_order[current_index];
                current_index = (current_index + 1) % 4;
                switch_light(next_lane);

                int current_traffic = lanes[next_lane].traffic;
                int phase_duration = (current_traffic > 15) ? 15 : 10;
                std::cout << "Phase duration: " << phase_duration << "s (Traffic: " << current_traffic << " vehicles)" << std::endl;

                run_phase(phase_duration);

                if (std::chrono::duration_cast<std::chrono::seconds>(
                    std::chrono::steady_clock::now() - last_update).count() >= 30) {
                    update_traffic();
                    last_update = std::chrono::steady_clock::now();
                }
            }
        }
        catch (...) {
            std::cout << "\nSimulation stopped." << std::endl;
        }
    }
};

int main() {
    TrafficLightController controller;
    std::cout << "Initial traffic:" << std::endl;
    for (const auto& [lane, data] : controller.lanes) {
        std::cout << lane << ": " << data.traffic << " vehicles" << std::endl;
    }
    controller.run();
    return 0;
}
