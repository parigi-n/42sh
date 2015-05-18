#!/bin/bash

ulimit -c 0

export PATH="/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/bin:/usr/heimdal/sbin:/home/parigi_n/bin"

export EDITOR='emacs'
export HISTSIZE=1000
export MAIL="/u/all/${USER}/mail/${USER}"
export PAGER='less'
export PS1="\[\e[01;32m\][\u] \w > \[\e[0m\]"
export SAVEHIST=1000
export WATCH='all'

alias ls='ls --color=auto'
alias ll='ls -l'
alias la='ls -la'
alias j='jobs'
alias emacs='emacs -nw'
alias ne='emacs'
alias xlock='xscreensaver-command -lock'
alias mr_clean='~/script/mr_clean.sh'
alias create_repo='~/script/create_repo.sh'
alias unfoo='unfoo'
alias azerty='setxkbmap fr'
alias qwerty='setxkbmap us'
alias ns_auth='~/script/ns_auth.py'
if [ -f ${HOME}/.mybashrc ]
then
    . ${HOME}/.mybashrc
fi
export PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/bin:/usr/heimdal/sbin:/home/parigi_n/bin:/home/parigi_n/bin
