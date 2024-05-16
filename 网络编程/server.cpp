#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <thread>


int main()
{
    //1.创建监听的套接字
    int fd = socket(AF_INET,SOCK_STREAM,0);    
    if(fd == -1 ) 
    {
        perror("socket create failed"); 
        return -1; 
    }
    //2 绑定本地的ip port
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr = INADDR_ANY; //0 可以绑定任意ip地址
    int net = bind(fd,(struct sockaddr*)& saddr,sizeof(saddr));
    if(net == -1)
    {
        perror("bind");
        return -1;
    }
    //3 设置监听
    net = listen(fd,128);
    if(net == -1)
    {
        perror("listen");
        return -1;
    }
    //4 阻塞并等待客户端的连接
    struct sockaddr_in caddr;
    socklen_t caddrSize = sizeof(caddr);
    int cfd = accept(fd,(struct sockaddr*) &caddr,&caddrSize);
    if(cfd == -1)
    {
        perror("accept");
        return -1;
    }

    //连接成功 打印客户端IP和端口
    char ip[32];
    printf("客户端ip %s,端口 %d \n",inet_ntop(AF_INET,&caddr.sin_addr.s_addr,ip,sizeof(ip)), ntohs(caddr.sin_port));

    //通信
    while (1)
    {
        printf("进入到while\n");
        //接收数据
        char buff[1024];
        int len = recv(cfd,buff,sizeof(buff),0);
        if(len > 0)
        {
            printf("client say: %s\n",buff);
            send(cfd,buff,len,0);
        }
        else if(len == 0)
        {
            printf("客户端已经断开了连接 \n");
            break;
        }
        else
        {
            perror("recv");
            break;
        }
    }

    //关闭文件描述符
    close(fd);
    close(cfd);
    
    return 0;
}