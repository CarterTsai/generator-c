#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> /* printk() */
#include <linux/slab.h> /* kmalloc() */
#include <linux/fs.h> /* everything... */
#include <linux/errno.h> /* error codes */
#include <linux/types.h> /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h> /* O_ACCMODE */
#include <linux/ioport.h>
#include <asm/uaccess.h> /* copy_from/to_user */
#include <asm/io.h> /* inb, outb */

#define SUCCESS 0
#define FAILS   0


/* Global variables are declared as static, so are global whithin the file */

static int major =  0;

/* Function declaration of <%= project_name %>.c */ 

static int <%= _(project_name).underscored() %>_open(struct inode *inode, struct file *filp); 
static int <%= _(project_name).underscored() %>_release(struct inode *inode, struct file *filp); 
static ssize_t <%= _(project_name).underscored() %>_read(struct file *filp, char __user *buf, 
                           size_t count, loff_t *f_pos); 
static ssize_t <%= _(project_name).underscored() %>_write(struct file *filp, const char __user *buf, 
                           size_t count, loff_t *f_pos); 

void <%= _(project_name).underscored() %>_exit(void);
int <%= _(project_name).underscored() %>_init(void);


/* Structure that declares the common */
/* file access fcuntions */
struct file_operations <%= _(project_name).underscored() %>_fops = { 
    read   : <%= _(project_name).underscored() %>_read,
    write  : <%= _(project_name).underscored() %>_write,
    open   : <%= _(project_name).underscored() %>_open,
    release: <%= _(project_name).underscored() %>_release
};

// Method

static int <%= _(project_name).underscored() %>_open(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "<%= project_name  %> : open operation\n");
    return 0;
} 

static int <%= _(project_name).underscored() %>_release(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "<%= project_name  %> : release operation\n");
    return 0;
}

static ssize_t <%= _(project_name).underscored() %>_read(struct file *filp, char __user *buf, 
                           size_t count, loff_t *f_pos)
{
    printk(KERN_INFO "<%= project_name  %> : read operation\n");
    return 0;
}

static ssize_t <%= _(project_name).underscored() %>_write(struct file *filp, const char __user *buf, 
                           size_t count, loff_t *f_pos)
{
    printk(KERN_INFO "<%= project_name  %> : write operation\n");
    return 0;
}


void <%= _(project_name).underscored() %>_exit(void)
{
    printk(KERN_INFO "<%= project_name  %> : Goodbye ~\n");
}

int <%= _(project_name).underscored() %>_init(void)
{
    printk(KERN_INFO "<%= project_name  %> : Hello World\n");
    return 0;
}

module_init(<%= _(project_name).underscored() %>_init);
module_exit(<%= _(project_name).underscored() %>_exit);

MODULE_AUTHOR("Your Name<mail@mail.com>");
MODULE_DESCRIPTION("Char Device Driver");
MODULE_LICENSE("GPL");

