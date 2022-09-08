#include <ros/ros.h>
#include <std_msgs/UInt16.h>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "start_arduino");

    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<std_msgs::UInt16>("start", 25);// chatter is the topic

    ros::Rate loop_rate (1);

    std_msgs::UInt16 msg;

    msg.data = 1;

    ROS_INFO("%u", msg.data);

    pub.publish(msg);
    ros::spinOnce();

    loop_rate.sleep();

    ros::shutdown(); // με αυτή τη γραμμή τερματίζω το πρόγραμμα
    return 0;

}
