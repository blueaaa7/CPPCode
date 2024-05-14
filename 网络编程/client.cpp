#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    //1.创建通信的套接字
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
    inet_pton(AF_INET,"127.0.0.1",&saddr.sin_addr.s_addr); //172.20.10.2
    int net = connect(fd,(struct sockaddr*)& saddr,sizeof(saddr));
    if(net == -1)
    {
        perror("connect");
        return -1;
    }

int number = 0;
    //通信
    while (1)
    {
        printf("进入到while\n");
        //发送数据
        char buff[1024];
        snprintf(buff,sizeof(buff),"你好 %d\n",number++);
        send(fd,buff,strlen(buff)+1,0);
        
        //接收数据
        memset(buff,0,sizeof(buff));
        int len = recv(fd,buff,sizeof(buff),0);
        if(len > 0)
        {
            printf("server say: %s",buff);
        }
        else if(len == 0)
        {
            printf("服务端已经断开了连接 \n");
            break;
        }
        else
        {
            perror("recv");
            break;
        }
        sleep(1);
    }

    //关闭文件描述符
    close(fd);
    
    return 0;
}