#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive

class Publisher(Node):
    def __init__(self):
        super().__init__('Talker')
        self.declare_parameter('v', rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter('d', rclpy.Parameter.Type.DOUBLE)
        self.publisher_ = self.create_publisher(
            AckermannDriveStamped, "drive", 10
        )
        self.timer_ = self.create_timer(
            0.5, self.publish_callback
        )

    def publish_callback(self):
        message = AckermannDriveStamped()
        message.header = Header()
        message.drive = AckermannDrive()

        message.drive.speed = float(self.get_parameter('v').value)
        message.drive.steering_angle = float(self.get_parameter('d').value)
        self.publisher_.publish(message)



def main(args=None):
    rclpy.init(args=args)
    node = Publisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=="__main__":
    main()


