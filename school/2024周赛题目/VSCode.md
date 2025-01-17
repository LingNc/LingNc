### 1. 下载并解压便携版 VSCode
首先，你需要下载一个已经配置好的便携版 VSCode。这个版本已经包含了你需要的一些工具，比如 `mingw`。

1. **下载压缩包**：从你提供的地方下载这个压缩包。
2. **解压压缩包**：将下载的压缩包解压到你电脑上的任意位置。解压后，你会看到一个文件夹，里面包含了 VSCode 和一些其他工具。

### 2. 提取 VSCode 本体
在解压后的文件夹中，找到一个名为 `VSCode` 的文件夹。这个文件夹就是 VSCode 的本体。

1. **复制 `VSCode` 文件夹**：将这个 `VSCode` 文件夹复制到你希望存放 VSCode 的地方。比如，你可以把它放在桌面上，或者放在一个你容易找到的文件夹里。

### 3. 配置系统环境变量
为了让 VSCode 能够找到 `mingw` 工具，你需要将 `mingw` 的路径添加到系统的环境变量中。

1. **找到 `mingw` 的路径**：在刚才复制的 `VSCode` 文件夹中，找到 `mingw` 文件夹，然后进入 `bin` 文件夹。这个文件夹的路径通常是 `VSCode\mingw\bin`。
2. **打开系统环境变量设置**：
   - 在 Windows 系统中，右键点击“此电脑”或“计算机”，选择“属性”。
   - 在左侧菜单中选择“高级系统设置”。
   - 在弹出的窗口中，点击“环境变量”按钮。
3. **添加环境变量**：
   - 在“系统变量”部分，找到名为 `Path` 的变量，然后点击“编辑”。
   - 在弹出的窗口中，点击“新建”按钮。
   - 将刚才找到的 `mingw` 的路径（例如 `C:\你的路径\VSCode\mingw\bin`）粘贴到新建的行中。
   - 点击“确定”保存设置。

### 4. 启动 VSCode 并编写 C++ 代码
现在，你可以启动 VSCode 并开始编写 C++ 代码了。

1. **启动 VSCode**：打开刚才复制的 `VSCode` 文件夹，找到并双击 `Code.exe` 文件，启动 VSCode。
2. **创建 C++ 文件**：在 VSCode 中，创建一个新的文件夹，并在其中创建一个 `.cpp` 文件，比如 `main.cpp`。
3. **编写代码**：在 `main.cpp` 文件中编写你的 C++ 代码。

### 5. 运行 C++ 代码
当你写好代码后，可以通过按下 `F5` 键（或者 `Fn + F5` 键，如果你的键盘有 `Fn` 键）来运行代码。

1. **选择调试器**：在第一次运行时，VSCode 会提示你选择调试器。选择 `gdb` 中的 `g++` 选项。
2. **运行代码**：选择调试器后，VSCode 会自动编译并运行你的 C++ 代码。
### 6. 配置桌面快捷方式
为了方便以后快速启动 VSCode，你可以为它创建一个桌面快捷方式。

1. **找到 VSCode 的可执行文件**：在刚才复制的 `VSCode` 文件夹中，找到 `Code.exe` 文件。这个文件通常位于 `VSCode` 文件夹的根目录下。
2. **创建快捷方式**：
   - 右键点击 `Code.exe` 文件，然后在弹出的菜单中选择“发送到” -> “桌面快捷方式”。
3. **验证快捷方式**：
   - 现在，你应该在桌面上看到一个名为 `Code` 的快捷方式图标。
   - 双击这个图标，VSCode 应该会启动。
