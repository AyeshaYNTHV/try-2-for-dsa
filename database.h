#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

class Database {
public:
    Database(); // Constructor
    void executeQuery(const std::string& query); // Execute PostgreSQL command
    std::vector<std::string> getPlaylist(); // Retrieve playlist data
};

#endif // DATABASE_H

