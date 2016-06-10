# Information for maintainers of the training material
This file contains the information an recepies for preparing new materials for ROOT tutorials
## Building the CernVM image
To build a new OVA image customized for the tutorials, is best to do it from a CernVM running image. Follow the next instructions:
- Get the RAW image (under KVM) of the latest stable CernVM release from the [CernVM download area](http://cernvm.cern.ch/portal/downloads)
- Prepare a *userdata* file to contextualize the VM image. Here is an example:
~~~
#!/bin/sh
. /etc/cernvm/site.conf
echo "source /cvmfs/sft.cern.ch/lcg/root-training-setup.sh" > /etc/profile.d/tutorial-setup.sh
exit

[amiconfig]
plugins=cernvm cernvm_appliance rapadminpassword

[rpath]
rap-password=

[cernvm_appliance]
password=

[cernvm]
organisations=HEPSOFT
repositories=hepsoft,sft
shell=/bin/bash
config_url=http://cernvm.cern.ch/config
users=user:hepsoft:$6$IafNtgu.$BdxurdZpW8bNHks8p2FFHr/qBGh9FSQg3zBgh90PPsSSHWn8dTMc78ltCQf/W99tPX/7v.wlRGzudvvYQzVHw1
edition=Desktop
screenRes=1024x768
keyboard=us-acentos
startXDM=on
auto_login=on
desktop_icons=README,CltEZXNrdG9wIEVudHJ5XQpWZXJzaW9uPTEuMApUeXBlPUFwcGxpY2F0aW9uCk5hbWU9UkVBRE1FCkNvbW1lbnQ9CkV4ZWM9ZmlyZWZveCBodHRwczovL2dpdGh1Yi5jb20vcm9vdC1taXJyb3IvdHJhaW5pbmcvYmxvYi9tYXN0ZXIvUkVBRE1FLm1kCkljb249L3Vzci9zaGFyZS9pY29ucy9yb290Ni5wbmcKUGF0aD0KVGVybWluYWw9ZmFsc2UKU3RhcnR1cE5vdGlmeT1mYWxzZQo=

[ucernvm-begin]
cvmfs_branch=cernvm-prod.cern.ch

[ucernvm-end]
~~~
- Several remarks concerning the `userdata` file
   - Note the setup script located in CVMFS the reference made in `/etc/profile.d/tutorial-setup.sh` 
   - The desktop icon `README` has been generated using `cat Desktop/README.desktop | base64 -w0` after a launcher has been created called README in the Desktop.
- Generate the final image with the command `cvm2ova -n ROOT-Tutorial -d 10000 -m 1024 -i cernvm-3.6.5.hdd -u userdata -o`. This one is using version 3.6.5 of CernVM, 1 GB memory and 10 GB hard disk.
- Copy the resulting image called *ROOT-Tutorial.ova* to the host or upload it to the GitHub site

