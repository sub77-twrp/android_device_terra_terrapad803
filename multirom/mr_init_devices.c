#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
	
	"/sys/devices/virtual/mem/null",
    
    // Framebuffer
    "/sys/class/graphics/fb0",

    "/sys/block/mmcblk0",
    
    "/sys/devices/platform/mtk-msdc.0*",
    "/sys/devices/platform/mtk-msdc.0/mmc_host",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001/block/mmcblk0",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p1",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p2",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p3",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p4",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p5",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p6",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p7",
    "/sys/devices/platform/mtk-msdc.0/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p8",

    "/sys/block/mmcblk1",
    "/sys/block/mmcblk1/mmcblk1p1",
    "/sys/block/mmcblk1/mmcblk1p2",
   
    "/sys/bus/mmc",
    "/sys/bus/mmc/drivers/mmcblk",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",

    "/sys/devices/virtual/input*",
    "/sys/devices/platform/mtk-kpd/input*",
    "/sys/class/misc/uinput",
    "/sys/class/input/input*",
    
    // for adb
    "/sys/class/tty/ptmx",
    "/sys/class/misc/android_adb",
    "/sys/class/android_usb/android0/f_adb",
    "/sys/bus/usb",

    // USB Drive is in here
    "/sys/devices/platform/msm_hsusb_host*",

    // exfat requires fuse device
    "/sys/devices/virtual/misc/fuse",
    
    // for qualcomm overlay - /dev/ion
    "/sys/devices/virtual/misc/ion",

    NULL
};
