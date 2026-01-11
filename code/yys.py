import subprocess
import os

# 执行命令并获取输出
result = subprocess.run(['python3', '--version'], capture_output=True, text=True)
print(result.stdout)

# 实时输出
subprocess.run(['python3', '--version'], check=True)
