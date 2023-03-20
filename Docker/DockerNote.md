- [Docker](#docker)
  - [Docker 常用命令](#docker-常用命令)
    - [Help](#help)
    - [Image](#image)
      - [Download](#download)
      - [Remove](#remove)
    - [Containers/APP](#containersapp)
      - [容器列表](#容器列表)
      - [新建容器并启动](#新建容器并启动)
      - [删除容器](#删除容器)
      - [容器进程](#容器进程)
      - [容器的元数据](#容器的元数据)
      - [进入容器](#进入容器)
      - [容器内拷贝文件](#容器内拷贝文件)


# Docker

## Docker 常用命令

### Help
```sh
docker [] --help
```

### Image
```sh
docker images -a
```

#### Download
```sh
docker pull 
```

#### Remove
```sh
docker rmi -f [ImageID]
docker rmi -f [ImageID] [ImageID] 
docker rmi -f $(docker images -aq)      # Delete all the images 
```

### Containers/APP

#### 容器列表
```sh
docker ps           # 容器列表（正在运行）
docker ps -a        # 所有容器
docker ps -n=[num]  # 最近创建的n个容器
docker ps -aq       # 编号
```

#### 新建容器并启动

```sh
docker run [] [image]
```

**参数**
```
--name [Name]      容器名字，用来区分容器
-d      后台方式运行
-it     使用交互方式运行，进入容器查看内容
-p      指定容器的端ロ -p 8080:8080
    -p ip:主机端口：容器端口
    -p 主机端口：容器端口（常用）
    -p 容器端口
    容器端ロ    
-p      #随机指定端口
```

`exit` 退出容器并停止

容器不停止推出 Ctrl+p+q

#### 删除容器
```sh 
docker rm [容器id]
```

```sh
docker start        # 启动
docker restart      # 重启
docker stop         # 停止
docker kill         # 强制停止
```

#### 容器进程
```sh
docker top [容器ID]     # 查看容器内的进程
```

#### 容器的元数据
```sh
docker inspect [容器ID]
```

#### 进入容器
```sh
docker exec -it [容器ID]        # 进入容器后开启新的终端
docker attach -it [容器ID]      # 进入容器正在执行的终端，不启动新进程
```

#### 容器内拷贝文件
```sh
docker cp [容器ID]:[路径]   [home路径]
```