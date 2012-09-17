#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

//copy from create_icmp_socket();
int getprotobyname_test(void)
{
    struct protoent *proto;

    proto = getprotobyname("icmp");

    printf("p_name %s p_proto %d\n", proto->p_name, proto->p_proto);

    return 0;
}

int main()
{
    getprotobyname_test();
    
    return 0;
}
