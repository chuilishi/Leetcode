# Linux

clear  清除命令行的内容

pwd  打印当前目录

ls  查看当前目录所有文件   -l 更多信息   -s 同时展示隐藏文件夹,以点开头的文件一般代表隐藏 (一些配置文件)   -ls,两者同时进行

 rm  -rf   文件   删除 // -f代表强制删除,  -r代表递归删除,也就是可以删除其目录下的文件

mkdir 创建文件夹( make directory)

rmdir  删除文件夹( rm directory)

find  目录  条件  动作   目录不加就找该目录  条件很复杂,上网找    一般都是find / -name  xxx

常用:

 **-path** 路径中  | **"* xxx *"** 包含xxx  | **-name " * .png"  -o  -name "*.jpg"**   png和jpg文件 |

-maxdepth 1 深度1(即不包括子目录)

grep  路径  关键字   从路径中找到带关键字的文件

cd - 返回之前那个目录    cd ..返回上级目录

touch 

cp

mv  文件夹存在/文件夹不存在

grep   global **regular expression**(正则表达式) print

passwd

定义变量

echo 回声  

打印变量

$代表

info

在查看类的命令后面加 > 某文本     加>> 某文本

起别名: alias  别名=真名    unalias  别名

解压缩tar:

tar -参数(一般是xzvf)  文件名  文件名... -C 目录   //

```
1 -c: 建立压缩档案
2 -x：解压
3 -t：查看内容
4 -r：向压缩归档文件末尾追加文件
5 -u：更新原压缩包中的文件
上面5个中选一个
1 -z：有gzip属性的
2 -j：有bz2属性的
3 -J：具有xz属性的（注3）
4 -Z：有compress属性的
5 -v：显示所有过程
6 -O：将文件解开到标准输出
上面6个组合

总结:
(1) *.tar 用 tar –xvf 解压
(2) *.gz 用 gzip -d或者gunzip 解压
(3) *.tar.gz和*.tgz 用 tar –xzf 解压
(4) *.bz2 用 bzip2 -d或者用bunzip2 解压
(5) *.tar.bz2用tar –xjf 解压
(6) *.Z 用 uncompress 解压
(7) *.tar.Z 用tar –xZf 解压
(8) *.rar 用 unrar e解压
(9) *.zip 用 unzip 解压
(10) *.xz 用 xz -d 解压
(11) *.tar.xz 用 tar -zJf 解压
压缩
1 # tar -cvf test.tar test 仅打包，不压缩 
2 # tar -zcvf test.tar.gz test 打包后，以gzip压缩 在参数f后面的压缩文件名是自己取的，习惯上用tar来做，如果加z参数，则以tar.gz 或tgz来代表gzip压缩过的tar file文件
```



**安装程序(apt)**

查看有啥版本:

apt-cache madison 软件  或

apt-cache policy 软件

有的话就可以:

apt-get install 软件=版本号    apt安装会把程序的各个部分分散在ubuntu设定的不同位置

**权限**

打印ls -l 之后 最左侧的文本  d rwx rwx r-x    

d代表是目录 r读取权限  w写入权限  x执行权限 ,-代表没有对应权限

chmod 改变权限

![image-20230116005915760](C:\Users\zh148\AppData\Roaming\Typora\typora-user-images\image-20230116005915760.png)

7对应三个,6对应rw,以此类推

获取root权限: sudo su 然后输入密码

网段:192.168.0.xxx之下的所有ip都是同一网段



![image-20230116004015367](C:\Users\zh148\AppData\Roaming\Typora\typora-user-images\image-20230116004015367.png)

ls /之后,我们看到linux的目录结构

![image-20230116004119904](C:\Users\zh148\AppData\Roaming\Typora\typora-user-images\image-20230116004119904.png)

安装软件通常在/usr下



**ifconfig** 获取ip相关信息

**颜色对应含义**

浅蓝色	[l]	软链接
白色		[-]	普通文件/硬链接
蓝色		[d] 目录
红色 	[l]	某文件被删除后，链接到该文件的软链接的颜色
红色闪烁  无  表示该文件已被删除，但还存在该文件的软链接
红色 	[-] 压缩包
黄色 	[c] 字符设备文件，如键盘鼠标
绿色 	[-] 可执行文件，可执行的程序 
桃红色	[s] 套接字文件
土黄色   [p] 管道文件
灰色文件		表示其它文件

**环境变量配置**

首先进入/etc/profile  配置环境变量的文件    //etc是配置文件的目录

```text
1 export JAVA_HOME=/usr/lib/jvm/jdk1.8.0_261
2 export PATH=$JAVA_HOME/bin:$PATH
3 export CLASSPATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar
```

export是执行的意思,  : 是分隔符,相当于windows的 ;

每个 $JAVA_HOME  都换成  JAVA_HOME变量    冒号:是分隔符,用来分隔各个PATH

PATH中存放的是可执行程序的搜索目录, 也就是可执行程序会从PATH中搜索

CLASSPATH是JAVA需要的

/etc/profile是全局的环境变量

还有一些开机读取的,关机读取的,用户自己的之类的东西都可以找环境变量



echo $PATH 可以查看所有环境变量

**vim**

按i进入编辑模式

写完按esc,然后

:w 保存文件但不退出vi
:w file 将修改另外保存到file中，不退出vi
:w! 强制保存，不推出vi
:wq 保存文件并退出vi
:wq! 强制保存文件，并退出vi ( 没有权限的情况下 )
:q 不保存文件，退出vi
:q! 不保存文件，强制退出vi
:e! 放弃所有修改，从上次保存文件开始再编辑命令历史

**mysql**

service mysql start/stop   开启/关闭服务

mysql -uroot -p 登录root用户

netstat -anp 查看端口

netstat -anp |grep mysql  查看带mysql字样的端口

use mysql-> select user, host from user (从user数据库中看user和host) 

create user 'test'@'localhost' identified  by 'zh';    identified: 以zh为密码   localhost可以换成%代表所有ip,也可以换成其他ip

**路径问题**

./  点代表工作目录  执行文件时前面必须要目录, 就算文件在当前文件,只有加上这个才能运行.( 除非配置了环境变量 )

**Tomcat**

启动路径: /usr/local/tomcat/apache-tomcat-9.0.11/bin/startup.sh

终止路径:shutdown.sh

端口设置为80可以在访问网址时就直接访问到端口

**服务**

/etc/init.d   这个文件下都是服务脚本

ubuntu有额外的
