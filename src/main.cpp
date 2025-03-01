#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

constexpr int PORT = 4009;
constexpr int BUFFER_SIZE = 1024;

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    sockaddr_in server_addr{}, client_addr{};

    // Create a UDP socket.
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Error: Could not create socket" << std::endl;
        return 1;
    }

    // Configure server address structure.
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces.
    server_addr.sin_port = htons(PORT);

    // Bind the socket.
    if (bind(sockfd, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) < 0) {
        std::cerr << "Error: Bind failed" << std::endl;
        close(sockfd);
        return 1;
    }

    std::cout << "UDP Server listening on port " << PORT << std::endl;

    socklen_t client_addr_len = sizeof(client_addr);
    while (true) {
        // Wait for incoming UDP packet.
        ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                             reinterpret_cast<sockaddr*>(&client_addr), &client_addr_len);
        if (n < 0) {
            std::cerr << "Error: recvfrom failed" << std::endl;
            continue;
        }
        buffer[n] = '\0';
        std::cout << "Received: " << buffer << std::endl;
    }

    close(sockfd);
    return 0;
}

