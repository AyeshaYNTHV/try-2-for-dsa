#ifndef YOUTUBE_API_H
#define YOUTUBE_API_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

class YouTubeAPI {
private:
    std::string apiKey;

public:
    YouTubeAPI(const std::string& key);
    nlohmann::json searchVideos(const std::string& query);
    nlohmann::json getVideoDetails(const std::string& videoId);
};

#endif
