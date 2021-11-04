- [ROS Tutorials](#ros-tutorials)
  - [Install ROS](#install-ros)
  - [Navigating the ROS filesystem](#navigating-the-ros-filesystem)
  - [Creating a ROS Package](#creating-a-ros-package)
    - [Creating a workspace for catkin](#creating-a-workspace-for-catkin)
    - [Creating a catkin package](#creating-a-catkin-package)
    - [Package dependencies](#package-dependencies)
  - [Run a ROS Package](#run-a-ros-package)
    - [Quick Overview of Graph Concepts](#quick-overview-of-graph-concepts)
    - [rosnode](#rosnode)
    - [rosrun](#rosrun)
      - [turtlesim (In tutorial)](#turtlesim-in-tutorial)
    - [ROS Topics](#ros-topics)
      - [Using rqt_fraph](#using-rqt_fraph)

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
```ruby
$ cd ~/catkin_ws/src
$ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp
```
The `catkin_create_pkg`:
```ruby
catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
```
After create, go to workspace path, use `catkin_make` and `source`(same as '`.`')
```ruby
$ cd ~/catkin_ws
$ catkin_make
$ . ~/catkin_ws/devel/setup.bash
```

### Package dependencies
Use `rospack depends` to find the dependencies. For more infomation, go to section 5 on this [website](http://wiki.ros.org/ROS/Tutorials/CreatingPackage)

## Run a ROS Package

For this tutorial we'll use a lighweight simulator, to install it run the following command:
```ruby
$ sudo apt-get install ros-<distro>-ros-tutorials
```
Replace '< distro >' with the name of your ROS distribution (e.g. indigo, jade, kinetic, noetic) [(link)](http://wiki.ros.org/ROS/Tutorials/UnderstandingNodes)

### Quick Overview of Graph Concepts
- [Nodes](http://wiki.ros.org/Nodes): A node is an executable that uses ROS to communicate with other nodes.
- [Messages](http://wiki.ros.org/Messages): ROS data type used when subscribing or publishing to a topic.
- [Topics](http://wiki.ros.org/Topics): Nodes can publish messages to a topic as well as subscribe to a topic to receive messages.
- [Master](http://wiki.ros.org/Master): Name service for ROS (i.e. helps nodes find each other)
- [rosout](http://wiki.ros.org/rosout): ROS equivalent of stdout/stderr
- [roscore](http://wiki.ros.org/roscore): Master + rosout + parameter server (parameter server will be introduced later)

**Run `roscore` is the first thing to do when using ROS**

### rosnode
[link](http://wiki.ros.org/ROS/Tutorials/UnderstandingNodes)
rosnode displays information about the ROS nodes that are currently running.
```ruby
$ rosnode list
```
after run will see:
```
    /<nodes>
    /...
```

The `rosnode info` command returns information about a specific node.
```
$ rosnode info /<node>
```

### rosrun
`rosrun allows` you to use the package name to directly run a node within a package (without having to know the package path)
```ruby
$ rosrun [package_name] [node_name]
# In tutorial: 
$ rosrun turtlesim turtlesim_node
```

```ruby
# In tutorial:
$ rosnode list
    /my_turtle
    /rosout
```

Change the node name:
```ruby
# In tutorial:
$ rosrun turtlesim turtlesim_node __name:=my_turtle
```

#### turtlesim (In tutorial)
```ruby
# In tutorial:
$ rosrun turtlesim turtlesim_node
```
In a new terminal:
```ruby
# In tutorial:
$ rosrun turtlesim turtle_teleop_key
```
This will allow use keyboard to control turtle.

### ROS Topics
[Link](http://wiki.ros.org/ROS/Tutorials/UnderstandingTopics)

Nodes are communicationg with each other over a ROS Topic. Some nodes will pulish to a topic, and some nodes will subscribe this topic to get the message.

>In tutorial: `turtle_teleop_key` is publishing the key strokes on a topic, while `turtlesim` subscribes to the same topic to receive the key strokes.

#### Using rqt_fraph
rqt_graph creates a dynamic graph of what's going on in the system. rqt_graph is part of the rqt package. Unless you already have it installed, run:
```ruby
$ sudo apt-get install ros-<distro>-rqt
$ sudo apt-get install ros-<distro>-rqt-common-plugins
```
replacing `< distro >` with the name of your ROS distribution (e.g. noetic, kinetic, lunar ...)

In a new terminal:
```
$ rosrun rqt_graph rqt_graph
```
