#pragma once

//宏定义  #define开头的行就是宏定义，宏定义也就是别名
//宏：预处理器指令
//#define 别名 真名

//管理员文件
#define ADMIN_FILE "admin.txt"//在编译前，预处理器会扫描整个代码，每当它看到 ADMIN_FILE，就会把它替换成字符串 "admin.txt"
// 你写的代码
//FILE* file = fopen(ADMIN_FILE, "r");

// 预处理器处理后的代码（这才是编译器真正看到的代码）
//FILE* file = fopen("admin.txt", "r");


//学生文件
#define STUDENT_FILE "student.txt"
//教师文件
#define TEACHER_FILE "teacher.txt"
//机房信息文件
#define COMPUTER_FILE "computerRoom.txt"
//订单文件
#define ORDER_FILE "order.txt"
