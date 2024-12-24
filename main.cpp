#include "database.h"
#include "httplib.h" // Lightweight HTTP server
#include "youtube_api.h"
#include <iostream>
#include <nlohmann/json.hpp> // For JSON conversion

using json = nlohmann::json;

int main() {
    const std::string apiKey = "AIzaSyBwbI-gvVhBedlMOPqxj5aIOQCgsGLaN6M";
    YouTubeAPI youtube(apiKey);
    Database db;

    httplib::Server server;

    // Endpoint to search YouTube videos
    server.Get("/api/search", [&](const httplib::Request& req, httplib::Response& res) {
        auto query = req.get_param_value("query");
        auto results = youtube.searchVideos(query);
        res.set_content(results.dump(), "application/json");
        });

    // Endpoint to fetch playlist data from the database
    server.Get("/api/playlist", [&](const httplib::Request& req, httplib::Response& res) {
        auto playlist = db.getPlaylist();

        // Convert playlist data to JSON
        json playlistJson;
        for (const auto& entry : playlist) {
            playlistJson.push_back(entry);
        }

        res.set_content(playlistJson.dump(), "application/json");
        });

    std::cout << "Server is running on http://localhost:8000\n";
    server.listen("localhost", 8000);

    return 0;
}
