import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist

class Subscriber(Node):

    def __init__(self):
        super().__init__('subscriber')
        self.subscription = self.create_subscription(
            Twist,
            '/test_cmd_vel',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg: Twist):
        self.get_logger().info('Angular Z: "%s"; Linear X: "%s"' % (msg.angular.z, msg.linear.x))

def main(args=None):
    rclpy.init(args=args)

    subscriber = Subscriber()

    rclpy.spin(subscriber)

    subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()