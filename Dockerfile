FROM ubuntu:20.04

# Disable interactive prompts during package installation 
ENV DEBIAN_FRONTEND=noninteractive 

# Install required packages: build-essential (for gcc/g++ and make), cmake, gdb, python3. 
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \ 
    cmake \ 
    gdb \
    python3 \
    && rm -rf /var/lib/apt/lists/* 

WORKDIR /app 

# Copy the CMake configuration and source code into the container. 
COPY CMakeLists.txt .
COPY src/ ./src/

# Build the project using out-of-source build
RUN mkdir -p build && cd build && cmake .. && make 

# Expose the UDP port (4009) 
EXPOSE 4009/udp 

# Run the server when the container starts (adjust path if needed)
CMD ["./build/ingress_server"]