Fri Mar  7 10:50:21 CST 2014
SecuGen FDx SDK PRO for Unix/Linux
Version 3.7.1 
#################################################################

Updating '.':
Restored 'src/test_compatibility_ansi378/linux/test'
At revision 570.
================================================================ 
Release Notes:
================================================================= 
1. This version supports the following SecuGen devices:
    USB Hamster PRO 20 VID:0x1162 PID:0x2200 (U20 class device)
    USB Hamster IV VID:0x1162 PID:0x330 (FDU04 class device)
    USB Hamster IV VID:0x1162 PID:0x2000 (SDU04P class device)
    USB Hamster Plus VID:0x1162 PID:0x320 (FDU03 class device)
    USB Hamster Plus VID:0x1162 PID:0x322 (SDU03M class device)
    USB Hamster Plus VID:0x1162 PID:0x1000 (SDU03P class device)
2. This version supports (has been tested with) the following Linux versions:
    (x86)
    UBUNTU 10.04
    Linux SG-UBUNTU 2.6.32-37-generic #81-Ubuntu SMP Fri Dec 2 20:35:14 UTC 2011 i686 GNU/Linux
    libusb-0.1-4 (2:0.1.13)
    gcc version 4.4.3 (Ubuntu 4.4.3-4ubuntu5) 

    (x64)
    Fedora Core 20
    Linux localhost.localdomain 3.11.10-301.fc20.x86_64 #1 SMP Thu Dec 5 14:01:17 UTC 2013 x86_64 x86_64 x86_64 GNU/Linux
    gcc (GCC) 4.8.2 20131212 (Red Hat 4.8.2-7)
    libusb-0.1.5-2.fc20.x86_64
    gtk+-1.2.10-76.fc20.x86_64
    java version "1.7.0_51"


================================================================= 
SYSTEM INSTALLATION NOTES
================================================================= 
1. Install the following packages if no0t already installed on your system.
    libgtk1.2-dev (1.2.10-18.1build2)

2. Install the SecuGen USB Device Drivers
    cd <install_dir>/lib/linux
    make install
    If you need to uninstall, the command is (make uninstall)

3. By default, only the root user can access the SecuGen USB device because the device requires 
    write permissions, To allow non-root users to use the device, perform the following steps:
    3.1 Create a SecuGen Group
        # groupadd SecuGen
    3.2 Add fingerprint users to the SecuGen group.
        #gpasswd -a myUserID SecuGen
        (substitute user name for myUserID)
    3.3 Create a file in /etc/udev/rules.d/99SecuGenSDU03M.rules.
        Add the following lines:

SYSFS{idVendor}=="1162", SYSFS{idProduct}=="0330", SYMLINK+="input/fdu04-%k", MODE="0660", GROUP="SecuGen"
SYSFS{idVendor}=="1162", SYSFS{idProduct}=="2000", SYMLINK+="input/sdu04p-%k", MODE="0660", GROUP="SecuGen"
SYSFS{idVendor}=="1162", SYSFS{idProduct}=="0322", SYMLINK+="input/sdu03m-%k", MODE="0660", GROUP="SecuGen"
SYSFS{idVendor}=="1162", SYSFS{idProduct}=="0320", SYMLINK+="input/fdu03-%k", MODE="0660", GROUP="SecuGen"
KERNEL=="uinput", MODE="0660", GROUP="SecuGen"

    3.4 Reboot

4. Plug in the Hamster Plus or Hamster IV device

5. Now you are ready to run the demo programs in the 
    <installdir>/bin/linux directory

6. When running GTK+ applications from the command-line, you may get 
   the following error message:
Gtk-WARNING **: Failed to load module "libcanberra-gtk-module.so": libcanberra-gtk-module.so: cannot open shared object file: No such file or directory
  $ echo $GTK_MODULES
  canberra-gtk-module
  $ export GTK-MODULES=

7. Binaries linked with Hamster Plus driver are appended with "_fdu03"

8. Binaries linked with Hamster IV driver are appended with "_fdu04"

9. Configuration for java applications
   libjnisgfplib.so supports only one class of SecuGen device at a time.
   The default configuration is for the SecuGen U20 device.
   
   Configuration for Hamster Plus
   cd <install_dir>/lib/linux
   cp libjnisgfplib.so.3.7.0.fdu03_rename libjnisgfplib.so
   make uninstall install

   Configuration for Hamster IV
   cd <install_dir>/lib/linux
   cp libjnisgfplib.so.3.7.0.fdu04_rename libjnisgfplib.so
   make uninstall install

   Configuration for Hamster PRO 20
   cd <install_dir>/lib/linux
   cp libjnisgfplib.so.3.7.0.fdu05_rename libjnisgfplib.so
   make uninstall install


================================================================= 
Java development
================================================================= 
JDK version 1.6.0_24 or later is required for distributions supporting Java

================================================================= 
Bug Fixes/Enhancements
================================================================= 
v3.7.0 REV477 2014-1-2  Hamster PRO 20 is now supported
v3.5.6 REV329 2013-2-25 Java now supported
v3.5.5 REV311 2013-2-13 Multiple devices of same class now supported.
                        FDU04 and FDU03 class devices cannot be used
                        concurrently within the same application. Multiple
                        FDU04 class devices can be used concurrently. 
                        Multiple FDU03 class devices can be used concurrently.
                        Fixed null S/N returned for SDU03M and SDU03P
v3.5.4 REV232 2012-09-28 Fixed auto on sample code
v3.5.4 REV219 2012-09-28 Added support for 512KB SDU04P
                        Fixed problem with exposure settings. Image quality is 
                        improved
v3.5.3 RC1    2012-06-25 Add support for SDU04P, FDU03 and SDU03P
v3.5.3 Beta1  2009-12-10 Initial Release


================================================================= 
Building the demo programs
================================================================= 
-----------------------------------------------------------------
FPLIB TEST SAMPLE
    cd <installdir>/sgfplibtest
    make
    ../bin/linux/fplibtest to run the program
-----------------------------------------------------------------
AUTO_ON TEST SAMPLE
    cd <installdir>/auto_on
    make
    ../bin/linux/fplibtest to run the program
-----------------------------------------------------------------
SECUGEN DIAGNOSTIC SAMPLE
    cd <installdir>/sgd2
    make
    ../bin/linux/sgd2 to run the program
-----------------------------------------------------------------
FPMATCHER SAMPLE
    cd <installdir>/fpmatcher
    make
    ../bin/linux/fpmatcher to run the program
-----------------------------------------------------------------

================================================================= 
Running the Java Samples
================================================================= 
-----------------------------------------------------------------
FPLIB TEST SAMPLE
    cd <installdir>/java
    .sudo ./run_jsgfplibtest.sh
-----------------------------------------------------------------
SGD SWING SAMPLE
    cd <installdir>/java    make
    .sudo ./run_jsgd.sh
-----------------------------------------------------------------
MULTIPLE DEVICE SAMPLE
    cd <installdir>/java
    .sudo ./run_jsgmultidevicetest.sh
-----------------------------------------------------------------
