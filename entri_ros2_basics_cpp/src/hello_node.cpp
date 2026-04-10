#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

/*
 * TODO: Create a Class named 'HelloNode' that inherits from rclcpp::Node.
 * Requirements:
 * 1. The constructor should name the node "hello_world_node".
 * 2. Create a timer that triggers every 1000ms (1 second).
 * 3. The timer callback should print "Hello, World!" using the RCLCPP_INFO macro.
 */

class HelloNode : public rclcpp::Node
{
public:
  HelloNode()
  : Node("hello_world_node")
  {
    // TODO: Initialize the timer here
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&HelloNode::timer_callback, this));
  }

private:
  // TODO: Define the timer_callback function here
  void timer_callback(){
    RCLCPP_INFO(this->get_logger(),"Hello, World")
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloNode>());
  rclcpp::shutdown();
  return 0;
}
