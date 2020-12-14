# kernel_crypto_ko_wsl
call kernel_crypto API by ko, testing on WSL2

# download wsl kernel code
You can download from here

    https://github.com/microsoft/WSL2-Linux-Kernel

# Install necessary tool
sudo apt install g++ make flex bison libssl-dev libelf-dev bc

ref:

    https://gist.github.com/cerebrate/d40c89d3fa89594e1b1538b2ce9d2720

# Before compile ko Compile the wsl first
make KCONFIG_CONFIG=Microsoft/config-wsl -j8

ref:

    https://microhobby.com.br/blog/2019/09/21/compiling-your-own-linux-kernel-for-windows-wsl2/

# Happy coding!

# Some error

warning: function declaration isn’t a prototype
change 
```c
static int __init hello_init()
//to
static int __init hello_init(void)
```

insmod: ERROR: could not insert module hello.ko: Invalid module format

ref:
    
    https://github.com/microsoft/WSL2-Linux-Kernel/issues/78

    https://github.com/microsoft/WSL2-Linux-Kernel/commit/ae801445ec80ef70b407b89c159ccb942bc58989

**Can not be solved**
```shell
uname -a
Linux DESKTOP-xxxxxx 4.19.104-microsoft-standard #1 SMP Wed Feb 19 06:37:35 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux
harold@DESKTOP-xxxxxx:~/wsl_kernel/WSL2-Linux-Kernel$ git branch --all
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/linux-msft-wsl-4.19.y
  remotes/origin/linux-msft-wsl-5.4.y
  remotes/origin/master
git checkout -t remotes/origin/linux-msft-wsl-4.19.y -b 4.19
git checkout ae801445ec80ef70b407b89c159ccb942bc58989
# Then compile the kernel and ko AGAIN
make KCONFIG_CONFIG=Microsoft/config-wsl -j8

```


# recording at 2020/12/11
As the reason of WSL can not support lsmod etc. I decide to use WSL as compile envoriment.
and test the out put on ResPi

# recording at 2020/12/13
After recompiling the WSL2 kernel, insmod is supported
ref:

    # for recompile wsl
    https://app.getpocket.com/read/3200196509
    # porject kernel log to shell
    https://blog.csdn.net/weixin_44395686/article/details/102551475

# recording at 2020/12/15
After modify
```shell
Dec 15 00:19:00 DESKTOP-C71FG7L kernel: [ 3260.024618] Harold reach end
Dec 15 00:24:15 DESKTOP-C71FG7L kernel: [ 3574.831773] short is the life of a kernel module!
Dec 15 00:24:15 DESKTOP-C71FG7L kernel: [ 3574.831773] short is the life of a kernel module!
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408078] hello, world - this is the kernel speaking!
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408079] Harold in KERNEL, START DUMP!
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408080] 78 00 78 01 78 02 78 03
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408080]  
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408081] 78 04 78 05 78 06 78 07
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408081]  
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408078] hello, world - this is the kernel speaking!
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408079] Harold in KERNEL, START DUMP!
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408080] 78 00 78 01 78 02 78 03
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408080]  
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408081] 78 04 78 05 78 06 78 07
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408081]  
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408081] 
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408081] Harold reach end
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408081] 
Dec 15 00:24:17 DESKTOP-C71FG7L kernel: [ 3577.408081] Harold reach end
```


TODO:

    - [x]  Why print TWICE!
  