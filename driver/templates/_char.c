#include <linux/init.h>
#include <linux/config.h>
#include <linux/module.h>
#include <linux/kernel.h> /* printk() */
#include <linux/slab.h> /* kmalloc() */
#include <linux/fs.h> /* everything... */
#include <linux/errno.h> /* error codes */
#include <linux/types.h> /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h> /* O_ACCMODE */
#include <linux/ioport.h>
#include <asm/system.h> /* cli(), *_flags */
#include <asm/uaccess.h> /* copy_from/to_user */
#include <asm/io.h> /* inb, outb */

/* Function declaration of <%= project_name %>.c */ 

int <%= _(project_name).underscored() %>_open(struct inode *inode, struct file *filp); 
int <%= _(project_name).underscored() %>_release(struct inode *inode, struct file *filp); 
ssize_t <%= _(project_name).underscored() %>_read(struct file *filp, char *buf, 
                           size_t count, loff_t *f_pos); 
ssize_t <%= _(project_name).underscored() %>_write(struct file *filp, char *buf, 
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

int <%= _(project_name).underscored() %>_open(struct inode *inode, struct file *filp){

} 

int <%= _(project_name).underscored() %>_release(struct inode *inode, struct file *filp){

}

ssize_t <%= _(project_name).underscored() %>_read(struct file *filp, char *buf, 
                           size_t count, loff_t *f_pos){

}


void <%= _(project_name).underscored() %>_exit(void){

}

int <%= _(project_name).underscored() %>_init(void){

}



module_init(<%= _(project_name).underscored() %>_init);
module_exit(<%= _(project_name).underscored() %>_exit);}

MODULE_AUTHOR("Your Name<mail@mail.com>");
MODULE_DESCRIPTION("Char Device Driver");
MODULE_LICENSE("GPL");

