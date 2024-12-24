#include "database.h"
#include <iostream>
#include <cstdlib>  // For system() function
#include <fstream>  // For reading query output files

Database::Database() {
    // Constructor - Optional initialization code can go here
}

// Function to execute a single PostgreSQL query
void Database::executeQuery(const std::string& query) {
    std::string dbname = "music_playlist_manager";
    std::string user = "postgres";
    std::string password = "123blink!";
    std::string host = "localhost";
    std::string port = "5433";

    // Set PostgreSQL password environment variable using _putenv
    std::string env = "PGPASSWORD=" + password;
    _putenv(env.c_str());


    // Command to execute SQL query
    std::string command = "psql -h " + host +
        " -p " + port +
        " -U " + user +
        " -d " + dbname +
        " -c \"" + query + "\"";

    std::cout << "Executing query: " << query << std::endl;
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Query executed successfully.\n";
    }
    else {
        std::cerr << "Error executing query.\n";
    }
}

// Function to retrieve the playlist from the database
std::vector<std::string> Database::getPlaylist() {
    std::string dbname = "music_playlist_manager";
    std::string user = "postgres";
    std::string password = "123blink!";
    std::string host = "localhost";
    std::string port = "5433";

    // Output file for query result
    std::string outputFile = "playlist_output.txt";

    // Set PostgreSQL password environment variable using _putenv
    std::string env = "PGPASSWORD=" + password;
    _putenv(env.c_str());

    // SQL command to fetch playlist and save to a file
    std::string command = "psql -h " + host +
        " -p " + port +
        " -U " + user +
        " -d " + dbname +
        " -c \"SELECT title, artist FROM songs;\" > " + outputFile;

    std::cout << "Fetching playlist...\n";
    system(command.c_str());

    // Parse the output file and return the playlist as a vector of strings
    std::vector<std::string> playlist;
    std::ifstream file(outputFile);
    std::string line;

    while (getline(file, line)) {
        if (line.find("|") != std::string::npos) { // Skip headers and separators
            playlist.push_back(line);
        }
    }

    file.close();
    return playlist;
}
