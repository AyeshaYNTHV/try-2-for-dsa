#pragma once
#ifndef SONG_QUEUE_H
#define SONG_QUEUE_H

#include <queue>
#include <string>

class SongQueue {
private:
    std::queue<std::string> queue;

public:
    void enqueue(const std::string& videoId) {
        queue.push(videoId);
    }

    void dequeue() {
        if (!queue.empty()) {
            queue.pop();
        }
    }

    std::string front() const {
        return queue.empty() ? "No song in queue" : queue.front();
    }

    bool isEmpty() const {
        return queue.empty();
    }
};

#endif
