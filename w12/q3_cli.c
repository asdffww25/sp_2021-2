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
	if((msgid = msgget(key, 0)) < 0){
		perror("msgget");
		exit(1);
	}
	while(1){
		len = msgrcv(msgid,&inmsg, 80, 0, 0);
		printf("Received Msg = %s, Len=%d\n", inmsg.mtext, len);
		memset(buf, '\0', BUFSIZ);
        fgets(buf, BUFSIZ, stdin);
        mesg.mtype = 1;
        strcpy(mesg.mtext, buf);
        if(msgsnd(msgid, (void *)&mesg, 80, IPC_NOWAIT) == -1){
            perror("msgsnd");
            exit(1);
        }

	}
	return 0;
}
