#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "ops_db.h"
#include "ops_mq.h"
#include "ops_log.h"
#include "ops_task.h"

// ref https://github.com/troydhanson/network/blob/master/unixdomain/05.dgram/recv.c

/* signals that we'll accept via signalfd in epoll */
#if 0
static int sigs[] = {SIGHUP,SIGTERM,SIGINT,SIGQUIT,SIGALRM};
static int signal_fd = -1;
static void register_signal()
{
	/* block all signals. we take signals synchronously via signalfd */
	sigset_t all;
	sigfillset(&all);
	sigprocmask(SIG_SETMASK,&all,NULL);

	/* a few signals we'll accept via our signalfd */
	sigset_t sw;
	sigemptyset(&sw);
	for(n=0; n < sizeof(sigs)/sizeof(*sigs); n++)
		sigaddset(&sw, sigs[n]);

	signal_fd = signalfd(-1, &sw, 0);

}
#endif

#if 0
static uint16_t process_data(uint16_t req_data_len, uint8_t* req_data_ptr, uint8_t* res_data_ptr)
{
    return 1;
}
#endif

#define TASK_IOPCLAUNCHER                "iopclaunch"

int main(int argc, char** argv)
{
#if 0
    struct msg_t req;
    struct msg_t res;
    uint8_t group;
    uint8_t cmdno;
    uint8_t *req_data_ptr;
    uint8_t *res_data_ptr;
    uint16_t req_data_len = 0;
    uint16_t res_data_len = 0;
#endif
    struct ops_db_t* db = get_db_instance();
    struct ops_mq_t* mq = get_mq_instance();
    struct ops_log_t* log = get_log_instance();
    struct ops_task_t* task = get_task_instance();

#if 0
    register_signal();
#endif

    db->init();
    mq->init();
    log->init();
    task->init();

    for(;;) {
#if 0
        memset((uint8_t*)&req, 0, sizeof(struct msg_t));
        memset((uint8_t*)&res, 0, sizeof(struct msg_t));
	mq->get_from(TASK_IOPCLAUNCHER, &req);         
	memcpy(&res.hdr, &req.hdr, sizeof(struct msg_hdr_t));
	strcpy(res.hdr.src, req.hdr.dst);
	strcpy(res.hdr.dst, req.hdr.src);
        group = req.hdr.fn;
        cmdno = req.hdr.cmd;
	req_data_ptr = (uint8_t*)&req.data;
        res_data_ptr = (uint8_t*)&res.data;
	req_data_len = req.hdr.data_size;
        log->debug(0x01, "------------------------------------\n");
        log->debug(0x01, "get MsgQ[%x.%x]%d\n", group, cmdno, req_data_len);
	log->debug(0x01, "------------------------------------\n");
	res_data_len = process_data(req_data_len, req_data_ptr, res_data_ptr);
        res.hdr.data_size = res_data_len;
        res.hdr.fn = 0x80 | group;

        if(strcmp(res.hdr.dst, "") != 0) {
            mq->set_to(res.hdr.dst, &res);
        }
#endif
	sleep(1);
    }

    return 0;
}

