- [Compiler](#compiler)
  - [ARM-GCC](#arm-gcc)
    - [ARM-GCC 链接文件 .ld](#arm-gcc-链接文件-ld)
  - [MDK](#mdk)
  - [IAR](#iar)
- [EIDE](#eide)
  - [链接文件](#链接文件)
  - [Flasher Configurations](#flasher-configurations)
    - [pyOCD](#pyocd)
  - [(Preprocessor Definitions) 预处理](#preprocessor-definitions-预处理)
- [烧录](#烧录)
  - [OpenOCD](#openocd)
  - [pyOCD](#pyocd-1)
    - [pyOCD add board](#pyocd-add-board)
- [工程配置](#工程配置)
- [.s and .ld file](#s-and-ld-file)
  - [Preprocessor Define](#preprocessor-define)

## Compiler

### ARM-GCC

[GCC Notes](../../C/GCC_Note.md)

#### ARM-GCC 链接文件 .ld

### MDK

链接文件：.sct (运行后生成)

### IAR

链接文件：icf

## EIDE

[EIDE](https://em-ide.com/zh-cn/docs/intro)

EIDE 配置

1. .pack 文件安装
2. 链接.ld 文件
3. 预处理

### 链接文件

在 vscode workspace 文件中添加语句，开启源文件文件自动搜索

```yaml
"settings":
    {
        "EIDE.SourceTree.AutoSearchIncludePath": true,
        "EIDE.SourceTree.AutoSearchObjFile": true,
        ....,
    }
```

### Flasher Configurations

#### pyOCD

add file pyocd.yaml in project dir

> To add pyOCD config file in EIDE: [EIDE: pyOCD](https://em-ide.com/zh-cn/docs/modules/flasher#pyocd)

```yaml
pack: Puya.PY32F0xx_DFP.1.1.7.pack
```

使用 VSCode debug 时，需要添加 pyocd.yaml 到工程根目录，_(EIDE 的 pyocd.yaml 不在根目录中)_

### (Preprocessor Definitions) 预处理

`USE_STDPERIPH_DRIVER` 和使用的芯片型号

## 烧录

### OpenOCD

支持芯片较少

### pyOCD

[pyOCD Official Document](https://pyocd.io/docs/index)

python 安装，在 mac m1 上因为是 arch64 芯片使用会报错，官方中有推荐使用 pipx 进行安装，不会报错

#### pyOCD add board

1. 官方支持的芯片

```sh
# Board Pack
pyocd pack find [BoardName]
pyocd pack install [BoardName]

# Flash
pyocd flash -t [BoardName] [FlashFile(.hex)]
```

2. 非官方支持的芯片

非官方支持的芯片需要 .pack 文件。

```sh
# find the include board in pack
pyocd list --targets --pack [Pack-File]

# Flash
pyocd flash --pack [PackFile] -t [BoardName] [FlashFile(.hex)]
```

> pyOCD config file: [pyocd.yaml](https://pyocd.io/docs/configuration.html#config-file)

## 工程配置

## .s and .ld file

### Preprocessor Define

Define board model and `USE_STDPERIPH_DRIVER`
