/*
Running Program:
First start the server then client can be connected...
 
Server:
-> gcc server.c -o server
->./server [port no.]
 
port number for client and server should be same.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(int argc,char *argv[])
{
	
	struct sockaddr_in serv_addr,cli_addr;
	
	if(argc < 2){
	
		fprintf(stderr,"Port no not given");
		exit(1);
		
	}
	  
	int sockfd,newsockfd,portno,clilen,n,nRet=0;   //File descriptor for Sockets
	char buffer[256];                       //Temporary buffer to read and write data
	// creating socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
    {
        printf("The socket not opened\n");
        exit(1);
    }
    else
    {
        printf("The socket opened successfully\n");
    }
	
	bzero((char *) &serv_addr,sizeof(serv_addr));
	
	portno = atoi(argv[1]);
	
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(portno);
	serv_addr.sin_addr.s_addr=INADDR_ANY;
    /*Binding the socket*/
	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0 ){
		printf("Error, Binding Failed");
	
	}
	 else
    {
        printf("Successfully bind to local port\n");
    }
	
    /*Listening to new_file Connections*/
	nRet=listen(sockfd,1);
	
    if(nRet<0)
    {
        printf("Error! Fail to start listen to local port\n");
        exit(1);
    }
    else
    {
        printf("Started listening to local port\n");
    }
	clilen = sizeof(cli_addr);
    /*Accept the new_file connection*/
	newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen);
	
	if(newsockfd < 0){
	
		printf("Error accepting");
	}
	
	
	FILE *fp;
	
	while(1){
		char com[10];
		bzero(buffer,256);
		n = read(newsockfd,buffer,255);
		sscanf(buffer,"%s",com);
		
		if(strcmp("NLINEX",com) == 0){
		
			fp = fopen("server_file.txt","r+");
	
			if(fp == NULL)
				printf("File error");
			int counter = 0;
			for(char c= getc(fp);c!=EOF;c=getc(fp)){
				if(c == '\n'){
					counter++;
				}
			}
			counter++;
			fclose(fp);
			printf("%d",counter);
			bzero(buffer,256);
			sprintf(buffer,"%d",counter);
			n = write(newsockfd,buffer,strlen(buffer));
			
			
		}else if(strcmp("READX",com) == 0){
			
			int line_no,val_flag=0;
			char lin[10];
			char value[10];
		
			sscanf(buffer,"%s %s",lin,value);
			
			if(strlen(value) == 0){
				val_flag=1;
			}else{
			for(int i =0;i<strlen(value);i++){
				if(value[i]>='0' && value[i]<='9'){
					continue;
				}else if(i==0 && value[i]=='-'){
					continue;
				}else{
					val_flag=2;
					break;
				}
			}
			}
		
			if(val_flag == 0){
			
				line_no = atoi(value);
				
					fp = fopen("server_file.txt","r");
	
					if(fp == NULL)
						printf("File error");
					
					int totaline = 0;
					for(char c= getc(fp);c!=EOF;c=getc(fp)){
						if(c == '\n'){
							totaline++;
						}
					}
					totaline++;
					fseek(fp,0,SEEK_SET);
					
				if(line_no >= totaline || ((line_no*-1) > totaline)){
					
						bzero(buffer,256);
						fclose(fp);
						lin[0]='\0';
						value[0]='\0';
						sprintf(buffer,"%s","Invalid Index");
						n = write(newsockfd,buffer,strlen(buffer));
					
						
				}else if(line_no < 0){ // reverse indexing
					
					int linetoskip = totaline + line_no;
					
					fp = fopen("server_file.txt","r");
	
					if(fp == NULL)
						printf("File error");
					
					for(char c= getc(fp);c!=EOF;c=getc(fp)){
						if(c == '\n'){
							linetoskip--;
						}
						if(linetoskip == 0){
							break;
						}
					}
					
					bzero(buffer,256);
					lin[0]='\0';
					value[0]='\0';
					fscanf(fp,"%[^\n]",buffer);
					fclose(fp);
					n = write(newsockfd,buffer,strlen(buffer));
					
				
				}else {	// forward indexing
				
					fp = fopen("server_file.txt","r");
	
					if(fp == NULL)
						printf("file error");
					if(line_no == 0){
						
						bzero(buffer,256);
						lin[0]='\0';
						value[0]='\0';
						fscanf(fp,"%[^\n]",buffer);
						fclose(fp);
						n = write(newsockfd,buffer,strlen(buffer));
					
					}else{
						int counter = line_no;
						for(char c= getc(fp);c!=EOF;c=getc(fp)){
							if(c == '\n'){
								counter--;
							}
							if(counter == 0){
								break;
							}
						}
						
						bzero(buffer,256);
						lin[0]='\0';
						value[0]='\0';
						fscanf(fp,"%[^\n]",buffer);
						fclose(fp);
						n = write(newsockfd,buffer,strlen(buffer));
					}
				
				}
				
			}else if(val_flag == 1){
			
				fp = fopen("server_file.txt","r");
	
				if(fp == NULL)
					printf("file error");
					
				
				bzero(buffer,256);
				lin[0]='\0';
				value[0]='\0';
				fscanf(fp,"%[^\n]",buffer);
				fclose(fp);
				n = write(newsockfd,buffer,strlen(buffer));
			
			}else{
			
			
				bzero(buffer,256);
				lin[0]='\0';
				value[0]='\0';
				sprintf(buffer,"%s","Error! Format not match");
				n = write(newsockfd,buffer,strlen(buffer));
			
			}
			
		
		}else if(strcmp("INSERTX",com) == 0){
		
			int line_no,val_flag=0;
			char lin[10];
			char value[10],msg[1024];
		
			int n1 = sscanf(buffer,"%s %s %s",lin,value,msg);
			
			if(n1==1){
			
				bzero(buffer,256);
				lin[0]='\0';
				value[0]='\0';
				msg[0]='\0';
				sprintf(buffer,"%s","incorrect format");
				n = write(newsockfd,buffer,strlen(buffer));
				
			}else if(n1==2){
			
				fp = fopen("server_file.txt","a");
	
				if(fp == NULL)
					printf("File error");
					
				fseek(fp,0,SEEK_END);
				fputs("\n",fp);
				fputs(value,fp);
				bzero(buffer,256);
				lin[0]='\0';
				value[0]='\0';
				msg[0]='\0';
				sprintf(buffer,"%s","Successful");
				fclose(fp);
				n = write(newsockfd,buffer,strlen(buffer));
			}else{
				
				for(int i =0;i<strlen(value);i++){
					if(value[i]>='0' && value[i]<='9'){
						continue;
					}else if(i==0 && value[i]=='-'){
						continue;
					}else{
						val_flag=2;
						break;
					}
				}
				
				
				if(val_flag == 0){
			
					line_no = atoi(value);
				
					fp = fopen("server_file.txt","r");
	
					if(fp == NULL)
						printf("file error");
					
					int totaline = 0;
					for(char c= getc(fp);c!=EOF;c=getc(fp)){
						if(c == '\n'){
							totaline++;
						}
					}
					totaline++;
					fseek(fp,0,SEEK_SET);
					
					if(line_no >= totaline || ((line_no*-1) > totaline)){
						
							bzero(buffer,256);
							fclose(fp);
							lin[0]='\0';
							value[0]='\0';
							msg[0]='\0';
							sprintf(buffer,"%s","Invalid Index");
							n = write(newsockfd,buffer,strlen(buffer));
						
							
					}else if(line_no < 0){ // reverse indexing
						
						int linetoskip = totaline + line_no;
						
						fp = fopen("server_file.txt","r+");
		
						if(fp == NULL)
							printf("file error");
							
						char line[500];
						FILE* new_file = tmpfile();
						
						while(fgets(line,sizeof(line),fp)){
							
							if(linetoskip ==0){
								
								fputs(msg,new_file);
								fputs("\n",new_file);
								linetoskip--;
								continue;
							
							}
							fputs(line,new_file);
							line[0]='\0';
							linetoskip--;
						}
						
						rewind(new_file);
						fseek(fp,0,SEEK_SET);
						
						
						while(fgets(line,sizeof(line),new_file)){
							fputs(line,fp);
							line[0]='\0';
						}
						
						bzero(buffer,256);
						lin[0]='\0';
						value[0]='\0';
						msg[0]='\0';
						sprintf(buffer,"%s","Successful - new_file");
						fclose(fp);
						fclose(new_file);
						n = write(newsockfd,buffer,strlen(buffer));
						
						
					
					}else {	// forward indexing
					
						fp = fopen("server_file.txt","r+");
		
						if(fp == NULL)
							printf("file error");
							
						if(line_no == 0){
							
							char line[500];
							FILE* new_file = tmpfile();
							printf("%s",msg);
							fputs(msg,new_file);
							fputs("\n",new_file);
							
							while(fgets(line,sizeof(line),fp)){
								fputs(line,new_file);
								line[0]='\0';
							}
							
							rewind(new_file);
							fseek(fp,0,SEEK_SET);
							
							
							while(fgets(line,sizeof(line),new_file)){
								fputs(line,fp);
								line[0]='\0';
							}
							
							bzero(buffer,256);
							lin[0]='\0';
							value[0]='\0';
							msg[0]='\0';
							sprintf(buffer,"%s","Successful");
							fclose(fp);
							fclose(new_file);
							n = write(newsockfd,buffer,strlen(buffer));
					
						}else{
							
							char line[500];
							FILE* new_file = tmpfile();
							
							int counter = 0;
							while(fgets(line,sizeof(line),fp)){
								fputs(line,new_file);
								line[0]='\0';
								counter++;
								if(counter == line_no){
									
									fputs(msg,new_file);
									fputs("\n",new_file);
								
								}
							}
							
							rewind(new_file);
							fseek(fp,0,SEEK_SET);
							
							
							while(fgets(line,sizeof(line),new_file)){
								fputs(line,fp);
								line[0]='\0';
							}
							
							bzero(buffer,256);
							lin[0]='\0';
							value[0]='\0';
							msg[0]='\0';
							sprintf(buffer,"%s","Successful - new_file");
							fclose(fp);
							fclose(new_file);
							n = write(newsockfd,buffer,strlen(buffer));
						}
				
				}
				
				}else{
				
				
					bzero(buffer,256);
					lin[0]='\0';
					value[0]='\0';
					msg[0]='\0';
					sprintf(buffer,"%s","Format Error");
					n = write(newsockfd,buffer,strlen(buffer));
				
				}
				
				
			}	
			
				
		}else{
		
			bzero(buffer,256);
			sprintf(buffer,"%s","Please give correct");
			n = write(newsockfd,buffer,strlen(buffer));
		}
		
		int i = strncmp("Bye", buffer,3);
		if(i==0)
		break;
		
	}
	
	close(sockfd);
	close(newsockfd);
	return 0;
	
}

