#!/bin/bash
pkg upgrade
pkg update
pkg install vim openssh wget
passwd
sshd
#下载npc
wget --no-check-certificate -O npc.tar.gz https://github.com/ehang-io/nps/releases/download/v0.26.10/linux_arm64_client.tar.gz
mkdir ~/npc && tar -zxvf npc.tar.gz -C ~/npc && cd ~/npc
#创建启动脚本
touch npc.sh
#设置服务器
echo "~/npc/npc -server=120.26.109.83:8024 -vkey=5y1tmhcvj2xkkjp0 -type=tcp" > npc.sh
chmod 777 npc.sh

#设置自动启动
mkdir -p $PREFIX/var/service/npc
touch $PREFIX/var/service/npc/run
cd $PREFIX/var/service/npc
echo "#!/data/data/com.termux/files/usr/bin/sh" >> run
echo "exec 2>&1" >> run
echo "exec ~/npc/npc.sh 2>&1" >> run

chmod +x $PREFIX/var/service/npc/run

mkdir -p $PREFIX/var/service/npc/log
touch $PREFIX/var/service/npc/log/run
cd $PREFIX/var/service/npc/log
echo "#!/data/data/com.termux/files/usr/bin/sh" >> run
echo "svlogger=\"/data/data/com.termux/files/usr/share/termux-services/svlogger\"" >> run
echo "exec \"${svlogger}\" \"$@\"" >> run
chmod +x $PREFIX/var/service/npc/log/run

#安装termux-services
pkg install termux-services

