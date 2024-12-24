#pragma once
#ifndef SONG_STACK_H
#define SONG_STACK_H

#include <stack>
#include <string>

class SongStack {
private:
    std::stack<std::string> stack;

public:
    void push(const std::string& videoId) {
        stack.push(videoId);
    }

    void pop() {
        if (!stack.empty()) {
            stack.pop();
        }
    }

    std::string top() const {
        return stack.empty() ? "No previous songs" : stack.top();
    }

    bool isEmpty() const {
        return stack.empty();
    }
};

#endif
