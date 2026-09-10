# 识辰工作台 · 智慧考勤管理系统

面向中小企业办公场景的智能考勤系统，集成 **IC 卡刷卡** 与 **SeetaFace6 人脸识别** 双通道打卡，覆盖员工注册、考勤查询、充值扣款、串口配置等管理功能，支持 Windows / Linux 双平台构建与部署。

## 一、项目概述

三层结构，双模态打卡 + 权限分级管理后台：

| 层级 | 组成 | 职责 |
|---|---|---|
| 界面层 | Qt Widgets（12 个 `.ui`） | 打卡主界面、管理员登录、7 页管理面板 |
| 业务层 | 单例 `MySql` 封装、全局串口管理 | 员工信息、考勤记录、充值扣款、CSV 导出 |
| 识别层 | SeetaFace6 + QCamera + 工作线程 | 人脸检测与 1:N 比对，异步执行 |

三条数据流：

- **刷卡流**：读卡器 → 串口(500 ms 缓冲) → 正则解析卡号 → 分发到各页面 → 签到 / 签退
- **刷脸流**：摄像头(120 ms 抓帧) → 工作线程检测 + 1:N 比对 → 签到 / 签退
- **管理流**：管理员登录(刷卡 / 密码) → 7 页管理面板 → SQLite 读写

## 二、项目结构

```
Attendance_Check_In_System/
├── Attendance_Check_In_System.pro      # qmake 工程（含 SeetaFace6 跨平台链接配置）
├── main.cpp
├── widget.{h,cpp,ui}                   # 考勤打卡主界面（串口 / 摄像头 / 时钟 / 音效）
├── loginadminwidget.{h,cpp,ui}         # 管理员登录（刷卡自动 / 手动密码）
├── systemmanagementpanel.{h,cpp,ui}    # 管理面板（侧边栏 7 页导航）
├── homepagewidget.{h,cpp,ui}           # 首页仪表盘
├── userregisterwidget.{h,cpp,ui}       # 员工注册
├── usermodifywidget.{h,cpp,ui}         # 员工修改 / 删除
├── attendancerecordswidget.{h,cpp,ui}  # 考勤查询 / 统计 / CSV 导出
├── rechargeanddeductionwidget.{h,cpp,ui} # 充值扣款
├── serialsetwidget.{h,cpp,ui}          # 串口设置
├── setadminwidge.{h,cpp,ui}            # 管理员设置（root 专属）
├── registerwidget.{h,cpp,ui}           # 管理员注册
├── mysql.{h,cpp}                       # SQLite 单例（懒加载 + 建表 + 事务）
├── face/                               # 人脸识别模块
│   ├── faceengine.{h,cpp}              # SeetaFace6 封装（PIMPL + 单例）
│   ├── facecapture.{h,cpp}             # 摄像头采集（引用计数 + 定时抓帧）
│   └── facedetector.{h,cpp}            # 工作线程：异步 1:N 比对
├── image/                              # 图标、音效等资源
└── src.qrc                             # Qt 资源打包
```

| 模块 | 职责 |
|---|---|
| `widget` | 打卡主界面：串口分发中心、摄像头、实时时钟、音效 |
| `mysql` | SQLite 单例：建表、事务、跨线程连接管理 |
| `systemmanagementpanel` | 7 页导航容器 + 权限门控 |
| 7 个业务 `*widget` | 首页、员工注册 / 修改、考勤查询、充值扣款、串口设置、管理员设置 / 注册 |
| `face/*` | 人脸检测、关键点与 1:N 识别（SDK 封装 / 采集 / 工作线程） |

## 三、功能特性

**考勤打卡**

- IC 卡刷卡打卡、摄像头刷脸打卡（任一方式即可签到 / 签退，防止代打卡）
- 实时时钟（时间 / 日期 / 星期，1 秒刷新）+ 最近 10 条打卡记录
- 打卡音效（单播放器，新音效自动中断旧音效）

**管理后台（7 页）**

| # | 页面 | 功能 |
|---|---|---|
| 0 | 首页仪表盘 | 欢迎语 + 统计概览 + 卡片式导航 |
| 1 | 员工注册 | 刷卡录入 + 填表 + 人脸特征录入 |
| 2 | 员工修改 | 刷卡定位 + 修改 + 删除 + 人脸补录 |
| 3 | 考勤查询 | 按卡片 / 姓名查询 + 统计栏 + CSV 导出 |
| 4 | 充值扣款 | 刷卡定位 + 充值 / 扣款 + 余额保护 |
| 5 | 串口设置 | 参数配置 + 收发测试 + `QSettings` 记忆 |
| 6 | 管理员设置 | 管理员注册与信息修改（仅 `root` 可见） |

## 四、量化成果

| 维度 | 指标 |
|---|---|
| 代码规模 | 手写 C++ 约 **3,800 行**；Qt 界面定义 **8,700 余行**（12 个 `.ui`）；最大模块 `widget.cpp` 506 行、`mysql.cpp` 500 行 |
| 界面数量 | **9 个**（1 打卡主界面 + 1 管理员登录 + 7 页管理面板） |
| 打卡方式 | **2 种**：IC 串口刷卡、SeetaFace6 人脸识别 |
| 数据库 | SQLite **4 张表**（`admin` / `user` / `card` / `records`），WAL 模式 |
| 人脸模型 | **3 个** `.csta` 共约 **103 MB**（检测 3.9 MB / 关键点 413 KB / 识别 98 MB） |
| 识别架构 | 独立工作线程 + 双数据库连接，UI 线程零阻塞 |
| 时序参数 | 串口缓冲 **500 ms**、摄像头抓帧 **120 ms**、时钟刷新 **1 s**、最近记录 **10 条** |
| 考勤判定 | 签到 09:00 / 签退 18:00，自动判定 正常 / 迟到 / 早退 / 缺勤 |
| 权限分级 | 超级管理员专属系统设置，普通管理员侧边栏无入口 + 二次校验 |
| 交付形态 | 单文件免安装 exe 约 **175 MB**（windeployqt + Enigma Virtual Box） |

## 五、数据库与核心机制

**数据库（SQLite，4 表）**

| 表 | 主键 | 说明 |
|---|---|---|
| `admin` | `adminCard` | 管理员账户（卡号、密码、姓名） |
| `user` | `card` | 员工信息 + 余额 + **人脸特征 BLOB** |
| `card` | `id` 自增 | 考勤记录（日期、签到 / 签退时间、状态） |
| `records` | `id` 自增 | 充值 / 扣款交易记录（类型、金额、操作后余额） |

考勤规则：签到 < 09:00 正常、≥ 09:00 迟到；签退 ≥ 18:00 正常、< 18:00 早退；当日已有记录写签退，不重复覆盖。

**串口分发**：全局唯一 `QSerialPort` 由主界面持有，`readyRead` → 500 ms 缓冲超时 → 正则提号，经信号分发到 7 个子页面。

**人脸线程模型**：`FaceCapture` 定时抓帧 → 工作线程 `FaceDetector` 执行检测 + 1:N 比对（独立连接 `face_worker` + WAL）→ 结果回主线程更新 UI。

**关键技术**

| 主题 | 实现要点 |
|---|---|
| SeetaFace6 集成 | PIMPL 隔离 SDK 头文件；MinGW 下转换 17 个导入库对接 MSVC 库 |
| 跨线程 SQLite | 工作线程独立连接 + WAL + `Qt::QueuedConnection`，避免 `database is locked` |
| 摄像头管理 | 引用计数，归零时真正释放硬件；静图模式下先设 `setCaptureMode` |
| 数据库懒加载 | 单例改为首次 `getMySql()` 时初始化，避免打包版驱动加载失败 |
| 模型路径 | 三级回退：`./models` → `appDir/models` → SDK 路径 |
| 单文件打包 | Enigma Virtual Box 虚拟化，175 MB 依赖打包为单个 exe |

## 六、编译与部署

**环境要求**：Qt 5.12（Widgets / Multimedia / SerialPort / SQL）、MinGW-w64 64-bit（Windows）或 GCC（Linux）、SeetaFace6 SDK。

```bash
# Windows（Qt 5.12 MinGW 命令行）
qmake Attendance_Check_In_System.pro && mingw32-make -j4

# Linux
qmake && make -j4
```

> SeetaFace6 路径在 `.pro` 中配置：Windows 为 `D:/SeetaFace6_Windows`，Linux 为 `$HOME/opt/SeetaFace6`。

**运行与打包**

1. 将 3 个 `.csta` 模型放入可执行文件同级的 `models/` 目录
2. 确保 SeetaFace6 DLL 与 exe 同目录（`.pro` 已配置 `QMAKE_POST_LINK` 自动复制）
3. 打包：`windeployqt` 收集 Qt 依赖 → Enigma Virtual Box 打包为单文件 exe

**首次使用**

1. 首次运行自动创建 `AttendanceSystem.db`（WAL 模式）与 4 张表
2. 自动初始化超级管理员：卡号 `c2-23-d6-e9`，用户名 `root`，密码 `123456`
3. 在「串口设置」页配置读卡器串口参数（`QSettings` 自动记忆）
4. 用超级管理员登录后，在「员工注册」页录入员工卡片与人脸
