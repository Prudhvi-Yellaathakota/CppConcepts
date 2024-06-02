// Full duplex communication between sever and client
// Filename: server.cc 
//compile: g++ server.cc -o Server -pthread
#include <iostream>
#include <thread>
#include <vector>
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
            std::cerr << "Client disconnected or error occurred." << std::endl;
            close(clientSocket);
            break;
        }
        std::cout << "Client: " << buffer << std::endl;
    }
}

void sendMessages(int clientSocket) {
    std::string message;
    while (true) {
        std::cout << "Server: ";
        std::getline(std::cin, message);
        send(clientSocket, message.c_str(), message.length(), 0);
    }
}

void handleClient(int clientSocket) {
    std::thread receiveThread(receiveMessages, clientSocket);
    std::thread sendThread(sendMessages, clientSocket);

    receiveThread.join();
    sendThread.join();
}

int main() {
    int serverSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind socket
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 3) < 0) {
        perror("Listen failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    // Accept clients and create threads to handle them
    while (true) {
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientSocket < 0) {
            perror("Accept failed");
            continue;
        }
        std::cout << "New client connected" << std::endl;
        std::thread clientThread(handleClient, clientSocket);
        clientThread.detach();  // Detach the thread to allow it to run independently
    }

    close(serverSocket);
    return 0;
}
