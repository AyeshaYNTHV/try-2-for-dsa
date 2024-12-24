#pragma once
								  #ifndef PLAYLIST_LINKED_LIST_H
#define PLAYLIST_LINKED_LIST_H

#include <string>
#include <iostream>

struct PlaylistNode {
    std::string title;
    std::string videoId;
    PlaylistNode* next;

    PlaylistNode(const std::string& t, const std::string& v)
        : title(t), videoId(v), next(nullptr) {}
};

class PlaylistLinkedList {
private:
    PlaylistNode* head;

public:
    PlaylistLinkedList() : head(nullptr) {}

    void addSong(const std::string& title, const std::string& videoId) {
        PlaylistNode* newNode = new PlaylistNode(title, videoId);
        if (!head) {
            head = newNode;
        } else {
            PlaylistNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayPlaylist() const {
        PlaylistNode* temp = head;
        while (temp) {
            std::cout << "Title: " << temp->title << ", Video ID: " << temp->videoId << std::endl;
            temp = temp->next;
        }
    }
};

#endif
