#! /bin/sh
echo $# #代表参数的个数
echo $*	#代表所有的参数
echo $0	#代表命令本身

# 注意！$i的模式只有0~9超过10个可以使用shift移位后使用
echo $1	#代表第一个参数
echo $2	#代表第2个参数
./main
echo $? #代表上一个命令的返回结果

