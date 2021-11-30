### Connect robot
1. Wifi : The password is `prl_robot`

2. Login to the race car using the following command:
```sh
ssh robot@10.42.0.1
```
4. Launch the racecar using the following command
```sh
roslaunch mushr_base teleop.launch
```

### Set host and 

> Set the environment variables ROS_IP and ROS_MASTER_URI (or edit and source ~/.bashrc). ROS_IP should be set to the ip address of your desktop or laptop. ROS_MASTER_URI should be set to http://<ip_address>:11311 where <ip_address> is the ip address of the ROS master. This will either be the ip of the robot if you are working with the robot, or the ip of your desktop/laptop if you are working in simulation.

```sh
export ROS_MASTER_URI=http://10.42.0.1:11311      # For Robot
export ROS_MASTER_URI=localhost:11311             # For Simulation
```

```sh
rosrun rviz rviz
```

```sh
scp -r _________ robot@10.42.0.1:~/catkin_ws/src
```
The above command copies the folder named _______ from your present working directory (pwd) to the catkin_ws/src folder in the robot!

```sh
sudo shutdown -P now
```


