adns_example
============

- test_ipv4.c resolves IPv4 addresses. 
- test_ipv6.c resolves IPv6 addresses. 
- test_txt.c resolves TXT Record of an address.
You input a host. Then it returns you an IP or TXT record.

Steps:

1. compile && build test_ipv6.c

    $ mv Makefile_test_ipv6 Makefile
    
    $ make
    
    $ ./test_ipv6

2. compile && build test_ipv4.c

    $ mv Makefile Makefile_test_ipv6

    $ mv Makefile.ipv4 Makefile

    $ make

    $ ./test_ipv4

3. compile && build test_txt.c

   $ mv Makefile Makefile.ipv6

   $ mv Makefile.txt Makefile

   $ make

   $ ./test_txt

Example:
```bash
$./test_ipv6

ipv6.google.com

ip: 2404:6800:4005:805::1012
```
```bash
$./test_txt

c6.changes.com.cn
domain: c6.changes.com.cn txt record is 2017061215584804o3ow7vjoembbz9slvpb91d1d0m27lyib1eshn9uvmlughk5s

www.changes.com.cn
domain: www.changes.com.cn txt record is empty

```
