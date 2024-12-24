#include "youtube_api.h"
#include <curl/curl.h>
#include <iostream>

YouTubeAPI::YouTubeAPI(const std::string& key) : apiKey(key) {}

size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* out) {
    size_t totalSize = size * nmemb;
    out->append((char*)contents, totalSize);
    return totalSize;
}

nlohmann::json YouTubeAPI::searchVideos(const std::string& query) {
    std::string url = "https://www.googleapis.com/youtube/v3/search?part=snippet&type=video&q="
        + query + "&key=" + apiKey;

    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return nlohmann::json::parse(response);
}

nlohmann::json YouTubeAPI::getVideoDetails(const std::string& videoId) {
    std::string url = "https://www.googleapis.com/youtube/v3/videos?part=snippet&id="
        + videoId + "&key=" + apiKey;

    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return nlohmann::json::parse(response);
}
