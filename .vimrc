" 显示行号
set nu
" 显示标尺
set ruler
" 输入的命令显示出来，看的清楚些
set showcmd
" 允许折叠
set foldenable
" 手动折叠
set foldmethod=manual
"去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限
set nocompatible
" 设置当文件被改动时自动载入
set autoread
" quickfix模式
autocmd FileType c,cpp map <buffer> <leader><space> :w<cr>:make<cr>
"代码补全
set completeopt=preview,menu
"允许插件
filetype plugin on
"共享剪贴板
set clipboard+=unnamed
" 语法高亮
set syntax=on
" 在处理未保存或只读文件的时候，弹出确认
set confirm
" 自动缩进
set autoindent
set cindent
" Tab键的宽度
set tabstop=4
" 统一缩进为4
set softtabstop=4
set shiftwidth=4
" 不要用空格代替制表符
set noexpandtab
" 在行和段开始处使用制表符
set smarttab
" 显示行号
" 侦测文件类型
filetype on
" 载入文件类型插件
filetype plugin on
" 为特定文件类型载入相关缩进文件
filetype indent on
" 保存全局变量
set viminfo+=!
" 带有如下符号的单词不要被换行分割
set iskeyword+=_,$,@,%,#,-
"打开文件类型检测, 加了这句才可以用智能补全
set completeopt=longest,menu
"默认打开Taglist
let Tlist_Auto_Open=1

" 设置配色
colo desert
" 设置字体和大小
set guifont=Menlo-Regular:h16
" 设置窗口大小
set lines=36 columns=62


" 显示中文帮助
if version >= 603
	set helplang=cn
	set encoding=utf-8
endif



"""""""""""""""""""""""""""""""""""""
"""""新文件标题""""""""""""""""""""""
"新建.c,.h,.sh,.java文件，自动插入文件头
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()"
""定义函数SetTitle，自动插入文件头
func SetTitle()
	"如果文件类型为.sh文件
	if &filetype == 'sh'
		call setline(1,"\#####################################")
		call append(line("."), "\# File Name: ".expand("%"))
		call append(line(".")+1, "\# Author: duny31030(https://duny31030.top/)")
		call append(line(".")+2, "\# mail: duny31030@126.com")
		call append(line(".")+3, "\# Created Time: ".strftime("%c"))
		call append(line(".")+4, "\######################################")
		call append(line(".")+5, "\#!/bin/bash")
		call append(line(".")+6, "")
	else
		call setline(1, "/*")
		call append(line("."), " *==================================")
		call append(line(".")+1, " *                              ")
		call append(line(".")+2, " *  > File Name: ".expand("%"))
		call append(line(".")+3, " *  > Author: duny31030")
		call append(line(".")+4, " *  > Mail: duny31030@126.com ")
		call append(line(".")+5, " *  > Created Time: ".strftime("%c"))
		call append(line(".")+6, " *  > Link:")
		call append(line(".")+7, " *                              ")
		call append(line(".")+8, " *==================================")
		call append(line(".")+9, " */")
	endif
	if &filetype == 'cpp'
		call append(line(".")+10, "     ")
		call append(line(".")+11, "#include<iostream>")
		call append(line(".")+12, "using namespace std;")
		call append(line(".")+13, "#define clr(a, x) memset(a, x, sizeof(a))")
		call append(line(".")+14, "#define rep(i,a,n) for(int i=a;i<=n;i++)")
		call append(line(".")+15, "#define pre(i,a,n) for(int i=n;i>=a;i--)")
		call append(line(".")+16, "#define ll long long")
		call append(line(".")+17, "#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);")

		call append(line(".")+18, "const double eps = 1e-6;")
		call append(line(".")+19, "const int INF = 0x3f3f3f3f;")
		call append(line(".")+20, "const int mod = 1e9 + 7;")
		call append(line(".")+21, " ")
		call append(line(".")+22, " ")

		call append(line(".")+23, "int main()")
		call append(line(".")+24, "{     ")
		call append(line(".")+25, "    ios")
		call append(line(".")+26, "#ifdef ONLINE_JUDGE")
		call append(line(".")+27, "#else")
		call append(line(".")+28, "    freopen(\"in.txt\",\"r\",stdin);")
		call append(line(".")+29, "    //freopen(\"out.txt\",\"w\",stdout); ")
		call append(line(".")+30, "#endif")
		call append(line(".")+31, "    ")
		call append(line(".")+32, "    ")
		call append(line(".")+33, "    fclose(stdin);")
		call append(line(".")+34, "    //fclose(stdout);")
		call append(line(".")+35, "    return 0;")
		call append(line(".")+36, "}     ")


	endif
	if &filetype == 'c'
		call append(line(".")+13, "#include<stdio.h>")
		call append(line(".")+7, "")
	endif
	"新建文件后，自动定位到文件末尾
	autocmd BufNewFile * normal G
endfunc


"列出当前目录文件
" map <F3> :tabnew .<CR>
map <F3> :NERDTree .<CR>
"打开树状文件目录
map <C-F3> \be


"C，C++ 按F5编译运行
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
	exec "w"
	if &filetype == 'c'
		exec "!g++ % -o %<"
		exec "! ./%<"
	elseif &filetype == 'cpp'
		exec "!g++ % -o %<"
		exec "! ./%<"
	elseif &filetype == 'java'
		exec "!javac %"
		exec "!java %<"
	elseif &filetype == 'sh'
		:!./%
	endif
endfunc

"C,C++的调试
map <F8> :call Rungdb()<CR>

func! Rungdb()
	exec "w"
	exec "!g++ % -g -o %<"
	exec "!gdb ./%<"
endfunc

""""""""""""""""
" 设置运行路径
set rtp+=~/.vim/bundle/Vundle.vim
" 调用vundle的安装脚本
call vundle#begin()
" 让vundle管理vundle
Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/nerdtree'

""Bundle 'OmniCppComplete'
" " ctrlp搜索插件
Bundle 'ctrlpvim/ctrlp.vim'
let g:ctrlp_map = '<c-p>'
let g:ctrlp_cmd = 'CtrlP'
" " 加强状态栏
Plugin 'bling/vim-airline'
" "代码补全
Bundle 'Shougo/neocomplcache'
let g:neocomplcache_enable_at_startup = 1

" " 自动格式化
Plugin 'Chiel92/vim-autoformat'
noremap <F2> :Autoformat<CR>
let g:autoformat_autoindent = 1
let g:autoformat_retab = 1
let g:autoformat_remove_trailing_spaces = 1

call vundle#end()

