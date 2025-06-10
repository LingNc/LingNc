#!/bin/bash

cd "/home/lingnc/LingNc/Python/Python实验/实验2"

while true; do
    output=$(python 6_蒙特卡罗计算π.py)
    
    if echo "$output" | grep -q "3\.1415"; then
        echo "找到匹配结果！"
        echo "$output"
        break
    else
        echo "当前结果: $output (不匹配，继续尝试...)"
    fi
done
