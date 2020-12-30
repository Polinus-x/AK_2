#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <linux/types.h>

MODULE_AUTHOR("Dakhno Nazar IO-81");
MODULE_DESCRIPTION("Writing Hello, World in Kernel");
MODULE_LICENSE("Dual BSD/GPL");

static uint count = 1;
module_param(count,uint,0);
MODULE_PARM_DESC(count, "How many times to write Hello, world");

static int __init initter(void)
{
  uint i = 0;
  
  if(count == 0) {
    printk(KERN_WARNING "WARNING! \nCounter is 0");
  }else if(count >=5 && count <= 10) {
    printk(KERN_WARNING "WARNING! \nCounter is between 5 and 10");
  }else if(count > 10) {
    printk(KERN_ERR "Counter is greater than 10");
    return -EINVAL;
  }

  for(i = 0; i < count; i++){
    printk(KERN_INFO "Hello, world!\n");
  }
  
  printk(KERN_INFO "count: %d\n", count);
  return 0;
}

static void __exit exitter(void)
{
  /* Do nothing here right now */
}

module_init(initter);
module_exit(exitter);
