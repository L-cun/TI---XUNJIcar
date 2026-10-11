# TI---XUNJIcar
# README.md（TI MSPM0 寻迹智能车项目）
```markdown
# TI---XUNJIcar
基于 TI MSPM0G3507 的寻迹智能车工程，CCS 开发环境。

## 📌 项目简介
本项目为嵌入式寻迹小车，使用 MSPM0G3507 主控芯片，搭载红外循迹传感器、OLED 显示屏、姿态传感器与电机驱动模块。
小车可完成黑线循迹、弯道识别、速度PID控制、姿态数据实时显示等功能。

## 🛠 硬件平台
- 主控：TI MSPM0G3507
- 驱动：直流电机驱动模块
- 感知：红外循迹阵列、WIT 姿态传感器
- 显示：SPI 接口 OLED 屏幕
- 电源：锂电池供电

## 💻 开发环境
- IDE：TI Code Composer Studio (CCS)
- 编程语言：C语言
- 编译工具：TI Arm Compiler
- 版本管理：Git + GitHub

## 📂 工程目录结构
```
├── Drivers/                # 底层驱动文件夹
│   ├── Delay/              # 延时函数
│   ├── Key/                # 按键驱动
│   ├── MSPM0/              # 系统时钟、中断配置
│   ├── Mor/                # 电机驱动
│   ├── OLED_Hardware_SPI/  # SPI OLED屏幕驱动
│   ├── WIT/                # 姿态传感器驱动
│   ├── circle/             # 弯道处理逻辑
│   └── xunji/              # 寻迹算法
├── targetConfigs/          # CCS芯片配置文件
├── main.c / main.h         # 主函数入口
├── mspm0-modules.syscfg    # SysConfig图形化配置文件
├── .gitignore              # Git忽略文件配置
└── .ccsproject             # CCS工程文件
```

## ✨ 功能说明
1. **红外寻迹**：多路红外传感器采集地面黑线，实现路径识别。
2. **电机控制**：PWM 输出控制电机转速，差速转向。
3. **PID调速**：使用PID算法稳定车速，优化过弯性能。
4. **姿态采集**：WIT 传感器读取小车姿态角。
5. **OLED显示**：实时打印传感器数据、车辆状态。

## 🚀 编译与烧录
1. 使用 CCS 导入本工程
2. 连接 MSPM0 开发板，选择对应 `.ccxml` 配置文件
3. 编译工程，下载程序到主控芯片
4. 上电即可运行寻迹逻辑

## ⚠ 注意事项
1. `Debug/`、`Release/` 编译输出文件已在 `.gitignore` 中忽略，不会上传到仓库。
2. 红外传感器需要根据实际赛道做阈值校准。
3. 电机PID参数需要根据机械结构进行调参。

## 📜 开源协议
MIT License
```

# 粘贴文本，Ctrl+O保存，Ctrl+X退出
git add README.md
git commit -m "docs: 完善项目README文档"
git push
```
