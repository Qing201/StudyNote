# Nginx-Docker

## Install

[Docker 安装 Nginx 容器 (完整详细版)](https://blog.csdn.net/BThinker/article/details/123507820)

>启动前需要先创建Nginx外部挂载的配置文件（ ~/nginx/conf/nginx.conf）
之所以要先创建 , 是因为Nginx本身容器只存在/etc/nginx 目录 , 本身就不创建 nginx.conf 文件
当服务器和容器都不存在 nginx.conf 文件时, 执行启动命令的时候 docker会将nginx.conf 作为目录创建 , 这并不是我们想要的结果 。

```sh
# 创建挂载目录
mkdir -p ~/nginx/conf
mkdir -p ~/nginx/log
mkdir -p ~/nginx/html
```



```sh
# 生成容器
docker run --name nginx -d nginx
# 将容器nginx.conf文件复制到宿主机
docker cp nginx:/etc/nginx/nginx.conf ~/nginx/conf/nginx.conf
# 将容器conf.d文件夹下内容复制到宿主机
docker cp nginx:/etc/nginx/conf.d ~/nginx/conf/conf.d
# 将容器中的html文件夹复制到宿主机
docker cp nginx:/usr/share/nginx/html ~/nginx/

docker stop nginx
docker rm nginx
```

> 国内的80端口只有备案后才可以开放

```sh
docker run --name nginx -v ~/nginx/conf/nginx.conf:/etc/nginx/nginx.conf -v ~/nginx/conf/conf.d:/etc/nginx/conf.d -v ~/nginx/log:/var/log/nginx -v ~/nginx/html:/usr/share/nginx/html -d -p 800:80 nginx
```