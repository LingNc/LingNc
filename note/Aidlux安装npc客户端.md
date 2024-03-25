## Termux安装 npc客户端 实现ssh远程访问

### 配置termux安装npc
打开termux，挂梯子，更新源
```shell
pkg upgrade
pkg update
```
安装vim和openssh和wget
```shell
pkg install vim openssh wget
```
更改密码(按照提示输入新密码)并重启服务
```shell
passwd
sshd
```
- ##### 输入 ```whoami``` 重看用户名，并牢记

下载NPC服务端并重命名为 npc.tar.gz
```bash
wget --no-check-certificate -O npc.tar.gz https://github.com/ehang-io/nps/releases/download/v0.26.10/linux_arm64_client.tar.gz
```
创建一个名为npc的目录并且解压NPC服务端文件到此目录下，并且进入到npc这个目录下
```shell
mkdir ~/npc && tar -zxvf npc.tar.gz -C ~/npc && cd ~/npc
```
编写NPC启动脚本
```shell
vim npc.sh
```
脚本内容
```shell
~/npc/npc -server=120.26.109.83:8024 -vkey=69fzarekw1mspxod -type=tcp
```
授予运行权限
```shell
chmod 777 npc.sh
```
### 设置服务为守护进程开机自动后台开启
#### 1. 相关指令(以sshd为例)
```shell
sv-enable sshd		#sshd服务设为自启动
sv-disable sshd		#取消sshd自启动
sv down sshd		#停止sshd服务，并使本次Termux运行期间sshd自启动服务失效
sv up sshd			#启动sshd服务
sv status sshd		#查看sshd服务运行状态
```
- 安装termux-services,然后重启termux
```shell
pkg install termux-services
```

- 要启用并运行服务，请运行 ```sv-enable <service>```

- 如果你只想运行一次，运行 ```sv up <service>```

- 要稍后停止服务，请运行 ```sv down <service>```

- 或者禁用它 ```sv-disable <service>```
#### 2. 自启动脚本创建
```shell
#在$PREFIX/var/service/下创建子目录，子目录名即为自启动服务名
mkdir -p $PREFIX/var/service/npc

#接下来创建执行脚本run
vim $PREFIX/var/service/npc/run
```
- 脚本内容
```shell
#!/data/data/com.termux/files/usr/bin/sh
exec 2>&1
exec ~/npc/npc.sh 2>&1
```
- 授运行权限
```shell
chmod +x $PREFIX/var/service/npc/run
```
- 配置输出
```shell
mkdir -p $PREFIX/var/service/npc/log
vim $PREFIX/var/service/npc/log/run
```
- ```log/run```中内容
```shell
#!/data/data/com.termux/files/usr/bin/sh
svlogger="/data/data/com.termux/files/usr/share/termux-services/svlogger"
exec "${svlogger}" "$@"
```
- 授运行权限
```shell
chmod +x $PREFIX/var/service/npc/log/run
```
- 此时日志在```$PREFIX/var/log/sv/npc```中
#### 3. 自启动设置
```shell
sv-enable npc
sv-enable sshd
```
- 重启```Termux```应用，此时```npc.sh```已经开始运行，查看日志文件```$PREFIX/var/log/sv/npc/current```

### 安装MCSmanager(docs.mcsmanager.com)

#### 安装nodejs
- 安装nvm(node版本管理器)
nvm是一个node版本管理器，类似与Python中的 Anaconda 、virtural-env。
1. 在终端执行以下命令，将自动进行nvm的安装：
```shell
wget -qO- https://raw.githubusercontent.com/creationix/nvm/v0.34.0/install.sh | bash
```
nvm将被安装到 ```$HOME/.nvm``` 目录中。

2. 安装完成后，重启终端，执行以下命令查看是否安装完成：
```shell
nvm --version
```
3. 使用
```shell
#查看所有可供安装的node版本：
nvm ls-remote

#选择自己想要的版本进行安装，MCS选用 v14.19.1 安装
nvm install v14.19.1

#查看本地已安装的node：
nvm ls

#使用node：
nvm use v14.19.1
```
