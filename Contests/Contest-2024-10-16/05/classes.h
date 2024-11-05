#pragma once

#include <queue>

class OSUpdater : public IRunnable {
public:
    void run() {
        std::cout << "OSUpdater\n";
    }
};

class Alarm : public IRunnable {
public:
    void run() {
        std::cout << "Alarm\n";
    }
};

class ActivityChecker : public IRunnable {
public:
    void run() {
        std::cout << "ActivityChecker\n";
    }
};

class Clock : public IRunnable, public IClock {
private:
    std::queue<std::pair<Time, IRunnable*>> tasks;
public:
    void add(IRunnable* client, Time time) {
        tasks.push({time, client});
    }
    bool next() {
        if (tasks.empty()) {
            return false;
        }
        auto cur = tasks.front();
        tasks.pop();
        std::string hours, minutes, seconds;
        if (cur.first.hours < 10) {
            hours = "0";
        }
        hours += std::to_string(cur.first.hours);
        if (cur.first.minutes < 10) {
            minutes = "0";
        }
        minutes += std::to_string(cur.first.minutes);
        if (cur.first.seconds < 10) {
            seconds = "0";
        }
        seconds += std::to_string(cur.first.seconds);
        std::cout << hours << ":" << minutes << ":" << seconds << " ";
        cur.second->run();
        return true;
    }
    void run() {
        while(next());
    }
};
