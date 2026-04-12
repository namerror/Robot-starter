# Phase 0 Tooling & Architecture Foundations

## Step 0.1 - ROS2 as a Distributed Graph

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