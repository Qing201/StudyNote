- [Docker](#docker)
  - [Reference](#reference)
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
      - [commit镜像](#commit镜像)
    - [容器数据卷 (Volume)](#容器数据卷-volume)
      - [具名与匿名挂载](#具名与匿名挂载)
      - [read and write permission](#read-and-write-permission)
    - [Docker file](#docker-file)
    - [Docker 网络](#docker-网络)
  - [企业实战](#企业实战)
    - [Docker Compose](#docker-compose)
    - [Docker Swarm](#docker-swarm)
    - [CI/CD Jenkins 流水线](#cicd-jenkins-流水线)
  - [Docker APP](#docker-app)
    - [Portainer](#portainer)
    - [Home Assistant](#home-assistant)


# Docker

## Reference
[Docker Doc](https://docs.docker.com/reference)
[Docker Hub](https://hub.docker.com)


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

#### commit镜像
将容器保存为一个新的本地image
```sh
docker commit -m=["提交的描述信息"] -a=["author"] [container ID] [target image name]:[TAG]
```

### 容器数据卷 (Volume)
container中的文件与本地系统文件共享

```sh
docker run it -v [local addr]:[container addr]
```


#### 具名与匿名挂载
没有指定 local addr 情况都是在 `/var/lib/docker/volumes/.../_data`
```sh
-v [container addr]         # 匿名挂载
-v [name]:[container addr]  # 具名挂载
-v /[local addr]:[container addr]   # 指定路径挂载
```

#### read and write permission
```sh
-v [local addr]:[container addr]:ro     # ro read-only
-v [local addr]:[container addr]:rw     # rw read-write 
```

ro: the file can only edit in local system, cannot edit in container

```sh
docker run --volumes-from [container_1] [container_2]
```
新建的container_2可以挂载container_1的数据卷

### Docker file

### Docker 网络


## 企业实战

### Docker Compose

### Docker Swarm

### CI/CD Jenkins 流水线


## Docker APP
### Portainer
[Portainer Install](https://docs.portainer.io/start/install-ce/server/docker/linux)

```sh
docker volume create portainer_data
docker run -d -p 8000:8000 -p 9443:9443 --name portainer --restart=always -v /var/run/docker.sock:/var/run/docker.sock -v portainer_data:/data portainer/portainer-ce:latest
```

[Portainer Update](https://docs.portainer.io/start/upgrade/docker)

```sh
docker stop portainer
docker rm portainer
docker pull portainer/portainer-ce:latest
```

### Home Assistant
[Home Assistant Install](https://www.home-assistant.io/installation/)
```sh
docker run -d \
  # -p 8123:8123 \    # don't need when use --network=host
  --name homeassistant \
  --privileged \
  --restart=unless-stopped \
  -e TZ=Asia/Shanghai \
  -v homeassistant_data:/config \
  --network=host \
  ghcr.io/home-assistant/home-assistant:stable
```

Once the Home Assistant Container is running Home Assistant should be accessible using `http://<host>:8123`
