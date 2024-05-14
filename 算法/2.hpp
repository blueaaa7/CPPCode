#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/compressed_image.hpp"
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

class ImagePublisher : public rclcpp::Node
{
public:
    ImagePublisher() : Node("image_publisher"), cap_(0)
    {
        publisher_ = this->create_publisher<sensor_msgs::msg::CompressedImage>("compressed_image", 10);
        timer_ = this->create_wall_timer(33ms, std::bind(&ImagePublisher::publish_image, this)); // 修改这里
    }

private:
    void publish_image()
    {
        cv::Mat frame;
        cap_ >> frame;
        if (!frame.empty())
        {
            auto msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toCompressedImageMsg();
            publisher_->publish(*msg);
        }
    }

    rclcpp::Publisher<sensor_msgs::msg::CompressedImage>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    cv::VideoCapture cap_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ImagePublisher>());
    rclcpp::shutdown();
    return 0;
}