import json
json_1 = {
    "json": [
        {
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
                "problemId": "C1015",
                "description": "编写一个程序，求解100～200之间所有整数中，各位数字之和为6的整数，并输出结果。",
                "source": "C程序设计A-机试题库",
                "title": "15.求各位数字之和为6的整数",
                "type": 1,
                "timeLimit": 1000,
                "memoryLimit": 256,
                "input": "无输入",
                "output": "输出各位数字之和为6的整数，每个整数占一行。",
                "examples": "<input></input><output>105\n114\n123\n132\n141\n150\n204</output>",
                "difficulty": 1,
                "ioScore": 100,
                "codeShare": True,
                "hint": "",
                "isRemoveEndBlank": True,
                "openCaseResult": True,
                "judgeCaseMode": "default"
            },
            "codeTemplates": []
        },
        {
            "data1": [
                {
                    "1.in": "",
                    "1.out": "105\n114\n123\n132\n141\n150\n204"
                }
            ]
        }
    ]
}
print(json_1)
print(json_1["json"][0]["problem"]["problemId"])