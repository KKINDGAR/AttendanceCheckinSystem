# 识辰工作台 · 智慧考勤管理系统

面向中小企业办公场景的智能考勤系统，集成 **IC 卡刷卡** 与 **SeetaFace6 人脸识别** 双通道打卡，覆盖员工注册、考勤查询、充值扣款、串口配置等管理功能，支持 Windows / Linux 双平台构建与部署。

- **双模态打卡**：刷卡、刷脸任一方式即可完成签到 / 签退，有效防止代打卡
- **异步人脸识别**：人脸检测与 1:N 比对在工作线程执行，UI 全程流畅不阻塞
- **完整管理后台**：7 页管理面板 + 权限分级（仅超级管理员可进入系统设置）

---

## 一、功能特性

### 1.1 考勤打卡（主界面）

| 功能 | 说明 |
|---|---|
| IC 卡刷卡打卡 | 串口读卡 → 正则解析卡号 → 签到 / 签退 |
| 人脸识别打卡 | 摄像头抓帧 → 工作线程检测 + 1:N 比对 → 签到 / 签退 |
| 实时时钟 | 时间 / 日期 / 星期，1 秒刷新 |
| 最近打卡记录 | 表格展示最近 10 条 |
| 打卡音效 | 单播放器防重叠，新音效自动中断旧音效 |
| 管理员入口 | 进入管理员登录页 |

### 1.2 管理后台（7 页）

| # | 页面 | 功能 |
|---|---|---|
| 0 | 首页仪表盘 `HomePageWidget` | 欢迎语 + 统计概览 + 卡片式导航 |
| 1 | 员工注册 `UserRegisterWidget` | 刷卡录入 + 填表 + 人脸特征录入 |
| 2 | 员工修改 `UserModifyWidget` | 刷卡定位 + 信息修改 + 删除 + 人脸补录 |
| 3 | 考勤查询 `AttendanceRecordsWidget` | 按卡片 / 姓名查询 + 统计栏 + **CSV 导出** |
| 4 | 充值扣款 `RechargeAndDeductionWidget` | 刷卡定位 + 充值 / 扣款 + 余额保护 |
| 5 | 串口设置 `SerialSetWidget` | 参数配置 + 收发测试 + `QSettings` 记忆 |
| 6 | 管理员设置 `SetAdminWidge` | 管理员注册与信息修改（**仅 root 可见**） |

---

## 二、技术栈

| 类别 | 技术 | 版本 |
|---|---|---|
| 框架 | Qt（Widgets / Multimedia / SerialPort / SQL） | 5.12.0 |
| 语言 | C++ | C++11 |
| 编译器 | MinGW-w64 64-bit（Windows）/ GCC（Linux） | mingw73_64 |
| 数据库 | SQLite 3（Qt 内置驱动，WAL 模式） | — |
| 人脸识别 | SeetaFace6 | 6.0 / 6.1 |
| 构建 | qmake | Qt 5.12 |
| 打包 | windeployqt + Enigma Virtual Box | — |
| 设计模式 | 单例、PIMPL、信号槽（观察者） | — |
| 并发 | `QThread` + `moveToThread` + `Qt::QueuedConnection` | — |
| 配置持久化 | `QSettings`（INI） | — |

---

## 三、项目结构

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

**代码规模**：手写 C++ 约 **3,800 行**（`*.cpp` / `*.h`），Qt Designer 界面定义 **8,700 余行**（12 个 `.ui`）。最大模块 `widget.cpp` 506 行、`mysql.cpp` 500 行。

---

## 四、系统架构

### 4.1 串口数据分发

全局唯一 `QSerialPort` 由 `Widget` 持有，通过信号槽分发给 7 个子页面：

```
QSerialPort (Widget 持有，唯一实例)
  └─ readyRead → Widget::onSerialReadyRead
       └─ 500 ms 缓冲超时 → onCardTimeout
            └─ 正则解析卡号（格式 xx-xx-xx-xx）
                 ├─ emit cardParsed            → 员工注册页
                 ├─ emit cardParsedToModify    → 员工修改页
                 ├─ emit cardParseAttendance   → 考勤查询页
                 ├─ emit cardParseRecharge     → 充值扣款页
                 ├─ emit cardParseRegistPage   → 管理员注册页
                 ├─ emit cardParseLoginPage    → 登录页
                 └─ emit cardParseSystemPage   → 管理面板
```

### 4.2 人脸识别线程模型

```
主线程 (UI)                              工作线程 (FaceDetector)
  FaceCapture::start() → 120 ms 定时抓帧
    → 缩放至 640px → QLabel 预览
    → emit frameCaptured
      → Widget::tryFaceCheckIn
        → emit frameForDetection ───────→ processFrame
                                          ├─ detectFace（CPU 密集）
                                          ├─ DB 查询（独立连接 face_worker）
                                          └─ 1:N 余弦相似度比对
        ←── matchResult / noMatch ────────┘
```

- 检测与比对全程不占用 UI 线程
- 工作线程使用独立数据库连接并启用 WAL，避免 `database is locked`

### 4.3 页面导航与权限门控

```
main.cpp → Widget（考勤打卡）
              └→ [管理员入口] → LoginAdminWidget
                    ├─ 刷卡 → 自动登录
                    └─ 手动输入（卡号+密码 / 用户名+密码）
                         └→ SystemManagementPanel（7 页导航）
                              ├─ setAdminCard(card) 读取管理员姓名
                              │    ├─ name == "root" → 显示管理员设置入口
                              │    └─ name != "root" → 隐藏（侧边栏无入口 + 二次校验）
                              └─ stackedWidget 页面切换
```

---

## 五、数据库设计

SQLite 单文件 `AttendanceSystem.db`，4 张表：

| 表 | 主键 | 说明 |
|---|---|---|
| `admin` | `adminCard` | 管理员账户（卡号、密码、姓名） |
| `user` | `card` | 员工信息（姓名、年龄、性别、注册时间、余额、**人脸特征 BLOB**） |
| `card` | `id` 自增 | 考勤记录（日期、签到时间、签退时间、状态） |
| `records` | `id` 自增 | 充值 / 扣款交易记录（类型、金额、操作后余额、备注） |

### 考勤规则

| 规则 | 条件 | 结果状态 |
|---|---|---|
| 正常签到 | 签到时间 < 09:00 | 正常 |
| 迟到 | 签到时间 ≥ 09:00 | 迟到 |
| 正常签退 | 签退时间 ≥ 18:00 | 正常 |
| 早退 | 签退时间 < 18:00 | 早退 |
| 缺勤 | 全天无记录 | 缺勤 |
| 每日一签 / 一退 | 当日已有记录则写签退，已签退不再覆盖 | — |

---

## 六、关键技术实现

| 主题 | 实现要点 |
|---|---|
| **SeetaFace6 集成** | `faceengine` 以 PIMPL 隐藏 SDK 头文件、单例暴露接口；MinGW 下用 17 个导入库（`.dll.a`）+ 29 个头文件完成 MSVC 库对接 |
| **跨线程 SQLite** | 主线程用默认连接，工作线程用命名连接 `face_worker`；两者均开 `journal_mode=WAL`，信号槽显式 `Qt::QueuedConnection` |
| **串口粘包处理** | `readyRead` 追加缓冲 + 500 ms 超时判定 + 正则提取卡号 |
| **摄像头引用计数** | `m_refCount` 计数归零时真正释放硬件；`setCaptureMode` 必须先于 `new QCameraImageCapture` |
| **数据库懒加载** | 单例改为首次 `getMySql()` 时初始化，避免在 `QApplication` 之前加载驱动导致打包版插件失效 |
| **人脸模型路径** | 三级回退：`./models` → `appDir/models` → SDK 路径 |

**人脸模型（3 个 `.csta`，共约 103 MB）**

| 模型文件 | 大小 | 用途 |
|---|---|---|
| `face_detector.csta` | 3.9 MB | 人脸检测定位 |
| `face_landmarker_pts5.csta` | 413 KB | 5 点关键点定位 |
| `face_recognizer.csta` | 98 MB | 特征提取 + 1:N 比对 |

---

## 七、技术难点与解决方案

| # | 难点 | 解决方案 |
|---|---|---|
| 1 | SeetaFace6 为 MSVC 编译，MinGW 无法直接链接 | 转换导入库（`.dll.a`）+ PIMPL 隔离头文件 |
| 2 | 跨线程 SQLite 报 `database is locked` | 工作线程独立连接 + WAL + QueuedConnection |
| 3 | DirectShow 后端在静图模式下状态机异常 | 调整 `setCaptureMode` 与 `QCameraImageCapture` 的创建顺序 |
| 4 | RFID 读卡器数据粘包 / 含噪声 | 500 ms 缓冲超时 + 正则提号 |
| 5 | 模型路径开发环境与打包版不一致 | 三级路径回退 |
| 6 | 174 MB 依赖无法直接分发 | Enigma Virtual Box 虚拟化打包为单 exe |
| 7 | 侧边栏按钮 `autoExclusive` 失效（父对象不同） | 手动 `setChecked(false)` 维护互斥 |
| 8 | 打包版数据库驱动加载失败 | 单例改懒加载 |
| 9 | 目标机缺 MinGW 运行时 | 补全 `libmcfgthread-2.dll`、`libgomp-1.dll` 等 |
| 10 | Qt Creator 增量编译导致 UI 不更新 | 全量清理 + 重新 UIC 生成 |

---

## 八、构建与运行

### 环境要求

- Qt 5.12（Widgets / Multimedia / SerialPort / SQL）
- MinGW-w64 64-bit（Windows，不可与 MSVC 混用）或 GCC（Linux）
- SeetaFace6 SDK（检测 / 关键点 / 识别 / 跟踪 + 授权库）

### 编译

```bash
# Windows 使用 Qt 5.12 MinGW 命令行环境
cd Attendance_Check_In_System
qmake Attendance_Check_In_System.pro
mingw32-make -j4

# Linux
qmake && make -j4
```

> SeetaFace6 路径在 `.pro` 中配置：Windows 为 `D:/SeetaFace6_Windows`，Linux 为 `$HOME/opt/SeetaFace6`，按实际安装位置修改。

### 运行与打包

1. 将 3 个 `.csta` 模型放入与可执行文件同级的 `models/` 目录
2. 确保 SeetaFace6 相关 DLL 在可执行文件目录（`.pro` 已配置 `QMAKE_POST_LINK` 自动复制）
3. 发布：`windeployqt` 收集 Qt 依赖，再用 Enigma Virtual Box 打包为单文件免安装 exe（约 175 MB）

---

## 九、使用说明

### 硬件

| 硬件 | 要求 |
|---|---|
| RFID 读卡器 | 串口（COM 口），卡号格式 `xx-xx-xx-xx` |
| 摄像头 | USB 摄像头，Windows DirectShow 兼容 |
| 操作系统 | Windows 7 / 10 / 11 64 位（Linux 端源码可用） |

### 首次使用

1. 首次运行自动创建数据库 `AttendanceSystem.db`（WAL 模式）与 4 张表
2. 自动初始化超级管理员：卡号 `c2-23-d6-e9`，用户名 `root`，密码 `123456`
3. 在「串口设置」页配置读卡器串口参数（`QSettings` 会自动记忆）
4. 用超级管理员登录后，在「员工注册」页录入员工卡片与人脸
