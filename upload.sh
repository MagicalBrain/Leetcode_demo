#! /bin/bash
## author: HRL
## For upload my change to github remote repo.

git add *

echo "请输入commit备注信息"
read info
git commit -m $info

echo "本地仓库的分支名称为？"
read branch
git push origin $branch
