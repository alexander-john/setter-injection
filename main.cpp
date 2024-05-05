#include <iostream>

// Dependency class
class Logger {
public:
    void log(const std::string& message) {
        std::cout << "Logging: " << message << std::endl;
    }
};

// Class with dependency injected through setter method
class Service {
private:
    Logger* logger; // Pointer to Logger dependency
public:
    // Setter Injection
    void setLogger(Logger* logger) {
        this->logger = logger;
    }

    void doSomething() {
        if (logger) {
            logger->log("Doing something in Service");
        } else {
            std::cout << "Logger is not set" << std::endl;
        }
    }
};

int main() {
    Logger logger;
    Service service;
    service.setLogger(&logger); // Dependency injected into Service through setter method
    service.doSomething();

    return 0;
}
