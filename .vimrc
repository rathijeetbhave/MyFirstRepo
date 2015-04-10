"----------Vimscript File Settings--------{{{
augroup filetype_vim
	autocmd!
	autocmd FileType vim setlocal foldmethod=marker
augroup END
"}}}

"----------Disable LATEX plugin------------{{{
"let g:loaded_autoload_acp = 1
let g:latex_enabled = 0
"}}}

"------------Pathogen Settings-----------{{{
execute pathogen#infect()
 "   syntax on
    filetype plugin indent on
    filetype plugin on
"}}}

"--------------Set Map Leader------------{{{
let mapleader = "`"
"}}}
    
"-------------Some Vim Settings---------------{{{

syntax on
colorscheme solarized
set foldlevelstart=0
set ruler
set relativenumber
set number
set wildmenu
"set mouse=a"
set ignorecase
set smartcase
set gdefault
set incsearch
set showmatch
set hlsearch
set t_Co=256
set softtabstop=4
set autoindent
"set clipboard=unnamedplus"
set pastetoggle=<F2>
set clipboard=unnamed
"}}}

"------------Some Au Commands----------{{{
"Save when losing focus"
au FocusLost * :wa

"Resize splits when window is resized"
au VimResized * :wincmd =

"Make sure vim returns to same line on reopning"
augroup line_return
    au!
    au BufReadPost *
        \ if line("'\"") > 0 && line("'\"") <= line("$") |
        \ execute 'normal! g`"zvzz' |
        \ endif
augroup END
"}}}

"------------Syntastic settings----------------{{{
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
"}}}

"---------------Mappings--------------------{{{
nnoremap gO o<ESC>j
nnoremap j gj
nnoremap k gk
nnoremap <leader>ev :vsplit $MYVIMRC<cr>
nnoremap <leader>sv :source $MYVIMRC<cr>
inoremap jk <Esc>
nnoremap H ^
nnoremap L $
noremap <C-z> :w<cr>
inoremap <C-z> <ESC>:w<cr>
nnoremap vv :vsplit<cr>
nnoremap <Leader>n :NERDTreeToggle<cr> 
"}}}
