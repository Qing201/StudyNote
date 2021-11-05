Python Scripts Tutorial
[Link](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29)

- [Node](#node)

# Node
```py
import rospy
from std_msgs.msg import String
```


> ```py
> rospy.init_node('talker' anonymous=True)
> ```
> It tells rospy the name of your node, name is "talker" in this case.
> `anonymous = True` ensures that your node has a unique name by adding random numbers to the end of NAME. 

# Topic
> ```py
> pub = rospy.Publisher('chatter', String, queue_size=10)
> ```
> It declares that your node is publishing to the chatter topic using the message type String.


# Public
> ```py
> while not rospy.is_shutdown():
>   hello_str = "hello world %s" % rospy.get_time()
>   rospy.loginfo(hello_str)
>   pub.publish(hello_str)
>   rate.sleep()
> ```

`rospy.loginfo`, which performs triple-duty: the messages get printed to screen, it gets written to the Node's log file, and it gets written to rosout.

### Publisher
> `pub.publish(hello_str)` that publishes a string to our chatter topic.

### Subscriber
> ```py
> def callback(data):
>   rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
> def listener():
>   rospy.init_node('listener', anonymous=True)
>   rospy.Subscriber("chatter", String, callback)
>   rospy.spin()
> ```

## Service and Clent Node
[Link](http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28python%29_)
**Look the videos on the bottun**

### Using srv
[Link](http://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv#Creating_a_srv)
1. Create a service file 
2. Check the .xml, able `message_ageneration` and `message_runtime`
3. Check the CMakeLists.txt, add .srv files in it.

> ```py
> s = rospy.Service('add_two_ints', AddTwoInts, handle_add_two_ints)
> ```
> This declares a new service named `add_two_ints` with the `AddTwoInts` service type. All requests are passed to `handle_add_two_ints` function. `handle_add_two_ints` is called with instances of `AddTwoIntsRequest` and returns instances of `AddTwoIntsResponse`.

Service file is the `.srv` files in srv folder. 