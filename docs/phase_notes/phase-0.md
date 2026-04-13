# Phase 0 Tooling & Architecture Foundations

## Step 0.1

### Action Items:
1. Creating packages under `ros2_ws/src/`:
    - `robot_bringup` (python, rclpy):
        - create Python subscriber to `/test_cmd_vel` topic
        - prints received values
    - `robot_core` (C++, rclcpp):
        - publish geometry_msgs/Twist messages to `/test_cmd_vel` topic
2. Launch using a single launch file under `robot_bringup`
   
### Notes
- ROS2 startup script: `source /opt/ros/jazzy/setup.bash`
- Package creation commands:
    - `ros2 pkg create --build-type ament_python --license Apache-2.0 robot_bringup`
    - `ros2 pkg create --build-type ament_cmake --license Apache-2.0 robot_core`
- Code:
    - [robot_bringup](/ros2_ws/src/robot_bringup/robot_bringup/subscriber.py)
    - [robot_core](/ros2_ws/src/robot_core/src/publisher.cpp)
- Launch file:
    - [robot_bringup/launch/launch.yaml](/ros2_ws/src/robot_bringup/launch/launch.yaml)

## Step 0.2
### Notes
1. DDS-based architecture:
    - Decentralized discovery: no central master node
    - Transport abstraction: UDP, multicast, shared memory, etc.
    - QoS policies for reliability, durability, etc.
    - Real-time capabilities
    - Cross-vendor interoperability
2. Communication models:
    - Topic: asynchronous, many-to-many, no guarantee anyone is listening, continuous data stream
        - used for: sensor streams, control commands, state estimates
    - Service: synchronous request-response, blocking, short-lived
        - used for: configuration, queries, discrete actions
    - Action: goal request (async), feedback (topic), result (future-like)
        - used for: long-running tasks, preemptible operations with progress tracking
    - Examples:

        | Function         | Correct Model                            | Why                                       |
        | ---------------- | ---------------------------------------- | ----------------------------------------- |
        | Wheel odometry   | Topic                                    | Continuous stream, many consumers         |
        | Reset odometry   | Service                                  | Discrete state change                     |
        | Navigate to goal | Action                                   | Long-running, feedback, cancelable        |
        | Emergency stop   | Topic                                    | Broadcast, low-latency, safety-critical   |
        | Battery query    | Service *(or topic depending on design)* | On-demand query OR periodic status stream |
