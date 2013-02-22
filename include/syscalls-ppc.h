/* Syscalls from arch/powerpc/include/asm/systbl.h as of 2.6.31rc2 */

#include "trinity.h"
#include "sanitise.h"

#include <fcntl.h>
#include <signal.h>
#include <asm/mman.h>
#include "syscalls/syscalls.h"

struct syscalltable syscalls_ppc[] = {
	{ .entry = &syscall_restart_syscall },
	{ .entry = &syscall_exit },
	{ .entry = &syscall_fork },
	{ .entry = &syscall_read },
	{ .entry = &syscall_write },
	{ .entry = &syscall_open },
	{ .entry = &syscall_close },
	{ .entry = &syscall_waitpid },
	{ .entry = &syscall_creat },
	{ .entry = &syscall_link },
	{ .entry = &syscall_unlink },
	{ .entry = &syscall_execve },
	{ .entry = &syscall_chdir },
	{ .entry = &syscall_time },
	{ .entry = &syscall_mknod },
	{ .entry = &syscall_chmod },
	{ .entry = &syscall_lchown },
	{ .entry = &syscall_ni_syscall },	/* obsolete "break" syscall */
	{ .entry = &syscall_stat },
	{ .entry = &syscall_lseek },
	{ .entry = &syscall_getpid },
	{ .entry = &syscall_mount },
	{ .entry = &syscall_oldumount },
	{ .entry = &syscall_setuid },
	{ .entry = &syscall_getuid },
	{ .entry = &syscall_stime },
	{ .entry = &syscall_ptrace },
	{ .entry = &syscall_alarm },
	{ .entry = &syscall_ni_syscall }, // was OLDSYS(fstat)
	{ .entry = &syscall_pause },
	{ .entry = &syscall_utime },
	{ .entry = &syscall_ni_syscall }, // (old stty syscall holder).h
	{ .entry = &syscall_ni_syscall }, // (old gtty syscall holder).h
	{ .entry = &syscall_access },
	{ .entry = &syscall_nice },
	{ .entry = &syscall_ni_syscall }, // old ftime syscall holder
	{ .entry = &syscall_sync },
	{ .entry = &syscall_kill },
	{ .entry = &syscall_rename },
	{ .entry = &syscall_mkdir },
	{ .entry = &syscall_rmdir },
	{ .entry = &syscall_dup },
	{ .entry = &syscall_pipe },
	{ .entry = &syscall_times },
	{ .entry = &syscall_ni_syscall }, // (old prof syscall holder)
	{ .entry = &syscall_brk },
	{ .entry = &syscall_setgid },
	{ .entry = &syscall_getgid },
	{ .entry = &syscall_signal },
	{ .entry = &syscall_geteuid },
	{ .entry = &syscall_getegid },
	{ .entry = &syscall_acct },
	{ .entry = &syscall_umount },		// recycled never used phys()
	{ .entry = &syscall_ni_syscall },	// old lock syscall holder
	{ .entry = &syscall_ioctl },
	{ .entry = &syscall_fcntl },
	{ .entry = &syscall_ni_syscall },	// old mpx syscall holder
	{ .entry = &syscall_setpgid },
	{ .entry = &syscall_ni_syscall },	// old ulimit syscall holder
	{ .entry = &syscall_olduname },
	{ .entry = &syscall_umask },
	{ .entry = &syscall_chroot },
	{ .entry = &syscall_ustat },
	{ .entry = &syscall_dup2 },
	{ .entry = &syscall_getppid },
	{ .entry = &syscall_getpgrp },
	{ .entry = &syscall_setsid },
	{ .entry = &syscall_sigaction },
	{ .entry = &syscall_sgetmask },
	{ .entry = &syscall_ssetmask },
	{ .entry = &syscall_setreuid },
	{ .entry = &syscall_setregid },
	{ .entry = &syscall_sigsuspend },
	{ .entry = &syscall_sigpending },
	{ .entry = &syscall_sethostname },
	{ .entry = &syscall_setrlimit },
	{ .entry = &syscall_ni_syscall }, // was COMPAT_SYS(old_getrlimit)
	{ .entry = &syscall_getrusage },
	{ .entry = &syscall_gettimeofday },
	{ .entry = &syscall_settimeofday },
	{ .entry = &syscall_getgroups },
	{ .entry = &syscall_setgroups },
	{ .entry = &syscall_select },
	{ .entry = &syscall_symlink },
	{ .entry = &syscall_lstat },
	{ .entry = &syscall_readlink },
	{ .entry = &syscall_uselib },
	{ .entry = &syscall_swapon },
	{ .entry = &syscall_reboot },
	{ .entry = &syscall_oldreaddir },
	{ .entry = &syscall_mmap },
	{ .entry = &syscall_munmap },
	{ .entry = &syscall_truncate },
	{ .entry = &syscall_ftruncate },
	{ .entry = &syscall_fchmod },
	{ .entry = &syscall_fchown },
	{ .entry = &syscall_getpriority },
	{ .entry = &syscall_setpriority },
	{ .entry = &syscall_ni_syscall }, // old profil syscall holder
	{ .entry = &syscall_statfs },
	{ .entry = &syscall_fstatfs },
	{ .entry = &syscall_ni_syscall },
	{ .entry = &syscall_socketcall },
	{ .entry = &syscall_syslog },
	{ .entry = &syscall_setitimer },
	{ .entry = &syscall_getitimer },
	{ .entry = &syscall_newstat },
	{ .entry = &syscall_newlstat },
	{ .entry = &syscall_newfstat },
	{ .entry = &syscall_uname },
	{ .entry = &syscall_ni_syscall }, // (105)"
	{ .entry = &syscall_vhangup },
	{ .entry = &syscall_ni_syscall }, // old 'idle' system call?
	{ .entry = &syscall_ni_syscall }, // 108
	{ .entry = &syscall_wait4 },
	{ .entry = &syscall_swapoff },
	{ .entry = &syscall_sysinfo },
	{ .entry = &syscall_ipc },
	{ .entry = &syscall_fsync },
	{ .entry = &syscall_sigreturn },
	{ .entry = &syscall_clone },
	{ .entry = &syscall_setdomainname },
	{ .entry = &syscall_newuname },
	{ .entry = &syscall_ni_syscall },
	{ .entry = &syscall_adjtimex },
	{ .entry = &syscall_mprotect },
	{ .entry = &syscall_sigprocmask },
	{ .entry = &syscall_ni_syscall }, // old create module
	{ .entry = &syscall_init_module },
	{ .entry = &syscall_delete_module },
	{ .entry = &syscall_ni_syscall }, // old get_kernel_syms
	{ .entry = &syscall_quotactl },
	{ .entry = &syscall_getpgid },
	{ .entry = &syscall_fchdir },
	{ .entry = &syscall_bdflush },
	{ .entry = &syscall_sysfs },
	{ .entry = &syscall_personality },
	{ .entry = &syscall_ni_syscall },	/* obsolete "afs" syscall */
	{ .entry = &syscall_setfsuid },
	{ .entry = &syscall_setfsgid },
	{ .entry = &syscall_llseek },
	{ .entry = &syscall_getdents },
	{ .entry = &syscall_select },
	{ .entry = &syscall_flock },
	{ .entry = &syscall_msync },
	{ .entry = &syscall_readv },
	{ .entry = &syscall_writev },
	{ .entry = &syscall_getsid },
	{ .entry = &syscall_fdatasync },
	{ .entry = &syscall_sysctl },
	{ .entry = &syscall_mlock },
	{ .entry = &syscall_munlock },
	{ .entry = &syscall_mlockall },
	{ .entry = &syscall_munlockall },
	{ .entry = &syscall_sched_setparam },
	{ .entry = &syscall_sched_getparam },
	{ .entry = &syscall_sched_setscheduler },
	{ .entry = &syscall_sched_getscheduler },
	{ .entry = &syscall_sched_yield },
	{ .entry = &syscall_sched_get_priority_max },
	{ .entry = &syscall_sched_get_priority_min },
	{ .entry = &syscall_sched_rr_get_interval },
	{ .entry = &syscall_nanosleep },
	{ .entry = &syscall_mremap },
	{ .entry = &syscall_setresuid },
	{ .entry = &syscall_getresuid },
	{ .entry = &syscall_ni_syscall }, // Old sys_query_module
	{ .entry = &syscall_poll },
	{ .entry = &syscall_nfsservctl },
	{ .entry = &syscall_setresgid },
	{ .entry = &syscall_getresgid },
	{ .entry = &syscall_prctl },
	{ .entry = &syscall_rt_sigreturn },
	{ .entry = &syscall_rt_sigaction },
	{ .entry = &syscall_rt_sigprocmask },
	{ .entry = &syscall_rt_sigpending },
	{ .entry = &syscall_rt_sigtimedwait },
	{ .entry = &syscall_rt_sigqueueinfo },
	{ .entry = &syscall_rt_sigsuspend },
	{ .entry = &syscall_pread64 },
	{ .entry = &syscall_pwrite64 },
	{ .entry = &syscall_chown },
	{ .entry = &syscall_getcwd },
	{ .entry = &syscall_capget },
	{ .entry = &syscall_capset },
	{ .entry = &syscall_sigaltstack },
	{ .entry = &syscall_sendfile },
	{ .entry = &syscall_ni_syscall }, // reserved for streams1
	{ .entry = &syscall_ni_syscall }, // reserved for streams2
	{ .entry = &syscall_vfork },
	{ .entry = &syscall_getrlimit },
	{ .entry = &syscall_readahead },
	{ .entry = &syscall_mmap },
	{ .entry = &syscall_truncate64 },
	{ .entry = &syscall_ftruncate64 },
	{ .entry = &syscall_stat64 },
	{ .entry = &syscall_lstat64 },
	{ .entry = &syscall_fstat64 },
	{ .entry = &syscall_ni_syscall }, // TODO: pciconfig_read
	{ .entry = &syscall_ni_syscall }, // TODO: pciconfig_write
	{ .entry = &syscall_ni_syscall }, // TODO: pciconfig_iobase
	{ .entry = &syscall_ni_syscall }, // 201
	{ .entry = &syscall_getdents64 },
	{ .entry = &syscall_pivot_root },
	{ .entry = &syscall_fcntl },	/* fcntl64 */
	{ .entry = &syscall_madvise },
	{ .entry = &syscall_mincore },
	{ .entry = &syscall_gettid },
	{ .entry = &syscall_tkill },
	{ .entry = &syscall_setxattr },
	{ .entry = &syscall_lsetxattr },
	{ .entry = &syscall_fsetxattr },
	{ .entry = &syscall_getxattr },
	{ .entry = &syscall_lgetxattr },
	{ .entry = &syscall_fgetxattr },
	{ .entry = &syscall_listxattr },
	{ .entry = &syscall_llistxattr },
	{ .entry = &syscall_flistxattr },
	{ .entry = &syscall_removexattr },
	{ .entry = &syscall_lremovexattr },
	{ .entry = &syscall_fremovexattr },
	{ .entry = &syscall_futex },
	{ .entry = &syscall_sched_setaffinity },
	{ .entry = &syscall_sched_getaffinity },
	{ .entry = &syscall_ni_syscall },
	{ .entry = &syscall_ni_syscall },
	{ .entry = &syscall_sendfile64 },
	{ .entry = &syscall_io_setup },
	{ .entry = &syscall_io_destroy },
	{ .entry = &syscall_io_getevents },
	{ .entry = &syscall_io_submit },
	{ .entry = &syscall_io_cancel },
	{ .entry = &syscall_set_tid_address },
	{ .entry = &syscall_fadvise64 },
	{ .entry = &syscall_exit_group },
	{ .entry = &syscall_lookup_dcookie },
	{ .entry = &syscall_epoll_create },
	{ .entry = &syscall_epoll_ctl },
	{ .entry = &syscall_epoll_wait },
	{ .entry = &syscall_remap_file_pages },
	{ .entry = &syscall_timer_create },
	{ .entry = &syscall_timer_settime },
	{ .entry = &syscall_timer_gettime },
	{ .entry = &syscall_timer_getoverrun },
	{ .entry = &syscall_timer_delete },
	{ .entry = &syscall_clock_settime },
	{ .entry = &syscall_clock_gettime },
	{ .entry = &syscall_clock_getres },
	{ .entry = &syscall_clock_nanosleep },
	{ .entry = &syscall_ni_syscall }, // TODO: ppc64_swapcontext
	{ .entry = &syscall_tgkill },
	{ .entry = &syscall_utimes },
	{ .entry = &syscall_statfs64 },
	{ .entry = &syscall_fstatfs64 },
	{ .entry = &syscall_fadvise64_64 },
	{ .entry = &syscall_rtas },
	{ .entry = &syscall_ni_syscall }, // TODO: debug_setcontext
	{ .entry = &syscall_ni_syscall },
	{ .entry = &syscall_migrate_pages },
	{ .entry = &syscall_mbind },
	{ .entry = &syscall_get_mempolicy },
	{ .entry = &syscall_set_mempolicy },
	{ .entry = &syscall_mq_open },
	{ .entry = &syscall_mq_unlink },
	{ .entry = &syscall_mq_timedsend },
	{ .entry = &syscall_mq_timedreceive },
	{ .entry = &syscall_mq_notify },
	{ .entry = &syscall_mq_getsetattr },
	{ .entry = &syscall_kexec_load },
	{ .entry = &syscall_add_key },
	{ .entry = &syscall_request_key },
	{ .entry = &syscall_keyctl },
	{ .entry = &syscall_waitid },
	{ .entry = &syscall_ioprio_set },
	{ .entry = &syscall_ioprio_get },
	{ .entry = &syscall_inotify_init },
	{ .entry = &syscall_inotify_add_watch },
	{ .entry = &syscall_inotify_rm_watch },
	{ .entry = &syscall_ni_syscall }, // TODO: spu_run
	{ .entry = &syscall_ni_syscall }, // TODO: spu_create
	{ .entry = &syscall_pselect6 },
	{ .entry = &syscall_ppoll },
	{ .entry = &syscall_unshare },
	{ .entry = &syscall_splice },
	{ .entry = &syscall_tee },
	{ .entry = &syscall_vmsplice },
	{ .entry = &syscall_openat },
	{ .entry = &syscall_mkdirat },
	{ .entry = &syscall_mknodat },
	{ .entry = &syscall_fchownat },
	{ .entry = &syscall_futimesat },
	{ .entry = &syscall_fstatat64 },
	{ .entry = &syscall_unlinkat },
	{ .entry = &syscall_renameat },
	{ .entry = &syscall_linkat },
	{ .entry = &syscall_symlinkat },
	{ .entry = &syscall_readlinkat },
	{ .entry = &syscall_fchmodat },
	{ .entry = &syscall_faccessat },
	{ .entry = &syscall_get_robust_list },
	{ .entry = &syscall_set_robust_list },
	{ .entry = &syscall_move_pages },
	{ .entry = &syscall_getcpu },
	{ .entry = &syscall_epoll_pwait },
	{ .entry = &syscall_utimensat },
	{ .entry = &syscall_signalfd },
	{ .entry = &syscall_timerfd_create },
	{ .entry = &syscall_eventfd },
	{ .entry = &syscall_sync_file_range2 },
	{ .entry = &syscall_fallocate },
	{ .entry = &syscall_ni_syscall }, // TODO: subpage_prot
	{ .entry = &syscall_timerfd_settime },
	{ .entry = &syscall_timerfd_gettime },
	{ .entry = &syscall_signalfd4 },
	{ .entry = &syscall_eventfd2 },
	{ .entry = &syscall_epoll_create1 },
	{ .entry = &syscall_dup3 },
	{ .entry = &syscall_pipe2 },
	{ .entry = &syscall_inotify_init1 },
	{ .entry = &syscall_perf_event_open },
	{ .entry = &syscall_preadv },
	{ .entry = &syscall_pwritev },
	{ .entry = &syscall_rt_tgsigqueueinfo },
};