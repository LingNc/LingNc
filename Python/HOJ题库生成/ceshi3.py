import json
json_1 ='''{
    "question": "18．编写程序，输入一个字符，判别它是否为大写字母，并输出结果。（‘A’对应的ASCII码为65）（20分）",
    "content": {
        "problem": {
            "auth": 1,
            "author": "LingNc",
            "isRemote": false,
            "problemId": "C1018",
            "description": "编写一个程序,输入一个字符，判断该字符是否为大写字母。大写字母的ASCII码范围为 $65 \\\\leq ASCII \\\\leq 90$。",
            "source": "C程序设计A-机试题库",
            "title": "18.判断字符是否为大写字母",
            "input": "输入一个字符。",
            "output": "如果输入的字符是大写字母，输出'Yes'，否则输出'No'。",
            "examples": "<input>A</input><output>Yes</output>",
            "difficulty": 0,
            "ioScore": 100,
            "codeShare": true,
            "hint": "$ 数据范围: \\n 65 \\leq ASCII \\leq 90 $"
        },
        "judgeMode": "default",
        "samples": [
            {
                "input": "1.in",
                "output": "1.out",
                "score": 50
            },
            {
                "input": "2.in",
                "output": "2.out",
                "score": 20
            },
            {
                "input": "3.in",
                "output": "3.out",
                "score": 10
            },
            {
                "input": "4.in",
                "output": "4.out",
                "score": 10
            },
            {
                "input": "5.in",
                "output": "5.out",
                "score": 10
            }
        ],
        "tags": [
            "河工C语言上机题库A"
        ],
        "codeTemplates": []
    },
    "testDataFileUse": {
        "data1": "正常测试数据，输入大写字母，如'A'到'Z'，生成多个测试数据，并生成对应的输出",
        "data2": "测试程序兼容性，输入非大写字母，如小写字母或数字，生成多个测试数据，生成对应的输出",
        "data3": "测试程序精度，输入特殊字符，如'@'或'#'，生成多个测试数据，生成对应的输出",
        "data4": "测试程序边界，输入边界值，如'A'，'Z'，生成多个测试数据，生成对应的输出",
        "data5": "测试程序健壮性，输入接近ASCII码边界的大写字母，如'Z'，生成多个测试数据，生成对应的输出"
    }
}'''
json_1=json_1.encode('utf-8')
res_json=json.loads(json_1)