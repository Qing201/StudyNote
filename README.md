- [ROS Tutorials](#ros-tutorials)
  - [Install ROS](#install-ros)
  - [Navigating the ROS filesystem](#navigating-the-ros-filesystem)
  - [Creating a ROS Package](#creating-a-ros-package)
    - [Creating a workspace for catkin](#creating-a-workspace-for-catkin)
    - [Creating a catkin package](#creating-a-catkin-package)
    - [Package dependencies](#package-dependencies)
  - [Run a ROS Package](#run-a-ros-package)

# ROS Tutorials 
[Official Website](http://wiki.ros.org/ROS/Tutorials)

## Install ROS
[Website](http://wiki.ros.org/ROS/Installation)

Two ROS1 version, ROS Melodic for Ubuntu 18.04, ROS Noetic for Ubuntu 20.04

To avoid source setup.bash in every new, use 
```ruby
$ echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
```
(Still need source .bash in /devel of the project)

Don't forget do 1.6 in tutorial website.

## Navigating the ROS filesystem
- Find anything in ros (return path for file)
    ```ruby
    $ rospack find [package_name]
    ```

- Move terminal direction to the file in ros
    ```
    $ roscd <package-or-stack>[/subdir]
    ```

- `rosls` same as ls in linux, return the files unter the path.

Using "TAB" in keyboard to fill the files name on terminal

## Creating a ROS Package
[Website](http://wiki.ros.org/ROS/Tutorials/CreatingPackage)

### Creating a workspace for catkin
[website link](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)
This example create a workspace named `catkin_ws`

```ruby
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make
```
Before continuing source your new setup.*sh file:
```ruby
$ source devel/setup.bash
```

For my understanding, these set belong should make a way to not source the setup.bash file every time after catkin_make: (I'm not sure the unferestanding is correct or not, didn't try) 
>To make sure your workspace is properly overlayed by the setup script, make sure ROS_PACKAGE_PATH environment variable includes the directory you're in.
```
$ echo $ROS_PACKAGE_PATH
/home/youruser/catkin_ws/src:/opt/ros/kinetic/share
```

### Creating a catkin package
```
$ cd ~/catkin_ws/src
$ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp
```
The `catkin_create_pkg`:
```
catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
```
After create, go to workspace path, use `catkin_make` and `source`(same as '`.`')
```
$ cd ~/catkin_ws
$ catkin_make
$ . ~/catkin_ws/devel/setup.bash
```

### Package dependencies
Use `rospack depends` to find the dependencies. For more infomation, go to section 5 on this [website](http://wiki.ros.org/ROS/Tutorials/CreatingPackage)

## Run a ROS Package

For this tutorial we'll use a lighweight simulator, to install it run the following command:
```
$ sudo apt-get install ros-<distro>-ros-tutorials
```
Replace '<distro>' with the name of your ROS distribution (e.g. indigo, jade, kinetic, noetic) [(link)](http://wiki.ros.org/ROS/Tutorials/UnderstandingNodes)




