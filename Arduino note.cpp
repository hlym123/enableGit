/**********************************************************************************************

**********************************************************************************************/



// File -> 使用编程器上传   无需启动引导，可直接烧录应用程序

/*
arduino在编译、链接、下载之后，hex文件自动删除了，造成软件仿真（如用proteus仿真）及其他单片机板应用的不便。
	Hex文件的提取: 
	1： 在arduino工具的File->preferences中找到preferences.txt文件。 
	2：用记事本打开preferences.txt,选择hex文件存放的路径，在最后行加入    build.path=d:\arduino\MyHexDir,    
	3：关闭arduino。 
	4：关闭preferences.txt ，关闭时对话框显示是否保存，选择保存。 Note：1：hex文件存放的路径可以由自己来定。
*/


/*
Bootloader local

...\arduino-1.6.5\hardware\arduino\avr\bootloaders\optiboot

*/



