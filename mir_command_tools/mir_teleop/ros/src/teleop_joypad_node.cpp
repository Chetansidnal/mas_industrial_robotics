/*
 * Copyright [2011] <Bonn-Rhein-Sieg University>
 *
 * teleop_joypad_node.cpp
 *
 *  Created on: Dec 15, 2011
 *      Author: Frederik Hegger
 */

#include "mir_teleop/teleop_joypad.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "teleop_joypad");
    ros::NodeHandle nh("~");
    string config_json;

    nh.getParam("config_json", config_json);
    std::cout<<"Path json--------"<<config_json<<endl;
    diaglib prodiag;
    prodiag.start_publishing("Node Has started", config_json);

    TeleOpJoypad* teleop = new TeleOpJoypad(nh,prodiag);

    // ros::Rate loop_rate(50);

    // ros::spin();

    ros::Rate r(50); // 10 hz
    while (ros::ok)
    {
    prodiag.check_dependent(config_json);
    ros::spinOnce();
    r.sleep();
    }

    delete teleop;
}

