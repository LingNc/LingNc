### **第一阶段：Python与数据处理速成（5.20-5.31）**
**目标**：掌握数据清洗与特征工程技能，应对A阶段任务
**每日任务**：2小时学习 + 1小时实战

1. **Python核心库（3天）**
   - **Pandas**（重点）：
     - 数据读取（`pd.read_csv`）、筛选（`df.loc/iloc`）、合并（`merge/concat`）
     - 时间序列操作（`pd.to_datetime`、`resample`、`rolling`）
   - **NumPy**（基础）：数组运算（`reshape`、`broadcasting`）、常用函数（`mean/std`）
   - **学习资源**：
     - 官方文档速读（Pandas 10分钟入门）
     - 实战：用股票数据计算移动平均线（示例代码↓）
       ```python
       import pandas as pd
       data = pd.read_csv('stock_price.csv', parse_dates=['date'])
       data['MA_7'] = data['close'].rolling(7).mean()
       ```

2. **数据清洗与特征工程（5天）**
   - **缺失值处理**：删除（`dropna`）、填充（`fillna`）、插值（`interpolate`）
   - **特征构建**：
     - 时间特征：小时/星期/月份、节假日标识
     - 统计特征：滞后值（`shift`）、滑动窗口统计量（`rolling`）
   - **实战任务**：
     - 对金融数据（如股票开盘价）生成滞后特征（`lag=1,3,7`）
     - 使用Kaggle数据集（如[Titanic](https://www.kaggle.com/c/titanic)）练习特征工程

3. **可视化与探索（2天）**
   - 用Matplotlib绘制价格趋势图、波动率分布图
   - 用Seaborn分析特征相关性（`heatmap`）

---

### **第二阶段：机器学习入门（6.1-6.15）**
**目标**：掌握回归模型与评估方法，应对初步建模

1. **Scikit-learn基础（3天）**
   - **回归模型**：线性回归、决策树、随机森林
   - **模型验证**：交叉验证（`TimeSeriesSplit`）、评估指标（MAE/RMSE）
   - **代码模板**：
     ```python
     from sklearn.ensemble import RandomForestRegressor
     from sklearn.model_selection import TimeSeriesSplit

     # 时间序列交叉验证
     tscv = TimeSeriesSplit(n_splits=5)
     for train_idx, test_idx in tscv.split(X):
         X_train, y_train = X[train_idx], y[train_idx]
         X_test, y_test = X[test_idx], y[test_idx]
         model = RandomForestRegressor()
         model.fit(X_train, y_train)
         pred = model.predict(X_test)
     ```

2. **梯度提升树模型（5天）**
   - **XGBoost/LightGBM**：
     - 核心参数：`n_estimators`, `learning_rate`, `max_depth`
     - 金融场景调参：降低学习率（`0.01-0.1`）、增加树深度（`8-12`）
   - **实战任务**：
     - 用XGBoost预测股票次日涨跌（二分类问题）
     - 参考Kaggle Notebook：[Stock Price Prediction](https://www.kaggle.com/code/faressayah/stock-market-analysis-prediction-using-lstm)

3. **模型融合（2天）**
   - 简单平均法、Stacking集成（用逻辑回归作为元模型）

---

### **第三阶段：时间序列专项突破（6.16-7.10）**
**目标**：掌握时序模型，冲刺A阶段排行榜

1. **传统时序模型（5天）**
   - **ARIMA/SARIMA**：
     - 参数意义：`p`（自回归阶数）、`d`（差分阶数）、`q`（移动平均阶数）
     - 实战步骤：
       1. 检验平稳性（ADF检验）
       2. 差分处理（`diff()`）
       3. 通过ACF/PACF图确定参数
   - **Prophet**：自动处理季节性与节假日
     ```python
     from prophet import Prophet
     model = Prophet(yearly_seasonality=True)
     model.fit(df[['ds','y']])  # ds为时间列，y为数值列
     future = model.make_future_dataframe(periods=30)
     forecast = model.predict(future)
     ```

2. **深度学习时序模型（7天）**
   - **LSTM**（重点）：
     - 输入数据形状：`(样本数, 时间步长, 特征数)`
     - PyTorch实现模板↓
       ```python
       import torch
       import torch.nn as nn

       class LSTMModel(nn.Module):
           def __init__(self, input_dim=1, hidden_dim=64):
               super().__init__()
               self.lstm = nn.LSTM(input_dim, hidden_dim, batch_first=True)
               self.linear = nn.Linear(hidden_dim, 1)
           def forward(self, x):
               out, _ = self.lstm(x)  # x形状: (batch_size, seq_len, input_dim)
               return self.linear(out[:, -1, :])  # 取最后一个时间步
       ```
   - **Transformer**（进阶）：位置编码、多头注意力机制

3. **多模态特征融合（3天）**
   - 将新闻情感分析（如VADER库）与价格序列结合

---

### **第四阶段：决赛冲刺与调优（7.11-7.18）**
**目标**：模型优化与提交策略

1. **过拟合应对**
   - 早停法（Early Stopping）、Dropout层（LSTM中设置`dropout=0.2`）
   - 数据增强：添加高斯噪声、时间窗口偏移

2. **自动化调参工具**
   - **Optuna**：超参数搜索框架（示例代码↓）
     ```python
     import optuna

     def objective(trial):
         params = {
             'learning_rate': trial.suggest_float('lr', 1e-4, 1e-2),
             'n_estimators': trial.suggest_int('n_est', 100, 500)
         }
         model = XGBRegressor(**params)
         return calculate_rmse(model, X, y)

     study = optuna.create_study(direction='minimize')
     study.optimize(objective, n_trials=50)
     ```

3. **提交策略**
   - 每天至少提交2次（早/晚各一次），观察过拟合情况
   - 保留最佳模型的训练代码与参数配置

---

### **关键资源推荐**
1. **书籍**：
   - 《利用Python进行数据分析》（Pandas/Numpy速查）
   - 《时间序列分析实战》（ARIMA/Prophet详解）

2. **课程**：
   - Kaggle Learn微课程（免费，30分钟/节）：[特征工程](https://www.kaggle.com/learn/feature-engineering)
   - Coursera《序列模型》（Andrew Ng，LSTM/Transformer专项）

3. **代码库**：
   - GitHub搜索关键词：`time-series-forecasting pytorch`
   - 官方示例：[PyTorch Forecasting](https://pytorch-forecasting.readthedocs.io/)

---

### **避坑指南**
- **不要过早使用复杂模型**：优先用XGBoost/Prophet跑通baseline
- **严防数据泄露**：金融数据必须按时间严格划分训练/验证集
- **保存中间结果**：将处理后的特征保存为`.pkl`或`.h5`文件，避免重复计算

按照此计划，你可以在**2个月**内从Python基础达到参赛水平，建议同步参与Kaggle相关比赛（如[Store Sales预测](https://www.kaggle.com/c/store-sales-time-series-forecasting)）积累实战经验。