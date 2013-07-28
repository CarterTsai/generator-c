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
#define FAILS   -1
#define DRIVER_NAME "<%= _(project_name).underscored() %>"

/* Global variables are declared as static, so are global whithin the file */

static int <%= _(project_name).underscored()  %>_major =  0;
static int <%= _(project_name).underscored()  %>_minor =  0;
static int num_of_dev = 1;

/* Function declaration of <%= project_name %>.c */ 

static int <%= _(project_name).underscored() %>_open(struct inode *inode, struct file *filp); 
static int <%= _(project_name).underscored() %>_release(struct inode *inode, struct file *filp); 
static ssize_t <%= _(project_name).underscored() %>_read(struct file *filp, char __user *buf, 
                           size_t count, loff_t *f_pos); 
static ssize_t <%= _(project_name).underscored() %>_write(struct file *filp, const char __user *buf, 
                           size_t count, loff_t *f_pos); 

static long <%= _(project_name).underscored() %>_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);

void <%= _(project_name).underscored() %>_exit(void);
int <%= _(project_name).underscored() %>_init(void);


/* Structure that declares the common */
/* file access fcuntions */
struct file_operations <%= _(project_name).underscored() %>_fops = { 
    owner  : THIS_MODULE,
    read   : <%= _(project_name).underscored() %>_read,
    write  : <%= _(project_name).underscored() %>_write,
    unlocked_ioctl  : <%= _(project_name).underscored() %>_ioctl,
    open   : <%= _(project_name).underscored() %>_open,
    release: <%= _(project_name).underscored() %>_release
};

// Method

static int <%= _(project_name).underscored() %>_open(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "<%= project_name  %> : open operation\n");
    return SUCCESS;
} 

static int <%= _(project_name).underscored() %>_release(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "<%= project_name  %> : release operation\n");
    return SUCCESS;
}

static ssize_t <%= _(project_name).underscored() %>_read(struct file *filp, char __user *buf, 
                           size_t count, loff_t *f_pos)
{
    printk(KERN_INFO "<%= project_name  %> : read operation\n");
    return SUCCESS;
}

static ssize_t <%= _(project_name).underscored() %>_write(struct file *filp, const char __user *buf, 
                           size_t count, loff_t *f_pos)
{
    printk(KERN_INFO "<%= project_name  %> : write operation\n");
    return SUCCESS;
}

static long <%= _(project_name).underscored() %>_ioctl(struct file *filp, unsigned int cmd, 
                            unsigned long arg)
{
    printk(KERN_INFO "<%= project_name  %> : ioctl operation\n");
    return SUCCESS;
}


void <%= _(project_name).underscored() %>_exit(void)
{
    printk(KERN_INFO "<%= project_name  %> : Goodbye ~\n");
}

int <%= _(project_name).underscored() %>_init(void)
{
    int result = 0;
    dev_t dev = MKDEV(<%= _(project_name).underscored()  %>_major, <%= _(project_name).underscored()  %>_minor);

    result = alloc_chrdev_region(&dev, 0, num_of_dev, DRIVER_NAME);

    printk(KERN_INFO "<%= project_name  %> : Hello World\n");
    return SUCCESS;
    
    error:
    return FAILS;
}

module_init(<%= _(project_name).underscored() %>_init);
module_exit(<%= _(project_name).underscored() %>_exit);

MODULE_AUTHOR("Your Name<mail@mail.com>");
MODULE_DESCRIPTION("Char Device Driver");
MODULE_LICENSE("GPL");

