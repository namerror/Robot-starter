#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class Publisher : public rclcpp::Node
{
public:
    Publisher()
    : Node("publisher")
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/test_cmd_vel", 10);
        auto timer_callback = [this]() -> void {
            auto message = geometry_msgs::msg::Twist();
            message.linear.x = 0.5;
            message.angular.z = 0.5;
            RCLCPP_INFO(this->get_logger(), "Publishing: '%f, %f'", message.linear.x, message.angular.z);
            publisher_->publish(message);
        };
        timer_ = this->create_wall_timer(500ms, timer_callback);
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Publisher>());
    rclcpp::shutdown();
    return 0;
}