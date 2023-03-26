# GitHub

1. 在项目文件夹git Bash,输入 git init 初始化

2. ```text
   git config --global user.name "这个双引号里填写的是你在 github 注册的账号"
   git config --global user.email "这个双引号里填写的是你在 github 注册的邮箱"
   ```

3. git add 文件名
   git add * 
   git add *.c

   都是提交文件到暂存区

   第一行代码是提交一个文件的写法，
   第二个是提交所有文件的写法
   第三个是提交所有.c文件
   暂存区代表标记这些文件纳入版本控制

4. git commit -m "这里是message"  把暂存区文件提交到仓库 ,-m表示message,一定要输入提交信息,否则会强制你输入

   git status 查看是否还有文件未提交( 即是否还有文件与暂存区不同 )

   git diff 文件名    可以查看该文件和暂存区的不同

   git log 显示最近到最远的提交日志

   git reset --hard HEAD~1   回退一个版本  ( 如果想退多一点就改数字 ) ( HEAD是master的第一个指针 )

   注意回退之后历史记录中那个版本在log中也消失了

   此时还想知道新版本的东西,git reflog

   ![img](https://pic4.zhimg.com/v2-d5fcbdd6c68e194c470b60cf7e4c8353_r.jpg)

   前面的435ccc9之类的就是版本号,

   现在可以git reset --hard 6fcfc89 来恢复了

   

   git checkout -- xx文件  可以将文件恢复成自己暂存区的文件 ( 回退版本则是恢复成		    commit后的文件 )  

5. 接下来就是与网络相关的内容了

   git remote add origin 仓库链接  

   ( 这是将本地仓库与远程仓库关联,以后本地仓库push,pull啥的都可以不加origin了 )

   git push -u origin master  ( 把master分支提交到网络上 ) 
   
   ( -u是第一次操作要做的,以后就不需要了 )
   
   

​		git push origin my_branch:master

​	   ( 这个是把my_branch推送到master分支 如果没有就会创建一个 )

​		类似的: git push origin :main  ( 把空的分支推送过去,相当于删除分支 ,

​		也可以git push origin --delete main )

6. ### 创建与合并分支

   git branch 查看分支

   git branch name 创建分支

   git branch -a 查看所有分支( 包括远程分支 )

   git checkout name 切换分支  ( 创建并切换分支是 git checkout -b name)

   git branch -d name 删除分支

   git merge name  合并分支 将name分支合并到现在的分支 ( 之前要先checkout到另一分支)    

   Fast forward模式下,合并分支后会丢掉分支信息

   可以git merge --no--ff "merge with no-ff" name 取消Fast forward合并name
   
   

 ### 一些注意事项

反复提交时都出现该文件为新内容,可能是换行机制的问题

可以关闭自动转换功能

git config core.autocrlf false  对当前仓库

git config --global core.autocrlf false     全局有效( 不推荐 )

### tips

**关于origin**

git push origin name 这里的origin是远程仓库的默认名称,等同于https://github.com/chuilishi/All-kinds-of-stuff.git   这玩意 你还可以有多个远程仓库,这时就不能再用origin了

**关于ssh公钥私钥**

git生成一个公钥一个私钥

给项目一个公钥,可以与自己的私钥配对

这样可以在不输入密码的情况下不让其他人都来push,配对成功了才能push

**关于git fetch**

git fetch origin master   ( origin一般可以省略 )

这是将远程的master分支搬到本地的远程分支上  本地的本地分支没有改变

想将本地的远程分支与本地分支合并: ( 在本地分支下执行 )

git merge origin/master 

Q: 可以直接操作本地的远程分支吗?

A: 不可以,不信自己试一下,必须操作本地的分支

所以 fetch和merge 搭配使用才达到pull的效果

**获取远程状态**

用git remote show origin

**查看当前所有分支**

git branch -a