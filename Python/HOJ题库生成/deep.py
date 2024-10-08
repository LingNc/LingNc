import os
from openai import OpenAI

# for backward compatibility, you can still use `https://api.deepseek.com/v1` as `base_url`.
client = OpenAI(api_key="sk-9011b751ed194e12bc0876ed3256f172", base_url="https://api.deepseek.com")

# 问题列表
questions = [
    "1．编写程序,程序运行时输出以下图形。（20分）\n****\n****\n  ****\n   ****",
    "2．已知圆的半径r=3.1，编程求圆的周长和面积，并输出结果（保留两位小数）。（20分）",
    "3．编写程序，从键盘上输入一个正整数n，判断其是奇数还是偶数，并输出结果。（20分）",
    "4．编写程序,用for循环求1+2+3+…+100的值并输出。（20分）",
    "5．编写程序，找出300~400之间所有不能被5和7同时整除的数并输出。（20分）",
    "6．假如我国国民生产总值的年增长率为7%，计算10年后我国国民生产总值与现在相比增长多少百分比，计算公式p=（1+r）n，其中r为年增长率，n为年数，p为与现在相比的倍数。（保留两位小数）。（20分）",
    "7．编写程序，从键盘上输入两个正整数m和n，找到二者中的较大数并输出。（20分）",
    "8．编写程序,用do…while循环求1+2+3+…+50的值并输出。（20分）",
    "9．编写程序，求Fibonacci(斐波那契)数列的前20个数。（20分）\nFibonacci数列有如下特点:第1，2两个数为1，1。从第3个数开始，该数是其前面两个数之和。即该数列为1,1,2,3,5,8,13,…,用数学方式表示为:\nF(1)=1,F(2)=1,F(n)=F(n-1)+F(n-2)(n>=3)",
    "10．编写程序，求1~1000之间除以3余1、除以5余2并且除以7余3的所有整数，并输出。（20分）",
    "11．计算存款利息。有1000元，想存一年。有3种方法可选:(1)活期，年利率为r1=0.0036；(2)一年期定期，年利率为r2=0.0225；(3)存两次半年定期，年利率为r3=0.0198。请分别计算出一年后按这3种不同方法所得到的本息和。（20分）",
    "12．编写程序，从键盘上输入一个正整数n，判断其能否被3整除，并输出结果。（20分）",
    "13．有一个函数：\n      x         (x<1)\ny=    2x-1      (1≤x<10)\n3x-11     (x≥10)\n编写程序，输入x的值，输出y相应的值。（20分）",
    "14．编写程序,用while循环求1+2+3+…+20的值，并输出。（20分）",
    "15．编写程序，求100～200之间各位数字之和为6的所有整数，并输出结果。（20分）",
    "16．编写程序，在屏幕上输出一行文字：“Hello World！”。（20分）",
    "17．求方程ax2+bx+c=0的根。a,b,c由键盘输入，设b2-4ac＞0且a≠0。（20分）",
    "18．编写程序，输入一个字符，判别它是否为大写字母，并输出结果。（‘A’对应的ASCII码为65）（20分）",
    "19．编程从键盘输入两个正整数，计算并输出这两个数的最大公约数。（20分）",
    "20．编写程序，输出200~300之间所有能被3整除但不能被5整除的所有整数。（20分）",
    "21．编写程序，输入一个三位正整数，求该数各位数字之和并输出。（20分）",
    "22．编写程序，输出100以内所有8的倍数，要求输出时每4个占一行。（20分）",
    "23．已知圆柱体底面半径r=3，高h=10，编程求其表面积和体积，并输出结果（保留两位小数）。（20分）",
    "24．编写程序，从键盘输入一个不长于10个字符的字符串，将其中的小写字母转换成大写字符，其他字符保持不变，并输出转换后的结果。（20分）",
    "25．编程程序，计算1+4+7+10+13+…+112的值并输出。（20分）",
    "26．编写程序，求边长为5的正方形的周长和面积，并输出结果。（20分）",
    "27．编写程序，输入两个数，按由大到小的顺序输出这两个数。（20分）",
    "28．编写程序，输出以下4×5的矩阵。（20分）\n1	2	3	4	5\n2	4	6	8	10\n3	6	9	12	15\n4	8	12	16	20",
    "29．编写程序，任意输入10个整数，找出其中最大的数并输出。（20分）",
    "30．编写程序，找到并输出200到300之间所有满足如下条件的数：个位数、十位数和百位数之积等于42，同时这三个数之和等于12。（20分）",
    "31．编写程序，输入梯形的上底，下底和高，求其面积并输出（保留两位小数）。（20分）",
    "32．编写程序，输入一个百分制成绩，要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。90~100分为‘A’，80~89分为‘B’、70~79分为‘C’、60~69分为‘D’、60分以下为‘E’。（20分）",
    "33．编写程序，从键盘上输入一个年份，判断其是否为闰年。（20分）\n（说明：凡能被4整除但不能被100整除，或能被400整除的年份为闰年。）",
    "34．编写程序，从键盘输入10个数，去掉其中最大值和最小值，求其余8个数的平均数，并输出。（20分）",
    "35．编写程序，求1~1000之间能同时被3,5,7整除的数，按每行4个数的格式输出结果。（20分）",
    "36．编写程序，把560分钟换算成用小时和分钟表示(如70分钟换算之后为1小时10分钟)，并输出结果。（20分）",
    "37．编写程序，输入一个三位正整数，求该数各位数字之和并输出。（20分）",
    "38．编写程序，输入一个正整数，判断其是否能被5和7同时整除，并输出结果。（20分）",
    "39. 编写程序，求1-1/2+1/3-1/4+…+1/99-1/100的值并输出，小数点后保留四位数字。（20分）",
    "40．编写程序，找到并输出100~999之间的水仙花数。所谓水仙花数是指这样的三位正整数，其各位数字的立方和等于该数本身。如：153=1*1*1+5*5*5+3*3*3。（20分）"
    "41．编写程序，求88除以7的余数并输出。（20分）",
    "42．编写程序，输入一个小写字母，将其转换为对应的大写字母并输出。（20分）",
    "43. 编写程序，输入一个大于或等于3的整数，判别它是否为素数。（20分）",
    "44．编写程序，输出500~600之间所有的偶数。（20分）",
    "45．编写程序，从键盘输入8个数到整型数组中，然后从小到大排序，并输出。（20分）",
    "46．编写程序，用355.0除以113.0求圆周率的近似值并输出，小数点后保留五位数字。（20分）",
    "47．有一阶跃函数：\ny={█(-1     (x<0)@0        (x=0)@1       (x>0))┤\n编写程序，输入一个x值，要求输出y相应的值。（20分）",
    "48．编写程序，输出100～200之间所有的奇数。（20分）",
    "49．编写程序，从键盘输入两个正整数，计算并输出这两个数的最小公倍数。（20分）",
    "50．编写程序，从键盘上输入10个整数存入一维数组a中，求出它们的最大值并输出。（20分）",
    "51．编写程序，从键盘输入一个英文字母，将该字母对应的ASCII码输出。（20分）",
    "52．某景区每张门票零售价格为25元，团体票价为20元，一次购票数目超过30张（含30张）时按团体票出售。编程从键盘输入购票数目，求出所需购票款的数额，并输出。（20分）",
    "53．编写程序,求1/2-2/3+3/4-4/5⋯-98/99+99/100的值并输出，小数点后保留四位数字。（20分）",
    "54．编写程序，从键盘输入一个字符串，统计并输出该字符串中字符的个数。（20分）",
    "55．编写程序，从键盘输入10个整数，计算这10个整数之和，并输出（要求用数组实现）。（20分）",
    "56．编写程序，运行时输出以下图形。（20分）\n#\n###\n#####",
    "57．编写程序，从键盘输入两个浮点型数据，计算这两个数的和、差、积、商，并输出结果（保留两位小数）。（20分）",
    "58. 编写程序，输入一个不多于5位的正整数,倒序输出它的各位数字。（20分）",
    "59．编写程序，从键盘输入一个正整数n，求n！并输出（设输入的数n满足：n≤15）。（20分）",
    "60．编写程序，定义一个包含10个元素的一维数组，从键盘对其初始化，计算该数组所有下标为偶数的元素之和，并输出结果。（20分）",
    "61．编写程序，输入两个整数,求它们的平方和并输出。（20分）",
    "62．有分段函数如下，编写程序，输入自变量x的值，求y相应的值并输出。（20分）\n      18      (x>0)\ny=    0       (x=0)\n-10     (x<0)",
    "63. 编写程序，要求从用户输入的三个整数中找到最大值，并将该最大值输出。（20分）",
    "64．编写程序，从键盘上输入10个整数存入一维数组a中，逆序输出数组a中的元素。（20分）",
    "65．编程输出公历1949~2019年之间的所有闰年年份。（20分）\n（说明：凡能被4整除但不能被100整除，或能被400整除的年份为闰年。）",
    "66．编写程序，把华氏法表示的温度(如64°F），转换为以摄氏法表示的温度(如17.8℃)（提示：转换公式为c=5/9(f−32)，其中，f代表华氏温度，c代表摄氏温度）。（20分）",
    "67．编写程序，从键盘输入三个整数x,y,z，把这三个数由大到小输出。（20分）",
    "68．编写程序，输入一个月份，求解并输出这个月有几天？（不考虑闰年情况）（20分）",
    "69．编程程序，求600~800之间所有奇数的和并输出。（20分）",
    "70．编写程序，从键盘输入10个数，去掉一个最大值，求其余9个数的平均数，并输出。（20分）",
    "71．编写程序，任意输入三个正整数，计算并输出它们的和及平均数。（20分）",
    "72．编写程序，求一年有多少分钟并输出结果（不考虑闰年情况）。（20分）",
    "73．编写程序，从键盘输入两个字符串，将这两个字符串连接成一个字符串输出。（20分）",
    "74．在全系1000名学生中举行慈善募捐，当总数达到2万元时就结束，统计此时捐款的人数以及平均每人捐款的数目。（20分）",
    "75．编写程序，输出100~200之间的所有素数。（说明：素数指除了1和其本身，没有其他数能够将其整除）。（20分）"
]

base_question = '''你好，你是一个非常棒的程序员，现在你正在编写一个程序，用来把一个问题转化为一种fps格式，要求你自己写入测试数据样例还有正确答案等，请你按照如下格式输出：
<item>
<title><![CDATA[题目标题]]></title>
<time_limit unit="s"><![CDATA[1]]></time_limit>
<memory_limit unit="mb"><![CDATA[128]]></memory_limit>

<description><![CDATA[题目描述]]></description>
<input><![CDATA[输入描述]]></input>
<output><![CDATA[输出描述]]></output>
<sample_input><![CDATA[样例输入（换行来表示多个输入）]]></sample_input>
<sample_output><![CDATA[样例输出（换行来表示多个输出）]]></sample_output>
<test_input><![CDATA[测试输入数据集（换行来表示多个输入）]]></test_input>
<test_output><![CDATA[测试输出数据集（换行来表示多个输出）]]></test_output>
<hint><![CDATA[提示]]></hint>
<source><![CDATA[C程序设计A-机试题库]]></source>
		<solution language="C"><![CDATA[C语言正确答案
]]></solution>

例如：{
问题：68．编写程序，输入一个月份，求解并输出这个月有几天？（不考虑闰年情况）（20分）

<item> <title><![CDATA[月份天数计算（不考虑闰年）]]></title> <time_limit unit="s"><![CDATA[1]]></time_limit> <memory_limit unit="mb"><![CDATA[128]]></memory_limit>
<description><![CDATA[编写一个程序，接收一个表示月份的整数（1到12），输出这个月份的天数。不考虑闰年，每个月的天数如下： 1月: 31天 2月: 28天 3月: 31天 4月: 30天 5月: 31天 6月: 30天 7月: 31天 8月: 31天 9月: 30天 10月: 31天 11月: 30天 12月: 31天 ]]></description>
<input><![CDATA[一个整数，表示月份（1-12）]]></input>
<output><![CDATA[输出该月份的天数，一个整数。]]></output>
<sample_input><![CDATA[3(样例只需要选答案中的一个就可以)]]></sample_input>
<sample_output><![CDATA[31]]></sample_output>
<test_input><![CDATA[1
2
3
4
5
6
7
8
9
10
11
12]]></test_input>
<test_output><![CDATA[31
28
31
30
31
30
31
31
30
31
30
31]]></test_output>
<hint><![CDATA[]]></hint>
<source><![CDATA[C程序设计A-机试题库]]></source>
<solution language="C"><![CDATA[
#include<stdio.h>

int main() {
int month;
while(scanf("%d", &month) == 1) {
if(month >= 1 && month <= 12)
printf("%d\n", (month == 2) ? 28 : (month % 2 == 0 && month != 2) ? 30 : 31);
else
printf("Invalid input!\n");
}
return 0;
}
]]></solution>
</item>}

接下来我给你一个问题，在你输出的xml格式中CDATA[]中可以用数学公式等md语法,为了美观简洁请你把问题中的描述含有数学的转化为md格式让方便看懂，比如矩阵，分数等，并且sample输出是展示的，test输出是判题的，请你不用了把test输出为空，保证一定有结果，最好需要10组以上的测试点，如果答案唯一就有限个就可以，并覆盖数据范围到边界，并且覆盖完全数据范围，如果test和sample的数据相同，请你依然把test的属数据写上和sample相同，不要说一样即可，谢谢谢谢，提示可以写也可以不写简单题不需要写，请你按照上述要求并输出在代码块中保证换行缩进正确给我相应的输出，谢谢。
问题：
'''
# 定义生成XML的函数
def generate_xml(answer):
    answer = answer[6:-3]
    return answer

# 处理每个问题并生成XML
with open("out.xml", "w") as file:
    # 初始化out.xml
    file.write('''<?xml version='1.0' encoding='utf-8'?>
<fps version="1.2" url="https://github.com/zhblue/freeproblemset/" />
<generator name="HUSTOJ" url="https://github.com/zhblue/hustoj/"/>''')
    
    for question in questions:
        # 使用OpenAI API获取答案
        response = client.chat.completions.create(
            model="deepseek-chat",
            messages=[
                {"role": "system", "content": "You are a helpful assistant"},
                {"role": "user", "content": base_question + question},
            ],
            max_tokens=4096,
            temperature=0.1,
            stream=False
        )
        answer = response.choices[0].message.content

        # 生成XML并写入文件
        xml_content = generate_xml(answer)
        file.write(xml_content)
        print(xml_content)


# 封闭xml文件结尾
file.write('''</fps>''')
print("XML文件已生成并保存为out.xml")