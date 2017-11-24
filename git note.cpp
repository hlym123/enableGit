/*****************************************************************************************

*****************************************************************************************/


1. git config user.name "Your name"
2. git config user.email "Your email address"



mkdir "directory"
cd "directory"

1. git init  	// 通过git init命令把这个目录变成Git可以管理的仓库
2. git add	 	// 用命令git add告诉Git，把文件添加到仓库
3. git commit  	// 用命令git commit告诉Git，把文件提交到仓库
4. git status
5. git diff "file name"



1. git reset --hard commit_id  // HEAD指向的版本就是当前版本，因此，Git允许我们在版本的历史之间穿梭




//===============================================
// 添加远程库
//===============================================

// 本地库与远程库关联
git remote add origin https://github.com/hlym123/enableGit.git

// 把本地库的内容推送到远程库上
git push -u origin master

