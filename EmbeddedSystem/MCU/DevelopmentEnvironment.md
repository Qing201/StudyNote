##  Compiler

### ARM-GCC

[GCC Notes](../../C/GCC_Note.md)

#### ARM-GCC 链接文件 .ld


### MDK
链接文件：.sct (运行后生成)

### IAR
链接文件：icf


## EIDE
[EIDE](https://em-ide.com/zh-cn/docs/intro)

## 烧录
### OpenOCD
支持芯片较少


### pyOCD
[pyOCD Official Document](https://pyocd.io/docs/index)

python 安装，在mac m1上因为是arch64芯片使用会报错，官方中有推荐使用pipx进行安装，不会报错

```sh
# Board Pack
pyocd pack find [BoardName]
pyocd pack install [BoardName]

# Flash
pyocd flash -t [BoardName] [FlashFile]

```

#### pyOCD add board
> [git reference](https://github.com/jaydcarlson/py32-template)

> [pyOCD config file](https://pyocd.io/docs/configuration.html#config-file)

add file pyocd.yaml 

```yaml
pack:
    Puya.PY32F0xx_DFP.1.1.7.pack
```

> To add pyOCD config file in EIDE: [EIDE: pyOCD](https://em-ide.com/zh-cn/docs/modules/flasher#pyocd)

## 工程配置

## .s and .ld file

### Preprocessor Define
Define board model and `USE_STDPERIPH_DRIVER`

