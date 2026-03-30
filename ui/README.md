# wxdev

wxdev is a small wxWidgets-based C++ application created as a learning project to demonstrate software architecture patterns and to provide a hands-on playground for common OpenSSL tasks. The repository uses a layered architecture to keep UI, application coordination, and cryptographic services separated.

Author: bainari8136

---

## Current status
- Implemented: OpenSSL version check (exposed through the app's UI).
- In progress / planned: additional OpenSSL demos (keygen, sign/verify, encryption, hashing, CSR/cert handling).
- Target platform for development: Microsoft Windows (development notes below).

If you already have the app running, use the UI to run the "Check OpenSSL Version" task to verify your OpenSSL integration.

---

## Goals
- Learn and demonstrate a clear layered architecture in a desktop GUI application.
- Keep UI code independent from cryptographic implementation details.
- Provide incremental, testable examples of OpenSSL usage in C++.

---

## Architecture (Layered)
The project follows a layered architecture with clear responsibilities:

- UI layer (src/ui)
  - All wxWidgets UI code: windows, dialogs, controls and presentation logic.
  - Responsible for displaying data, collecting user input, and forwarding actions to the app layer.

- App layer (src/app)
  - Mediator / coordinator between UI and service layers.
  - Translates UI actions into service requests and maps service results back to the UI.
  - Keeps UI and service implementations decoupled.

- Service layer (src/service)
  - Encapsulates OpenSSL and other helper utilities.
  - Implements the cryptographic operations (currently includes the OpenSSL version check).
  - Returns results in types and formats convenient for the app and UI.

Flow:
User -> UI Layer -> App Layer -> Service Layer (OpenSSL) -> App Layer -> UI

---

## OpenSSL tasks (implemented / planned)
Implemented:
- OpenSSL version check (currently available in the UI)

Planned / easy to add:
- RSA key generation (PEM/DER)
- Symmetric encryption/decryption (AES)
- Digital signatures (sign/verify)
- Hashing (SHA-2 family)
- Random bytes generation
- Certificate / CSR parsing and PEM handling
- PEM <-> DER conversions

If you want specific features prioritized, list them and I can update the README and/or add issues.

---

## Repository layout (convention)
- CMakeLists.txt / Makefile
- src/
  - ui/            # wxWidgets windows, dialogs, controls
  - app/           # mediator / controller components
  - service/       # OpenSSL wrappers and crypto utilities
- resources/       # UI resources, icons
- tests/           # unit / integration tests (optional)
- README.md

---

## Windows development (dependencies & build)
Recommended tools
- Visual Studio 2019 / 2022 (with Desktop development with C++ workload) or MSYS2 toolchain
- CMake >= 3.15
- vcpkg (recommended) OR manual OpenSSL + wxWidgets installs
- OpenSSL development libraries (libssl / libcrypto)
- wxWidgets development libraries (matching architecture: x64 vs x86)

Using vcpkg (recommended)
1. Clone and bootstrap vcpkg (one-time):
   - git clone https://github.com/microsoft/vcpkg.git
   - .\vcpkg\bootstrap-vcpkg.bat

2. Install dependencies (example x64):
   - .\vcpkg\vcpkg.exe install openssl:x64-windows wxwidgets:x64-windows

3. Configure CMake to use vcpkg toolchain:
   - cmake -S . -B build -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake

4. Build:
   - cmake --build build --config Release
   - Resulting binary (e.g. `wxdev.exe`) will be under `build\Release\`.

If NOT using vcpkg
- Install or build wxWidgets and OpenSSL yourself, then point CMake to their install locations:
  - cmake -S . -B build -G "Visual Studio 17 2022" -A x64 -DOPENSSL_ROOT_DIR="C:/path/to/openssl" -DwxWidgets_ROOT_DIR="C:/path/to/wxWidgets"

Running the app
- Launch the produced executable (e.g. `build\Release\wxdev.exe`).
- Use the UI to run the OpenSSL version check. Future UI controls will expose additional demos.

Notes and common issues
- Ensure architecture matches (x64 vs x86) across wxWidgets, OpenSSL and your build.
- On Windows, OpenSSL sometimes requires that OpenSSL DLLs are on PATH or next to the executable.
- If CMake can't find libraries, set the corresponding *_ROOT_DIR or use the vcpkg toolchain.

---

## Security & usage notes
- This project is for learning and demonstration. Do not use sample/demo crypto code in production without careful review.
- Follow best practices for key management, secure memory handling, and up-to-date OpenSSL versions if using in real applications.

---

## Contributing & roadmap
- Open an issue for new OpenSSL demos you want implemented.
- Recommended development flow:
  1. Create a feature branch.
  2. Implement service-layer logic and tests.
  3. Add app-layer methods to expose features.
  4. Add UI controls and wiring.
  5. Create PR and request review.

Planned next items (you can pick priority):
- RSA key generation UI + service
- Hashing UI + service
- Symmetric encryption (AES) UI + service
- Sign/verify demo
- Automated unit tests for service layer

---

## License
No license is specified in the repository yet. If you'd like a permissive option, consider adding an MIT or Apache-2.0 LICENSE file. I can add the text for you.

---

