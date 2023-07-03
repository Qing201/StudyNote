## EIDE


## 烧录
### OpenOCD
支持芯片较少


### pyOCD
python 安装，在mac m1上因为是arch64芯片使用会报错，官方中有推荐使用pipx进行安装，不会报错

```sh
# Board Pack
pyocd pack find [BoardName]
pyocd pack install [BoardName]

# Flash
pyocd flash -t [BoardName] [FlashFile]

```

## 工程配置
