import launch
from launch_ros.actions import Node

def generate_launch_description():
    return launch.LaunchDescription([
        Node(
            package='robot_bringup',
            executable='subscriber',
            name='subscriber_node',
        ),
        Node(
            package='robot_core',
            executable='publisher',
            name='publisher_node',
        ),
    ])