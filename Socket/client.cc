// Full duplex communication between sever and client
// Filename: client.cc 
//compile: g++ client.cc -o Client -pthread
#include <iostream>
#include <thread>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void receiveMessages(int clientSocket) {
    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
        if (bytesReceived <= 0) {
            std::cerr << "Server disconnected or error occurred." << std::endl;
            close(clientSocket);
            break;
        }
        std::cout << "Server: " << buffer << std::endl;
    }
}

void sendMessages(int clientSocket) {
    std::string message;
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, message);
        send(clientSocket, message.c_str(), message.length(), 0);
    }
}

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        close(clientSocket);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        close(clientSocket);
        exit(EXIT_FAILURE);
    }

    std::cout << "Connected to the server." << std::endl;

    std::thread receiveThread(receiveMessages, clientSocket);
    std::thread sendThread(sendMessages, clientSocket);

    receiveThread.join();
    sendThread.join();

    close(clientSocket);
    return 0;
}
