echo "要查找文件吗？"
echo "请输入要查找的文件（别用中文）"
read filename
find ./ -name *$filename*

