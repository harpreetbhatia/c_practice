#include <stdlib.h>
#include <stdio.h>

	The functions stat(), fstat(), lstat() are used to get the file status. Here are their prototypes
	 
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
	int stat(const char *file_name, struct stat *buf); int fstat(int file_desc, struct stat *buf);
	int lstat(const char *file_name, struct stat *buf);
	These functions return information about the specified file. You do not need any access rights to the file to get this information but you need search rights to all directories named in the path leading to the file.
	stat	-	stats the file pointed to by file_name and fills in buf. lstat	-	identical to stat, except in the case of a symbolic link,
	where the link itself is stat-ed, not the file that it refers to. fstat	-	identical to stat, only the open file pointed to by file_desc
	is stated in place of file_name.
	They all return a stat structure, which contains the following fields: struct stat {
	dev_t		st_dev;		/* device */ ino_t	st_ino;	/* inode */
	mode_t	st_mode;	/* protection */
	nlink_t		st_nlink;		/* number of hard links */ uid_t	st_uid;	/* user ID of owner */ gid_t	st_gid;	/* group ID of owner */
	dev_t		st_rdev;		/* device type (if inode device) */ off_t	st_size;	/* total size, in bytes */
	unsigned long st_blksize; /* blocksize for filesystem I/O */ unsigned long st_blocks; /* number of blocks allocated */ time_t        st_atime;    /* time of last access */
	time_t	st_mtime;	/* time of last modification */
	 
	time_t	st_ctime;	/* time of last change */
	};

	On success, zero is returned. On error, -1 is returned, and errno is set appropriately.
	Here is a small piece of code which returns the size of a file by accessing the st_size member of the stat structure.
	boolean get_file_size(char *file_path,int *file_size)
	{

	struct stat stat_buffer;
	if (stat((char *)file_path, &stat_buffer)!=0) return(FALSE);
	*file_size = stat_buffer.st_size; return(TRUE);
	}

	So how do we check if a file exists or not?
	Use functions like stat() as used above to find out if a file exits or not. Also, one can use fopen(). When using fopen(), just open for reading and close immediately. If the file does not exists, fopen() will given an error.
	The functions stat(), fstat(), lstat() are used to get the file status. Here are their prototypes
	 
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
	int stat(const char *file_name, struct stat *buf); int fstat(int file_desc, struct stat *buf);
	int lstat(const char *file_name, struct stat *buf);
	These functions return information about the specified file. You do not need any access rights to the file to get this information but you need search rights to all directories named in the path leading to the file.
	stat	-	stats the file pointed to by file_name and fills in buf. lstat	-	identical to stat, except in the case of a symbolic link,
	where the link itself is stat-ed, not the file that it refers to. fstat	-	identical to stat, only the open file pointed to by file_desc
	is stated in place of file_name.
	They all return a stat structure, which contains the following fields: struct stat {
	dev_t		st_dev;		/* device */ ino_t	st_ino;	/* inode */
	mode_t	st_mode;	/* protection */
	nlink_t		st_nlink;		/* number of hard links */ uid_t	st_uid;	/* user ID of owner */ gid_t	st_gid;	/* group ID of owner */
	dev_t		st_rdev;		/* device type (if inode device) */ off_t	st_size;	/* total size, in bytes */
	unsigned long st_blksize; /* blocksize for filesystem I/O */ unsigned long st_blocks; /* number of blocks allocated */ time_t        st_atime;    /* time of last access */
	time_t	st_mtime;	/* time of last modification */
	 
	time_t	st_ctime;	/* time of last change */
	};

	On success, zero is returned. On error, -1 is returned, and errno is set appropriately.
	Here is a small piece of code which returns the size of a file by accessing the st_size member of the stat structure.
	boolean get_file_size(char *file_path,int *file_size)
	{

	struct stat stat_buffer;
	if (stat((char *)file_path, &stat_buffer)!=0) return(FALSE);
	*file_size = stat_buffer.st_size; return(TRUE);
	}

	So how do we check if a file exists or not?
	Use functions like stat() as used above to find out if a file exits or not. Also, one can use fopen(). When using fopen(), just open for reading and close immediately. If the file does not exists, fopen() will given an error.
