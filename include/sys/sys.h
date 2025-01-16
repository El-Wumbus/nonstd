#ifndef SYS_H
#define SYS_H

#include <types.h>


/* stat */
typedef u64 dev_t;
typedef u64 ino_t;
typedef u64 nlink_t;
typedef u32 mode_t;
typedef u32 uid_t;
typedef u32 gid_t;
typedef u64 off_t;
typedef u64 blksize_t;
typedef u64 blkcnt_t;
typedef u64 time_t;

struct timespec {
    time_t tv_sec;
    long   tv_nsec;
};

struct kstat {
	dev_t st_dev;
	ino_t st_ino;
	nlink_t st_nlink;

	mode_t st_mode;
	uid_t st_uid;
	gid_t st_gid;
	unsigned int    __pad0;
	dev_t st_rdev;
	off_t st_size;
	blksize_t st_blksize;
	blkcnt_t st_blocks;

	long st_atime_sec;
	long st_atime_nsec;
	long st_mtime_sec;
	long st_mtime_nsec;
	long st_ctime_sec;
	long st_ctime_nsec;
	long __unused[3];
};

/*
struct stat {
    dev_t st_dev;
    ino_t st_ino;
    nlink_t st_nlink;

    mode_t st_mode;
    uid_t st_uid;
    gid_t st_gid;
    unsigned int    __pad0;
    dev_t st_rdev;
    off_t st_size;
    blksize_t st_blksize;
    blkcnt_t st_blocks;

    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long __unused[3];
};
*/


#define O_CREAT        0100
#define O_EXCL         0200
#define O_NOCTTY       0400
#define O_TRUNC       01000
#define O_APPEND      02000
#define O_NONBLOCK    04000
#define O_DSYNC      010000
#define O_SYNC     04010000
#define O_RSYNC    04010000
#define O_DIRECTORY 0200000
#define O_NOFOLLOW  0400000
#define O_CLOEXEC  02000000

#define O_ASYNC      020000
#define O_DIRECT     040000
#define O_LARGEFILE 0100000
#define O_NOATIME  01000000
#define O_PATH    010000000
#define O_TMPFILE 020200000
#define O_NDELAY O_NONBLOCK

// TODO: Metadata api
#define O_RDONLY  00
#define O_WRONLY  01
#define O_RDWR    02

/* syscalls */

enum SYS_SYSCALL {
    SYS_SCALL_WRITE = 0x1,
    SYS_SCALL_OPEN = 0x2L,
    SYS_SCALL_CLOSE = 0x3L,
    SYS_SCALL_EXIT = 0x3cL,
};

long sys_syscall0(long n);
long sys_syscall1(long n, long a1);
long sys_syscall2(long n, long a1, long a2);
long sys_syscall3(long n, long a1, long a2, long a3);
long sys_syscall4(long n, long a1, long a2, long a3, long a4);
long sys_syscall5(long n, long a1, long a2, long a3, long a4, long a5);

void sys_exit(int code);

int sys_open(const char *const filename, const int flags, const mode_t mode);
int sys_close(const int fd);
unsigned int sys_write(unsigned int fd, const char *buf, size_t count);

#endif
