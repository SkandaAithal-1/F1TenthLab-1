# F1Tenth Lab-1

This is a very basic ROS2
 package.    

There are two nodes implemented here - `talker_og` and `relay`. 

`talker_og` publishes to the `drive` topic.  
`relay` subscribes to `drive` and publishes to the `drive_relay` topic.


## Build instruction

Place this package in a colcon workspace. Then
```
colcon build
```

## Run instructions

There is a launch file given which can be used to launch two nodes - `talker_og` and `relay`.  
First source the ROS2 setup script and the local workspace setup script.
```
source /opt/ros/foxy/setup.bash
source install/setup.bash
```

Then,
```
ros2 launch lab1_pkg lab1_launch.py
```
