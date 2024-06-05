import json

Q_json={
    "judgeMode": "default",
    "samples": [
        {
            "input": "1.in",
            "output": "1.out",
            "score": 100
        }
    ],
    "tags": [
        "河工C语言上机题库A"
    ],
    "problem": {
        "auth": 1,
        "author": "LingNc",
        "isRemote": False,
        "problemId": "C1008",
        "description": "编写一个程序，使用`do...while`循环计算并输出从1加到50的和，即求解表达式 $1 + 2 + 3 + ... + 50$ 的值。",
        "source": "C程序设计A-机试题库",
        "title": "8.求1到50的和（使用do...while循环）",
        "type": 1,
        "timeLimit": 1000,
        "memoryLimit": 256,
        "input": "无输入",
        "output": "输出一个整数，表示1加到50的和。",
        "examples": "<input></input><output>1275</output>",
        "difficulty": 1,
        "ioScore": 100,
        "codeShare": True,
        "hint": "",
        "isRemoveEndBlank": True,
        "openCaseResult": True,
        "judgeCaseMode": "default"
    },
    "codeTemplates": []
}
Q_json["languages"]=[
        "C",
        "C With O2",
        "C++",
        "C++ With O2",
        "C++ 17",
        "C++ 17 With O2",
        "C++ 20",
        "C++ 20 With O2",
        "Java",
        "Python3",
        "Golang",
        "C#",
        "JavaScript Node",
        "JavaScript V8"
    ]
print(Q_json)