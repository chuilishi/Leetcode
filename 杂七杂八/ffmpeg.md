### ffmpeg

```
ffprobe -v quiet -print_format json -show_streams out.mp4
```

查看out.mp4的视频信息



**基本使用**

```
ffmpeg -i input.mp4 -c:v libx264 output.mp4
```

-i 输入流

-c: v 选择视频的编码器

-c: a 选择音频的编码器

**编码器**

`-encoders`可以查看所有编码器

- libx264：最流行的开源H.264编码器
- libx265：开源的HEVC编码器
- libvpx：谷歌的VP8和VP9编码器
- libaom：AV1编码器
- NVENC：基于NVIDIA GPU的H.264编码器，可以使用GPU硬件加速
- hevc_nvenc : 基于NVIDIA GPU的H.265编码器，可以使用GPU硬件加速
- hevc_qsv : Inter核显的 编码器( 貌似强一点 )



### Python中使用

```
import ffmpeg
import sys
import os
fullname = sys.argv[1].replace("'","")
filename = os.path.basename(fullname)
path = os.path.dirname(fullname)
Is = ffmpeg.input(filename)
Os = ffmpeg.output(Is,'(_)'+filename,vcodec='hevc_qsv')
ffmpeg.run(Os)
```

### 打包成exe

只有打包成exe才能拖动文件进去

使用**nuitka**来打包

[ Python利用Nuitka模块将程序打包成.exe](https://blog.csdn.net/qq_40144132/article/details/109646464)

[Python打包exe的王炸-Nuitka - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/133303836#:~:text=生成的UI_xxx.py文件和你编写的py模块 (可以包含IP%2C密码)放到一个下一级的文件夹，设置为必须编译为C%2FC%2B%2B。,从此你的打包成功率提升到95%，exe打开速度提升到一秒左右 。)

```
python -m nuitka main.py --standalone--windows-icon-from-ico=图标
```

--standalone 独立环境 把所有依赖包和python环境全部打包

用了--standalone之后就不用再用下面的了,不过可能比较大

--include-package=复制比如numpy,PyQt5 这些带文件夹的叫包或者轮子