//
// Created by lazy on 2022/4/14.
// Copyright (c) lazy. (https://weibo.com/lazypeople)
//

#include "adns.h"
#include <sys/errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int test_dns(char *host) {
    adns_state ads;
    adns_initflags flags;
    flags = adns_if_nosigpipe | adns_if_noerrprint | adns_if_debug;

    adns_init_strcfg(&ads, flags, NULL, "nameserver 114.114.114.114");

    adns_query que = NULL;

    adns_submit(ads, host, (adns_rrtype) adns_r_txt, (adns_queryflags) 0, NULL, &que);

    int try_cnt = -1;

    while (try_cnt < 32) {
        try_cnt += 1;

        adns_answer *ans;
        int res = adns_check(ads, &que, &ans, NULL);
        if (res == 0) {
            if (ans->rrs.manyistr != NULL) {
                if ((*ans->rrs.manyistr)->i == 0)
                    printf("domain: %s txt record is empty\n", host);
                else
                    printf("domain: %s txt record is %s\n", host, (*ans->rrs.manyistr)->str);
                adns_finish(ads);
                break;
            } else {
                printf("domain: %s txt record is empty\n", host);
                adns_finish(ads);
                break;
            }
        } else if (res == ESRCH || res == EAGAIN) {
            sleep(1);
        } else {
            printf("host(%s) is err!\n", host);
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char host[128];
    while (1) {
        scanf("%s", host);
        if (strlen(host) == 3 && strcmp(host, "eof")) break;
        test_dns(host);
    }
    return 0;
}
