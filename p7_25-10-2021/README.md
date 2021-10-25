# 7th Plenary session: 25.10.2021 #

In this plenary session we talked about the following topics:

* How to improve the workflow
* Home Exam 2

## Let's upgrade the workflow ##

Here are some tips and tricks how to improve your programming workflow.

* Workstation
  
  Whether you are using a laptop or desktop, make sure to use one with a good
  screen and keyboard. Even though I am stuck with a MacBook, I would definitely
  recommend Thinkpads and Dell XPS. They have great Linux-compatible hardwares.
  Anyways, stick to your budget! :-)

* Operating System
  
  Stay away of Windows! :-D

* Terminal
  
  If you like to live inside the terminal like me, you would avoid terminals
  which have a bad performance and slow rendering. Instead, make sure to choose
  a GPU-accelerated one which supports True (24-bit) or 256 colors.  
  I am a fan of Alacritty, which is a GPU-accelerated terminal emulator written
  in Rust. The scrolling is super fast, although the power consumtion is not the
  greatest. Since it is focused on simplicity and performance, Alacritty does
  not support windows and tabs. It relies on `tmux` or `screen` to enable these
  features.  
  [This](<https://arslan.io/2018/02/05/gpu-accelerated-terminal-alacritty/>) is
  a great post to configure and custommize Alacritty.  
  Other examples of highly custommizable terminals:

  * iterm2
  * kitty

* Shell

  
  Shell is the soul of the terminal. Without a shell, the terminal is just flesh
  and bones. Zsh is superseding bash and becoming the default shell for many
  Operating Systems. Oh My Zsh is an open source, community-driven framework for
  managing your Zsh configuration.  
  To install Oh My Zsh use the command below:

  ```sh
  sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
  ```
  Omz has a lot of plugins that will make your life easier. Check
  [here](<https://github.com/ohmyzsh/ohmyzsh/tree/master/plugins>) for a list of
  plugins. Personally, I use the following:  
  ```sh
  plugins=(git zsh-autosuggestions git-flow-completion fzf-tab cd-gitroot fast-syntax-highlighting)
  ```

* Aliases
  
  To avoid typing long commands, replace them with aliases.
  Zsh aliases are configured in the `.zshrc` file and they are loaded on the
  shell startup (`source .zshrc` when you add a new one, if you don't want to
  restart the terminal)
  ```sh
  alias in3230="ssh -Y debian@IP_of_your_vm"
  ```

* Zsh functions
  
  The golden rule of automation is: If you do something frequently, then you
  have to automate it. Since I use git a lot, I want to avoid wasting time with
  typing `git add . && git commit -m "small update" && git push` every time I
  want to push something in the reposiroty.  
  A Zsh function placed in `~/.zshenv` is perfect for these situations.
  ```sh
  function Git() {
    cd-gitroot
    git add .
    if [ "$1" != "" ]
    then
        git commit -m "$1"
        git push origin HEAD
    else
        git commit --amend --no-edit
        git push --force
    fi # closing statement of if-else block
  }
  ```

* bash | python scripts
  
  To push a change in your repo, pull it in the vm and test your code in
  mininet, you **MUST** use shell/python scripts. Doing this manually will waste
  you a lot of time, which you could have used by focusing on your code.
  Check [here](<https://github.com/kr1stj0n/plenaries-in3230-h21/blob/main/p7_25-10-2021/scripts/>)
  two examples of a shell and python script that you can import in your workflow.


* autojump
  
  [autojump](https://github.com/wting/autojump) is a faster way to navigate your
  filesystem. It works by maintaining a database of the directories you use the
  most from the command line.

  *Directories must be visited first before they can be jumped to.*


* Tmux
  
  [tmux](<https://github.com/tmux/tmux>) is a terminal multiplexer: it enables a
  number of terminals to be created, accessed, and controlled from a single
  screen. tmux is my daily driver. If you haven't checked it yet, please do it.
  Combined with the terminal, it can help you switched between your programming
  projects.  
  What I usually do is:  
  - One tmux session per project  
  - Inside a tmux session, I use several tmux windows (first window for Vimming
  the source code, another window to ssh to the server I am testing)
  - Two or mode panes inside a window if needed


* Editor
  
  I will not tell you which [one](<https://www.vim.org/>) is my favourite editor.
  Make sure to leverage some features like: autosuggestions, autocompletion,
  snippets, etc. from the editor you are using.

* Edit remote files
  
  This process should not be painful. The code in the vm needs to be synced with
  the main code in your computer. You have several options to seamlessly do
  this.  
  - automate git with Zsh functions as suggested above
  - sshfs (mount a remote directory as a volume in your computer)
  - configure your editor to edit files remotely via scp
