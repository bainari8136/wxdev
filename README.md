# wxWidgets Layered Architecture Application

## Project Overview

This project is a wxWidgets application designed to learn and understand **Layered Architecture** as a software architecture pattern. The application demonstrates how to organize code into distinct layers with clear separation of concerns, with each layer responsible for specific functionality.

## Architecture Layers

### 1. Presentation Layer (UI)
**Location:** `ui/` folder

The presentation layer is the entry point for user interaction. It is built with **wxWidgets** and handles:
- User interface components and interactions
- Event handling from user actions
- Display of information to users
- Communication with the application layer for business logic

### 2. Application Layer (Mediator)
**Location:** `app/` folder

The application layer acts as a mediator between the presentation layer and the infrastructure layer. It is responsible for:
- Orchestrating business logic
- Processing data from the presentation layer
- Communicating with the infrastructure layer
- Translating between UI requests and service calls

### 3. Infrastructure Layer (Services)
**Location:** `services/` folder

The infrastructure layer is the lower layer that handles all logic to interact with external services. It is responsible for:
- Managing external service integrations
- Encapsulating OpenSSL C API calls
- Handling SSL/TLS operations
- Abstracting external service complexity from upper layers

## Project Structure

```
wxdev/
├── ui/                    # Presentation Layer (wxWidgets UI)
│   ├── Frame.h
│   ├── Frame.cpp
│   └── CMakeLists.txt
├── app/                   # Application Layer (Business Logic Mediator)
│   ├── SSLVersion.h
│   ├── SSLVersion.cpp
│   └── CMakeLists.txt
├── services/              # Infrastructure Layer (External Services)
│   ├── OpenSSLService.h
│   ├── OpenSSLService.cpp
│   └── CMakeLists.txt
├── main.cpp               # Entry point
├── CMakeLists.txt         # CMake configuration
└── README.md
```

## Technologies Used

- **wxWidgets**: Cross-platform GUI toolkit
- **OpenSSL**: SSL/TLS cryptography library
- **CMake**: Build system

## Building the Project

This project uses CMake as its build system. Instructions for building will depend on your platform and installed dependencies.

## Learning Objectives

This project serves as a practical example for understanding:
- Layer-based architectural pattern
- Separation of concerns
- Dependency inversion (upper layers depend on lower layer contracts)
- Abstraction of external services
- Modular code organization
