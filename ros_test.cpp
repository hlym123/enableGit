/*

    Website:
		1. http://wiki.ros.org/cn
		2. http://www.ncnynl.com/archives/201610/919.html

	Book:
		1.《机器人操作系统（ROS）浅析》  
		2.《Learning ROS for Robotics Programming》

	实战:		
		1. 搭建ROS小车底盘B-目录:
			http://www.ncnynl.com/archives/201703/1414.html
		2. 基于ROS的自主导航小车Plantbot:
			https://zhuanlan.zhihu.com/p/26644994
		3. ROS与Arduino教程	
	
	directory:
		《机器人操作系统（ROS）浅析》
		《Learning ROS for Robotics Programming》 -- Second Edition		
		ROS与Arduino教程
		
*/

 
/*************************************************************************************

	《机器人操作系统（ROS）浅析》  
			[美] Jason M. O'Kane 著
			肖军浩 译
	Learning note

	@date: Wednesday, August 16, 2017
	
	log:
		1. 2017/12/13 重拾......
		
	

	
*************************************************************************************/


//====================================================================================
// 第二章 -- 入门概述
// 工欲善其事，必先利其器。 -- 孔子 



// 启动节点管理器
roscore 

// 启动节点/运行ROS程序
rosrun package-name excutable-name  // 功能包名 可执行文件名

// 获取运行节点列表
rosnode list 

// 使用 rosrun 命令显式设置节点的名称，语法如下：
rosrun package-name executable-name __name:=node-name

// 查看节点
rosnode info node-name

// 终止节点
rosnide kill node-name

// 获取当前活跃的话题
rostopic list

// 打印消息内容
rostopic echo topic-name

// 测量发布频率
rostopic hz topic-name  // 每秒发布消息数
rostopic bw topic-name  // 每秒发布消息所占字节量

// 查看消息类型
rosmsg show message-type-name

// 发布消息, 重复地按照指定的频率给指定的话题发布指定的消息
rostopic pub –r rate-in-hz topic-name message-type message-content  





//====================================================================================
// 第三章 -- 编写ROS程序
// 知之者不如好之者，好之者不如乐之者。 -- 孔子
// This is a ROS version of the standard "hello, world" programe.


所有的 ROS 软件，包括我们创建的软件，都被组织成功能包。
一、在我们写任何程序之前，第一步是创建一个容纳我们的功能包的工作区，然后再创建功能包本身。
1. 创建工作区（工作目录）
2. 创建src目录,存放功能包的源码
3. 创建功能包（在src目录下）
	catkin_create_pkg package-name

二、编译程序
1. 声明依赖库(程序所依赖的其他功能包)
	编辑包目录下的 CMakeLists.txt 文件
		find_package(catkin REQUIRED COMPONENTS package-names)
	在包的清单文件中列出依赖库
		build_depend （编译依赖） 和 run_depend（运行依赖） 
		<build_depend>package-name</build_depend>
		<run_depend>package-name</run_depend
2. 声明可执行文件
	在 CMakeLists.txt 中添加两行，
	来声明我们需要创建的可执行文件。其一般形式是：
		add_executable(executable-name source-files)
		target_link_libraries(executable-name ${catkin_LIBRARIES})
3. 编译工作区
	catkin_make  // 在工作目录中运行
4. 执行名为 setup.bash 的脚本文件


三、执行程序





#include <ros/ros.h>


int main(int argc, char **argv)
{
	// Initialize the ROS system.
	ros::init(argc, argv, "hello_world");  // 初始化ROS客户端库
	
	// Establish this programe as a ROS node.
	ros::NodeHandle nh;
	
	// Send some output as a log message.
	ROS_INFO_STREAM("Hello, ROS!");
}

//------------------------------------------------------------------------------------
// This program publishes randomly−generated velocity  messages for turtlesim .
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	// Initialize the ROS system and become a node;
	ros::init(argc, argv, "publish_velocity");
	ros::NodeHandle nh;
	
	// Create a publisher object.
	ros:Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
	
	// Send the random number generator.
	srand(time(0));
    
	// Loop at 2Hz until the node is shutdown.
	ros::Rate rate(2);
	
	while (ros::ok()) {
		// Create and fill in the message. The other four fields, 
		// which are ignore turtlesim, default to 0.
		geometry_msgs::Twist msg;
		msg.liner.x = double(rand())/double(RAND_MAX);
		mag.angular.z = 2 * double(rand())/double(RAND_MAX) - 1;
		
		// Publish the message.
		pub.publish(msg);
		
		// Send a messgae to rosout with the details.
		ROS_INFO_STREAM("Send random velocity command:", 
						<< "liner=" << msg.liner.x 
						<< "angular=" << msg.angular.z);
						
		// Wait untilit's time for another iteration.
		rate.sleep();
	}
}

//------------------------------------------------------------------------------------
// This programe subscribes to turtle1/pose and show its messages on the screen.
#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <iomanip.h>  // for std::setprecision and std::fixed


// A callback function. Executed each time a new pose message arrives.
void PoseMessagesReceived(const turtlesim::Pose &msg)
{
	ROS_INFO_STREAM(std::setprecision(2) << std::fixed 
					<< "position=(" << msg.x << ", " << msg.y << ")"
					<< "*direction=" << msg.theta);
}

int main(int argc, char **argv)
{
	// Initialize the ROS system and become a noed.
	ros::init(argc, argv, "subscribe_to_pose");
	ros::NodeHandle nh;
	
	// Create subsciber object
	ros::Subscriber sub = nh.subscib("turtle1/pose", 1000, &PoseMessagesReceived);
	
	// Let ROS take over.
	ros::spin();
}

//====================================================================================
// 第四章 -- 日志消息     
// 业精于勤荒于嬉，行成于思毁于随。 -- 韩愈



//====================================================================================
// 第五章 -- 计算图源命名
// 博学之，审问之，慎思之，明辨之，笃行之。 -- 礼记•中庸



//====================================================================================
// 第六章 -- 启动文件
// 吾尝终日而思矣，不如须臾之所学也。 -- 荀子





/*************************************************************************************

	《Learning ROS for Robotics Programming》 -- Second Edition
		 
	Learning note

	@date: Wednesday, December 13, 2017
	
	log:
		1. 2017/12/13  
		
	
*************************************************************************************/






/*************************************************************************************

	ROS与Arduino教程 http://www.ncnynl.com/archives/201610/919.html
		 
	Learning note

	@date: Friday, December 22, 2017
	
	log:
		1. 2017/12/22  
		
	
*************************************************************************************/


// =============================================================
// 1. ROS与Arduino-Hello World (publisher例子)
// =============================================================
/**
 * rosserial Publisher Example
 * Prints "hello world!"
 */
#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;   // 初始化节点实例

// 实例化一个发布,主题叫chatter,使用消息类型为std_msgs::String
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);  

char hello[13] = "hello world!";

void setup()
{
	nh.initNode(); 
	nh.advertise(chatter);
}

void loop()
{
	str_msg.data = hello;
	chatter.publish( &str_msg );
	nh.spinOnce();
	delay(1000);
}

// 新终端运行，/dev/ttyUSB0为Arduino设备
rosrun rosserial_python serial_node.py /dev/ttyUSB0
// 消息显示
rostopic echo chatter 
 


// =============================================================
// 2. ROS与Arduino-Blink (subscriber例子) 
// =============================================================
/**
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle nh;

// 创建回调函数messageCb,必需传递常量消息引用值作为参数
void messageCb(const std_msgs::Empty& toggle_msg)
{
	digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

// 实例化订阅,有两个参数,主题名toggle_led和回调函数名,标明主题的消息类型std_msgs::Empty代码
ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb);

void setup()
{
	pinMode(13, OUTPUT);
	nh.initNode();
	nh.subscribe(sub);
}

void loop()
{
	nh.spinOnce();
	delay(1);
}

// 新终端运行，/dev/ttyUSB0为Arduino设备
rosrun rosserial_python serial_node.py /dev/ttyUSB0
// 发布主题
rostopic pub toggle_led std_msgs/Empty --once



// =============================================================
// 3. ROS与Arduino-使用ros::Time和TF
// =============================================================
/** 
 * rosserial Time and TF Example
 * Publishes a transform at current time
 */

#include <ros.h>
#include <ros/time.h>
#include <tf/transform_broadcaster.h>

ros::NodeHandle  nh;

// 实例化TransformStamped消息类，broadcaster类
geometry_msgs::TransformStamped t;  
tf::TransformBroadcaster broadcaster;

// 指定需要进行转换的参考系名称/base_link，/odom
char base_link[] = "/base_link";
char odom[] = "/odom";

void setup()
{
	nh.initNode();
	broadcaster.init(nh);  // 初始化broadcaster类，使用节点处理类作为参数。
}

void loop()
{  
	// 设置不同参考系的名称，及转换的值内容
	t.header.frame_id = odom;
	t.child_frame_id = base_link;
	t.transform.translation.x = 1.0; 
	t.transform.rotation.x = 0.0;
	t.transform.rotation.y = 0.0; 
	t.transform.rotation.z = 0.0; 
	t.transform.rotation.w = 1.0;  
	
	t.header.stamp = nh.now();  // 调用nh.now()，返回当前的时间。
	
	broadcaster.sendTransform(t);
	nh.spinOnce();
	delay(10);
}

// 新终端运行，/dev/ttyUSB0为Arduino设备
rosrun rosserial_python serial_node.py /dev/ttyUSB0
// 检查是否成功
rosrun tf tf_echo odom base_link



// =============================================================
// 4. ROS与Arduino-Temperature Sensor（温度传感器）
// =============================================================
#include <Wire.h>
#include <ros.h>
#include <std_msgs/Float32.h>


//Set up the ros node and publisher
std_msgs::Float32 temp_msg;
ros::Publisher pub_temp("temperature", &temp_msg);
ros::NodeHandle nh;

int sensorAddress = 0x91 >> 1;  // From datasheet sensor address is 0x91
                                // shift the address 1 bit right,
                                // the Wire library only needs the 7
                                // most significant bits for the address

void setup()
{
	Wire.begin();        // join i2c bus (address optional for master)

	nh.initNode();
	nh.advertise(pub_temp);
}

long publisher_timer;

void loop()
{
	if (millis() > publisher_timer) {
		// step 1: request reading from sensor
		Wire.requestFrom(sensorAddress,2);
		delay(10);
		if (2 <= Wire.available()) {  // if two bytes were received
			byte msb;
			byte lsb;
			int temperature;

			msb = Wire.read();  // receive high byte (full degrees)
			lsb = Wire.read();  // receive low byte (fraction degrees)
			temperature = ((msb) << 4);  // MSB
			temperature |= (lsb >> 4);   // LSB

			temp_msg.data = temperature*0.0625;
			pub_temp.publish(&temp_msg);
		}

		publisher_timer = millis() + 1000; //publish once a second
	}

	nh.spinOnce();
}

#include <OneWire.h>
#include <DallasTemperature.h>
 
// 定义DS18B20数据口连接arduino的2号IO上
#define ONE_WIRE_BUS 2
 
// 初始连接在单总线上的单总线设备
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  // 设置串口通信波特率
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
 
  // 初始库
  sensors.begin();
}
 
void loop(void)
{ 
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // 发送命令获取温度
  Serial.println("DONE");
   
  Serial.print("Temperature for the device 1 (index 0) is: ");
  Serial.println(sensors.getTempCByIndex(0));  
}



// =============================================================
// 5. ROS与Arduino-Push Button(按钮)
// =============================================================
/** 
 * Button Example for Rosserial
 */

#include <ros.h>
#include <std_msgs/Bool.h>


ros::NodeHandle nh;

std_msgs::Bool pushed_msg;
ros::Publisher pub_button("pushed", &pushed_msg);

const int button_pin = 7;
const int led_pin = 13;

bool last_reading;
long last_debounce_time=0;
long debounce_delay=50;
bool published = true;

void setup()
{
	nh.initNode();
	nh.advertise(pub_button);

	pinMode(led_pin, OUTPUT);
	pinMode(button_pin, INPUT);

	// Enable the pullup resistor on the button
	digitalWrite(button_pin, HIGH);

	// The button is a normally button
	last_reading = !digitalRead(button_pin);
}

void loop()
{
	bool reading = ! digitalRead(button_pin);

	if (last_reading != reading){
		last_debounce_time = millis();
		published = false;
	}

	// if the button value has not changed during the debounce delay
	// we know it is stable
	if (!published && (millis() - last_debounce_time) > debounce_delay) {
		digitalWrite(led_pin, reading);
		pushed_msg.data = reading;
		pub_button.publish(&pushed_msg);
		published = true;
	}

	last_reading = reading;

	nh.spinOnce();
}



 






























