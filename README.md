# QT-restaurantManagerment
C++ Qt 基于数据库SQLite 的餐馆信息管理系统

#### 本项目为本人大三数据库系统的大作业，项目每行代码都是本人从头到尾自己写的。

注：大作业为六人组团体作业，本人主要负责软件设计与实现，主要负责的功能有：用户登录、菜品管理、餐桌管理、顾客排队与就座。



#### 开发环境：

- QT6.2.4

  下载教程： [(152条消息) 1、【QT】QT6.2 官网下载与安装教程_追逐者-桥的博客-CSDN博客_qt软件下载](https://blog.csdn.net/ARM_qiao/article/details/125232068?ops_request_misc=&request_id=&biz_id=102&utm_term=qt6.2.4安装&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-125232068.nonecase&spm=1018.2226.3001.4187) 

- SQLite

  下载教程：https://blog.csdn.net/lj19990824/article/details/120966250?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-2-120966250-blog-105456944.pc_relevant_3mothn_strategy_and_data_recovery&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-2-120966250-blog-105456944.pc_relevant_3mothn_strategy_and_data_recovery&utm_relevant_index=5

#### 学习参考教程：

 [Qt学生管理系统1项目设计与布局开发_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1pZ4y1S7jd/?vd_source=5b40b8fbdaeaa1818563ece8e159bdf3) 

#### README.md参考：

 [chenyongzhe/Qt-studentmanager: C++ Qt 基于数据库Mysql学生信息管理系统 (github.com)](https://github.com/chenyongzhe/Qt-studentmanager) 



#### 使用说明

该餐馆信息管理系统使用的数据库为SQLite；
在另外一台电脑上运行时运行环境必须满足以下要求：

1.那台电脑必须要安装数据库SQLite

2.导入本人数据库脚本文件 data.db (推荐使用navicat)

3.根据你的电脑中data.db的存储位置，修改main.cpp和menusql.cpp里连接SQLite的地址

4.在data.db的user表中可以查看登录的账号密码。

注：可以使用    账号：1、密码：1   登录

以上步骤若没完成则会编译运行不了

运行后进入登录页面



程序效果以及更详细的内容可以看我的实验报告