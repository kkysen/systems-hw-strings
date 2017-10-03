


typedef signed char __int8_t;

typedef unsigned char __uint8_t;
typedef short int __int16_t;

typedef short unsigned int __uint16_t;
typedef int __int32_t;

typedef unsigned int __uint32_t;
typedef long int __int64_t;

typedef long unsigned int __uint64_t;
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;
typedef int __int_least32_t;

typedef unsigned int __uint_least32_t;
typedef long int __int_least64_t;

typedef long unsigned int __uint_least64_t;
typedef long int __intmax_t;


typedef long unsigned int __uintmax_t;


typedef long int __intptr_t;

typedef long unsigned int __uintptr_t;

typedef long unsigned int size_t;
typedef long int ptrdiff_t;
typedef short unsigned int wchar_t;
typedef struct {
    long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
    long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;


typedef __builtin_va_list __gnuc_va_list;


typedef __gnuc_va_list va_list;
typedef __int64_t __blkcnt_t;


typedef __int32_t __blksize_t;


typedef __uint32_t __dev_t;


typedef unsigned long __fsblkcnt_t;


typedef unsigned long __fsfilcnt_t;


typedef __uint32_t __uid_t;


typedef __uint32_t __gid_t;


typedef __uint64_t __ino_t;


typedef long long __key_t;


typedef __uint16_t __sa_family_t;


typedef int __socklen_t;
typedef void *_LOCK_T;

void __cygwin_lock_init(_LOCK_T *);

void __cygwin_lock_init_recursive(_LOCK_T *);

void __cygwin_lock_fini(_LOCK_T *);

void __cygwin_lock_lock(_LOCK_T *);

int __cygwin_lock_trylock(_LOCK_T *);

void __cygwin_lock_unlock(_LOCK_T *);

typedef long _off_t;


typedef int __pid_t;
typedef __uint32_t __id_t;
typedef __uint32_t __mode_t;


__extension__ typedef long long _off64_t;


typedef _off_t __off_t;


typedef _off64_t __loff_t;
typedef long _fpos_t;


typedef _off64_t _fpos64_t;
typedef long unsigned int __size_t;
typedef long signed int _ssize_t;
typedef _ssize_t __ssize_t;


typedef unsigned int wint_t;


typedef struct {
    int __count;
    union {
        wint_t __wch;
        unsigned char __wchb[4];
    } __value;
} _mbstate_t;


typedef _LOCK_T _flock_t;


typedef void *_iconv_t;


typedef unsigned long __clock_t;


typedef long __time_t;


typedef unsigned long __clockid_t;


typedef unsigned long __timer_t;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;


typedef __builtin_va_list __va_list;
typedef unsigned int __ULong;
struct _reent;

struct __locale_t;


struct _Bigint {
    struct _Bigint *_next;
    int _k, _maxwds, _sign, _wds;
    __ULong _x[1];
};


struct __tm {
    int __tm_sec;
    int __tm_min;
    int __tm_hour;
    int __tm_mday;
    int __tm_mon;
    int __tm_year;
    int __tm_wday;
    int __tm_yday;
    int __tm_isdst;
};


struct _on_exit_args {
    void *_fnargs[32];
    void *_dso_handle[32];
    
    __ULong _fntypes;
    
    
    __ULong _is_cxa;
};

struct _atexit {
    struct _atexit *_next;
    int _ind;
    
    void (*_fns[32])(void);
    
    struct _on_exit_args _on_exit_args;
};

struct __sbuf {
    unsigned char *_base;
    int _size;
};

struct __sFILE {
    unsigned char *_p;
    int _r;
    int _w;
    short _flags;
    short _file;
    struct __sbuf _bf;
    int _lbfsize;
    
    
    void *_cookie;
    
    _ssize_t (__attribute__((__cdecl__)) *_read)(struct _reent *, void *, char *, size_t);
    
    _ssize_t (__attribute__((__cdecl__)) *_write)(struct _reent *, void *, const char *, size_t);
    
    _fpos_t (__attribute__((__cdecl__)) *_seek)(struct _reent *, void *, _fpos_t, int);
    
    int (__attribute__((__cdecl__)) *_close)(struct _reent *, void *);
    
    
    struct __sbuf _ub;
    unsigned char *_up;
    int _ur;
    
    
    unsigned char _ubuf[3];
    unsigned char _nbuf[1];
    
    
    struct __sbuf _lb;
    
    
    int _blksize;
    _off_t _offset;
    
    
    struct _reent *_data;
    
    
    _flock_t _lock;
    
    _mbstate_t _mbstate;
    int _flags2;
};

struct __sFILE64 {
    unsigned char *_p;
    int _r;
    int _w;
    short _flags;
    short _file;
    struct __sbuf _bf;
    int _lbfsize;
    
    struct _reent *_data;
    
    
    void *_cookie;
    
    _ssize_t (__attribute__((__cdecl__)) *_read)(struct _reent *, void *, char *, size_t);
    
    _ssize_t (__attribute__((__cdecl__)) *_write)(struct _reent *, void *, const char *, size_t);
    
    _fpos_t (__attribute__((__cdecl__)) *_seek)(struct _reent *, void *, _fpos_t, int);
    
    int (__attribute__((__cdecl__)) *_close)(struct _reent *, void *);
    
    
    struct __sbuf _ub;
    unsigned char *_up;
    int _ur;
    
    
    unsigned char _ubuf[3];
    unsigned char _nbuf[1];
    
    
    struct __sbuf _lb;
    
    
    int _blksize;
    int _flags2;
    
    _off64_t _offset;
    
    _fpos64_t (__attribute__((__cdecl__)) *_seek64)(struct _reent *, void *, _fpos64_t, int);
    
    
    _flock_t _lock;
    
    _mbstate_t _mbstate;
};

typedef struct __sFILE64 __FILE;


struct _glue {
    struct _glue *_next;
    int _niobs;
    __FILE *_iobs;
};
struct _rand48 {
    unsigned short _seed[3];
    unsigned short _mult[3];
    unsigned short _add;
    
    
};

struct _reent {
    int _errno;
    
    
    __FILE *_stdin, *_stdout, *_stderr;
    
    int _inc;
    char _emergency[25];
    
    
    int _unspecified_locale_info;
    struct __locale_t *_locale;
    
    int __sdidinit;
    
    void (__attribute__((__cdecl__)) *__cleanup)(struct _reent *);
    
    
    struct _Bigint *_result;
    int _result_k;
    struct _Bigint *_p5s;
    struct _Bigint **_freelist;
    
    
    int _cvtlen;
    char *_cvtbuf;
    
    union {
        struct {
            unsigned int _unused_rand;
            char *_strtok_last;
            char _asctime_buf[26];
            struct __tm _localtime_buf;
            int _gamma_signgam;
            __extension__ unsigned long long _rand_next;
            struct _rand48 _r48;
            _mbstate_t _mblen_state;
            _mbstate_t _mbtowc_state;
            _mbstate_t _wctomb_state;
            char _l64a_buf[8];
            char _signal_buf[24];
            int _getdate_err;
            _mbstate_t _mbrlen_state;
            _mbstate_t _mbrtowc_state;
            _mbstate_t _mbsrtowcs_state;
            _mbstate_t _wcrtomb_state;
            _mbstate_t _wcsrtombs_state;
            int _h_errno;
        } _reent;
        
        
        struct {
            
            unsigned char *_nextf[30];
            unsigned int _nmalloc[30];
        } _unused;
    } _new;
    
    
    struct _atexit *_atexit;
    struct _atexit _atexit0;
    
    
    void (**(_sig_func))(int);
    
    
    struct _glue __sglue;
    __FILE __sf[3];
};

extern struct _reent *_impure_ptr;
extern struct _reent *const _global_impure_ptr;

void _reclaim_reent(struct _reent *);


struct _reent *__attribute__((__cdecl__)) __getreent(void);

typedef __uint8_t u_int8_t;


typedef __uint16_t u_int16_t;


typedef __uint32_t u_int32_t;


typedef __uint64_t u_int64_t;

typedef int register_t;

typedef __int8_t int8_t;


typedef __uint8_t uint8_t;


typedef __int16_t int16_t;


typedef __uint16_t uint16_t;


typedef __int32_t int32_t;


typedef __uint32_t uint32_t;


typedef __int64_t int64_t;


typedef __uint64_t uint64_t;


typedef __intmax_t intmax_t;


typedef __uintmax_t uintmax_t;


typedef __intptr_t intptr_t;


typedef __uintptr_t uintptr_t;


static __inline__ __uint32_t __ntohl(__uint32_t);

static __inline__ __uint16_t __ntohs(__uint16_t);

static __inline__ __uint32_t
__ntohl(__uint32_t _x) {
    __asm__("bswap %0" : "=r" (_x) : "0" (_x));
    return _x;
}

static __inline__ __uint16_t
__ntohs(__uint16_t _x) {
    __asm__("xchgb %b0,%h0"
    : "=Q" (_x)
    : "0" (_x));
    return _x;
}

typedef unsigned long __sigset_t;
typedef __suseconds_t suseconds_t;


typedef long time_t;
struct timeval {
    time_t tv_sec;
    suseconds_t tv_usec;
};
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};
struct itimerspec {
    struct timespec it_interval;
    struct timespec it_value;
};


typedef __sigset_t sigset_t;
typedef unsigned long fd_mask;


typedef struct _types_fd_set {
    fd_mask fds_bits[(((64) + (((sizeof(fd_mask) * 8)) - 1)) / ((sizeof(fd_mask) * 8)))];
} _types_fd_set;


int select(int __n, _types_fd_set *__readfds, _types_fd_set *__writefds, _types_fd_set *__exceptfds,
           struct timeval *__timeout);

int pselect(int __n, _types_fd_set *__readfds, _types_fd_set *__writefds, _types_fd_set *__exceptfds,
            const struct timespec *__timeout, const sigset_t *__set);


typedef __uint32_t in_addr_t;


typedef __uint16_t in_port_t;
typedef unsigned char u_char;


typedef unsigned short u_short;


typedef unsigned int u_int;


typedef unsigned long u_long;


typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;


typedef __blkcnt_t blkcnt_t;


typedef __blksize_t blksize_t;


typedef unsigned long clock_t;
typedef long daddr_t;


typedef char *caddr_t;


typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;


typedef __id_t id_t;


typedef __ino_t ino_t;
typedef __off_t off_t;


typedef __dev_t dev_t;


typedef __uid_t uid_t;


typedef __gid_t gid_t;


typedef __pid_t pid_t;


typedef __key_t key_t;


typedef _ssize_t ssize_t;


typedef __mode_t mode_t;


typedef __nlink_t nlink_t;


typedef __clockid_t clockid_t;


typedef __timer_t timer_t;


typedef __useconds_t useconds_t;
typedef __int64_t sbintime_t;


typedef struct __pthread_t {
    char __dummy;
} *pthread_t;
typedef struct __pthread_mutex_t {
    char __dummy;
} *pthread_mutex_t;

typedef struct __pthread_key_t {
    char __dummy;
} *pthread_key_t;
typedef struct __pthread_attr_t {
    char __dummy;
} *pthread_attr_t;
typedef struct __pthread_mutexattr_t {
    char __dummy;
} *pthread_mutexattr_t;
typedef struct __pthread_condattr_t {
    char __dummy;
} *pthread_condattr_t;
typedef struct __pthread_cond_t {
    char __dummy;
} *pthread_cond_t;
typedef struct __pthread_barrierattr_t {
    char __dummy;
} *pthread_barrierattr_t;
typedef struct __pthread_barrier_t {
    char __dummy;
} *pthread_barrier_t;


typedef struct {
    pthread_mutex_t mutex;
    int state;
}
        pthread_once_t;
typedef struct __pthread_spinlock_t {
    char __dummy;
} *pthread_spinlock_t;
typedef struct __pthread_rwlock_t {
    char __dummy;
} *pthread_rwlock_t;
typedef struct __pthread_rwlockattr_t {
    char __dummy;
} *pthread_rwlockattr_t;

static __inline unsigned short
__bswap_16(unsigned short __x) {
    return (__x >> 8) | (__x << 8);
}

static __inline unsigned int
__bswap_32(unsigned int __x) {
    return (__bswap_16(__x & 0xffff) << 16) | (__bswap_16(__x >> 16));
}

static __inline unsigned long long
__bswap_64(unsigned long long __x) {
    return (((unsigned long long) __bswap_32(__x & 0xffffffffull)) << 32) | (__bswap_32(__x >> 32));
}


typedef struct timespec timespec_t;


typedef struct timespec timestruc_t;


typedef __loff_t loff_t;
struct flock {
    short l_type;
    short l_whence;
    off_t l_start;
    off_t l_len;
    pid_t l_pid;
};


typedef unsigned long vm_offset_t;


typedef unsigned long vm_size_t;


typedef void *vm_object_t;


typedef char *addr_t;


static __inline__ int gnu_dev_major(dev_t);

static __inline__ int gnu_dev_minor(dev_t);

static __inline__ dev_t gnu_dev_makedev(int, int);

static __inline__ int
gnu_dev_major(dev_t dev) {
    return (int) (((dev) >> 16) & 0xffff);
}

static __inline__ int
gnu_dev_minor(dev_t dev) {
    return (int) ((dev) & 0xffff);
}

static __inline__ dev_t
gnu_dev_makedev(int maj, int min) {
    return (((maj) << 16) | ((min) & 0xffff));
}


typedef __FILE FILE;


typedef _fpos64_t fpos_t;


ssize_t __attribute__((__cdecl__)) getline(char **, size_t *, FILE *);

ssize_t __attribute__((__cdecl__)) getdelim(char **, size_t *, int, FILE *);


char *__attribute__((__cdecl__)) ctermid(char *);


FILE *__attribute__((__cdecl__)) tmpfile(void);

char *__attribute__((__cdecl__)) tmpnam(char *);

char *__attribute__((__cdecl__)) tempnam(const char *, const char *);

int __attribute__((__cdecl__)) fclose(FILE *);

int __attribute__((__cdecl__)) fflush(FILE *);

FILE *__attribute__((__cdecl__)) freopen(const char *restrict, const char *restrict, FILE *restrict);

void __attribute__((__cdecl__)) setbuf(FILE *restrict, char *restrict);

int __attribute__((__cdecl__)) setvbuf(FILE *restrict, char *restrict, int, size_t);

int __attribute__((__cdecl__))
fprintf(FILE *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)));

int __attribute__((__cdecl__))
fscanf(FILE *restrict, const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));

int __attribute__((__cdecl__)) printf(const char *restrict, ...) __attribute__ ((__format__ (__printf__, 1, 2)));

int __attribute__((__cdecl__)) scanf(const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 1, 2)));

int __attribute__((__cdecl__))
sscanf(const char *restrict, const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));

int __attribute__((__cdecl__))
vfprintf(FILE *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));

int __attribute__((__cdecl__)) vprintf(const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)));

int __attribute__((__cdecl__))
vsprintf(char *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));

int __attribute__((__cdecl__)) fgetc(FILE *);

char *__attribute__((__cdecl__)) fgets(char *restrict, int, FILE *restrict);

int __attribute__((__cdecl__)) fputc(int, FILE *);

int __attribute__((__cdecl__)) fputs(const char *restrict, FILE *restrict);

int __attribute__((__cdecl__)) getc(FILE *);

int __attribute__((__cdecl__)) getchar(void);

char *__attribute__((__cdecl__)) gets(char *);

int __attribute__((__cdecl__)) putc(int, FILE *);

int __attribute__((__cdecl__)) putchar(int);

int __attribute__((__cdecl__)) puts(const char *);

int __attribute__((__cdecl__)) ungetc(int, FILE *);

size_t __attribute__((__cdecl__)) fread(void *restrict, size_t _size, size_t _n, FILE *restrict);

size_t __attribute__((__cdecl__)) fwrite(const void *restrict, size_t _size, size_t _n, FILE *);


int __attribute__((__cdecl__)) fgetpos(FILE *restrict, fpos_t *restrict);

int __attribute__((__cdecl__)) fseek(FILE *, long, int);


int __attribute__((__cdecl__)) fsetpos(FILE *, const fpos_t *);

long __attribute__((__cdecl__)) ftell(FILE *);

void __attribute__((__cdecl__)) rewind(FILE *);

void __attribute__((__cdecl__)) clearerr(FILE *);

int __attribute__((__cdecl__)) feof(FILE *);

int __attribute__((__cdecl__)) ferror(FILE *);

void __attribute__((__cdecl__)) perror(const char *);

FILE *__attribute__((__cdecl__)) fopen(const char *restrict _name, const char *restrict _type);

int __attribute__((__cdecl__))
sprintf(char *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)));

int __attribute__((__cdecl__)) remove(const char *);

int __attribute__((__cdecl__)) rename(const char *, const char *);

int __attribute__((__cdecl__)) fseeko(FILE *, off_t, int);

off_t __attribute__((__cdecl__)) ftello(FILE *);


int __attribute__((__cdecl__))
snprintf(char *restrict, size_t, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__))
vsnprintf(char *restrict, size_t, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

int __attribute__((__cdecl__))
vfscanf(FILE *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));

int __attribute__((__cdecl__)) vscanf(const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)));

int __attribute__((__cdecl__))
vsscanf(const char *restrict, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));

int __attribute__((__cdecl__)) asiprintf(char **, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));

char *__attribute__((__cdecl__)) asniprintf(char *, size_t *, const char *,
                                            ...) __attribute__ ((__format__ (__printf__, 3, 4)));

char *__attribute__((__cdecl__)) asnprintf(char *restrict, size_t *restrict, const char *restrict,
                                           ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__)) diprintf(int, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));

int __attribute__((__cdecl__)) fiprintf(FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));

int __attribute__((__cdecl__)) fiscanf(FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));

int __attribute__((__cdecl__)) iprintf(const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)));

int __attribute__((__cdecl__)) iscanf(const char *, ...) __attribute__ ((__format__ (__scanf__, 1, 2)));

int __attribute__((__cdecl__)) siprintf(char *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));

int __attribute__((__cdecl__)) siscanf(const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));

int __attribute__((__cdecl__))
sniprintf(char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__))
vasiprintf(char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));

char *__attribute__((__cdecl__)) vasniprintf(char *, size_t *, const char *,
                                             __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

char *__attribute__((__cdecl__)) vasnprintf(char *, size_t *, const char *,
                                            __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

int __attribute__((__cdecl__))
vdiprintf(int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));

int __attribute__((__cdecl__))
vfiprintf(FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));

int __attribute__((__cdecl__))
vfiscanf(FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));

int __attribute__((__cdecl__)) viprintf(const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)));

int __attribute__((__cdecl__)) viscanf(const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)));

int __attribute__((__cdecl__))
vsiprintf(char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));

int __attribute__((__cdecl__))
vsiscanf(const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));

int __attribute__((__cdecl__))
vsniprintf(char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

FILE *__attribute__((__cdecl__)) fdopen(int, const char *);

int __attribute__((__cdecl__)) fileno(FILE *);


int __attribute__((__cdecl__)) pclose(FILE *);

FILE *__attribute__((__cdecl__)) popen(const char *, const char *);


void __attribute__((__cdecl__)) setbuffer(FILE *, char *, int);

int __attribute__((__cdecl__)) setlinebuf(FILE *);


int __attribute__((__cdecl__)) getw(FILE *);

int __attribute__((__cdecl__)) putw(int, FILE *);


int __attribute__((__cdecl__)) getc_unlocked(FILE *);

int __attribute__((__cdecl__)) getchar_unlocked(void);

void __attribute__((__cdecl__)) flockfile(FILE *);

int __attribute__((__cdecl__)) ftrylockfile(FILE *);

void __attribute__((__cdecl__)) funlockfile(FILE *);

int __attribute__((__cdecl__)) putc_unlocked(int, FILE *);

int __attribute__((__cdecl__)) putchar_unlocked(int);

int __attribute__((__cdecl__)) dprintf(int, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)));

FILE *__attribute__((__cdecl__)) fmemopen(void *restrict, size_t, const char *restrict);


FILE *__attribute__((__cdecl__)) open_memstream(char **, size_t *);

int __attribute__((__cdecl__))
vdprintf(int, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));


int __attribute__((__cdecl__)) renameat(int, const char *, int, const char *);


int __attribute__((__cdecl__))
_asiprintf_r(struct _reent *, char **, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));

char *__attribute__((__cdecl__)) _asniprintf_r(struct _reent *, char *, size_t *, const char *,
                                               ...) __attribute__ ((__format__ (__printf__, 4, 5)));

char *__attribute__((__cdecl__)) _asnprintf_r(struct _reent *, char *restrict, size_t *restrict, const char *restrict,
                                              ...) __attribute__ ((__format__ (__printf__, 4, 5)));

int __attribute__((__cdecl__)) _asprintf_r(struct _reent *, char **restrict, const char *restrict,
                                           ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__))
_diprintf_r(struct _reent *, int, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__))
_dprintf_r(struct _reent *, int, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__)) _fclose_r(struct _reent *, FILE *);

int __attribute__((__cdecl__)) _fcloseall_r(struct _reent *);

FILE *__attribute__((__cdecl__)) _fdopen_r(struct _reent *, int, const char *);

int __attribute__((__cdecl__)) _fflush_r(struct _reent *, FILE *);

int __attribute__((__cdecl__)) _fgetc_r(struct _reent *, FILE *);

int __attribute__((__cdecl__)) _fgetc_unlocked_r(struct _reent *, FILE *);

char *__attribute__((__cdecl__)) _fgets_r(struct _reent *, char *restrict, int, FILE *restrict);

char *__attribute__((__cdecl__)) _fgets_unlocked_r(struct _reent *, char *restrict, int, FILE *restrict);


int __attribute__((__cdecl__)) _fgetpos_r(struct _reent *, FILE *, fpos_t *);

int __attribute__((__cdecl__)) _fsetpos_r(struct _reent *, FILE *, const fpos_t *);

int __attribute__((__cdecl__))
_fiprintf_r(struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__))
_fiscanf_r(struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)));

FILE *__attribute__((__cdecl__)) _fmemopen_r(struct _reent *, void *restrict, size_t, const char *restrict);

FILE *__attribute__((__cdecl__)) _fopen_r(struct _reent *, const char *restrict, const char *restrict);

FILE *
__attribute__((__cdecl__)) _freopen_r(struct _reent *, const char *restrict, const char *restrict, FILE *restrict);

int __attribute__((__cdecl__))
_fprintf_r(struct _reent *, FILE *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__)) _fpurge_r(struct _reent *, FILE *);

int __attribute__((__cdecl__)) _fputc_r(struct _reent *, int, FILE *);

int __attribute__((__cdecl__)) _fputc_unlocked_r(struct _reent *, int, FILE *);

int __attribute__((__cdecl__)) _fputs_r(struct _reent *, const char *restrict, FILE *restrict);

int __attribute__((__cdecl__)) _fputs_unlocked_r(struct _reent *, const char *restrict, FILE *restrict);

size_t __attribute__((__cdecl__)) _fread_r(struct _reent *, void *restrict, size_t _size, size_t _n, FILE *restrict);

size_t __attribute__((__cdecl__))
_fread_unlocked_r(struct _reent *, void *restrict, size_t _size, size_t _n, FILE *restrict);

int __attribute__((__cdecl__))
_fscanf_r(struct _reent *, FILE *restrict, const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 3, 4)));

int __attribute__((__cdecl__)) _fseek_r(struct _reent *, FILE *, long, int);

int __attribute__((__cdecl__)) _fseeko_r(struct _reent *, FILE *, _off_t, int);

long __attribute__((__cdecl__)) _ftell_r(struct _reent *, FILE *);

_off_t __attribute__((__cdecl__)) _ftello_r(struct _reent *, FILE *);

void __attribute__((__cdecl__)) _rewind_r(struct _reent *, FILE *);

size_t __attribute__((__cdecl__))
_fwrite_r(struct _reent *, const void *restrict, size_t _size, size_t _n, FILE *restrict);

size_t __attribute__((__cdecl__))
_fwrite_unlocked_r(struct _reent *, const void *restrict, size_t _size, size_t _n, FILE *restrict);

int __attribute__((__cdecl__)) _getc_r(struct _reent *, FILE *);

int __attribute__((__cdecl__)) _getc_unlocked_r(struct _reent *, FILE *);

int __attribute__((__cdecl__)) _getchar_r(struct _reent *);

int __attribute__((__cdecl__)) _getchar_unlocked_r(struct _reent *);

char *__attribute__((__cdecl__)) _gets_r(struct _reent *, char *);

int __attribute__((__cdecl__))
_iprintf_r(struct _reent *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)));

int __attribute__((__cdecl__))
_iscanf_r(struct _reent *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));

FILE *__attribute__((__cdecl__)) _open_memstream_r(struct _reent *, char **, size_t *);

void __attribute__((__cdecl__)) _perror_r(struct _reent *, const char *);

int __attribute__((__cdecl__))
_printf_r(struct _reent *, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 2, 3)));

int __attribute__((__cdecl__)) _putc_r(struct _reent *, int, FILE *);

int __attribute__((__cdecl__)) _putc_unlocked_r(struct _reent *, int, FILE *);

int __attribute__((__cdecl__)) _putchar_unlocked_r(struct _reent *, int);

int __attribute__((__cdecl__)) _putchar_r(struct _reent *, int);

int __attribute__((__cdecl__)) _puts_r(struct _reent *, const char *);

int __attribute__((__cdecl__)) _remove_r(struct _reent *, const char *);

int __attribute__((__cdecl__)) _rename_r(struct _reent *, const char *_old, const char *_new);

int __attribute__((__cdecl__))
_scanf_r(struct _reent *, const char *restrict, ...) __attribute__ ((__format__ (__scanf__, 2, 3)));

int __attribute__((__cdecl__))
_siprintf_r(struct _reent *, char *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__))
_siscanf_r(struct _reent *, const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)));

int __attribute__((__cdecl__))
_sniprintf_r(struct _reent *, char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)));

int __attribute__((__cdecl__)) _snprintf_r(struct _reent *, char *restrict, size_t, const char *restrict,
                                           ...) __attribute__ ((__format__ (__printf__, 4, 5)));

int __attribute__((__cdecl__))
_sprintf_r(struct _reent *, char *restrict, const char *restrict, ...) __attribute__ ((__format__ (__printf__, 3, 4)));

int __attribute__((__cdecl__)) _sscanf_r(struct _reent *, const char *restrict, const char *restrict,
                                         ...) __attribute__ ((__format__ (__scanf__, 3, 4)));

char *__attribute__((__cdecl__)) _tempnam_r(struct _reent *, const char *, const char *);

FILE *__attribute__((__cdecl__)) _tmpfile_r(struct _reent *);

char *__attribute__((__cdecl__)) _tmpnam_r(struct _reent *, char *);

int __attribute__((__cdecl__)) _ungetc_r(struct _reent *, int, FILE *);

int __attribute__((__cdecl__))
_vasiprintf_r(struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

char *__attribute__((__cdecl__)) _vasniprintf_r(struct _reent *, char *, size_t *, const char *,
                                                __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)));

char *__attribute__((__cdecl__)) _vasnprintf_r(struct _reent *, char *, size_t *, const char *,
                                               __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)));

int __attribute__((__cdecl__))
_vasprintf_r(struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

int __attribute__((__cdecl__))
_vdiprintf_r(struct _reent *, int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

int __attribute__((__cdecl__))
_vdprintf_r(struct _reent *, int, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

int __attribute__((__cdecl__))
_vfiprintf_r(struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

int __attribute__((__cdecl__))
_vfiscanf_r(struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)));

int __attribute__((__cdecl__)) _vfprintf_r(struct _reent *, FILE *restrict, const char *restrict,
                                           __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

int __attribute__((__cdecl__)) _vfscanf_r(struct _reent *, FILE *restrict, const char *restrict,
                                          __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)));

int __attribute__((__cdecl__))
_viprintf_r(struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));

int __attribute__((__cdecl__))
_viscanf_r(struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));

int __attribute__((__cdecl__))
_vprintf_r(struct _reent *, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)));

int __attribute__((__cdecl__))
_vscanf_r(struct _reent *, const char *restrict, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)));

int __attribute__((__cdecl__))
_vsiprintf_r(struct _reent *, char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

int __attribute__((__cdecl__))
_vsiscanf_r(struct _reent *, const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)));

int __attribute__((__cdecl__)) _vsniprintf_r(struct _reent *, char *, size_t, const char *,
                                             __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)));

int __attribute__((__cdecl__)) _vsnprintf_r(struct _reent *, char *restrict, size_t, const char *restrict,
                                            __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)));

int __attribute__((__cdecl__)) _vsprintf_r(struct _reent *, char *restrict, const char *restrict,
                                           __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)));

int __attribute__((__cdecl__)) _vsscanf_r(struct _reent *, const char *restrict, const char *restrict,
                                          __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)));


int __attribute__((__cdecl__)) fpurge(FILE *);

ssize_t __attribute__((__cdecl__)) __getdelim(char **, size_t *, int, FILE *);

ssize_t __attribute__((__cdecl__)) __getline(char **, size_t *, FILE *);


void __attribute__((__cdecl__)) clearerr_unlocked(FILE *);

int __attribute__((__cdecl__)) feof_unlocked(FILE *);

int __attribute__((__cdecl__)) ferror_unlocked(FILE *);

int __attribute__((__cdecl__)) fileno_unlocked(FILE *);

int __attribute__((__cdecl__)) fflush_unlocked(FILE *);

int __attribute__((__cdecl__)) fgetc_unlocked(FILE *);

int __attribute__((__cdecl__)) fputc_unlocked(int, FILE *);

size_t __attribute__((__cdecl__)) fread_unlocked(void *restrict, size_t _size, size_t _n, FILE *restrict);

size_t __attribute__((__cdecl__)) fwrite_unlocked(const void *restrict, size_t _size, size_t _n, FILE *);

int __attribute__((__cdecl__)) __srget_r(struct _reent *, FILE *);

int __attribute__((__cdecl__)) __swbuf_r(struct _reent *, int, FILE *);


FILE *__attribute__((__cdecl__)) funopen(const void *__cookie, int (*__readfn)(void *__c, char *__buf, size_t __n),
                                         int (*__writefn)(void *__c, const char *__buf, size_t __n),
                                         _fpos64_t (*__seekfn)(void *__c, _fpos64_t __off, int __whence),
                                         int (*__closefn)(void *__c));

FILE *__attribute__((__cdecl__)) _funopen_r(struct _reent *, const void *__cookie,
                                            int (*__readfn)(void *__c, char *__buf, size_t __n),
                                            int (*__writefn)(void *__c, const char *__buf, size_t __n),
                                            _fpos64_t (*__seekfn)(void *__c, _fpos64_t __off, int __whence),
                                            int (*__closefn)(void *__c));

static __inline__ int __sgetc_r(struct _reent *__ptr, FILE *__p);

static __inline__ int __sgetc_r(struct _reent *__ptr, FILE *__p) {
    int __c = (--(__p)->_r < 0 ? __srget_r(__ptr, __p) : (int) (*(__p)->_p++));
    if ((__p->_flags & 0x4000) && (__c == '\r')) {
        int __c2 = (--(__p)->_r < 0 ? __srget_r(__ptr, __p) : (int) (*(__p)->_p++));
        if (__c2 == '\n')
            __c = __c2;
        else
            ungetc(__c2, __p);
    }
    return __c;
}


static __inline__ int __sputc_r(struct _reent *_ptr, int _c, FILE *_p) {
    
    if ((_p->_flags & 0x4000) && _c == '\n')
        __sputc_r(_ptr, '\r', _p);
    
    if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char) _c != '\n'))
        return (*_p->_p++ = _c);
    else
        return (__swbuf_r(_ptr, _c, _p));
}


char *mkdtemp(char *);


const char *getprogname(void);

void setprogname(const char *);


int unsetenv(const char *);

extern void *memalign(size_t, size_t);

extern void *valloc(size_t);


typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;


typedef struct {
    long long int quot;
    long long int rem;
} lldiv_t;


typedef int (*__compar_fn_t)(const void *, const void *);


int __attribute__((__cdecl__)) __locale_mb_cur_max(void);


void __attribute__((__cdecl__)) abort(void) __attribute__ ((__noreturn__));

int __attribute__((__cdecl__)) abs(int);

__uint32_t __attribute__((__cdecl__)) arc4random(void);

__uint32_t __attribute__((__cdecl__)) arc4random_uniform(__uint32_t);

void __attribute__((__cdecl__)) arc4random_buf(void *, size_t);

int __attribute__((__cdecl__)) atexit(void (*__func)(void));

double __attribute__((__cdecl__)) atof(const char *__nptr);

float __attribute__((__cdecl__)) atoff(const char *__nptr);

int __attribute__((__cdecl__)) atoi(const char *__nptr);

int __attribute__((__cdecl__)) _atoi_r(struct _reent *, const char *__nptr);

long __attribute__((__cdecl__)) atol(const char *__nptr);

long __attribute__((__cdecl__)) _atol_r(struct _reent *, const char *__nptr);

void *__attribute__((__cdecl__)) bsearch(const void *__key, const void *__base, size_t __nmemb, size_t __size,
                                         __compar_fn_t _compar);

void *__attribute__((__cdecl__)) calloc(size_t __nmemb, size_t __size);

div_t __attribute__((__cdecl__)) div(int __numer, int __denom);

void __attribute__((__cdecl__)) exit(int __status) __attribute__ ((__noreturn__));

void __attribute__((__cdecl__)) free(void *);

char *__attribute__((__cdecl__)) getenv(const char *__string);

char *__attribute__((__cdecl__)) _getenv_r(struct _reent *, const char *__string);

char *__attribute__((__cdecl__)) _findenv(const char *, int *);

char *__attribute__((__cdecl__)) _findenv_r(struct _reent *, const char *, int *);

extern char *suboptarg;

int __attribute__((__cdecl__)) getsubopt(char **, char *const *, char **);

long __attribute__((__cdecl__)) labs(long);

ldiv_t __attribute__((__cdecl__)) ldiv(long __numer, long __denom);

void *__attribute__((__cdecl__)) malloc(size_t __size);

int __attribute__((__cdecl__)) mblen(const char *, size_t);

int __attribute__((__cdecl__)) _mblen_r(struct _reent *, const char *, size_t, _mbstate_t *);

int __attribute__((__cdecl__)) mbtowc(wchar_t *restrict, const char *restrict, size_t);

int __attribute__((__cdecl__))
_mbtowc_r(struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);

int __attribute__((__cdecl__)) wctomb(char *, wchar_t);

int __attribute__((__cdecl__)) _wctomb_r(struct _reent *, char *, wchar_t, _mbstate_t *);

size_t __attribute__((__cdecl__)) mbstowcs(wchar_t *restrict, const char *restrict, size_t);

size_t __attribute__((__cdecl__))
_mbstowcs_r(struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);

size_t __attribute__((__cdecl__)) wcstombs(char *restrict, const wchar_t *restrict, size_t);

size_t __attribute__((__cdecl__))
_wcstombs_r(struct _reent *, char *restrict, const wchar_t *restrict, size_t, _mbstate_t *);


char *__attribute__((__cdecl__)) mkdtemp(char *);


int __attribute__((__cdecl__)) mkstemp(char *);


int __attribute__((__cdecl__)) mkstemps(char *, int);


char *__attribute__((__cdecl__)) mktemp(
        char *) __attribute__ ((__deprecated__("the use of `mktemp' is dangerous; use `mkstemp' instead")));


char *__attribute__((__cdecl__)) _mkdtemp_r(struct _reent *, char *);

int __attribute__((__cdecl__)) _mkostemp_r(struct _reent *, char *, int);

int __attribute__((__cdecl__)) _mkostemps_r(struct _reent *, char *, int, int);

int __attribute__((__cdecl__)) _mkstemp_r(struct _reent *, char *);

int __attribute__((__cdecl__)) _mkstemps_r(struct _reent *, char *, int);

char *__attribute__((__cdecl__)) _mktemp_r(struct _reent *,
                                           char *) __attribute__ ((__deprecated__("the use of `mktemp' is dangerous; use `mkstemp' instead")));

void __attribute__((__cdecl__)) qsort(void *__base, size_t __nmemb, size_t __size, __compar_fn_t _compar);

int __attribute__((__cdecl__)) rand(void);

void *__attribute__((__cdecl__)) realloc(void *__r, size_t __size);

void *__attribute__((__cdecl__)) reallocf(void *__r, size_t __size);


char *__attribute__((__cdecl__)) realpath(const char *restrict path, char *restrict resolved_path);


int __attribute__((__cdecl__)) rpmatch(const char *response);


void __attribute__((__cdecl__)) srand(unsigned __seed);

double __attribute__((__cdecl__)) strtod(const char *restrict __n, char **restrict __end_PTR);

double __attribute__((__cdecl__)) _strtod_r(struct _reent *, const char *restrict __n, char **restrict __end_PTR);

float __attribute__((__cdecl__)) strtof(const char *restrict __n, char **restrict __end_PTR);


long __attribute__((__cdecl__)) strtol(const char *restrict __n, char **restrict __end_PTR, int __base);

long __attribute__((__cdecl__))
_strtol_r(struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long __attribute__((__cdecl__)) strtoul(const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long __attribute__((__cdecl__))
_strtoul_r(struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);

int __attribute__((__cdecl__)) system(const char *__string);


long __attribute__((__cdecl__)) a64l(const char *__input);

char *__attribute__((__cdecl__)) l64a(long __input);

char *__attribute__((__cdecl__)) _l64a_r(struct _reent *, long __input);


int __attribute__((__cdecl__)) on_exit(void (*__func)(int, void *), void *__arg);


void __attribute__((__cdecl__)) _Exit(int __status) __attribute__ ((__noreturn__));


int __attribute__((__cdecl__)) putenv(char *__string);

int __attribute__((__cdecl__)) _putenv_r(struct _reent *, char *__string);

void *__attribute__((__cdecl__)) _reallocf_r(struct _reent *, void *, size_t);

int __attribute__((__cdecl__)) setenv(const char *__string, const char *__value, int __overwrite);

int __attribute__((__cdecl__)) _setenv_r(struct _reent *, const char *__string, const char *__value, int __overwrite);

char *__attribute__((__cdecl__)) __itoa(int, char *, int);

char *__attribute__((__cdecl__)) __utoa(unsigned, char *, int);

char *__attribute__((__cdecl__)) itoa(int, char *, int);

char *__attribute__((__cdecl__)) utoa(unsigned, char *, int);


int __attribute__((__cdecl__)) rand_r(unsigned *__seed);


double __attribute__((__cdecl__)) drand48(void);

double __attribute__((__cdecl__)) _drand48_r(struct _reent *);

double __attribute__((__cdecl__)) erand48(unsigned short [3]);

double __attribute__((__cdecl__)) _erand48_r(struct _reent *, unsigned short [3]);

long __attribute__((__cdecl__)) jrand48(unsigned short [3]);

long __attribute__((__cdecl__)) _jrand48_r(struct _reent *, unsigned short [3]);

void __attribute__((__cdecl__)) lcong48(unsigned short [7]);

void __attribute__((__cdecl__)) _lcong48_r(struct _reent *, unsigned short [7]);

long __attribute__((__cdecl__)) lrand48(void);

long __attribute__((__cdecl__)) _lrand48_r(struct _reent *);

long __attribute__((__cdecl__)) mrand48(void);

long __attribute__((__cdecl__)) _mrand48_r(struct _reent *);

long __attribute__((__cdecl__)) nrand48(unsigned short [3]);

long __attribute__((__cdecl__)) _nrand48_r(struct _reent *, unsigned short [3]);

unsigned short *
__attribute__((__cdecl__)) seed48(unsigned short [3]);

unsigned short *
__attribute__((__cdecl__)) _seed48_r(struct _reent *, unsigned short [3]);

void __attribute__((__cdecl__)) srand48(long);

void __attribute__((__cdecl__)) _srand48_r(struct _reent *, long);


char *__attribute__((__cdecl__)) initstate(unsigned, char *, size_t);

long __attribute__((__cdecl__)) random(void);

char *__attribute__((__cdecl__)) setstate(char *);

void __attribute__((__cdecl__)) srandom(unsigned);


long long __attribute__((__cdecl__)) atoll(const char *__nptr);

long long __attribute__((__cdecl__)) _atoll_r(struct _reent *, const char *__nptr);

long long __attribute__((__cdecl__)) llabs(long long);

lldiv_t __attribute__((__cdecl__)) lldiv(long long __numer, long long __denom);

long long __attribute__((__cdecl__)) strtoll(const char *restrict __n, char **restrict __end_PTR, int __base);

long long __attribute__((__cdecl__))
_strtoll_r(struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long __attribute__((__cdecl__)) strtoull(const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long __attribute__((__cdecl__))
_strtoull_r(struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);

int __attribute__((__cdecl__)) __attribute__((__nonnull__(1))) posix_memalign(void **, size_t, size_t);


char *__attribute__((__cdecl__)) _dtoa_r(struct _reent *, double, int, int, int *, int *, char **);


int __attribute__((__cdecl__)) _system_r(struct _reent *, const char *);

void __attribute__((__cdecl__)) __eprintf(const char *, const char *, unsigned int, const char *);

void __attribute__((__cdecl__))
qsort_r(void *__base, size_t __nmemb, size_t __size, void *__thunk, int (*_compar)(void *, const void *, const void *))
__asm__ ("" "__bsd_qsort_r");

extern long double _strtold_r(struct _reent *, const char *restrict, char **restrict);

extern long double strtold(const char *restrict, char **restrict);


void *aligned_alloc(size_t, size_t) __attribute__((__malloc__)) __attribute__((__alloc_align__(1)))
__attribute__((__alloc_size__(2)));

int at_quick_exit(void (*)(void));

_Noreturn void
quick_exit(int);


struct __locale_t;
typedef struct __locale_t *locale_t;


void *__attribute__((__cdecl__)) memchr(const void *, int, size_t);

int __attribute__((__cdecl__)) memcmp(const void *, const void *, size_t);

void *__attribute__((__cdecl__)) memcpy(void *restrict, const void *restrict, size_t);

void *__attribute__((__cdecl__)) memmove(void *, const void *, size_t);

void *__attribute__((__cdecl__)) memset(void *, int, size_t);

char *__attribute__((__cdecl__)) strcat(char *restrict, const char *restrict);

char *__attribute__((__cdecl__)) strchr(const char *, int);

int __attribute__((__cdecl__)) strcmp(const char *, const char *);

int __attribute__((__cdecl__)) strcoll(const char *, const char *);

char *__attribute__((__cdecl__)) strcpy(char *restrict, const char *restrict);

size_t __attribute__((__cdecl__)) strcspn(const char *, const char *);

char *__attribute__((__cdecl__)) strerror(int);

size_t __attribute__((__cdecl__)) strlen(const char *);

char *__attribute__((__cdecl__)) strncat(char *restrict, const char *restrict, size_t);

int __attribute__((__cdecl__)) strncmp(const char *, const char *, size_t);

char *__attribute__((__cdecl__)) strncpy(char *restrict, const char *restrict, size_t);

char *__attribute__((__cdecl__)) strpbrk(const char *, const char *);

char *__attribute__((__cdecl__)) strrchr(const char *, int);

size_t __attribute__((__cdecl__)) strspn(const char *, const char *);

char *__attribute__((__cdecl__)) strstr(const char *, const char *);

char *__attribute__((__cdecl__)) strtok(char *restrict, const char *restrict);

size_t __attribute__((__cdecl__)) strxfrm(char *restrict, const char *restrict, size_t);


int strcoll_l(const char *, const char *, locale_t);

char *strerror_l(int, locale_t);

size_t strxfrm_l(char *restrict, const char *restrict, size_t, locale_t);


char *__attribute__((__cdecl__)) strtok_r(char *restrict, const char *restrict, char **restrict);


int __attribute__((__cdecl__)) bcmp(const void *, const void *, size_t);

void __attribute__((__cdecl__)) bcopy(const void *, void *, size_t);

void __attribute__((__cdecl__)) bzero(void *, size_t);


void __attribute__((__cdecl__)) explicit_bzero(void *, size_t);

int __attribute__((__cdecl__)) timingsafe_bcmp(const void *, const void *, size_t);

int __attribute__((__cdecl__)) timingsafe_memcmp(const void *, const void *, size_t);


int __attribute__((__cdecl__)) ffs(int);

char *__attribute__((__cdecl__)) index(const char *, int);


void *__attribute__((__cdecl__)) memccpy(void *restrict, const void *restrict, int, size_t);

char *__attribute__((__cdecl__)) rindex(const char *, int);


char *__attribute__((__cdecl__)) stpcpy(char *restrict, const char *restrict);

char *__attribute__((__cdecl__)) stpncpy(char *restrict, const char *restrict, size_t);


int __attribute__((__cdecl__)) strcasecmp(const char *, const char *);


char *__attribute__((__cdecl__)) strdup(const char *);

char *__attribute__((__cdecl__)) _strdup_r(struct _reent *, const char *);

char *__attribute__((__cdecl__)) strndup(const char *, size_t);

char *__attribute__((__cdecl__)) _strndup_r(struct _reent *, const char *, size_t);

int __attribute__((__cdecl__)) strerror_r(int, char *, size_t)

__asm__ ("" "__xpg_strerror_r");


char *__attribute__((__cdecl__)) _strerror_r(struct _reent *, int, int, int *);


size_t __attribute__((__cdecl__)) strlcat(char *, const char *, size_t);

size_t __attribute__((__cdecl__)) strlcpy(char *, const char *, size_t);


int __attribute__((__cdecl__)) strncasecmp(const char *, const char *, size_t);


size_t __attribute__((__cdecl__)) strnlen(const char *, size_t);


char *__attribute__((__cdecl__)) strsep(char **, const char *);


char *__attribute__((__cdecl__)) strlwr(char *);

char *__attribute__((__cdecl__)) strupr(char *);


char *__attribute__((__cdecl__)) strsignal(int __signo);


int __attribute__((__cdecl__)) strtosigno(const char *__name);


void __attribute__((__cdecl__)) __assert(const char *, int, const char *) __attribute__ ((__noreturn__));

void __attribute__((__cdecl__))
__assert_func(const char *, int, const char *, const char *) __attribute__ ((__noreturn__));


size_t m_strlen(const char *const s) {
    const char *p = s - 1;
    while (*++p);
    return p - s;
}

size_t m_strnlen(const char *const s, size_t length) {
    const char *p = s - 1;
    length += 2;
    while (--length && *++p);
    return p - s;
}

char *m_strcpy(char *dest, const char *src) {
    char *tmp = dest;
    while ((*dest++ = *src++));
    return tmp;
}

char *m_strncpy(char *dest, const char *src, size_t length) {
    char *tmp = dest;
    while (length-- && (*dest++ = *src++));
    return tmp;
}

char *m_strcat(char *dest, const char *src) {
    char *tmp = dest;
    while (*dest++);
    while ((*dest++ = *src++));
    return tmp;
}

char *m_strncat(char *dest, const char *src, size_t length) {
    char *tmp = dest;
    while (*dest++);
    while (length-- && (*dest++ = *src++));
    return tmp;
}

int m_strcmp(const char *s1, const char *s2) {
    char c1;
    char c2;
    while ((c1 = *s1++) && (c2 = *s2++) && c1 == c2);
    return c1 - c2;
}

int m_strncmp(const char *s1, const char *s2, size_t length) {
    char c1;
    char c2;
    while (length-- && (c1 = *s1++) && (c2 = *s2++) && c1 == c2);
    return c1 - c2;
}

const char *m_strchr(const char *s, const int c) {
    if (c == 0) {
        return s + m_strlen(s);
    }
    char temp;
    while ((temp = *s++) && temp != c);
    if (temp == c) {
        return s - 1;
    }
    return
            ((void *) 0);
}

const char *m_strstr(const char *s1, const char *s2) {
    for (int i = 0; s1[i]; s1++) {
    
    }
}

typedef struct string_funcs_t {
    
    const char *const name;
    
    size_t (*const strlen)(const char *s);
    
    size_t (*const strnlen)(const char *s, size_t length);
    
    char *(*const strcpy)(char *dest, const char *src);
    
    char *(*const strncpy)(char *dest, const char *src, size_t length);
    
    char *(*const strcat)(char *dest, const char *src);
    
    char *(*const strncat)(char *dest, const char *src, size_t length);
    
    int (*const strcmp)(const char *s1, const char *s2);
    
    int (*const strncmp)(const char *s1, const char *s2, size_t length);
    
    const char *(*const strchr)(const char *s, int c);
    
    const char *(*const strstr)(const char *s1, const char *s2);
    
} StringFuncs;


size_t *test_strlen(size_t (*const strlen)(const char *s), size_t *results) {
    *results++ = strlen("hello");
    return results;
}

size_t *test_strnlen(size_t (*const strnlen)(const char *s, size_t length), size_t *results) {
    return results;
}

size_t *test_strcpy(char *(*const strcpy)(char *dest, const char *src), size_t *results) {
    return results;
}

size_t *test_strncpy(char *(*const strncpy)(char *dest, const char *src, size_t length), size_t *results) {
    return results;
}

size_t *test_strcat(char *(*const strcat)(char *dest, const char *src), size_t *results) {
    return results;
}

size_t *test_strncat(char *(*const strncat)(char *dest, const char *src, size_t length), size_t *results) {
    return results;
}

size_t *test_strcmp(int (*const strcmp)(const char *s1, const char *s2), size_t *results) {
    return results;
}

size_t *test_strncmp(int (*const strncmp)(const char *s1, const char *s2, size_t length), size_t *results) {
    return results;
}

size_t *test_strchr(const char *(*const strchr)(const char *s, int c), size_t *results) {
    return results;
}

size_t *test_strstr(const char *(*const strstr)(const char *s1, const char *s2), size_t *results) {
    return results;
}


void test_string_funcs(const StringFuncs *const funcs_ptr, size_t *results) {
    const StringFuncs funcs = *funcs_ptr;
    printf("Testing %s Implementation of String Functions\n\n", funcs.name);
}

void compare_all_string_funcs(const StringFuncs *all_string_funcs, const uint num_string_funcs,
                              const uint baseline_string_funcs_index) {
    
    ((
             baseline_string_funcs_index < num_string_funcs
     ) ? (void) 0 : __assert_func(".\\strings.c", 185, __func__,
                                  "baseline_string_funcs_index < num_string_funcs"
    ));
    const size_t results_size = 100 * sizeof(size_t);
    size_t *const results = (size_t *) calloc(0, num_string_funcs * results_size);
    for (uint i = 0; i < num_string_funcs; ++i) {
        test_string_funcs(all_string_funcs + i, results + (results_size * i));
    }
    const size_t *const baseline_results = results + (results_size * baseline_string_funcs_index);
    for (uint i = 0; i < num_string_funcs; ++i) {
        const size_t *const test_results = results + (results_size * i);
        if (memcmp(baseline_results, test_results, results_size) != 0) {
            printf("StringFuncs #%u (%s) failed\n", i, all_string_funcs[i].name);
        }
    }
}


void compare_string_funcs(const StringFuncs *const baseline_string_funcs, const StringFuncs *const test_string_funcs) {
    const StringFuncs all_string_funcs[] = {*baseline_string_funcs, *test_string_funcs};
    compare_all_string_funcs(all_string_funcs, (sizeof((all_string_funcs)) / sizeof(*(all_string_funcs))), 0);
}

const StringFuncs mine = {"Mine", &m_strlen, &m_strnlen, &m_strcpy, &m_strncpy, &m_strcat, &m_strncat, &m_strcmp,
                          &m_strncmp, &m_strchr, &m_strstr,};
const StringFuncs std = {"Std", &strlen, &strnlen, &strcpy, &strncpy, &strcat, &strncat, &strcmp, &strncmp, &strchr,
                         &strstr,};

int main() {
    compare_string_funcs(&std, &mine);
    
    printf("%zu\n", m_strlen("Hello"));
    printf("%zu\n", m_strnlen("Hello", 3));
    printf("%zu\n", m_strnlen("Hello", 10));
    
    char *s = (char *) malloc(1000);
    m_strcpy(s, "Hello");
    printf("%s\n", s);
    
    m_strncpy(s, "Hello, World", 6);
    printf("%s\n", s);
    
    m_strncpy(s, "Hello, World", 20);
    printf("%s\n", s);
    
}

int my_strlen(char *s) {
    return (int) m_strlen(s);
}

int my_strnlen(char *s, int n) {
    return (int) m_strnlen(s, (size_t) n);
}

char *my_strcpy(char *dest, char *source) {
    return m_strcpy(dest, source);
}

char *my_strncpy(char *dest, char *source, int n) {
    return m_strncpy(dest, source, (size_t) n);
}

char *my_strcat(char *dest, char *source) {
    return m_strcat(dest, source);
}

char *my_strncat(char *dest, char *source, int n) {
    return m_strncat(dest, source, (size_t) n);
}

int my_strcmp(char *s1, char *s2) {
    return m_strcmp(s1, s2);
}

char *my_strchr(char *s1, char c) {
    return (char *) m_strchr(s1, c);
}

char *my_strstr(char *s1, char *s2) {
    return (char *) m_strstr(s1, s2);
}
