<img src="https://i.imgur.com/y2bQtnZ.png" width="150" height="150" alt="Logo" />

# 42-Minitalk
## Overview
The **minitalk** project is a **communication program** developed as part of **42 School**. It consists of a client and server that communicate via UNIX signals. It demonstrates how to send and receive messages using signals like SIGUSR1 and SIGUSR2, converting these signals into binary data to transmit strings between the client and server processes. This project is designed to deepen understanding of inter-process communication (IPC) and signal handling in C.

## Getting started
This project is compatible on Linux and macOS.
> If you are on macOS, make sure you have installed **Xcode Command Line Tools**.
1. Clone this repository
```bash
git clone https://github.com/extrymes/42-Minitalk.git
cd 42-Minitalk
```
2. Compile and launch the `server` program
```bash
make
./server
```
3. Execute `client` in another terminal
```bash
./client <server_pid> <message>
```
You must pass it the server PID and a custom message.

## Contributing
We welcome contributions from everyone! Whether you're fixing bugs, adding new features, improving documentation, or simply sharing your ideas, your input is greatly appreciated.

Thanks for visiting and happy coding!
