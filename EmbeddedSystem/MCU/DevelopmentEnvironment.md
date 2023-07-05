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

#### pyOCD add board
> [git reference](https://github.com/jaydcarlson/py32-template)

Puya's DFP is not currently indexed anywhere, so pyOCD can't automatically download it with the typical `pack update` and `pack install` commands. However, we can manually download and extract this pack, and then install the pack using cmsis-pack-manager (which PyOCD uses under the hood)

First, get a copy of the DFP, which is found in Puya's PY32 SDK download available on their [PY32 web page](https://www.puyasemi.com/cpzx3/info_271_aid_247_kid_246.html). The download link is listed under the "Datasheet" column in the far right of the device table — you can [directly download the file here](https://www.puyasemi.com/uploadfiles/2022/11/PY-MCU%E8%B5%84%E6%96%99-20221117.rar), though this link may be out of date. If you extract this RAR, you'll end up with documentation, code samples, and the Puya.PY32F0xx_DFP.1.1.0.pack DFP pack.

Next, unzip `Puya.PY32F0xx_DFP.1.1.0.pack` (it's just a ZIP with a .pack extension). Then, copy the `pdesc` file to cmsis-pack-manager's repository along with all the other pdsc files (this will be located in your Python distribution). It needs to be renamed to `Puya.PY32F0xx_DFP.1.1.0.pdsc` (with the version numbers present).

Next, copy the original DFP pack file to `Puya\PY32F0xx_DFP\1.1.0.pack` creating directories and renaming the pack file accordingly. 

Now, add the pack to cmsis-pack-manager:
```
PS C:\> pack-manager add-packs Puya.PY32F0xx_DFP.1.1.0.pdsc
```
Now you can install the actual target support in PyOCD:
```
PS C:\> pyocd pack find PY32
  Part          Vendor   Pack                Version   Installed
------------------------------------------------------------------
  PY32F002Ax5   Puya     Puya.PY32F0xx_DFP   1.1.0     True
  PY32F003x4    Puya     Puya.PY32F0xx_DFP   1.1.0     True
  PY32F003x6    Puya     Puya.PY32F0xx_DFP   1.1.0     True
  PY32F003x8    Puya     Puya.PY32F0xx_DFP   1.1.0     True
  PY32F030x3    Puya     Puya.PY32F0xx_DFP   1.1.0     True
  PY32F030x4    Puya     Puya.PY32F0xx_DFP   1.1.0     True
  PY32F030x6    Puya     Puya.PY32F0xx_DFP   1.1.0     True
  PY32F030x7    Puya     Puya.PY32F0xx_DFP   1.1.0     True
  PY32F030x8    Puya     Puya.PY32F0xx_DFP   1.1.0     True
  PY32F072xB    Puya     Puya.PY32F0xx_DFP   1.1.0     True

PS C:\> pyocd pack install PY32F003x8
```

## 工程配置


