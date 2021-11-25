#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct mymsgbuf {
	long mtype;
	char mtext[80];
};

int main(void){
	key_t key;
	int msgid, len;
	char buf[BUFSIZ] = {0,};
	struct mymsgbuf inmsg;
	struct mymsgbuf mesg;

	key = ftok("ketfile", 1);
	msgid = msgget(key, IPC_CREAT|0644);
	if(msgid == -1){
		perror("msgget");
		exit(1);
	}
	while(1){
			memset(buf, '\0', BUFSIZ);
			fgets(buf, BUFSIZ, stdin);
			mesg.mtype = 1;
			strcpy(mesg.mtext, buf);
			if(msgsnd(msgid, (void *)&mesg, 80, IPC_NOWAIT) == -1){
				perror("msgsnd");
				exit(1);
			}
			len = msgrcv(msgid,&inmsg, 80, 0, 0);
			printf("Received Msg = %s\n", inmsg.mtext);
			}
		
	return 0;
}
