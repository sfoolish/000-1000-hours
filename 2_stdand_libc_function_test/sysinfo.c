/* 显示当前系统进程总数   /proc/sys/kernel/threads-max 系统支持最大进程数 */
#include <stdio.h>
#include <sys/sysinfo.h>

int main()
{
    struct sysinfo info;

    sysinfo(&info);
    
    printf("Seconds since boot                : %d\n", info.uptime);
    printf("1, 5, and 15 minute load averages : %d %d %d\n", info.loads[0], info.loads[1], info.loads[2]);
    printf("Total usable main memory size     : %d\n", info.totalram);
    printf("Available memory size             : %d\n", info.freeram);
    printf("Amount of shared memory           : %d\n", info.sharedram);
    printf("Memory used by buffers            : %d\n", info.bufferram);
    printf("Total swap space size             : %d\n", info.totalswap);
    printf("swap space still available        : %d\n", info.freeswap);
    printf("Number of current processes       : %d\n", info.procs);
    printf("Total high memory size            : %d\n", info.totalhigh);
    printf("Available high memory size        : %d\n", info.freehigh);
    printf("Memory unit size in bytes         : %d\n", info.mem_unit);
    return 0;
}
