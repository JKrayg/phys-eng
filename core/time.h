#pragma once

#include <chrono>


class Time {
public:
	std::chrono::high_resolution_clock::time_point last_time;
	double delta_time = 0.0;
	double accumulator = 0.0;


	Time() {
		last_time = std::chrono::high_resolution_clock::now();
	}

	void update_time() {
		auto current_time =  std::chrono::high_resolution_clock::now();
		delta_time = std::chrono::duration<double>(current_time - last_time).count();
		if (delta_time > 0.25) delta_time = 0.25;
		last_time = current_time;
		accumulator += delta_time;
		//accumulator += delta_time;
	}
};