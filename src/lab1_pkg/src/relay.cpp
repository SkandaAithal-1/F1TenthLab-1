#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"
using std::placeholders::_1;

class Subscriber : public rclcpp::Node
{
public:
    Subscriber()
    : Node("subscribe")
    {
        publisher_ = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("drive_relay", 10);

        subscriber_ = this->create_subscription<ackermann_msgs::msg::AckermannDriveStamped>(
            "drive", 10, std::bind(&Subscriber::topic_callback, this, _1)
        );
    }    

private:
    void topic_callback(const ackermann_msgs::msg::AckermannDriveStamped::SharedPtr message) const
    {
        // RCLCPP_INFO(this->get_logger(), "I heard this - '%s'", msg->data.c_str());
        auto msg = ackermann_msgs::msg::AckermannDriveStamped();
        msg.header = std_msgs::msg::Header();
        msg.drive = ackermann_msgs::msg::AckermannDrive();
        msg.drive.speed = message->drive.speed*3;
        msg.drive.steering_angle = message->drive.steering_angle*3;
        publisher_->publish(msg);
    }
    rclcpp::Subscription<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr subscriber_;
    rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr publisher_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();
    return 0;
}